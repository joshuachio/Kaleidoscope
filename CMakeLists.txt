cmake_minimum_required(VERSION 3.0)

set(KALEIDOSCOPE_PROJECT_NAME "Kaleidoscope")
set(KALEIDOSCOPE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(KALEIDOSCOPE_SRC_DIR ${KALEIDOSCOPE_ROOT_DIR}/src)
set(KALEIDOSCOPE_INCLUDE_DIR ${KALEIDOSCOPE_ROOT_DIR}/include)

project(${KALEIDOSCOPE_PROJECT_NAME})

# find_package(LLVM REQUIRED CONFIG)
# include_directories(${LLVM_INCLUDE_DIRS})
# add_definitions(${LLVM_DEFINITIONS})

add_subdirectory(${KALEIDOSCOPE_SRC_DIR})

# llvm_map_components_to_libnames(llvm_libs support core irreader)
# target_link_libraries(kaleidoscope ${llvm_libs})

# set(LLVM_FLAGS "llvm-config --cxxflags --ldflags --system-libs --libs core")

# add_compile_options(${LLVM_FLAGS})

add_compile_options(`llvm-config --cxxflags --ldflags --system-libs --libs core`)