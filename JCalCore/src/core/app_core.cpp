#include "JCalCore/core/app_core.h"
#include "JCalCore/core/keycodes.h"
#include "JCalCore/core/vector.h"
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
const Vec2 AppCore::s_starting_window_size = { 800, 500 };

AppCore::AppCore()
    : _should_quit(false)
    , _framebuffer_size(s_starting_window_size)
    , _clear_color(1.0f, 0.0f, 0.0f)
    , _window_handler(std::unique_ptr<WindowHandler>(new WindowHandler()))
    , _imgui_handler(std::unique_ptr<ImGuiHandler>(new ImGuiHandler()))
{
    bool init_success = true;
    init_success = init_glfw();
    if (!init_success) throw std::runtime_error(s_appcore_init_fail_msg);

    _window_handler->init(s_starting_window_size);
    
    init_success = init_glad();
    if (!init_success) throw std::runtime_error(s_appcore_init_fail_msg);

    hookup_callbacks();

    _imgui_handler->init(_window_handler->get_window(), s_starting_window_size);
}

AppCore::~AppCore() { }

AppCore& AppCore::instance()
{
    static AppCore instance;
    return instance;
}

void AppCore::draw_gui()
{
    _imgui_handler->new_frame();
    _imgui_handler->draw_window(_framebuffer_size);
    _imgui_handler->render();
}

void AppCore::set_clear_color(const Vec3& color)
{ 
    _clear_color = color; 
    glClearColor(color.r, color.g, color.b, 1.0f);
}

void AppCore::clear_color() { glClear(GL_COLOR_BUFFER_BIT); }
void AppCore::poll_events() const { glfwPollEvents(); }
void AppCore::swap_buffers() const { glfwSwapBuffers(_window_handler->get_window()); }
void AppCore::quit_app() { _should_quit = true; }

bool AppCore::init_glfw()
{
    if (!glfwInit())
    {
        fmt::print("{}\n", s_glfw_init_fail_msg);
        return false;
    }

    fmt::print("{}\n", s_glfw_init_success_msg);
    return true;
}

bool AppCore::init_glad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fmt::print("{}\n", s_glad_init_fail_msg);
        return false;
    }

    glViewport(0, 0, s_starting_window_size.x, s_starting_window_size.y);

    fmt::print("{}\n", s_glad_init_success_msg);
    return true;
}

void AppCore::hookup_callbacks() const
{
    GLFWwindow* window = _window_handler->get_window();
    glfwSetWindowUserPointer(window, (void*)this);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_callback);
}

void AppCore::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    AppCore* core = static_cast<AppCore*>(glfwGetWindowUserPointer(window));
    core->on_key_callback(key, action);
}

void AppCore::on_key_callback(int key, int action)
{
    fmt::print("Key [{}] was [{}]\n", key, action);
    switch (key)
    {
        case JUMI_KEY_Q:
        {
            quit_app();
            break;
        }
    }
}

void AppCore::framebuffer_callback(GLFWwindow* window, int width, int height)
{
    AppCore* core = static_cast<AppCore*>(glfwGetWindowUserPointer(window));
    core->on_framebuffer_callback(width, height);
}

void AppCore::on_framebuffer_callback(int width, int height)
{
    fmt::print("Framebuffer changed to {} x {}\n", width, height);
    glViewport(0, 0, width, height);
    _framebuffer_size.x = width;
    _framebuffer_size.y = height;
}

void AppCore::show_window(bool show) const { _window_handler->show_window(show); }
