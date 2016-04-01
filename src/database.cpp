#include "database.hpp"

db_key Persistable::get_key() const {
        return key;
}


database* Database::db = NULL;
mutex Database::init_mutex;


void Database::initialize() {
        // int config_result = sqlite3_config(SQLITE_CONFIG_SERIALIZED);
        // if (config_result != 0) {
        //         throw std::runtime_error("Error while setting sqlite3 configuration!");
        // }
        db = new database(":memory:");
}


database* Database::connection() {
        if (db == NULL) {
                lock_guard<mutex> lock(init_mutex);
                if (db == NULL) {
                        initialize();
                }
        }
        return db;
}
