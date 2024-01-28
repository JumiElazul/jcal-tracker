#include "json/json_handler.h"
#include "core/time.h"
#include "core/structs.h"
#include <fstream>
#include <filesystem>
#include <sstream>
#include "nlohmann/json.hpp"
#include "fmt/format.h"

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MealEntry, timestamp, meal_description, calories)
using json = nlohmann::json;

const std::string JsonHandler::s_current_directory = std::filesystem::current_path().string();
const std::string JsonHandler::s_user_directory = s_current_directory + "\\user1";
const std::string JsonHandler::s_json_filepath = s_user_directory + "\\user_data.json";


void JsonHandler::init_json_if_needed(const std::string& dir_path, const std::string& filepath) const
{
    if (!std::filesystem::exists(dir_path))
    {
        std::filesystem::create_directory(dir_path);
    }

    if (!std::filesystem::exists(filepath))
    {
        std::ofstream file{ filepath };
        json j{ json::object() };
        file << std::setw(4) << j << std::endl;
        file.close();
    }
}

json JsonHandler::deserialize_json(const std::string& json_path) const
{
    std::ifstream file{ json_path };
    json j;
    file >> j;
    file.close();
    return j;
}

void JsonHandler::serialize_json(const std::string& json_path, const json& j) const
{
    std::ofstream file{ json_path };
    file << std::setw(4) << j << std::endl;
    file.close();
}

void JsonHandler::add_meal_entry(json& j, const MealEntry& meal_entry) const
{
    jcaltime::time_struct time = jcaltime::get_current_time();
    std::string year_month_day_str{ time.get_ymd_string() };

    if (j.find(year_month_day_str) == j.end())
    {
        j[year_month_day_str] = json::array();
    }

    j[year_month_day_str].push_back(meal_entry);
}

void JsonHandler::test_func()
{
    fmt::print("{}\n", jcaltime::get_current_time().get_full_time());
    init_json_if_needed(s_user_directory, s_json_filepath);

    json j = deserialize_json(s_json_filepath);
}

