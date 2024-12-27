/**************************************************************************************************/
/**
* \addtogroup GUI
* @{
* \details
* This file provides the public interface for the GLView Module.
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

#pragma once

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/gfx_common.hpp"

#include "gfx/element/gfx_mesh.hpp"
#include "gfx/element/gfx_input.hpp"
#include "gfx/element/gfx_camera.hpp"
#include "gfx/element/gfx_light.hpp"
#include "gfx/shader/gfx_shader.hpp"
#include "gfx/gfx_glframebuffer.hpp"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types and Classes
**===============================================================================================*/
namespace WorldWeaver
{
    namespace GUI
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class GLView
        {

        public:
            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the GLView.
            */
            GLView(void);

            /**************************************************************************************************/
            /**
            * \brief The default destructor for the GLView.
            */
            ~GLView(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Gets the Light.
            */
            GFX::Element::Light* GetLight(void);

            /**************************************************************************************************/
            /**
             * \brief Resizes the view.
             *  
             * \param[in] width  The width of the view.
             * \param[in] height The height of the view.
             */
            void Resize(int32_t width, int32_t height);

            /**************************************************************************************************/
            /**
             * \brief Renders the view.
             */
            void Render(void);

            /**************************************************************************************************/
            /**
            * \brief Loads a mesh.
            * 
            * \param[in] path The path to the mesh.
            */
            void LoadMesh(const std::string& path);

            /**************************************************************************************************/
            /**
            * \brief Sets the mesh.
            * 
            * \param[in] mesh The mesh.
            */
           void SetMesh(std::shared_ptr<GFX::Element::Mesh> mesh);

           /**************************************************************************************************/
           /**
           * \brief Gets the mesh.
           * 
           * \retval std::shared_ptr<GFX::Element::Mesh> The mesh.
           */
           std::shared_ptr<GFX::Element::Mesh> GetMesh(void);

           /**************************************************************************************************/
           /**
           * \brief Called when the mouse is moved.
           * 
           * \param[in] x      The x position of the mouse.
           * \param[in] y      The y position of the mouse.
           * \param[in] button The button pressed.
           */
           void OnMouseMove(float64_t x, float64_t y, GFX::Element::Input::EInputButton button);

           /**************************************************************************************************/
           /**
           * \brief Called when the mouse is scrolled.
           * 
           * \param[in] delta The scroll delta.
           */
           void OnMouseWheel(float64_t delta);

           /**************************************************************************************************/
           /**
           * \brief Resets the view.
           */
           void ResetView(void);

        private:
            /*********************************/
            // Private member variables
            /*********************************/

            std::unique_ptr<GFX::Element::Camera> m_Camera;             // The camera.
            std::unique_ptr<GFX::Render::GLFrameBuffer> m_FrameBuffer;  // The frame buffer.
            std::unique_ptr<GFX::Util::Shader> m_Shader;                // The shader.
            std::unique_ptr<GFX::Element::Light> m_Light;               // The light.
            std::shared_ptr<GFX::Element::Mesh> m_Mesh;                 // The mesh.
            glm::vec2 m_Size;                                           // The size of the view.

        };
    }
}

/*=================================================================================================
** 3.3 Constants
**===============================================================================================*/

/*=================================================================================================
** 3.4 Variables
**===============================================================================================*/

/*=================================================================================================
** 3.5 Functions
**===============================================================================================*/
namespace WorldWeaver
{
    namespace GUI
    {
        inline GLView::~GLView()
        {
            m_Shader->Unload();
        }
    }
}

/** @} */