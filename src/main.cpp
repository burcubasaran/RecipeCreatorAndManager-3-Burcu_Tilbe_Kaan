#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>
#include <string>
#include "database.hpp"



class hello : public cppcms::application {
public:
        hello(cppcms::service &srv) :
                cppcms::application(srv){}
        virtual void main(std::string url);
};

void hello::main(std::string url) {
        std::string url_param = url.substr(1);
        std::string greeting;
        response().out() <<
                "<html>\n"
                "<body>\n"
                "<h1>"
                "\n";
        try {
                database* db = Database::connection();
                *db << "SELECT greeting FROM greetings WHERE language LIKE ?" << url_param >> greeting;
                response().out() << greeting;
        } catch(std::exception const &e) {
                response().out() << e.what();
        }
        response().out() <<
                "</h1>\n"
                "</body>\n"
                "</html>\n";

}

int main(int argc,char ** argv) {
        database* db = Database::connection();
        try {
                *db << "CREATE TABLE IF NOT EXISTS greetings(language TEXT PRIMARY KEY NOT NULL, greeting TEXT NOT NULL);";
        } catch(std::exception const &e) {
                std::cerr << "Error creating table." << std::endl;
                std::cerr << e.what() << std::endl;
                return 1;
        } try {
                auto ps = *db << "INSERT INTO greetings VALUES (?, ?)";
                ps << "turkish" << "Merhaba!";
                ps++;
                ps << "english" << "Hello!";
                ps++;
                ps << "japanese" << "お早う";
                ps++;

                cppcms::service srv(argc,argv);
                srv.applications_pool().mount(
                        cppcms::applications_factory<hello>());
                srv.run();
        } catch(std::exception const &e) {
                std::cerr << e.what() << std::endl;
                return 1;
        }
}
