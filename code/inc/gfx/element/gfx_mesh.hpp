/**************************************************************************************************/
/**
* \addtogroup GFX_ELEMENT
* @{
* \details
* This file provides the public interface for the Mesh Module.
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

#include "gfx/element/gfx_element.hpp"
#include "gfx/element/gfx_vertex.hpp"
#include "gfx/shader/gfx_shader.hpp"
#include "gfx/gfx_glvibuffer.hpp"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types and Classes
**===============================================================================================*/
namespace GFX
{
    namespace Element
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        class Mesh : public Element
        {

        public:
            /*********************************/
            // Public member variables
            /*********************************/

            glm::vec3 m_Color;      // The color of the mesh.
            float32_t m_Roughness;  // The roughness of the mesh.
            float32_t m_Metallic;   // The metallic value of the mesh.

            /*********************************/
            // Constructors/Destructor
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief The default constructor for the Mesh.
            */
            Mesh(void) = default;

            /**************************************************************************************************/
            /**
            * \brief The default destructor for the Mesh.
            */
            virtual ~Mesh(void);

            /*********************************/
            // Public functions
            /*********************************/

            /**************************************************************************************************/
            /**
            * \brief Loads the mesh from a file.
            * 
            * \param[in] path The path to the mesh file.
            * 
            * \retval True if the mesh was loaded.
            * \retval False if the mesh was not loaded.
            */
            bool Load(const std::string& path);

            /**************************************************************************************************/
            /**
            * \brief Adds a vertex to the mesh.
            * 
            * \param[in] vertex The vertex to add.
            */
            void AddVertex(const Vertex& vertex);

            /**************************************************************************************************/
            /**
            * \brief Adds an index to the mesh.
            * 
            * \param[in] index The index to add.
            */
            void AddIndex(uint32_t index);

            /**************************************************************************************************/
            /**
            * \brief Gets the indices of the mesh.
            * 
            * \retval std::vector<uint32_t> The indices of the mesh.
            */
            std::vector<uint32_t> GetIndices(void) const;

            /**************************************************************************************************/
            /**
            * \brief Updates the mesh.
            * 
            * \param[in] shader The shader to update.
            */
            void Update(GFX::Util::Shader* shader) override;

            /**************************************************************************************************/
            /**
            * \brief Initializes the mesh.
            */
            void Initialize(void);

            /**************************************************************************************************/
            /**
            * \brief Creates the buffers for the mesh.
            */
            void CreateBuffers(void);

            /**************************************************************************************************/
            /**
            * \brief Deletes the buffers for the mesh.
            */
            void DeleteBuffers(void);
            
            /**************************************************************************************************/
            /**
            * \brief Renders the mesh.
            */
            void Render(void);

            /**************************************************************************************************/
            /**
            * \brief Binds to the mesh buffers.
            */
            void Bind(void);

            /**************************************************************************************************/
            /**
            * \brief Unbiunds from the mesh buffers.
            */
            void UnBind(void);

        private:
            /*********************************/
            // Private member variables
            /*********************************/

            std::unique_ptr<GFX::Render::GLVertexBuffer> m_RenderBufferManager;     // The Render Buffer Manager.
            std::vector<Vertex> m_Vertices;                                         // The vertices of the mesh.
            std::vector<uint32_t> m_Indices;                                        // The indices of the mesh.


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

namespace GFX
{
    namespace Element
    {
        /**************************************************************************************************/
        /**
        * \par Details: 
        */
        inline Mesh::~Mesh(void)
        {
            DeleteBuffers();
        }
    }
    
} // namespace GFX

/** @} */