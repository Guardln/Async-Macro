#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"
#include "../H/skStr.h"
#include "../H/xorstr.h"

namespace ui {
	void RunStyle();
	void init(LPDIRECT3DDEVICE9);
	void renderMain();
}

namespace ui {
	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = ("                      Async Macro");
}

namespace ui {
	inline ImVec2 screen_res{ 000, 000 };
	inline ImVec2 window_pos{ 0, 0 };
	inline ImVec2 window_size{ 400, 300 };
	inline DWORD  window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
}