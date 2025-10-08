add_library(Three Three.cpp)

add_executable(main main.cpp)

target_link_libraries(main Three)