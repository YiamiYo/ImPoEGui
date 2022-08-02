#pragma once

#include "imgui.h"

#include "GLImageTexture.h"
#include "ActMapWidget.h"

class App {
protected:
    ImFont* font;
    //GLImageTexture mapImage;
    ActMapWidget actMapWidget;

public:
    App();

    ~App(); // destructor
    App(const App&) = delete; // copy constructor
    App(App&&) = delete; // move constructor
    App& operator=(const App&) = delete; // copy assignment
    App& operator=(const App&&) = delete; // move assignment

    void Draw();
};