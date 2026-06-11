cmake_minimum_required(VERSION 3.16)

project(temperature_monitor LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)   


add_subdirectory(portable-display-driver)

add_library(htu21d_driver STATIC
            third_party/htu21d/crc_calc.c
            third_party/htu21d/htu21d_i2c.c
           )


target_include_directories(htu21d_driver PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/third_party/htu21d 
                          )
