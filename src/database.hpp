#ifndef RECIPEMANAGER_DATABASE_H
#define RECIPEMANAGER_DATABASE_H

#include <sqlite_modern_cpp.h>
using sqlite::database;

#include <mutex>
using std::mutex;
using std::lock_guard;

typedef unsigned int db_key;


/**
 * Base class for all objects that can be stored in the database.
 */
class Persistable {
protected:
        db_key key = 0;
public:
        db_key get_key() const;
        virtual void save() = 0;
        virtual void remove() = 0;
};


/**
 * This is the class used for database access. It is a singleton, and
 * is thread-safe.
 */
class Database {
private:
        static database* db;
        static mutex init_mutex;
        static void initialize();
        Database();
public:
        static database* connection();
};


#endif
