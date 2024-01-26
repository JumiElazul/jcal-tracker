#include "gui/imgui_handler.h"
#include "json/json_handler.h"
#include "JCalCore/core/vector.h"
#include <vector>
#include <string>
#include <fmt/format.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

ImGuiHandler::ImGuiHandler(JsonHandler& json_handler)
    : _json_handler(json_handler) { }

ImGuiHandler::~ImGuiHandler() 
{ 
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiHandler::new_frame() const
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiHandler::draw_window(const Vec2& framebuffer_size) const
{
    ImVec2 window_size{ framebuffer_size.x, framebuffer_size.y };
    ImVec2 window_pos{ 0, 0 };
    ImGui::SetNextWindowSize(window_size);
    ImGui::SetNextWindowPos(window_pos);

    ImGuiWindowFlags flags = ImGuiWindowFlags_None;
    flags = ImGuiWindowFlags_NoResize
          | ImGuiWindowFlags_NoCollapse
          | ImGuiWindowFlags_NoDecoration;
    bool open = true;

    if (ImGui::Begin("Test Window", &open, flags))
    {
        if (ImGui::Button("Write To File"))
        {
            _json_handler.test_func();
        }

        ImGui::End();
    }
}

void ImGuiHandler::render() const
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGui::UpdatePlatformWindows();
}

void ImGuiHandler::init(GLFWwindow* window, const Vec2& window_size)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.Fonts->AddFontFromFileTTF("assets/iosevka-custom.ttf", 20.0f);
    ImGui::StyleColorsLight();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");

    ImVec2 size;
    size.x = window_size.x;
    size.y = window_size.y;
    ImGui::SetNextWindowPos({ 0, 0 });
    ImGui::SetNextWindowSize(size);
}

