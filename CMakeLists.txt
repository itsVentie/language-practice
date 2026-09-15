cmake_minimum_required(VERSION 3.20)
project(Study CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE STUDY_SOURCES 
    "basics/*.cpp"
    "functions/*.cpp"
    "pointers_memory/*.cpp"
    "structures_classes/*.cpp"
    "stl/*.cpp"
    "libs/*.cpp"
    "oop/*.cpp"
)

foreach(SOURCE_FILE ${STUDY_SOURCES})
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
endforeach()