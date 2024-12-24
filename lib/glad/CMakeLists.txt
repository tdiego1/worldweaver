project(glad)

set(GLAD_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c
    )

set(GLAD_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include/glad/glad.h
    )

add_library(glad STATIC
            ${GLAD_SOURCES}
            ${GLAD_INCLUDES}
            )

target_include_directories(glad
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                           )