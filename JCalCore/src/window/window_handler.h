#pragma once
#include "JCalCore/core/vector.h"

struct GLFWwindow;

class WindowHandler
{
friend class AppCore;
public:
    ~WindowHandler();

    GLFWwindow* get_window() const;
    void show_window(bool show = true) const;
    inline Vec2 get_window_size() const { return _window_size; }

private:
    GLFWwindow* _main_window;
    Vec2 _window_size;

    void init(const Vec2& window_size);

    WindowHandler() = default;
    WindowHandler(const WindowHandler& other) = delete;
    WindowHandler operator=(const WindowHandler& other) = delete;
    WindowHandler(const WindowHandler&& other) = delete;
    WindowHandler operator=(const WindowHandler&& other) = delete;
};
