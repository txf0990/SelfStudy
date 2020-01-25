include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cpp)

add_executable(vectorTest vectorTest.cpp)
target_link_libraries(vectorTest gtest_main)
add_test(vectorTest vectorTest --gtest_color=yes)
