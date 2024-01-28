#pragma once
#include "core/structs.h"
#include <string>
#include <vector>
#include <map>
#include <nlohmann/json_fwd.hpp>

struct MealEntry;

class JsonHandler
{
friend class AppCore;
public:
    ~JsonHandler() = default;

    std::map<std::string, std::vector<MealEntry>> deserialize_json(const std::string& json_path) const;
    void serialize_json(const std::string& json_path, const std::map<std::string, std::vector<MealEntry>>& meal_entries) const;
    const std::string get_default_json_filepath() const;

private:
    void init_json_if_needed(const std::string& filepath) const;

    JsonHandler() = default;
    JsonHandler(const JsonHandler& other) = delete;
    JsonHandler operator=(const JsonHandler& other) = delete;
    JsonHandler(const JsonHandler&& other) = delete;
    JsonHandler operator=(const JsonHandler&& other) = delete;

    static const std::string s_current_directory;
    static const std::string s_user_directory;
    static const std::string s_json_filepath;
};

