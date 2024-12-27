project(code)

find_package( OpenGL REQUIRED)

set(PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/star.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx_helper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/gui_main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/gui_glview.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/gui_star.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_glwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_vertex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_uicontext.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_glcontext.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_shader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_glframebuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_input.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_light.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx/gfx_mesh.cpp
)

set(PROJECT_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/worldweaver/application.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/worldweaver/gfx_helper.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/worldweaver/star.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gui/gui_main.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gui/gui_glview.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gui/gui_star.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_window.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_glwindow.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_vibuffer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_framebuffer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_rendercontext.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_uicontext.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_glcontext.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/element/gfx_vertex.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/element/gfx_camera.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/element/gfx_input.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/element/gfx_light.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/element/gfx_mesh.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/shader/gfx_shader.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/inc/gfx/gfx_glframebuffer.hpp
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

configure_file("${CMAKE_SOURCE_DIR}/lib/assimp/include/assimp/config.h.in" "${CMAKE_SOURCE_DIR}/lib/assimp/include/assimp/config.h")
configure_file("${CMAKE_SOURCE_DIR}/lib/assimp/contrib/zlib/zconf.h.cmakein" "lib/assimp/contrib/zlib/zconf.h")

target_link_libraries(worldweaver
                      libassert-lib
                      imgui
                      assimp
                      ${OPENGL_LIBRARIES}
                      glm
                      glfw
                      glad
                      )