#pragma once
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
    inline bool should_quit() const { return _should_quit; }


private:
    bool _should_quit;
    std::unique_ptr<WindowHandler> _window_handler;
    std::unique_ptr<ImGuiHandler> _imgui_handler;

    bool init_glfw();
    bool init_glad();
    void hookup_callbacks() const;

    AppCore();
    ~AppCore();
    AppCore(const AppCore& other) = delete;
    AppCore& operator=(const AppCore& other) = delete;
    AppCore(const AppCore&& other) = delete;
    AppCore& operator=(const AppCore&& other) = delete;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void on_key_callback(int key, int action);

    static const std::string s_appcore_init_fail_msg;
    static const std::string s_glfw_init_fail_msg;
    static const std::string s_glfw_init_success_msg;
    static const std::string s_glad_init_fail_msg;
    static const std::string s_glad_init_success_msg;
};

