cmake_minimum_required(VERSION 3.2)
add_library(blk
    brace_handler.cpp
    bulk.cpp
    bulk_proxy.cpp
    command_handler.cpp
    console_output.cpp
    file_output.cpp
    handler.cpp
    handler_fabric.cpp
    lib.cpp
    )
set_target_properties(blk PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)
target_link_libraries(blk stdc++fs)