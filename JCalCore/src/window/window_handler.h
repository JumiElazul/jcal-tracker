#pragma once

struct GLFWwindow;

class WindowHandler
{
friend class AppCore;
public:
    ~WindowHandler();

    GLFWwindow* get_window() const;
    void show_window(bool show = true) const;

private:
    GLFWwindow* _main_window;

    void init();

    WindowHandler() = default;
    WindowHandler(const WindowHandler& other) = delete;
    WindowHandler operator=(const WindowHandler& other) = delete;
    WindowHandler(const WindowHandler&& other) = delete;
    WindowHandler operator=(const WindowHandler&& other) = delete;
};
