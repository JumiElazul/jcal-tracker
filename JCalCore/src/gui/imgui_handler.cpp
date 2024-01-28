#include "gui/imgui_handler.h"
#include "core/time.h"
#include "json/json_handler.h"
#include "JCalCore/core/vector.h"
#include <algorithm>
#include <string>
#include <vector>
#include <fmt/format.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

const char* DatePicker::s_days[31] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                                     "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                                     "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31" };

const char* DatePicker::s_months[12] = { "January", "February", "March", "April", "May", "June",
                                       "July", "August", "September", "October", "November", "December" };

DatePicker::DatePicker(int year_range, int start_year)
    : _year_range(year_range), _start_year(start_year)
{
    for (int i = 0; i < _year_range; ++i)
    {
        _years.push_back(std::to_string(_start_year + i));
    }
}

void DatePicker::render()
{
    ImGui::Combo("Day", &_selected_day, s_days, IM_ARRAYSIZE(s_days));
    ImGui::Combo("Month", &_selected_month, s_months, IM_ARRAYSIZE(s_months));

    std::vector<const char*> year_c_str;
    for (const auto& str : _years)
    {
        year_c_str.push_back(str.c_str());
    }
    ImGui::Combo("Year", &_selected_year, year_c_str.data(), year_c_str.size());

    std::string selected_date = std::string(s_days[_selected_day + 1]) + " " +
        std::string(s_months[_selected_month + 1]) + " " +
        _years[_selected_year];

    ImGui::Text("Selected Date: %s", selected_date.c_str());
}

ImGuiHandler::ImGuiHandler(JsonHandler& json_handler)
    : _json_handler(json_handler) { }

int ImGuiHandler::filter_characters(ImGuiInputTextCallbackData* data)
{
    if (data->EventChar == '\t' || data->EventChar == '\n' || data->EventChar == '\r' || data->EventChar == ' ')
        return 1;

    static char allowed_characters[] = "0123456789";

    if (std::find(std::begin(allowed_characters), std::end(allowed_characters), data->EventChar) == std::end(allowed_characters))
    {
        return 1;
    }

    return 0;
}

ImGuiHandler::~ImGuiHandler() 
{ 
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiHandler::new_frame() const
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiHandler::draw_window(const Vec2& framebuffer_size)
{
    ImVec2 window_size{ framebuffer_size.x, framebuffer_size.y };
    ImVec2 window_pos{ 0, 0 };
    ImGui::SetNextWindowSize(window_size);
    ImGui::SetNextWindowPos(window_pos);

    ImGuiWindowFlags flags = ImGuiWindowFlags_None;
    flags = ImGuiWindowFlags_NoResize
          | ImGuiWindowFlags_NoCollapse
          | ImGuiWindowFlags_NoDecoration;
    bool open = true;

    if (ImGui::Begin("Test Window", &open, flags))
    {
        static char meal_buffer[128];
        static char calorie_buffer[6];

        std::map<std::string, std::vector<MealEntry>> meal_data = _json_handler.deserialize_json(_json_handler.get_default_json_filepath());

        ImGui::InputTextWithHint("##meal_description", "Meal Description", meal_buffer, IM_ARRAYSIZE(meal_buffer));
        ImGui::InputTextWithHint("##calories", "Calories", calorie_buffer, IM_ARRAYSIZE(calorie_buffer), ImGuiInputTextFlags_CallbackCharFilter, filter_characters);

        if (ImGui::Button("Add Entry"))
        {
            if (meal_buffer[0] != '\0' && calorie_buffer[0] != '\0')
            {
                MealEntry meal_entry;
                meal_entry.meal_description = meal_buffer;
                meal_entry.calories = std::stoi(calorie_buffer);
                meal_entry.timestamp = jcaltime::get_current_time().get_hms_string();

                jcaltime::time_struct time = jcaltime::get_current_time();
                std::string date = time.get_ymd_string();
                meal_data[date].push_back(meal_entry);

                _json_handler.serialize_json(_json_handler.get_default_json_filepath(), meal_data);

                meal_buffer[0] = '\0';
                calorie_buffer[0] = '\0';
            }
        }

        ImGui::Separator();

        _date_picker.render();

        ImGui::End();
        //ImGui::ShowDemoWindow();
    }
}

void ImGuiHandler::render() const
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGui::UpdatePlatformWindows();
}

void ImGuiHandler::init(GLFWwindow* window, const Vec2& window_size)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.Fonts->AddFontFromFileTTF("assets/iosevka-custom.ttf", 20.0f);
    ImGui::StyleColorsLight();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460");

    ImVec2 size;
    size.x = window_size.x;
    size.y = window_size.y;
    ImGui::SetNextWindowPos({ 0, 0 });
    ImGui::SetNextWindowSize(size);
}

