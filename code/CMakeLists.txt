project(code)

find_package( OpenGL REQUIRED)

set(PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/star.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp

)

set(PROJECT_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/worldweaver/star.hpp
)

add_executable(worldweaver
    ${PROJECT_SOURCES}
    ${PROJECT_INCLUDES}
)

target_include_directories(worldweaver PUBLIC
                           ${OPENGL_INCLUDE_DIRS}
                           ${CMAKE_CURRENT_SOURCE_DIR}/inc
                           ${CMAKE_SOURCE_DIR}/lib/glfw/include
                           ${CMAKE_SOURCE_DIR}/lib/glm
                           ${CMAKE_SOURCE_DIR}/lib/imgui
                           ${CMAKE_SOURCE_DIR}/lib/libassert
                           ${CMAKE_SOURCE_DIR}/lib/glad/include
                           )

target_link_libraries(worldweaver
                      libassert-lib
                      imgui
                      ${OPENGL_LIBRARIES}
                      glm
                      glfw
                      glad
                      )