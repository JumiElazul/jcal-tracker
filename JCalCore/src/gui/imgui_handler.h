#pragma once

struct GLFWwindow;
struct Vec2;

class ImGuiHandler
{
friend class AppCore;
public:
    ~ImGuiHandler();

    void new_frame() const;
    void draw_window(const Vec2& framebuffer_size) const;
    void render() const;

private:
    void init(GLFWwindow* window, const Vec2& window_size);

    ImGuiHandler() = default;
    ImGuiHandler(const ImGuiHandler& other) = delete;
    ImGuiHandler operator=(const ImGuiHandler& other) = delete;
    ImGuiHandler(const ImGuiHandler&& other) = delete;
    ImGuiHandler operator=(const ImGuiHandler&& other) = delete;
};
