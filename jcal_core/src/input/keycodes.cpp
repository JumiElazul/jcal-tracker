#include "jcal_core/keycodes.h"
#include "jcal_core/logger.h"
#include <GLFW/glfw3.h>

namespace jumi
{

    namespace jumi_keycodes
    {

        bool KeyCodeConverter::s_initialized = false;
        JUMI_KEYCODE KeyCodeConverter::s_glfw_to_jumi_keymap[KEYMAP_ARRAY_SIZE];
        JUMI_KEYACTION KeyCodeConverter::s_glfw_to_jumi_actionmap[ACTIONMAP_ARRAY_SIZE];
        std::string KeyCodeConverter::s_keycode_to_string[KEYMAP_TOSTR_ARRAY_SIZE];
        std::string KeyCodeConverter::s_keyaction_to_string[ACTIONMAP_TOSTR_ARRAY_SIZE];

        void KeyCodeConverter::init()
        {
            if (!s_initialized)
            { 
                JUMI_INFO("KeymapInitializer initializing");
                initialize_key_mappings();
                initialize_key_actions();
                initialize_keycode_tostr_array();
                initialize_keyaction_tostr_array();
                s_initialized = true;
            }
            else
            {
                JUMI_WARN("!! KeymapInitializer already initialized !!");
            }
        }

        bool KeyCodeConverter::is_initialized() { return s_initialized; }

        int KeyCodeConverter::glfw_to_jumi_keycode(int keycode)
        {
            if (keycode < 0 || keycode >= KEYMAP_ARRAY_SIZE)
            {
                JUMI_CRITICAL("glfw_to_jumi_keycode attempting to index a value outside of the bounds of the array, returning invalid keycode");
                return -1;
            }
            return s_glfw_to_jumi_keymap[keycode];
        }

        int KeyCodeConverter::glfw_to_jumi_keyaction(int action)
        {
            if (action < 0 || action >= ACTIONMAP_ARRAY_SIZE)
            {
                JUMI_CRITICAL("glfw_to_jumi_keyaction attempting to index a value outside of the bounds of the array, returning invalid actioncode");
                return -1;
            }
            return s_glfw_to_jumi_actionmap[action];
        }

        std::string KeyCodeConverter::keycode_to_string(JUMI_KEYCODE keycode) { return s_keycode_to_string[keycode]; }

        std::string KeyCodeConverter::keyaction_to_string(JUMI_KEYACTION action) { return s_keyaction_to_string[action]; }

