#pragma once
#include <jcal_core/core.h>
#include <memory>
#include <ostream>

namespace jumi
{
    namespace timers
    {
        class AppTimer;
    }

    class GLFWCallbackContext;
    class WindowHandler;
    class InputHandler;

    struct JUMI_API EngineConfig
    {
        int glfw_version_major = 3;
        int glfw_version_minor = 3;

        bool verify() const;
    };

    class JUMI_API EngineCore
    {
    public:
        EngineCore();
        ~EngineCore();
        EngineCore(const EngineCore&) = delete;
        EngineCore& operator=(const EngineCore&) = delete;
        EngineCore(EngineCore&&) = delete;
        EngineCore& operator=(EngineCore&&) = delete;

        static std::unique_ptr<WindowHandler> create_window_handler();
        static EngineCore& instance();
        void init(const EngineConfig& config = {});
        const WindowHandler& window() const;
        const InputHandler& input() const;
        double time() const;

        inline bool initialized() const { return _initialized; }

    private:
        bool _initialized = false;
        std::unique_ptr<GLFWCallbackContext> _glfw_callback_context;
        std::unique_ptr<WindowHandler> _window_handler;
        std::unique_ptr<InputHandler> _input_handler;
        std::unique_ptr<timers::AppTimer> _app_timer;

        bool init_glfw() const;
        void create_modules();
    };
}

inline std::ostream& operator<<(std::ostream& os, const jumi::EngineConfig& config)
{
    os << "GLFW version: " << config.glfw_version_major << "." << config.glfw_version_minor;
    return os;
}
