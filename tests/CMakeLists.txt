add_executable(Three_class_tests main.cpp Three_class_tests.cpp)

target_link_libraries(Three_class_tests gtest gtest_main Three)

include(GoogleTest)
gtest_discover_tests(Three_class_tests)