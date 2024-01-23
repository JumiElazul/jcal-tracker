#pragma once

struct GLFWwindow;

class ImGuiHandler
{
friend class AppCore;
public:
    ~ImGuiHandler();

    void new_frame() const;
    void draw_window() const;
    void render() const;

private:
    void init(GLFWwindow* window);

    ImGuiHandler() = default;
    ImGuiHandler(const ImGuiHandler& other) = delete;
    ImGuiHandler operator=(const ImGuiHandler& other) = delete;
    ImGuiHandler(const ImGuiHandler&& other) = delete;
    ImGuiHandler operator=(const ImGuiHandler&& other) = delete;
};
