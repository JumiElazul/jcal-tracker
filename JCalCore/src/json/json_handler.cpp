#include "json/json_handler.h"
#include "core/structs.h"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <vector>
#include <map>
#include "nlohmann/json.hpp"
#include "fmt/format.h"

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MealEntry, timestamp, meal_description, calories)
using json = nlohmann::json;

const std::string JsonHandler::s_current_directory = std::filesystem::current_path().string();
const std::string JsonHandler::s_json_filepath = s_current_directory + "\\user_data.json";

void JsonHandler::init_json_if_needed(const std::string& filepath) const
{
    if (!std::filesystem::exists(filepath))
    {
        std::ofstream file{ filepath };
        json j{ json::object() };
        file << std::setw(4) << j << std::endl;
        file.close();
    }
}

std::map<std::string, std::vector<MealEntry>> JsonHandler::deserialize_json(const std::string& json_path) const
{
    init_json_if_needed(json_path);
    std::ifstream file{ json_path };
    nlohmann::json j;
    file >> j;

    std::map<std::string, std::vector<MealEntry>> meal_entries;

    for (const auto& [date, entries] : j.items()) 
    {
        std::vector<MealEntry> day_meal_entries;

        for (const auto& entry : entries) 
        {
            MealEntry meal_entry;
            meal_entry.timestamp = entry.value("timestamp", "");
            meal_entry.meal_description = entry.value("meal_description", "");
            meal_entry.calories = entry.value("calories", 0);
            day_meal_entries.push_back(meal_entry);
        }

        meal_entries[date] = day_meal_entries;
    }

    return meal_entries;
}

void JsonHandler::serialize_json(const std::string& json_path, const std::map<std::string, std::vector<MealEntry>>& meal_entries) const
{
    std::ofstream file{ json_path };
    json j;

    for (const auto& [date, entries] : meal_entries)
    {
        json date_array = nlohmann::json::array();
        for (const auto& entry : entries)
        {
            json entry_json;
            entry_json["timestamp"] = entry.timestamp;
            entry_json["meal_description"] = entry.meal_description;
            entry_json["calories"] = entry.calories;
            date_array.push_back(entry_json);
        }
        j[date] = date_array;
    }

    file << std::setw(4) << j << std::endl;
}

const std::string JsonHandler::get_default_json_filepath() const { return s_json_filepath; }

