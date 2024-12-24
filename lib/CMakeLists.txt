project(lib)

add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(libassert)

#---------------------------------------------------------------------------
    # imGUI library

set(IMGUI_INCLUDE_DIR imgui)

add_library(imgui
        ${IMGUI_INCLUDE_DIR}/imgui.h
        ${IMGUI_INCLUDE_DIR}/imgui.cpp
        ${IMGUI_INCLUDE_DIR}/imconfig.h
        ${IMGUI_INCLUDE_DIR}/imgui_internal.h
        ${IMGUI_INCLUDE_DIR}/imstb_textedit.h
        ${IMGUI_INCLUDE_DIR}/imstb_rectpack.h
        ${IMGUI_INCLUDE_DIR}/imstb_truetype.h
        ${IMGUI_INCLUDE_DIR}/imgui_widgets.cpp
        ${IMGUI_INCLUDE_DIR}/imgui_tables.cpp
        ${IMGUI_INCLUDE_DIR}/imgui_demo.cpp
        ${IMGUI_INCLUDE_DIR}/imgui_draw.cpp
        ${IMGUI_INCLUDE_DIR}/backends/imgui_impl_glfw.h
        ${IMGUI_INCLUDE_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_INCLUDE_DIR}/backends/imgui_impl_opengl3.h
        ${IMGUI_INCLUDE_DIR}/backends/imgui_impl_opengl3.cpp
    )

target_include_directories(imgui
                            PRIVATE glfw/include
                            PRIVATE glad/inc
                            PUBLIC ${IMGUI_INCLUDE_DIR}
                            )

