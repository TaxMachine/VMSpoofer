#include "GUI.hpp"

#ifdef USING_GUI

#include "../VMs/Bootstrap.hpp"

#include <functional>

#include "../../imgui/imgui.h"

void ToggleButton(const char* str_id, bool* v, const std::function<void()>& callback = []() {}) {
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    float height = ImGui::GetFrameHeight();
    float width = height * 1.55f;
    float radius = height * 0.50f;
    if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
        *v = !*v;
    ImU32 col_bg;
    if (ImGui::IsItemHovered())
        col_bg = *v ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
    else
        col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);
    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
    draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
    if (ImGui::IsItemClicked())
        callback( );
}


void GUI::CreateGUI() {
    bool the_bool = false;
    ImGui::SetNextWindowSize({265.f,319.f});

    ImGui::Begin( "Host VM Spoofer");
    ImGui::SetCursorPos({25.f,42.f});
    ToggleButton("vmware", &the_bool, Bootstrap::VMWareBootstrap);
    ImGui::SetCursorPos({80.f,46.f});
    ImGui::PushItemWidth(105.000000);
    ImGui::Text("VMWare spoofing");
    ImGui::PopItemWidth( );
    ImGui::SetCursorPos({25.f,91.f});
    ToggleButton("vbox", &the_bool, Bootstrap::VirtualBoxBootstrap);
    ImGui::SetCursorPos({80.f,91.f});
    ImGui::PushItemWidth(133.000000);
    ImGui::Text("VirtualBox spoofing");
    ImGui::PopItemWidth( );
    ImGui::SetCursorPos({25.f,142.f});
    ToggleButton("qemu", &the_bool, Bootstrap::QEmuBootstrap);
    ImGui::SetCursorPos({80.f,145.f});
    ImGui::PushItemWidth(133.000000);
    ImGui::Text("QEmu / KVM spoofing");
    ImGui::PopItemWidth( );
    ImGui::SetCursorPos({25.f,196.f});
    ToggleButton("proxmox", &the_bool);
    ImGui::SetCursorPos({80.f,199.f});
    ImGui::PushItemWidth(42.000000);
    ImGui::Text("Proxmox spoofing");
    ImGui::PopItemWidth( );
    ImGui::SetCursorPos({25.f,247.f});
    ToggleButton("vsphere", &the_bool);
    ImGui::SetCursorPos({80.f,250.f});
    ImGui::PushItemWidth(112.000000);
    ImGui::Text("VSphere spoofing");
    ImGui::PopItemWidth( );


    ImGui::End();
}

#endif