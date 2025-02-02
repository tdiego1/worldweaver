/**************************************************************************************************/
/**
 * \addtogroup OBJECTS
 * @{
 * \details
 * This file provides the public interface for the Iconoshpere Module.
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

#include <map>

#include "worldweaver/common.hpp"

/*=================================================================================================
** 3.  DECLARATIONS
**
** 3.1 Macros
**===============================================================================================*/

/*=================================================================================================
** 3.2 Types and Classes
**===============================================================================================*/

namespace Object
{

    /**************************************************************************************************/
    /**
     * \par Details:
     */
    class Icosphere
    {

      public:
        /*********************************/
        // Constructors/Destructor
        /*********************************/

        /**************************************************************************************************/
        /**
         * \brief The default constructor for the Icosphere.
         */
        Icosphere(float32_t radius, int32_t subdivision);

        /**************************************************************************************************/
        /**
         * \brief The default destructor for the Icosphere.
         */
        ~Icosphere(void);

        /*********************************/
        // Public functions
        /*********************************/

        /**************************************************************************************************/
        /**
         * \brief Gents the radius of the Icosphere.
         *
         * \retval float32_t The radius of the Icosphere.
         */
        float32_t GetRadius(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the subdivision of the Icosphere.
         *
         * \retval int32_t The subdivision of the Icosphere.
         */
        int32_t GetSubdivision(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the radius of the Icosphere.
         *
         * \param[in] radius The radius of the Icosphere.
         */
        void SetRadius(float32_t radius);

        /**************************************************************************************************/
        /**
         * \brief Sets the subdivision of the Icosphere.
         *
         * \param[in] subdivision The subdivision of the Icosphere.
         */
        void SetSubdivision(int32_t subdivision);

        /**************************************************************************************************/
        /**
         * \brief Reverses the normals of the Icosphere.
         */
        void ReverseNormals(void);

        /**************************************************************************************************/
        /**
         * \brief Gets the vertex count of the Icosphere.
         *
         * \retval uint32_t The vertex count of the Icosphere.
         */
        uint32_t GetVertexCount(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the index count of the Icosphere.
         *
         * \retval uint32_t The index count of the Icosphere.
         */
        uint32_t GetIndexCount(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the normal count of the Icosphere.
         *
         * \retval uint32_t The normal count of the Icosphere.
         */
        uint32_t GetNormalCount(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the texture coordinate count of the Icosphere.
         *
         * \retval uint32_t The texture coordinate count of the Icosphere.
         */
        uint32_t GetTexCoordCount(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the line index count of the Icosphere.
         *
         * \retval uint32_t The line index count of the Icosphere.
         */
        uint32_t GetLineIndexCount(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the triangle count of the Icosphere.
         *
         * \retval uint32_t The triangle count of the Icosphere.
         */
        uint32_t GetTriangleCount(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the vertex size of the Icosphere.
         *
         * \retval uint32_t The vertex size of the Icosphere.
         */
        uint32_t GetVertexSize(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the index size of the Icosphere.
         *
         * \retval uint32_t The index size of the Icosphere.
         */
        uint32_t GetIndexSize(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the normal size of the Icosphere.
         *
         * \retval uint32_t The normal size of the Icosphere.
         */
        uint32_t GetNormalSize(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the texture coordinate size of the Icosphere.
         *
         * \retval uint32_t The texture coordinate size of the Icosphere.
         */
        uint32_t GetTexCoordSize(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the line index size of the Icosphere.
         *
         * \retval uint32_t The line index size of the Icosphere.
         */
        uint32_t GetLineIndexSize(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the vertices of the Icosphere.
         *
         * \retval const float32_t* Pointer to the vertices of the Icosphere.
         */
        const float32_t* GetVertices(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the indices of the Icosphere.
         *
         * \retval const uint32_t* Pointer to the indices of the Icosphere.
         */
        const uint32_t* GetIndices(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the normals of the Icosphere.
         *
         * \retval const float32_t* Pointer to the normals of the Icosphere.
         */
        const float32_t* GetNormals(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the texture coordinates of the Icosphere.
         *
         * \retval const float32_t* Pointer to the texture coordinates of the Icosphere.
         */
        const float32_t* GetTexCoords(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the line indices of the Icosphere.
         *
         * \retval const uint32_t* Pointer to the line indices of the Icosphere.
         */
        const uint32_t* GetLineIndices(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the interleaved vertex count of the Icosphere.
         *
         * \retval uint32_t The interleaved vertex count of the Icosphere.
         */
        uint32_t GetInterleavedVertexCount(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the interleaved vertex size of the Icosphere.
         *
         * \retval uint32_t The interleaved vertex size of the Icosphere.
         */
        uint32_t GetInterleavedVertexSize(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the interleaved stride of the Icosphere.
         *
         * \retval int32_t The interleaved stride of the Icosphere.
         */
        int32_t GetInterleavedStride(void) const;

        /**************************************************************************************************/
        /**
         * \brief Gets the interleaved vertices of the Icosphere.
         *
         * \retval const float32_t* Pointer to the interleaved vertices of the Icosphere.
         */
        const float32_t* GetInterleavedVertices(void) const;

        /**************************************************************************************************/
        /**
         * \brief Draws the Icosphere.
         */
        void Draw() const;

        /**************************************************************************************************/
        /**
         * \brief Draws the Icosphere with lines.
         */
        void DrawLines() const;

        /**************************************************************************************************/
        /**
         * \brief Draws the Icosphere with both triangles and lines.
         */
        void DrawWithLines() const;

      private:
        /*********************************/
        // Private type definitions
        /*********************************/

        /*********************************/
        // Private member variables
        /*********************************/

        float32_t m_Radius;                                                    ///< The radius of the Icosphere.
        int32_t m_Subdivision;                                                 ///< The subdivision frequencies for the Icosphere.
        std::vector<float32_t> m_Vertices;                                     ///< The vertices of the Icosphere.
        std::vector<uint32_t> m_Indices;                                       ///< The indices of the Icosphere.
        std::vector<float32_t> m_Normals;                                      ///< The normals of the Icosphere.
        std::vector<float32_t> m_TexCoords;                                    ///< The texture coordinates of the Icosphere.
        std::vector<uint32_t> m_LineIndices;                                   ///< The line indices of the Icosphere.
        std::map<std::pair<float32_t, float32_t>, uint32_t> m_SharedIndices;   ///< The shared indices of the Icosphere.

        std::vector<float32_t> m_InterleavedVertices;                          ///< The interleaved vertices of the Icosphere.
        int32_t m_InterleavedStride;                                           ///< The interleaved stride of the Icosphere.

        /*********************************/
        // Private functions
        /*********************************/

        /**************************************************************************************************/
        /**
         * \brief Computes the face normal of a triangle.
         *
         * \param[in] v1 The first vertex of the triangle.
         * \param[in] v2 The second vertex of the triangle.
         * \param[in] v3 The third vertex of the triangle.
         * \param[out] normal The computed normal.
         */
        static void Icosphere::ComputeFaceNormal(const float v1[3], const float v2[3], const float v3[3], float normal[3]);

        /**************************************************************************************************/
        /**
         * \brief Computes the normal of a vertex.
         *
         * \param[in] v The vertex.
         * \param[out] normal The computed normal.
         */
        static void Icosphere::ComputeVertexNormal(const float v[3], float normal[3]);

        /**************************************************************************************************/
        /**
         * \brief Computes the scale for a given length.
         *
         * \param[in] v The vector.
         * \param[in] length The desired length.
         *
         * \retval float The scale factor.
         */
        static float Icosphere::ComputeScaleForLength(const float v[3], float length);

        /**************************************************************************************************/
        /**
         * \brief Interpolates between two vertices.
         *
         * \param[in] v1 The first vertex.
         * \param[in] v2 The second vertex.
         * \param[in] alpha The interpolation factor.
         * \param[in] length The desired length.
         * \param[out] newV The interpolated vertex.
         */
        static void Icosphere::InterpolateVertex(const float v1[3], const float v2[3], float alpha, float length, float newV[3]);

        /**************************************************************************************************/
        /**
         * \brief Interpolates between two texture coordinates.
         *
         * \param[in] t1 The first texture coordinate.
         * \param[in] t2 The second texture coordinate.
         * \param[in] alpha The interpolation factor.
         * \param[out] newT The interpolated texture coordinate.
         */
        static void Icosphere::InterpolateTexCoord(const float t1[2], const float t2[2], float alpha, float newT[2]);

        /**************************************************************************************************/
        /**
         * \brief Linearly interpolates between two values.
         *
         * \param[in] from The starting value.
         * \param[in] to The ending value.
         * \param[in] alpha The interpolation factor.
         *
         * \retval float The interpolated value.
         */
        static float Icosphere::Lerp(float from, float to, float alpha);

        /**************************************************************************************************/
        /**
         * \brief Checks if a texture coordinate is shared.
         *
         * \param[in] t The texture coordinate.
         *
         * \retval bool True if the texture coordinate is shared, false otherwise.
         */
        static bool Icosphere::IsSharedTexCoord(const float t[2]);

        /**************************************************************************************************/
        /**
         * \brief Checks if a point is on a line segment.
         *
         * \param[in] a The first point of the line segment.
         * \param[in] b The second point of the line segment.
         * \param[in] c The point to check.
         *
         * \retval bool True if the point is on the line segment, false otherwise.
         */
        static bool Icosphere::IsOnLineSegment(const float a[2], const float b[2], const float c[2]);

        /**************************************************************************************************/
        /**
         * \brief Updates the radius of the Icosphere.
         */
        void Icosphere::UpdateRadius();

        /**************************************************************************************************/
        /**
         * \brief Computes the vertices of an icosahedron.
         *
         * \retval std::vector<float> The vertices of the icosahedron.
         */
        std::vector<float> Icosphere::ComputeIcosahedronVertices();

        /**************************************************************************************************/
        /**
         * \brief Builds the flat vertices of the Icosphere.
         */
        void Icosphere::BuildVerticesFlat();

        /**************************************************************************************************/
        /**
         * \brief Builds the smooth vertices of the Icosphere.
         */
        void Icosphere::BuildVerticesSmooth();

        /**************************************************************************************************/
        /**
         * \brief Subdivides the flat vertices of the Icosphere.
         */
        void Icosphere::SubdivideVerticesFlat();

        /**************************************************************************************************/
        /**
         * \brief Subdivides the smooth vertices of the Icosphere.
         */
        void Icosphere::SubdivideVerticesSmooth();

        /**************************************************************************************************/
        /**
         * \brief Builds the interleaved vertices of the Icosphere.
         */
        void Icosphere::BuildInterleavedVertices();

        /**************************************************************************************************/
        /**
         * \brief Adds vertices to the Icosphere.
         *
         * \param[in] v1 The first vertex.
         * \param[in] v2 The second vertex.
         * \param[in] v3 The third vertex.
         */
        void Icosphere::AddVertices(const float v1[3], const float v2[3], const float v3[3]);

        /**************************************************************************************************/
        /**
         * \brief Adds normals to the Icosphere.
         *
         * \param[in] n1 The first normal.
         * \param[in] n2 The second normal.
         * \param[in] n3 The third normal.
         */
        void Icosphere::AddNormals(const float n1[3], const float n2[3], const float n3[3]);

        /**************************************************************************************************/
        /**
         * \brief Adds texture coordinates to the Icosphere.
         *
         * \param[in] t1 The first texture coordinate.
         * \param[in] t2 The second texture coordinate.
         * \param[in] t3 The third texture coordinate.
         */
        void Icosphere::AddTexCoords(const float t1[2], const float t2[2], const float t3[2]);

        /**************************************************************************************************/
        /**
         * \brief Adds indices to the Icosphere.
         *
         * \param[in] i1 The first index.
         * \param[in] i2 The second index.
         * \param[in] i3 The third index.
         */
        void Icosphere::AddIndices(unsigned int i1, unsigned int i2, unsigned int i3);

        /**************************************************************************************************/
        /**
         * \brief Adds line indices to the Icosphere.
         *
         * \param[in] i1 The first line index.
         * \param[in] i2 The second line index.
         */
        void Icosphere::AddLineIndices(unsigned int i1, unsigned int i2);

        /**************************************************************************************************/
        /**
         * \brief Adds sub-vertex attributes to the Icosphere.
         *
         * \param[in] v The vertex.
         * \param[in] n The normal.
         * \param[in] t The texture coordinate.
         *
         * \retval unsigned int The index of the added sub-vertex.
         */
        unsigned int Icosphere::AddSubVertexAttribs(const float v[3], const float n[3], const float t[2]);
    };
}   // namespace Object

/*=================================================================================================
** 3.3 Constants
**===============================================================================================*/

/*=================================================================================================
** 3.4 Variables
**===============================================================================================*/

/*=================================================================================================
** 3.5 Functions
**===============================================================================================*/
namespace Object
{
    /**************************************************************************************************/
    /**
     * \par Details:
     */
    inline Icosphere::~Icosphere()
    {
    }
}   // namespace Object

/** @} */