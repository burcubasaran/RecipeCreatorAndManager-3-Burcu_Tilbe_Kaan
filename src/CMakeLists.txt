add_library(database STATIC database.cpp)

add_library(recipes STATIC recipes.cpp)

add_executable(Recipe-Manager main.cpp)
target_link_libraries(Recipe-Manager database recipes cppcms sqlite3)
install(TARGETS Recipe-Manager RUNTIME DESTINATION bin)
