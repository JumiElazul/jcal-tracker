#include "jcal_core/engine_core.h"
#include "jcal_core/input_handler.h"
#include "jcal_core/window_handler.h"
#include "jcal_core/logger.h"
#include "core/app_timer.h"
#include "core/glfw_callback_context.h"
#include <memory>
#include <GLFW/glfw3.h>

namespace jumi
{

    bool EngineConfig::verify() const
    {
        bool valid = true;
        valid |= (glfw_version_major == 3 && glfw_version_minor == 3);
        valid |= (glfw_version_major == 4 && (glfw_version_minor >= 0 && glfw_version_minor <= 6));
        return valid;
    }

    EngineCore::EngineCore()
    {
        Logger::init();
        JUMI_TRACE("EngineCore constructed");
    }

    EngineCore::~EngineCore()
    {
        JUMI_TRACE("EngineCore destructed");
        glfwTerminate();
    }

    EngineCore& EngineCore::instance()
    {
        static EngineCore instance;
        JUMI_TRACE("EngineCore instance()");
        return instance;
    }

    void EngineCore::init(const EngineConfig& config)
    {
        JUMI_TRACE("EngineCore init()");

        if (!config.verify())
        {
            JUMI_WARN("EngineCore cannot be initialized; invalid config");
            return;
        }
        else
        {
            JUMI_WARN("EngineCore initialized with config {}.{}", config.glfw_version_major, config.glfw_version_minor);
        }

        if (!init_glfw())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        create_modules();
        _window_handler->init(config.glfw_version_major, config.glfw_version_minor);
        _glfw_callback_context->init(_window_handler->window());

        _initialized = true;
    }

    bool EngineCore::init_glfw() const
    {
        if (!glfwInit())
        {
            return false;
        }
        return true;
    }

    void EngineCore::create_modules()
    {
        JUMI_TRACE("EngineCore create_modules()");
        _app_timer = std::make_unique<timers::AppTimer>();
        _window_handler = std::make_unique<WindowHandler>();
        _glfw_callback_context = std::make_unique<GLFWCallbackContext>();
        _input_handler = std::make_unique<InputHandler>();
    }

    const WindowHandler& EngineCore::window() const
    {
        JUMI_TRACE("EngineCore window()");
        return *_window_handler;
    }

    const InputHandler& EngineCore::input() const
    {
        JUMI_TRACE("EngineCore input()");
        return *_input_handler;
    }

    double EngineCore::time() const { return _app_timer->time_since_init(); }
}


