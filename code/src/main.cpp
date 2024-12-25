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

    glfwInit(); // Initialize the GLFW window.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // Set the OpenGL major version to 3.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // Set the OpenGL minor version to 3.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // Get the OpenGL profile to core.

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

    uint32_t vertex_shader; // Vertex shader object ID.
    int32_t success;        // Is the shader compilation successful?
    char info_log[512];     // String for logging errors.

    // Create vertex shader object.
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    // Attach the shader source code to the shader object.
    glShaderSource(vertex_shader, 1, &g_VertexShaderSource, NULL);

    // Compile the vertex shader.
    glCompileShader(vertex_shader);

    // Check if compilation was successful.
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    // Retrieve error message if compilation was unsuccessful.
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);

        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
        printf("%s", info_log);
        printf("\n");
    }

    // 5. Setup Fragment Shader
    ///////////////////////////////////////////////////////
    
    uint32_t fragment_shader;   // Fragment shader object ID.

    // Create fragment shader object.
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    // Attach the fragment source code to the fragment shader object.
    glShaderSource(fragment_shader, 1, &g_FragmentShaderSource, NULL);

    // Compile the fragement shader.
    glCompileShader(fragment_shader);

    // Check if the compilation was successful.
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    // Retrieve error message if compilation was unsuccessful.
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);

        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
        printf("%s", info_log);
        printf("\n");
    }

    // 6. Link and Compile Shader Program
    ///////////////////////////////////////////////////////

    uint32_t shader_program;    // Shader program object ID.

    // Create shader program.
    shader_program = glCreateProgram();

    // Attach vertex shader to shader program.
    glAttachShader(shader_program, vertex_shader);

    // Attach fragment shader to shader program.
    glAttachShader(shader_program, fragment_shader);

    // Link shaders to shader program.
    glLinkProgram(shader_program);

    // Check if linking was successful.
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

    //Retrieve error message if linking was unsuccessful.
    if(!success)
    {
        glGetProgramInfoLog(shader_program, 512, NULL, info_log);

        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
        printf("%s", info_log);
        printf("\n");
    }

    // Delete vertex and fragment shaders after linking.
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

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
        glUseProgram(shader_program);

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
    glDeleteProgram(shader_program);

    // Properly terminates and cleans all the GLFW resources that were allocated.
    glfwTerminate();

    return 0;
}
/** @}*/