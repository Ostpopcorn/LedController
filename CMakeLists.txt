

if(ESP_PLATFORM)
    idf_component_register(SRC_DIRS src
            INCLUDE_DIRS include)
    component_compile_options(-std=gnu++17)
else()
    cmake_minimum_required(VERSION 3.16)
    project(led_matrix_control)

    set(CMAKE_CXX_STANDARD 17)


    add_library(led_control_lib STATIC src/Coordinate.cpp include/Coordinate.h src/Led.cpp include/Led.h src/LedController.cpp include/LedController.h src/Animator.tpp include/Animator.h src/Color.tpp include/Color.h src/ColorRGBA.tpp src/ColorRGB.tpp)
    add_executable(led_control main.cpp)
    add_executable(tests_setup tests.cpp tests.cpp)
    target_link_libraries(led_control led_control_lib)
    target_link_libraries(tests_setup led_control_lib)
endif()
