#include "ActMapWidget.h"

#include <memory>

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"


ActMapWidget::ActMapWidget() {
    mapImages = {
        GLImageTexture("assets/images/acts/Waypoint_map_act_1.jpg")
    };
    mapLabels = {
        {
            { "The Twilight Strand", { ImVec2(0.0f, 0.0f), ImVec2(0.0f, 0.0f) } },
            { "Lioneye's Watch", { ImVec2(0.0f, 100.0f), ImVec2(0.0f, 0.0f) } }
        }
    };
}

ActMapWidget::~ActMapWidget() {

}


void ActMapWidget::Draw(int act) {
    auto& mapImage = mapImages[act - 1];
    auto& mapLabel = mapLabels[act - 1];

    //ImGui::PushID(this);

    ImVec2 imagePos = ImGui::GetCursorPos();
    ImGui::Image(mapImage.GetTexture(), mapImage.GetSize());
    static bool editing = true;

    ImVec2 lastPos = ImGui::GetCursorPos();

    for(auto& label : mapLabel) {
        ImGui::PushID(label.first);
        ImGui::SetCursorPos(imagePos + label.second.first);
        ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, label.second.second);
        if(!editing) {
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
        }
        ImGui::Button("2m 34s", ImVec2(80, ImGui::GetFrameHeight()));

        if(editing && ImGui::IsItemActive()) {
            if(ImGui::IsMouseDragging(0, 0.0f)) {
                ImVec2 dragDelta = ImGui::GetMouseDragDelta();
                label.second.first += dragDelta;
                ImGui::ResetMouseDragDelta();
            }
        } else if(ImGui::IsItemHovered())
            ImGui::SetTooltip("Level 12");
        
        if(!editing)
            ImGui::PopStyleColor(3);
        ImGui::PopStyleVar();
        ImGui::PopID();
    }

    ImGui::SetCursorPos(lastPos);

    // if(editing && ImGui::IsItemActive()) {
    //     if(ImGui::IsMouseDragging(0, 0.0f)) {
    //         ImVec2 dragDelta = ImGui::GetMouseDragDelta();
    //         pos.x += dragDelta.x;
    //         pos.y += dragDelta.y;
    //         ImGui::ResetMouseDragDelta();
    //     }
    // } else if(ImGui::IsItemHovered())
    //     ImGui::SetTooltip("Level 12");

    //ImGui::PopID();
}