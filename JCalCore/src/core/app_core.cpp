#include "JCalCore/core/app_core.h"
#include "window/window_handler.h"
#include "gui/imgui_handler.h"
#include <string>
#include <memory>
#include <fmt/format.h>
#include <GLFW/glfw3.h>
#include <GLAD/glad.h>

const std::string AppCore::s_appcore_init_fail_msg = "AppCore Initialization : [FAILURE]";
const std::string AppCore::s_glfw_init_fail_msg = "GLFW Initialization : [FAILURE]";
const std::string AppCore::s_glfw_init_success_msg = "GLFW Initialization : [SUCCESS]";
const std::string AppCore::s_glad_init_fail_msg = "GLAD Initialization : [FAILURE]";
const std::string AppCore::s_glad_init_success_msg = "GLAD Initialization : [SUCCESS]";

AppCore::AppCore()
    : _should_quit(false)
    , _window_handler(std::unique_ptr<WindowHandler>(new WindowHandler()))
    , _imgui_handler(std::unique_ptr<ImGuiHandler>(new ImGuiHandler()))
{
    bool init_success = true;
    init_success = init_glfw();
    if (!init_success) throw std::runtime_error(s_appcore_init_fail_msg);

    _window_handler->init();
    
    init_success = init_glad();
    if (!init_success) throw std::runtime_error(s_appcore_init_fail_msg);

    hookup_callbacks();

    _imgui_handler->init();
}

AppCore::~AppCore()
{
}

AppCore& AppCore::instance()
{
    static AppCore instance;
    return instance;
}

void AppCore::poll_events() const { glfwPollEvents(); }
void AppCore::swap_buffers() const { glfwSwapBuffers(_window_handler->get_window()); }
void AppCore::quit_app() { _should_quit = true; }

bool AppCore::init_glfw()
{
    if (!glfwInit())
    {
        fmt::print("{}", s_glfw_init_fail_msg);
        return false;
    }

    fmt::print("{}", s_glfw_init_success_msg);
    return true;
}

bool AppCore::init_glad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fmt::print("{}", s_glad_init_fail_msg);
        return false;
    }

    fmt::print("{}", s_glad_init_success_msg);
    return true;
}

void AppCore::hookup_callbacks() const
{
    GLFWwindow* window = _window_handler->get_window();
    glfwSetWindowUserPointer(window, (void*)this);
    glfwSetKeyCallback(_window_handler->get_window(), key_callback);
}

void AppCore::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    const AppCore* core = static_cast<const AppCore*>(glfwGetWindowUserPointer(window));
    core->on_key_callback(key, action);
}

void AppCore::on_key_callback(int key, int action)
{
    fmt::print("Key [{}] was [{}]", key, action);
}

void AppCore::show_window(bool show) const { _window_handler->show_window(show); }
