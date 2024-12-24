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
    WIN32
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
                           )

target_link_libraries(worldweaver
                      libassert-lib
                      imgui
                      ${OPENGL_LIBRARIES}
                      glm
                      glfw
                      )

install(TARGETS worldweaver
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)