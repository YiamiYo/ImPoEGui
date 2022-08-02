#pragma once

#include <string>
#include "imgui.h"

class GLImageTexture {
protected:
    struct GLTexture {
        ImTextureID value;
        GLTexture(ImTextureID value);
        ~GLTexture();
    };

    ImVec2 size;
    std::shared_ptr<GLTexture> texture;

public:
    GLImageTexture(const char* filename);

    const ImTextureID& GetTexture() const;
    const ImVec2& GetSize() const;
};