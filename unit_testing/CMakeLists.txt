cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test 
# and the GTest and pthread library
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
add_library(Code_Lib ../JSONParser.cpp)
add_executable(runTests json_parser_test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread Code_Lib)
target_compile_features(runTests PRIVATE cxx_std_17)