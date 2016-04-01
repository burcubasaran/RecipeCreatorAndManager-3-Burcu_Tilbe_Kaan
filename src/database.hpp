#ifndef RECIPEMANAGER_DATABASE_H
#define RECIPEMANAGER_DATABASE_H

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


#endif
