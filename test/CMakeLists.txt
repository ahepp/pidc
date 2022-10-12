add_executable(pidc_tests
        pidc_tests.c
        )
target_link_libraries(pidc_tests
        PRIVATE
        pidc
        unity
        )
target_compile_options(pidc_tests
        PRIVATE
        -Wall
        )
add_custom_command(
        POST_BUILD
        TARGET pidc_tests
        COMMAND pidc_tests
        )
