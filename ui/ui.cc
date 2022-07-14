#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"

using namespace ImGui;

void ui::renderMain() {
    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin(window_title, &globals.active, window_flags);
    {BeginChild(skCrypt("##mainPage"));
    SetCursorPosY(5);
    SetCursorPosX(120);
    if (Button(skCrypt("Settings"))) globals.macroPage = 0;
    SameLine();
    if (Button(skCrypt("Config"))) globals.macroPage = 1;
    Separator();
    if (globals.macroPage == 0)
    {
        window_size.y = 350;

        SetCursorPosX(120);
        Checkbox(skCrypt("Enable"), &settings.enabled);
        SameLine();
        Checkbox(skCrypt("Aim Check"), &settings.aimCheck);
        Separator();
        SetCursorPosX(168);
        Text(skCrypt("Primary X"));
        SetCursorPosX(75);
        SliderFloat(skCrypt("##Primary X"), &settings.primary.x, -100, 100);
        SetCursorPosX(168);
        Text(skCrypt("Primary Y"));
        SetCursorPosX(75);
        SliderFloat(skCrypt("##Primary Y"), &settings.primary.y, -100, 100);
        SetCursorPosX(168);
        Text(skCrypt("Smoothing"));
        SetCursorPosX(75);
        SliderInt(skCrypt("##Smoothing##1"), &settings.sleep1, 100, 1);
        Separator();
        SetCursorPosX(163);
        Text(skCrypt("Secondary X"));
        SetCursorPosX(75);
        SliderFloat(skCrypt("##Secondary X"), &settings.secondary.x, -100, 100);
        SetCursorPosX(163);
        Text(skCrypt("Secondary Y"));
        SetCursorPosX(75);
        SliderFloat(skCrypt("##Secondary Y"), &settings.secondary.y, -100, 100);
        SetCursorPosX(168);
        Text(skCrypt("Smoothing"));
        SetCursorPosX(75);
        SliderInt(skCrypt("##Smoothing##2"), &settings.sleep2, 100, 1);
    }
    if (globals.macroPage == 1)
    {
        window_size.y = 135;
        SetCursorPosX(168);
        Text(skCrypt("Config"));
        SetCursorPosX(66);
        InputText(skCrypt("##Config"), settings.config, IM_ARRAYSIZE(settings.config));
        SetCursorPosX(150);
        if (Button(skCrypt("Load"))) macro::load();
        SameLine();
        if (Button(skCrypt("Save"))) macro::save();
    }
    if (globals.macroPage == 2)
    {
        window_size.y = 350;
        // Quick configs tab here \\
        ----------------------------

    }
    }EndChild();
    ImGui::End();
}

void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;
	
    // colors
    ui::RunStyle();

	if (window_pos.x == 0) {
		RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;

		// init images here
	}
}

void ui::RunStyle()
{
    ImGuiStyle& style = ImGui::GetStyle();

    style.Colors[ImGuiCol_TitleBgActive] = ImColor(0, 0, 0, 155);
    style.Colors[ImGuiCol_WindowBg] = ImColor(0, 0, 255, 255);
    style.Colors[ImGuiCol_ChildBg] = ImColor(5, 5, 5, 255);
    style.Colors[ImGuiCol_Button] = ImColor(0, 0, 255, 255);
    style.Colors[ImGuiCol_ButtonActive] = ImColor(0, 0, 0, 255);
    style.Colors[ImGuiCol_ButtonHovered] = ImColor(0, 0, 255, 255);
    style.Colors[ImGuiCol_CheckMark] = ImColor(0, 0, 255, 255);
    style.Colors[ImGuiCol_FrameBg] = ImColor(30, 30, 30, 205);
    style.Colors[ImGuiCol_FrameBgHovered] = ImColor(35, 35, 35, 205);
    style.Colors[ImGuiCol_FrameBgActive] = ImColor(0, 0, 255, 55);
    style.Colors[ImGuiCol_SliderGrab] = ImColor(0, 0, 255, 255);
    style.Colors[ImGuiCol_SliderGrabActive] = ImColor(0, 0, 255, 255);
    style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
}


