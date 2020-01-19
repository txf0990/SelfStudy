include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(NameCalc NameCalc.h NameCalc.cpp)
add_library(Student Student.h Student.cpp)
target_link_libraries(Student NameCalc)

add_library(NameCalcStatic NameCalcStatic.h NameCalcStatic.cpp)

add_executable(main main.cpp)
target_link_libraries(main Student)
target_link_libraries(main NameCalcStatic)

add_executable(NameCalcTest NameCalcTest.cpp)
target_link_libraries(NameCalcTest gtest_main)
target_link_libraries(NameCalcTest NameCalc)
add_test(NameCalcTest NameCalcTest --gtest_color=yes)

add_executable(StudentTest StudentTest.cpp)
target_link_libraries(StudentTest gmock_main)
target_link_libraries(StudentTest Student)
add_test(StudentTest StudentTest --gtest_color=yes)
