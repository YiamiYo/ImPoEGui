#include "GLImageTexture.h"

#include <iostream>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif
//#include <SDL_image.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLImageTexture::GLTexture::GLTexture(ImTextureID value) : value(value) {

}

GLImageTexture::GLTexture::~GLTexture() {
    glDeleteTextures(1, (GLuint*)&value);
}


GLImageTexture::GLImageTexture(const char* filename) {
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    if(image_data == NULL)
        return;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    texture = std::make_shared<GLTexture>((ImTextureID)(intptr_t)image_texture);
    size = ImVec2(image_width, image_height);
}


const ImTextureID& GLImageTexture::GetTexture() const {
    return texture->value;
}

const ImVec2& GLImageTexture::GetSize() const {
    return size;
}