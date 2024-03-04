include_directories(${KALEIDOSCOPE_INCLUDE_DIR})

add_library(lexer lexer.cpp)
add_library(parser parser.cpp)

find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


add_executable(kaleidoscope main.cpp)
target_link_libraries(kaleidoscope parser lexer)
llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(kaleidoscope ${llvm_libs})