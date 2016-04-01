#ifndef RECIPEMANAGER_RECIPES_H
#define RECIPEMANAGER_RECIPES_H
#include "common.hpp"
#include "database.hpp"


class Recipe;
class Ingredient;
class IngredientListing;
class Profile;

/**
 * The class for ingredients.
 *
 * This class only contains the base information about ingredients,
 * such as the name of the ingredient. Recipe specific information
 * such as amount of the ingredient in the recipe should be stored in
 * IngredientListing.
 */
class Ingredient : public Persistable {
private:
        string name;
public:
        Ingredient() {}
        Ingredient(db_key key);

        void save();
        void remove();

        void set_name(string name);
        string get_name();
};


/**
 * This class is used to map ingredients to recipes. Recipe objects
 * will contain IngredientListing objects.
 */
class IngredientListing : public Persistable {
private:
        unsigned int amount = 0;
        string unit;
        Ingredient ingredient;
        db_key recipe_key;
public:
        IngredientListing() {}
        IngredientListing(db_key key);

        void save();
        void remove();

        Recipe get_recipe();
        void set_recipe(Recipe & recipe);

        void set_ingredient(Ingredient ingredient);
        void set_amount(unsigned int amount, string unit);
        string show();
};


/**
 * The class for ingredients.
 */
class Recipe : public Persistable {
private:
        string name;
        vector<IngredientListing> ingredients;
        string instructions;
public:
        Recipe() {}
        Recipe(db_key key);

        void save();
        void remove();

        string get_name();
        string set_name(string name);

        const string & get_instructions();
        string set_instructions(string instructions);

        const vector<IngredientListing> & get_ingredients();
        void add_ingredient(IngredientListing ingredient);
        void remove_ingredient(IngredientListing ingredient);
};


/**
 * The class for user profiles.
 */
class Profile : public Persistable {
private:
        string name;
        vector<Recipe> recipes;
public:
        Profile() {}
        Profile(db_key key);

        void save();
        void remove();

        void set_name(string name);
        string get_name();

        const vector<Recipe> & get_recipes();
        void add_recipe(Recipe recipe);
        void remove_recipe(Recipe recipe);
};

#endif // RECIPEMANAGER_RECIPES_H
