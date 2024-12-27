/**************************************************************************************************/
/**
* \addtogroup GFX_RENDER
* @{
* \details
* This file provides the public interface for the GLFrameBuffer Module.
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

#include "gfx/gfx_glframebuffer.hpp"

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
void GFX::Render::GLFrameBuffer::CreateBuffers(int32_t width, int32_t height)
{
    m_Width = width;
    m_Height = height;

    if (m_FBO)
    {
        DeleteBuffers();
    }

    glGenFramebuffers(1, &m_FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
    glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_TextureID, 0);

    glCreateTextures(GL_TEXTURE_2D, 1, &m_DepthID);
    glBindTexture(GL_TEXTURE_2D, m_DepthID);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH24_STENCIL8, m_Width, m_Height);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_DepthID, 0);

    GLenum buffers[4] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(m_TextureID, buffers);

    Unbind();
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLFrameBuffer::DeleteBuffers(void)
{
    if (m_FBO)
    {
        glDeleteFramebuffers(GL_FRAMEBUFFER, &m_FBO);
        glDeleteTextures(1, &m_TextureID);
        glDeleteTextures(1, &m_DepthID);
        m_TextureID = 0;
        m_DepthID = 0;
    }
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLFrameBuffer::Bind(void)
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);
    glViewport(0, 0, m_Width, m_Height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
void GFX::Render::GLFrameBuffer::Unbind(void)
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

/**************************************************************************************************/
/**
* \par Details: 
*/
uint32_t GFX::Render::GLFrameBuffer::GetTexture(void)
{
    return m_TextureID;
}

/*=================================================================================================
** 5.  PRIVATE AND PROTECTED FUNCTIONS
**===============================================================================================*/

/** @} */