//
// Created by aleksndra on 11/19/26.
//

#ifndef PROJECT_TEXTURE2D_H
#define PROJECT_TEXTURE2D_H
#include "Error.h"
#include "stb_image.h"
#include <glad/glad.h>
#include <string>

class Texture2D
{
    unsigned m_Id;

public:
    Texture2D(std::string pathToImg, GLenum filtering, GLenum sampling)
    {
        glGenTextures(1, &m_Id);
        glBindTexture(GL_TEXTURE_2D, m_Id);

        // wrap
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sampling);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, sampling);

        // filter
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtering);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering);

        // load img
        int width, height, nChannel;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(pathToImg.c_str(), &width, &height, &nChannel, 0);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            ASSERT(false, "Failed to load texture");
        }

        stbi_image_free(data);
    }

    void active(GLenum e)
    {
        glActiveTexture(e);
        glBindTexture(GL_TEXTURE_2D, m_Id);
    }

    void setFiltering(GLenum filtering)
    {
        glBindTexture(GL_TEXTURE_2D, m_Id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtering);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtering);
    }
};

#endif //PROJECT_TEXTURE2D_H
