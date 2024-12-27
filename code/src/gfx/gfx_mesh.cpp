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

/*=================================================================================================
** 1.  REFERENCES
**===============================================================================================*/

/*=================================================================================================
** 2.  INCLUDE FILES
**===============================================================================================*/

#include "gfx/element/gfx_mesh.hpp"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

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

/*=================================================================================================
** 3.5 Static function prototypes
**===============================================================================================*/

/*=================================================================================================
** 4.  PUBLIC FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
* \par Details: 
*/
bool GFX::Element::Mesh::Load(const std::string& path)
{
    const uint32_t c_mesh_import_flags =
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_SortByPType |
        aiProcess_GenNormals |
        aiProcess_GenUVCoords |
        aiProcess_OptimizeMeshes |
        aiProcess_ValidateDataStructure;

    Assimp::Importer Importer;

    const aiScene* scene = Importer.ReadFile(path.c_str(),
    c_mesh_import_flags);

    if (scene && scene->HasMeshes())
    {
        m_Indices.clear();
        m_Vertices.clear();

        auto* mesh = scene->mMeshes[0];

        for (uint32_t i = 0; i < mesh->mNumVertices; i++)
        {
            GFX::Element::Vertex vertex;
            vertex.m_Position = { mesh->mVertices[i].x, mesh->mVertices[i].y ,mesh->mVertices[i].z };
            vertex.m_Normal = { mesh->mNormals[i].x, mesh->mNormals[i].y ,mesh->mNormals[i].z };

            AddVertex(vertex);
        }

        for (size_t i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];

            for (size_t j = 0; j < face.mNumIndices; j++)
            AddIndex(face.mIndices[j]);
        }

        Initialize();
        return true;
    }
    return false;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::AddVertex(const GFX::Element::Vertex& vertex)
{
    m_Vertices.push_back(vertex);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::AddIndex(uint32_t index)
{
    m_Indices.push_back(index);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
std::vector<uint32_t> GFX::Element::Mesh::GetIndices() const
{
    return m_Indices;
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::Update(GFX::Util::Shader* shader)
{
    // pbr color
    shader->SetVector3(m_Color, "albedo");

    shader->SetFloat1(m_Roughness, "roughness");
    shader->SetFloat1(m_Metallic, "metallic");
    shader->SetFloat1(1.0f, "ao");
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::Initialize()
{
    m_RenderBufferManager = std::make_unique<GFX::Render::GLVertexBuffer>();

    CreateBuffers();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::CreateBuffers()
{
    m_RenderBufferManager->CreateBuffers(m_Vertices, m_Indices);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::DeleteBuffers()
{
    m_RenderBufferManager->DeleteBuffers();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::Render()
{
    m_RenderBufferManager->Draw((int32_t) m_Indices.size());
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::Bind()
{
    m_RenderBufferManager->Bind();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Element::Mesh::UnBind()
{
    m_RenderBufferManager->UnBind();
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */