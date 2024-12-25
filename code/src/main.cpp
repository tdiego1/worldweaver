/**************************************************************************************************/
/**
 * \addtogroup main
 * @{
 * \details
 * This file implements the main functionality.
 * 
 * \par COPYRIGHT
 * Copyright (C) 2024 Diego Torres. All rights reserved.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************************************/

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <libassert/assert.hpp>

#include "gui/gui_main.hpp"
#include "worldweaver/gfx_helper.hpp"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types
**===============================================================================================*/

/*=================================================================================================
** 3.3 External global variables
**===============================================================================================*/

/*=================================================================================================
** 3.4 Static global variables
**===============================================================================================*/

const char* g_VertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* g_FragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n";

/*=================================================================================================
** 3.5 Static function prototypes
**===============================================================================================*/

/**************************************************************************************************/
/**
 * \brief Callbck to update the OpenGL viewport when window is resized.
 * 
 * \param[in]     window  The GLFW window.
 * \param[in]     width   The width of the window.
 * \param[out]    height  The height of the window.
 */
void frameBufferSizeCallback(GLFWwindow* window, int32_t width, int32_t height);

/*=================================================================================================
** 4.  PRIVATE FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
 * \par Details: None.
 */
void frameBufferSizeCallback(GLFWwindow* window, int32_t width, int32_t height)
{
    glViewport(0, 0, width, height);    //Update the OpenGL viewport
}

/*=================================================================================================
** 5.  PUBLIC FUNCTIONS
**===============================================================================================*/
/**************************************************************************************************/
/**
 * \brief This is the main function for the QT window
 */
int main(int argc, char *argv[])
{
    // 1. Initialize and Configure GLFW
    ///////////////////////////////////////////////////////
    
    WorldWeaver::GFX::GFXHelper gfx_helper;

    gfx_helper.GFXHelperInit();

    // 2. Create GLFW Window
    ///////////////////////////////////////////////////////

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    // Check if the window was created successfully.
    if(window == NULL)
    {
        printf("Failed to create GLFW window.\n");
        glfwTerminate();
        return -1;
    }

    // Set the window we just created to the current context.
    glfwMakeContextCurrent(window);

    // Register the window resize callback.
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    // 3. Load OpenGL function pointers with GLAD
    ///////////////////////////////////////////////////////

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD");
        return -1;
    }

    // 4. Setup Vertex Shader
    ///////////////////////////////////////////////////////

    gfx_helper.SetupShader(g_VertexShaderSource, WorldWeaver::GFX::GFXHelper::ShaderType::VERTEX);

    // 5. Setup Fragment Shader
    ///////////////////////////////////////////////////////

    gfx_helper.SetupShader(g_FragmentShaderSource, WorldWeaver::GFX::GFXHelper::ShaderType::FRAGMENT);    

    // 6. Link and Compile Shader Program
    ///////////////////////////////////////////////////////

    gfx_helper.CompileShaderProgram();

    // 7. Setup Vertex Data, Attributes, and Buffers
    ///////////////////////////////////////////////////////

    float vertices[] = 
    {
         0.5f,  0.5f, 0.0f, // Top Right
         0.5f, -0.5f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f  // Top Left
    };

    uint32_t indices[] = 
    {
        0, 1, 3,    // First triangle
        1, 2, 3     // Second triangle
    };

    uint32_t vbo;   // OpenGL Vertex Buffer Object (VBO) ID
    uint32_t vao;   // OpenGL Vertex Array Object (VAO) ID
    uint32_t ebo;   // OpenGL Element Buffer Object (EDO) ID

    // Generate OpenGL vertex array with ID stored in vao.
    glGenVertexArrays(1, &vao);

    // Generate OpenGL vertex and element buffers
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    // Bind the vao
    glBindVertexArray(vao);

    // Bind the vbo object and copy verterx data to the buffer memory.
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Bind the to ebo and copy indicies to the buffer memory.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind vbo.
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind vao.
    glBindVertexArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // 8. ImGui Setup
    ///////////////////////////////////////////////////////

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    // 9. Render Loop
    ///////////////////////////////////////////////////////

    // Loops until the window is closed.
    while(!glfwWindowShouldClose(window))
    {
        // Process input.
        glfwPollEvents();
        if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        WorldWeaver::GUI::StarInterface();

        // Rendering commands.
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Specify the shader program to use.
        glUseProgram(gfx_helper.GetShaderProgram());

        // Bind to VAO
        glBindVertexArray(vao);

        // Draw triangle.
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swaps the buffer to render to the screen.
        glfwSwapBuffers(window);
    }

    // 9. Clean Up and Terminate
    ///////////////////////////////////////////////////////

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteProgram(gfx_helper.GetShaderProgram());

    // Properly terminates and cleans all the GLFW resources that were allocated.
    glfwTerminate();

    return 0;
}
/** @}*/