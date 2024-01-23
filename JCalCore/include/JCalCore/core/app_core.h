#pragma once
#include "JCalCore/core/vector.h"
#include <memory>
#include <string>

struct GLFWwindow;
class WindowHandler;
class ImGuiHandler;

class AppCore
{
public:
    static AppCore& instance();

    void show_window(bool show = true) const;
    void poll_events() const;
    void swap_buffers() const;
    void quit_app();
    void draw_gui();
    void clear_color();
    void set_clear_color(const Vec3& color);
    inline bool should_quit() const { return _should_quit; }

private:
    bool _should_quit;
    Vec2 _framebuffer_size;
    Vec3 _clear_color;
    std::unique_ptr<WindowHandler> _window_handler;
    std::unique_ptr<ImGuiHandler> _imgui_handler;

    bool init_glfw();
    bool init_glad();
    void hookup_callbacks() const;
    void on_key_callback(int key, int action);
    void on_framebuffer_callback(int key, int action);

    AppCore();
    ~AppCore();
    AppCore(const AppCore& other) = delete;
    AppCore& operator=(const AppCore& other) = delete;
    AppCore(const AppCore&& other) = delete;
    AppCore& operator=(const AppCore&& other) = delete;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void framebuffer_callback(GLFWwindow* window, int width, int height);

    static const std::string s_appcore_init_fail_msg;
    static const std::string s_glfw_init_fail_msg;
    static const std::string s_glfw_init_success_msg;
    static const std::string s_glad_init_fail_msg;
    static const std::string s_glad_init_success_msg;
    static const Vec2 s_starting_window_size;
};

