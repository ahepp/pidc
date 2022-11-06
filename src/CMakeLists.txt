add_library(pidc
        pidc.c
        )
target_include_directories(pidc
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        )
target_compile_options(pidc
        PRIVATE
        -Wall
        )

    file(GLOB_RECURSE PIDC_INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/*")
set_target_properties(pidc
        PROPERTIES
        PUBLIC_HEADER "${PIDC_INCLUDE_FILES}"
        )

install(TARGETS pidc
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )
