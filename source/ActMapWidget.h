#pragma once

#include <map>
#include <vector>

#include "GLImageTexture.h"

class ActMapWidget {
protected:
    std::vector<GLImageTexture> mapImages;
    std::vector<std::map<const char*, std::pair<ImVec2, ImVec2>>> mapLabels;

public:
    ActMapWidget();
    ~ActMapWidget();

    void Draw(int act);
};