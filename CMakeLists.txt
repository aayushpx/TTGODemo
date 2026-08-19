cmake_minimum_required(VERSION 3.16)

add_compile_definitions(TTGO_S3 BOARD_HAS_PSRAM)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(TTGODemo)
