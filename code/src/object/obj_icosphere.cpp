/**************************************************************************************************/
/**
 * \addtogroup OBJECTS
 * @{
 * \details
 * This file provides the public interface for the Iconsphere Module.
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

#include "object/obj_icosphere.hpp"

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
Object::Icosphere::Icosphere(float32_t radius, int32_t subdivision) : m_Radius(radius), m_Subdivision(subdivision)
{
    // Constructor implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
float32_t Object::Icosphere::GetRadius(void) const
{
    return m_Radius;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
int32_t Object::Icosphere::GetSubdivision(void) const
{
    return m_Subdivision;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::SetRadius(float32_t radius)
{
    m_Radius = radius;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::SetSubdivision(int32_t subdivision)
{
    m_Subdivision = subdivision;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::ReverseNormals(void)
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetVertexCount(void) const
{
    return static_cast<uint32_t>(m_Vertices.size()) / 3;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetIndexCount(void) const
{
    return static_cast<uint32_t>(m_Indices.size());
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetNormalCount(void) const
{
    return static_cast<uint32_t>(m_Normals.size()) / 3;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetTexCoordCount(void) const
{
    return static_cast<uint32_t>(m_TexCoords.size()) / 2;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetLineIndexCount(void) const
{
    return static_cast<uint32_t>(m_LineIndices.size());
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetTriangleCount(void) const
{
    return GetIndexCount() / 3;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetVertexSize(void) const
{
    return static_cast<uint32_t>(m_Vertices.size() * sizeof(float32_t));
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetIndexSize(void) const
{
    return static_cast<uint32_t>(m_Indices.size() * sizeof(uint32_t));
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetNormalSize(void) const
{
    return static_cast<uint32_t>(m_Normals.size() * sizeof(float32_t));
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetTexCoordSize(void) const
{
    return static_cast<uint32_t>(m_TexCoords.size() * sizeof(float32_t));
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetLineIndexSize(void) const
{
    return static_cast<uint32_t>(m_LineIndices.size() * sizeof(uint32_t));
}

/**************************************************************************************************/
/**
 * \par Details:
 */
const float32_t* Object::Icosphere::GetVertices(void) const
{
    return m_Vertices.data();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
const uint32_t* Object::Icosphere::GetIndices(void) const
{
    return m_Indices.data();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
const float32_t* Object::Icosphere::GetNormals(void) const
{
    return m_Normals.data();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
const float32_t* Object::Icosphere::GetTexCoords(void) const
{
    return m_TexCoords.data();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
const uint32_t* Object::Icosphere::GetLineIndices(void) const
{
    return m_LineIndices.data();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetInterleavedVertexCount(void) const
{
    return GetVertexCount();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
uint32_t Object::Icosphere::GetInterleavedVertexSize(void) const
{
    return static_cast<uint32_t>(m_InterleavedVertices.size() * sizeof(float32_t));
}

/**************************************************************************************************/
/**
 * \par Details:
 */
int32_t Object::Icosphere::GetInterleavedStride(void) const
{
    return m_InterleavedStride;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
const float32_t* Object::Icosphere::GetInterleavedVertices(void) const
{
    return m_InterleavedVertices.data();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::Draw() const
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::DrawLines() const
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::DrawWithLines() const
{
    // Function implementation
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::ComputeFaceNormal(const float v1[3], const float v2[3], const float v3[3], float normal[3])
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::ComputeVertexNormal(const float v[3], float normal[3])
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
float Object::Icosphere::ComputeScaleForLength(const float v[3], float length)
{
    // Function implementation
    return 0.0f;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::InterpolateVertex(const float v1[3], const float v2[3], float alpha, float length, float newV[3])
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::InterpolateTexCoord(const float t1[2], const float t2[2], float alpha, float newT[2])
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
float Object::Icosphere::Lerp(float from, float to, float alpha)
{
    // Function implementation
    return 0.0f;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
bool Object::Icosphere::IsSharedTexCoord(const float t[2])
{
    // Function implementation
    return false;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
bool Object::Icosphere::IsOnLineSegment(const float a[2], const float b[2], const float c[2])
{
    // Function implementation
    return false;
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::UpdateRadius()
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
std::vector<float> Object::Icosphere::ComputeIcosahedronVertices()
{
    // Function implementation
    return std::vector<float>();
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::BuildVerticesFlat()
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::BuildVerticesSmooth()
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::SubdivideVerticesFlat()
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::SubdivideVerticesSmooth()
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::BuildInterleavedVertices()
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::AddVertices(const float v1[3], const float v2[3], const float v3[3])
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::AddNormals(const float n1[3], const float n2[3], const float n3[3])
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::AddTexCoords(const float t1[2], const float t2[2], const float t3[2])
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::AddIndices(unsigned int i1, unsigned int i2, unsigned int i3)
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
void Object::Icosphere::AddLineIndices(unsigned int i1, unsigned int i2)
{
    // Function implementation
}

/**************************************************************************************************/
/**
 * \par Details:
 */
unsigned int Object::Icosphere::AddSubVertexAttribs(const float v[3], const float n[3], const float t[2])
{
    // Function implementation
    return 0;
}

/** @} */
