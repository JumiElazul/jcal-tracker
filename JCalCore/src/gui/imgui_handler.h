#pragma once
#include <string>
#include <vector>

struct GLFWwindow;
struct Vec2;
class JsonHandler;
class ImGuiInputTextCallbackData;

class DatePicker
{
public:
    DatePicker(int year_range = 10, int start_year = 2020);

    void render();

private:
    int _selected_day = 1;
    int _selected_month = 0;
    int _selected_year = 0;

    int _year_range;
    int _start_year;
    std::vector<std::string> _years;

    static const char* s_days[31];
    static const char* s_months[12];
};

class ImGuiHandler
{
friend class AppCore;
public:
    ~ImGuiHandler();

    void new_frame() const;
    void draw_window(const Vec2& framebuffer_size);
    void render() const;

private:
    JsonHandler& _json_handler;
    DatePicker _date_picker;

    void init(GLFWwindow* window, const Vec2& window_size);

    ImGuiHandler(JsonHandler& json_handler);
    ImGuiHandler(const ImGuiHandler& other) = delete;
    ImGuiHandler operator=(const ImGuiHandler& other) = delete;
    ImGuiHandler(const ImGuiHandler&& other) = delete;
    ImGuiHandler operator=(const ImGuiHandler&& other) = delete;

    static int filter_characters(ImGuiInputTextCallbackData* data);
};
