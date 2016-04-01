#include "common.hpp"
#include "database.hpp"
#include "recipes.hpp"


Ingredient::Ingredient(db_key key) {}
void Ingredient::save() {}
void Ingredient::remove() {}
void Ingredient::set_name(string name) {}
string Ingredient::get_name() {}


IngredientListing::IngredientListing(db_key key) {}

void IngredientListing::save() {}
void IngredientListing::remove() {}

Recipe IngredientListing::get_recipe() {}
void IngredientListing::set_recipe(Recipe & recipe) {}

void IngredientListing::set_ingredient(Ingredient ingredient) {}
void IngredientListing::set_amount(unsigned int amount, string unit) {}
string IngredientListing::show() {}


Recipe::Recipe(db_key key) {}

void Recipe::save() {}
void Recipe::remove() {}

string Recipe::get_name() {}
string Recipe::set_name(string name) {}

const string & Recipe::get_instructions() {}
string Recipe::set_instructions(string instructions) {}

const vector<IngredientListing> & Recipe::get_ingredients() {}
void Recipe::add_ingredient(IngredientListing ingredient) {}
void Recipe::remove_ingredient(IngredientListing ingredient) {}


Profile::Profile(db_key key) {}

void Profile::save() {}
void Profile::remove() {}

void Profile::set_name(string name) {}
string Profile::get_name() {}

const vector<Recipe> & Profile::get_recipes() {}
void Profile::add_recipe(Recipe recipe) {}
void Profile::remove_recipe(Recipe recipe) {}