        void KeyCodeConverter::initialize_key_mappings()
        {
            JUMI_DEBUG("Initializing KeyMappings, filling KeyMap array with KeyCode values");
            // Initialize every value to -1 to indicate an invalid keycode
            std::fill(std::begin(s_glfw_to_jumi_keymap), std::end(s_glfw_to_jumi_keymap), - 1);

            s_glfw_to_jumi_keymap[GLFW_KEY_SPACE] =            JUMI_KEY_SPACE;
            s_glfw_to_jumi_keymap[GLFW_KEY_APOSTROPHE] =       JUMI_KEY_APOSTROPHE;
            s_glfw_to_jumi_keymap[GLFW_KEY_COMMA] =            JUMI_KEY_COMMA;
            s_glfw_to_jumi_keymap[GLFW_KEY_MINUS] =            JUMI_KEY_MINUS;
            s_glfw_to_jumi_keymap[GLFW_KEY_PERIOD] =           JUMI_KEY_PERIOD;
            s_glfw_to_jumi_keymap[GLFW_KEY_SLASH] =            JUMI_KEY_SLASH;
            s_glfw_to_jumi_keymap[GLFW_KEY_0] =                JUMI_KEY_0;
            s_glfw_to_jumi_keymap[GLFW_KEY_1] =                JUMI_KEY_1;
            s_glfw_to_jumi_keymap[GLFW_KEY_2] =                JUMI_KEY_2;
            s_glfw_to_jumi_keymap[GLFW_KEY_3] =                JUMI_KEY_3;
            s_glfw_to_jumi_keymap[GLFW_KEY_4] =                JUMI_KEY_4;
            s_glfw_to_jumi_keymap[GLFW_KEY_5] =                JUMI_KEY_5;
            s_glfw_to_jumi_keymap[GLFW_KEY_6] =                JUMI_KEY_6;
            s_glfw_to_jumi_keymap[GLFW_KEY_7] =                JUMI_KEY_7;
            s_glfw_to_jumi_keymap[GLFW_KEY_8] =                JUMI_KEY_8;
            s_glfw_to_jumi_keymap[GLFW_KEY_9] =                JUMI_KEY_9;
            s_glfw_to_jumi_keymap[GLFW_KEY_SEMICOLON] =        JUMI_KEY_SEMICOLON;
            s_glfw_to_jumi_keymap[GLFW_KEY_EQUAL] =            JUMI_KEY_EQUAL;
            s_glfw_to_jumi_keymap[GLFW_KEY_A] =                JUMI_KEY_A;
            s_glfw_to_jumi_keymap[GLFW_KEY_B] =                JUMI_KEY_B;
            s_glfw_to_jumi_keymap[GLFW_KEY_C] =                JUMI_KEY_C;
            s_glfw_to_jumi_keymap[GLFW_KEY_D] =                JUMI_KEY_D;
            s_glfw_to_jumi_keymap[GLFW_KEY_E] =                JUMI_KEY_E;
            s_glfw_to_jumi_keymap[GLFW_KEY_F] =                JUMI_KEY_F;
            s_glfw_to_jumi_keymap[GLFW_KEY_G] =                JUMI_KEY_G;
            s_glfw_to_jumi_keymap[GLFW_KEY_H] =                JUMI_KEY_H;
            s_glfw_to_jumi_keymap[GLFW_KEY_I] =                JUMI_KEY_I;
            s_glfw_to_jumi_keymap[GLFW_KEY_J] =                JUMI_KEY_J;
            s_glfw_to_jumi_keymap[GLFW_KEY_K] =                JUMI_KEY_K;
            s_glfw_to_jumi_keymap[GLFW_KEY_L] =                JUMI_KEY_L;
            s_glfw_to_jumi_keymap[GLFW_KEY_M] =                JUMI_KEY_M;
            s_glfw_to_jumi_keymap[GLFW_KEY_N] =                JUMI_KEY_N;
            s_glfw_to_jumi_keymap[GLFW_KEY_O] =                JUMI_KEY_O;
            s_glfw_to_jumi_keymap[GLFW_KEY_P] =                JUMI_KEY_P;
            s_glfw_to_jumi_keymap[GLFW_KEY_Q] =                JUMI_KEY_Q;
            s_glfw_to_jumi_keymap[GLFW_KEY_R] =                JUMI_KEY_R;
            s_glfw_to_jumi_keymap[GLFW_KEY_S] =                JUMI_KEY_S;
            s_glfw_to_jumi_keymap[GLFW_KEY_T] =                JUMI_KEY_T;
            s_glfw_to_jumi_keymap[GLFW_KEY_U] =                JUMI_KEY_U;
            s_glfw_to_jumi_keymap[GLFW_KEY_V] =                JUMI_KEY_V;
            s_glfw_to_jumi_keymap[GLFW_KEY_W] =                JUMI_KEY_W;
            s_glfw_to_jumi_keymap[GLFW_KEY_X] =                JUMI_KEY_X;
            s_glfw_to_jumi_keymap[GLFW_KEY_Y] =                JUMI_KEY_Y;
            s_glfw_to_jumi_keymap[GLFW_KEY_Z] =                JUMI_KEY_Z;
            s_glfw_to_jumi_keymap[GLFW_KEY_LEFT_BRACKET] =     JUMI_KEY_LEFT_BRACKET;
            s_glfw_to_jumi_keymap[GLFW_KEY_BACKSLASH] =        JUMI_KEY_BACKSLASH;
            s_glfw_to_jumi_keymap[GLFW_KEY_RIGHT_BRACKET] =    JUMI_KEY_RIGHT_BRACKET;
            s_glfw_to_jumi_keymap[GLFW_KEY_GRAVE_ACCENT] =     JUMI_KEY_GRAVE_ACCENT;
            s_glfw_to_jumi_keymap[GLFW_KEY_WORLD_1] =          JUMI_KEY_WORLD_1;
            s_glfw_to_jumi_keymap[GLFW_KEY_WORLD_2] =          JUMI_KEY_WORLD_2;
            s_glfw_to_jumi_keymap[GLFW_KEY_ESCAPE] =           JUMI_KEY_ESCAPE;
            s_glfw_to_jumi_keymap[GLFW_KEY_ENTER] =            JUMI_KEY_ENTER;
            s_glfw_to_jumi_keymap[GLFW_KEY_TAB] =              JUMI_KEY_TAB;
            s_glfw_to_jumi_keymap[GLFW_KEY_BACKSPACE] =        JUMI_KEY_BACKSPACE;
            s_glfw_to_jumi_keymap[GLFW_KEY_INSERT] =           JUMI_KEY_INSERT;
            s_glfw_to_jumi_keymap[GLFW_KEY_DELETE] =           JUMI_KEY_DELETE;
            s_glfw_to_jumi_keymap[GLFW_KEY_RIGHT] =            JUMI_KEY_RIGHT;
            s_glfw_to_jumi_keymap[GLFW_KEY_LEFT] =             JUMI_KEY_LEFT;
            s_glfw_to_jumi_keymap[GLFW_KEY_DOWN] =             JUMI_KEY_DOWN;
            s_glfw_to_jumi_keymap[GLFW_KEY_UP] =               JUMI_KEY_UP;
            s_glfw_to_jumi_keymap[GLFW_KEY_PAGE_UP] =          JUMI_KEY_PAGE_UP;
            s_glfw_to_jumi_keymap[GLFW_KEY_PAGE_DOWN] =        JUMI_KEY_PAGE_DOWN;
            s_glfw_to_jumi_keymap[GLFW_KEY_HOME] =             JUMI_KEY_HOME;
            s_glfw_to_jumi_keymap[GLFW_KEY_END] =              JUMI_KEY_END;
            s_glfw_to_jumi_keymap[GLFW_KEY_CAPS_LOCK] =        JUMI_KEY_CAPS_LOCK;
            s_glfw_to_jumi_keymap[GLFW_KEY_SCROLL_LOCK] =      JUMI_KEY_SCROLL_LOCK;
            s_glfw_to_jumi_keymap[GLFW_KEY_NUM_LOCK] =         JUMI_KEY_NUM_LOCK;
            s_glfw_to_jumi_keymap[GLFW_KEY_PRINT_SCREEN] =     JUMI_KEY_PRINT_SCREEN;
            s_glfw_to_jumi_keymap[GLFW_KEY_PAUSE] =            JUMI_KEY_PAUSE;
            s_glfw_to_jumi_keymap[GLFW_KEY_F1] =               JUMI_KEY_F1;
            s_glfw_to_jumi_keymap[GLFW_KEY_F2] =               JUMI_KEY_F2;
            s_glfw_to_jumi_keymap[GLFW_KEY_F3] =               JUMI_KEY_F3;
            s_glfw_to_jumi_keymap[GLFW_KEY_F4] =               JUMI_KEY_F4;
            s_glfw_to_jumi_keymap[GLFW_KEY_F5] =               JUMI_KEY_F5;
            s_glfw_to_jumi_keymap[GLFW_KEY_F6] =               JUMI_KEY_F6;
            s_glfw_to_jumi_keymap[GLFW_KEY_F7] =               JUMI_KEY_F7;
            s_glfw_to_jumi_keymap[GLFW_KEY_F8] =               JUMI_KEY_F8;
            s_glfw_to_jumi_keymap[GLFW_KEY_F9] =               JUMI_KEY_F9;
            s_glfw_to_jumi_keymap[GLFW_KEY_F10] =              JUMI_KEY_F10;
            s_glfw_to_jumi_keymap[GLFW_KEY_F11] =              JUMI_KEY_F11;
            s_glfw_to_jumi_keymap[GLFW_KEY_F12] =              JUMI_KEY_F12;
            s_glfw_to_jumi_keymap[GLFW_KEY_F13] =              JUMI_KEY_F13;
            s_glfw_to_jumi_keymap[GLFW_KEY_F14] =              JUMI_KEY_F14;
            s_glfw_to_jumi_keymap[GLFW_KEY_F15] =              JUMI_KEY_F15;
            s_glfw_to_jumi_keymap[GLFW_KEY_F16] =              JUMI_KEY_F16;
            s_glfw_to_jumi_keymap[GLFW_KEY_F17] =              JUMI_KEY_F17;
            s_glfw_to_jumi_keymap[GLFW_KEY_F18] =              JUMI_KEY_F18;
            s_glfw_to_jumi_keymap[GLFW_KEY_F19] =              JUMI_KEY_F19;
            s_glfw_to_jumi_keymap[GLFW_KEY_F20] =              JUMI_KEY_F20;
            s_glfw_to_jumi_keymap[GLFW_KEY_F21] =              JUMI_KEY_F21;
            s_glfw_to_jumi_keymap[GLFW_KEY_F22] =              JUMI_KEY_F22;
            s_glfw_to_jumi_keymap[GLFW_KEY_F23] =              JUMI_KEY_F23;
            s_glfw_to_jumi_keymap[GLFW_KEY_F24] =              JUMI_KEY_F24;
            s_glfw_to_jumi_keymap[GLFW_KEY_F25] =              JUMI_KEY_F25;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_0] =             JUMI_KEY_KP_0;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_1] =             JUMI_KEY_KP_1;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_2] =             JUMI_KEY_KP_2;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_3] =             JUMI_KEY_KP_3;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_4] =             JUMI_KEY_KP_4;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_5] =             JUMI_KEY_KP_5;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_6] =             JUMI_KEY_KP_6;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_7] =             JUMI_KEY_KP_7;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_8] =             JUMI_KEY_KP_8;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_9] =             JUMI_KEY_KP_9;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_DECIMAL] =       JUMI_KEY_KP_DECIMAL;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_DIVIDE] =        JUMI_KEY_KP_DIVIDE;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_MULTIPLY] =      JUMI_KEY_KP_MULTIPLY;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_SUBTRACT] =      JUMI_KEY_KP_SUBTRACT;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_ADD] =           JUMI_KEY_KP_ADD;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_ENTER] =         JUMI_KEY_KP_ENTER;
            s_glfw_to_jumi_keymap[GLFW_KEY_KP_EQUAL] =         JUMI_KEY_KP_EQUAL;
            s_glfw_to_jumi_keymap[GLFW_KEY_LEFT_SHIFT] =       JUMI_KEY_LEFT_SHIFT;
            s_glfw_to_jumi_keymap[GLFW_KEY_LEFT_CONTROL] =     JUMI_KEY_LEFT_CONTROL;
            s_glfw_to_jumi_keymap[GLFW_KEY_LEFT_ALT] =         JUMI_KEY_LEFT_ALT;
            s_glfw_to_jumi_keymap[GLFW_KEY_LEFT_SUPER] =       JUMI_KEY_LEFT_SUPER;
            s_glfw_to_jumi_keymap[GLFW_KEY_RIGHT_SHIFT] =      JUMI_KEY_RIGHT_SHIFT;
            s_glfw_to_jumi_keymap[GLFW_KEY_RIGHT_CONTROL] =    JUMI_KEY_RIGHT_CONTROL;
            s_glfw_to_jumi_keymap[GLFW_KEY_RIGHT_ALT] =        JUMI_KEY_RIGHT_ALT;
            s_glfw_to_jumi_keymap[GLFW_KEY_RIGHT_SUPER] =      JUMI_KEY_RIGHT_SUPER;
            s_glfw_to_jumi_keymap[GLFW_KEY_MENU] =             JUMI_KEY_MENU;
        }

        void KeyCodeConverter::initialize_key_actions()
        {
            JUMI_DEBUG("Initializing KeyActions, filling KeyAction array with KeyAction values");
            std::fill(std::begin(s_glfw_to_jumi_actionmap), std::end(s_glfw_to_jumi_actionmap), - 1);

            s_glfw_to_jumi_actionmap[GLFW_RELEASE] =           JUMI_KEYACTION_RELEASE;
            s_glfw_to_jumi_actionmap[GLFW_PRESS] =             JUMI_KEYACTION_PRESS;
            s_glfw_to_jumi_actionmap[GLFW_REPEAT] =            JUMI_KEYACTION_REPEAT;
        }

        void KeyCodeConverter::initialize_keycode_tostr_array()
        {
            JUMI_DEBUG("Initializing KeyCode to String Array, filling array with string values");

            s_keycode_to_string[JUMI_KEY_SPACE] =            "JUMI_KEY_SPACE";
            s_keycode_to_string[JUMI_KEY_APOSTROPHE] =       "JUMI_KEY_APOSTROPHE";
            s_keycode_to_string[JUMI_KEY_COMMA] =            "JUMI_KEY_COMMA";
            s_keycode_to_string[JUMI_KEY_MINUS] =            "JUMI_KEY_MINUS";
            s_keycode_to_string[JUMI_KEY_PERIOD] =           "JUMI_KEY_PERIOD";
            s_keycode_to_string[JUMI_KEY_SLASH] =            "JUMI_KEY_SLASH";
            s_keycode_to_string[JUMI_KEY_0] =                "JUMI_KEY_0";
            s_keycode_to_string[JUMI_KEY_1] =                "JUMI_KEY_1";
            s_keycode_to_string[JUMI_KEY_2] =                "JUMI_KEY_2";
            s_keycode_to_string[JUMI_KEY_3] =                "JUMI_KEY_3";
            s_keycode_to_string[JUMI_KEY_4] =                "JUMI_KEY_4";
            s_keycode_to_string[JUMI_KEY_5] =                "JUMI_KEY_5";
            s_keycode_to_string[JUMI_KEY_6] =                "JUMI_KEY_6";
            s_keycode_to_string[JUMI_KEY_7] =                "JUMI_KEY_7";
            s_keycode_to_string[JUMI_KEY_8] =                "JUMI_KEY_8";
            s_keycode_to_string[JUMI_KEY_9] =                "JUMI_KEY_9";
            s_keycode_to_string[JUMI_KEY_SEMICOLON] =        "JUMI_KEY_SEMICOLON";
            s_keycode_to_string[JUMI_KEY_EQUAL] =            "JUMI_KEY_EQUAL";
            s_keycode_to_string[JUMI_KEY_A] =                "JUMI_KEY_A";
            s_keycode_to_string[JUMI_KEY_B] =                "JUMI_KEY_B";
            s_keycode_to_string[JUMI_KEY_C] =                "JUMI_KEY_C";
            s_keycode_to_string[JUMI_KEY_D] =                "JUMI_KEY_D";
            s_keycode_to_string[JUMI_KEY_E] =                "JUMI_KEY_E";
            s_keycode_to_string[JUMI_KEY_F] =                "JUMI_KEY_F";
            s_keycode_to_string[JUMI_KEY_G] =                "JUMI_KEY_G";
            s_keycode_to_string[JUMI_KEY_H] =                "JUMI_KEY_H";
            s_keycode_to_string[JUMI_KEY_I] =                "JUMI_KEY_I";
            s_keycode_to_string[JUMI_KEY_J] =                "JUMI_KEY_J";
            s_keycode_to_string[JUMI_KEY_K] =                "JUMI_KEY_K";
            s_keycode_to_string[JUMI_KEY_L] =                "JUMI_KEY_L";
            s_keycode_to_string[JUMI_KEY_M] =                "JUMI_KEY_M";
            s_keycode_to_string[JUMI_KEY_N] =                "JUMI_KEY_N";
            s_keycode_to_string[JUMI_KEY_O] =                "JUMI_KEY_O";
            s_keycode_to_string[JUMI_KEY_P] =                "JUMI_KEY_P";
            s_keycode_to_string[JUMI_KEY_Q] =                "JUMI_KEY_Q";
            s_keycode_to_string[JUMI_KEY_R] =                "JUMI_KEY_R";
            s_keycode_to_string[JUMI_KEY_S] =                "JUMI_KEY_S";
            s_keycode_to_string[JUMI_KEY_T] =                "JUMI_KEY_T";
            s_keycode_to_string[JUMI_KEY_U] =                "JUMI_KEY_U";
            s_keycode_to_string[JUMI_KEY_V] =                "JUMI_KEY_V";
            s_keycode_to_string[JUMI_KEY_W] =                "JUMI_KEY_W";
            s_keycode_to_string[JUMI_KEY_X] =                "JUMI_KEY_X";
            s_keycode_to_string[JUMI_KEY_Y] =                "JUMI_KEY_Y";
            s_keycode_to_string[JUMI_KEY_Z] =                "JUMI_KEY_Z";
            s_keycode_to_string[JUMI_KEY_LEFT_BRACKET] =     "JUMI_KEY_LEFT_BRACKET";
            s_keycode_to_string[JUMI_KEY_BACKSLASH] =        "JUMI_KEY_BACKSLASH";
            s_keycode_to_string[JUMI_KEY_RIGHT_BRACKET] =    "JUMI_KEY_RIGHT_BRACKET";
            s_keycode_to_string[JUMI_KEY_GRAVE_ACCENT] =     "JUMI_KEY_GRAVE_ACCENT";
            s_keycode_to_string[JUMI_KEY_WORLD_1] =          "JUMI_KEY_WORLD_1";
            s_keycode_to_string[JUMI_KEY_WORLD_2] =          "JUMI_KEY_WORLD_2";
            s_keycode_to_string[JUMI_KEY_ESCAPE] =           "JUMI_KEY_ESCAPE";
            s_keycode_to_string[JUMI_KEY_ENTER] =            "JUMI_KEY_ENTER";
            s_keycode_to_string[JUMI_KEY_TAB] =              "JUMI_KEY_TAB";
            s_keycode_to_string[JUMI_KEY_BACKSPACE] =        "JUMI_KEY_BACKSPACE";
            s_keycode_to_string[JUMI_KEY_INSERT] =           "JUMI_KEY_INSERT";
            s_keycode_to_string[JUMI_KEY_DELETE] =           "JUMI_KEY_DELETE";
            s_keycode_to_string[JUMI_KEY_RIGHT] =            "JUMI_KEY_RIGHT";
            s_keycode_to_string[JUMI_KEY_LEFT] =             "JUMI_KEY_LEFT";
            s_keycode_to_string[JUMI_KEY_DOWN] =             "JUMI_KEY_DOWN";
            s_keycode_to_string[JUMI_KEY_UP] =               "JUMI_KEY_UP";
            s_keycode_to_string[JUMI_KEY_PAGE_UP] =          "JUMI_KEY_PAGE_UP";
            s_keycode_to_string[JUMI_KEY_PAGE_DOWN] =        "JUMI_KEY_PAGE_DOWN";
            s_keycode_to_string[JUMI_KEY_HOME] =             "JUMI_KEY_HOME";
            s_keycode_to_string[JUMI_KEY_END] =              "JUMI_KEY_END";
            s_keycode_to_string[JUMI_KEY_CAPS_LOCK] =        "JUMI_KEY_CAPS_LOCK";
            s_keycode_to_string[JUMI_KEY_SCROLL_LOCK] =      "JUMI_KEY_SCROLL_LOCK";
            s_keycode_to_string[JUMI_KEY_NUM_LOCK] =         "JUMI_KEY_NUM_LOCK";
            s_keycode_to_string[JUMI_KEY_PRINT_SCREEN] =     "JUMI_KEY_PRINT_SCREEN";
            s_keycode_to_string[JUMI_KEY_PAUSE] =            "JUMI_KEY_PAUSE";
            s_keycode_to_string[JUMI_KEY_F1] =               "JUMI_KEY_F1";
            s_keycode_to_string[JUMI_KEY_F2] =               "JUMI_KEY_F2";
            s_keycode_to_string[JUMI_KEY_F3] =               "JUMI_KEY_F3";
            s_keycode_to_string[JUMI_KEY_F4] =               "JUMI_KEY_F4";
            s_keycode_to_string[JUMI_KEY_F5] =               "JUMI_KEY_F5";
            s_keycode_to_string[JUMI_KEY_F6] =               "JUMI_KEY_F6";
            s_keycode_to_string[JUMI_KEY_F7] =               "JUMI_KEY_F7";
            s_keycode_to_string[JUMI_KEY_F8] =               "JUMI_KEY_F8";
            s_keycode_to_string[JUMI_KEY_F9] =               "JUMI_KEY_F9";
            s_keycode_to_string[JUMI_KEY_F10] =              "JUMI_KEY_F10";
            s_keycode_to_string[JUMI_KEY_F11] =              "JUMI_KEY_F11";
            s_keycode_to_string[JUMI_KEY_F12] =              "JUMI_KEY_F12";
            s_keycode_to_string[JUMI_KEY_F13] =              "JUMI_KEY_F13";
            s_keycode_to_string[JUMI_KEY_F14] =              "JUMI_KEY_F14";
            s_keycode_to_string[JUMI_KEY_F15] =              "JUMI_KEY_F15";
            s_keycode_to_string[JUMI_KEY_F16] =              "JUMI_KEY_F16";
            s_keycode_to_string[JUMI_KEY_F17] =              "JUMI_KEY_F17";
            s_keycode_to_string[JUMI_KEY_F18] =              "JUMI_KEY_F18";
            s_keycode_to_string[JUMI_KEY_F19] =              "JUMI_KEY_F19";
            s_keycode_to_string[JUMI_KEY_F20] =              "JUMI_KEY_F20";
            s_keycode_to_string[JUMI_KEY_F21] =              "JUMI_KEY_F21";
            s_keycode_to_string[JUMI_KEY_F22] =              "JUMI_KEY_F22";
            s_keycode_to_string[JUMI_KEY_F23] =              "JUMI_KEY_F23";
            s_keycode_to_string[JUMI_KEY_F24] =              "JUMI_KEY_F24";
            s_keycode_to_string[JUMI_KEY_F25] =              "JUMI_KEY_F25";
            s_keycode_to_string[JUMI_KEY_KP_0] =             "JUMI_KEY_KP_0";
            s_keycode_to_string[JUMI_KEY_KP_1] =             "JUMI_KEY_KP_1";
            s_keycode_to_string[JUMI_KEY_KP_2] =             "JUMI_KEY_KP_2";
            s_keycode_to_string[JUMI_KEY_KP_3] =             "JUMI_KEY_KP_3";
            s_keycode_to_string[JUMI_KEY_KP_4] =             "JUMI_KEY_KP_4";
            s_keycode_to_string[JUMI_KEY_KP_5] =             "JUMI_KEY_KP_5";
            s_keycode_to_string[JUMI_KEY_KP_6] =             "JUMI_KEY_KP_6";
            s_keycode_to_string[JUMI_KEY_KP_7] =             "JUMI_KEY_KP_7";
            s_keycode_to_string[JUMI_KEY_KP_8] =             "JUMI_KEY_KP_8";
            s_keycode_to_string[JUMI_KEY_KP_9] =             "JUMI_KEY_KP_9";
            s_keycode_to_string[JUMI_KEY_KP_DECIMAL] =       "JUMI_KEY_KP_DECIMAL";
            s_keycode_to_string[JUMI_KEY_KP_DIVIDE] =        "JUMI_KEY_KP_DIVIDE";
            s_keycode_to_string[JUMI_KEY_KP_MULTIPLY] =      "JUMI_KEY_KP_MULTIPLY";
            s_keycode_to_string[JUMI_KEY_KP_SUBTRACT] =      "JUMI_KEY_KP_SUBTRACT";
            s_keycode_to_string[JUMI_KEY_KP_ADD] =           "JUMI_KEY_KP_ADD";
            s_keycode_to_string[JUMI_KEY_KP_ENTER] =         "JUMI_KEY_KP_ENTER";
            s_keycode_to_string[JUMI_KEY_KP_EQUAL] =         "JUMI_KEY_KP_EQUAL";
            s_keycode_to_string[JUMI_KEY_LEFT_SHIFT] =       "JUMI_KEY_LEFT_SHIFT";
            s_keycode_to_string[JUMI_KEY_LEFT_CONTROL] =     "JUMI_KEY_LEFT_CONTROL";
            s_keycode_to_string[JUMI_KEY_LEFT_ALT] =         "JUMI_KEY_LEFT_ALT";
            s_keycode_to_string[JUMI_KEY_LEFT_SUPER] =       "JUMI_KEY_LEFT_SUPER";
            s_keycode_to_string[JUMI_KEY_RIGHT_SHIFT] =      "JUMI_KEY_RIGHT_SHIFT";
            s_keycode_to_string[JUMI_KEY_RIGHT_CONTROL] =    "JUMI_KEY_RIGHT_CONTROL";
            s_keycode_to_string[JUMI_KEY_RIGHT_ALT] =        "JUMI_KEY_RIGHT_ALT";
            s_keycode_to_string[JUMI_KEY_RIGHT_SUPER] =      "JUMI_KEY_RIGHT_SUPER";
            s_keycode_to_string[JUMI_KEY_MENU] =             "JUMI_KEY_MENU";
        }

        void KeyCodeConverter::initialize_keyaction_tostr_array()
        {
            JUMI_DEBUG("Initializing KeyAction to String Array, filling array with string values");

            s_keyaction_to_string[JUMI_KEYACTION_RELEASE] =  "JUMI_KEYACTION_RELEASE";
            s_keyaction_to_string[JUMI_KEYACTION_PRESS] =    "JUMI_KEYACTION_PRESS";
            s_keyaction_to_string[JUMI_KEYACTION_REPEAT] =   "JUMI_KEYACTION_REPEAT";
        }

    }
}
