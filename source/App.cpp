#include "App.h"

App::App() {
    font = ImGui::GetIO().Fonts->AddFontFromFileTTF("assets/fonts/fontin2_pc/Fontin-Bold.ttf", 20.0f);
    IM_ASSERT(font != NULL);
}

App::~App() {

}


void App::Draw() {
    static float f = 0.0f;
    static int counter = 0;
    static bool editing = true;
    static int act = 1;

    // ImGuiIO& io = ImGui::GetIO();
    
    // We demonstrate using the full viewport area or the work area (without menu-bars, task-bars etc.)
    // Based on your use case you may want one of the other.
    // const ImGuiViewport* viewport = ImGui::GetMainViewport();
    // ImGui::SetNextWindowPos(viewport->WorkPos, ImGuiCond_FirstUseEver);
    // ImGui::SetNextWindowSize(viewport->WorkSize, ImGuiCond_FirstUseEver);

    ImGui::PushFont(font);

    ImGui::Begin(
        "Map",
        nullptr,
        //ImGuiWindowFlags_NoTitleBar |
        //ImGuiWindowFlags_NoResize |
        //ImGuiWindowFlags_NoCollapse |
        //ImGuiWindowFlags_NoMove |
        //ImGuiWindowFlags_NoSavedSettings |
        ImGuiInputTextFlags_None
    );

    actMapWidget.Draw(act);
    
    // ImVec2 imagePos = ImGui::GetCursorPos();
    // ImGui::Image(mapImage.GetTexture(), mapImage.GetSize());
    // //ImGui::Image(font->ContainerAtlas->TexID,  ImVec2(f * font->ContainerAtlas->TexWidth, f * font->ContainerAtlas->TexHeight););

    // static ImVec2 pos(imagePos.x, imagePos.y);
    // ImVec2 lastPos = ImGui::GetCursorPos();

    // ImGui::SetCursorPos(ImVec2(pos.x, pos.y));
    // if(!editing) {
    //     ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    //     ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    //     ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    // }
    // ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.5f, 0.0f));
    // static bool selected;
    // ImGui::Button("2m 34s###twilight strand", ImVec2(80, ImGui::GetFontSize() * 1.5f));
    // ImGui::PopStyleVar();
    // if(!editing)
    //     ImGui::PopStyleColor(3);
    // //ImGui::Text("2m 34s");
    // ImGui::SetCursorPos(lastPos);
    // if(editing && ImGui::IsItemActive()) {
    //     if(ImGui::IsMouseDragging(0, 0.0f)) {
    //         ImVec2 dragDelta = ImGui::GetMouseDragDelta();
    //         pos.x += dragDelta.x;
    //         pos.y += dragDelta.y;
    //         ImGui::ResetMouseDragDelta();
    //     }
    // } else if(ImGui::IsItemHovered())
    //     ImGui::SetTooltip("Level 12");

    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    //ImGui::SliderFloat2("pos", pos, 0.0f, 1000.0f);

    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Checkbox("Editing mode", &editing);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
    
    ImGui::PopFont();
}