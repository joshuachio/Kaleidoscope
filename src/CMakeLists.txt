include_directories(${KALEIDOSCOPE_INCLUDE_DIR})

add_library(lexer lexer.cpp)
add_library(parser parser.cpp)

add_executable(kaleidoscope main.cpp)
target_link_libraries(kaleidoscope parser lexer)