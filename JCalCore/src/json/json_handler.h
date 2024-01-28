#pragma once
#include <string>
#include <map>
#include <nlohmann/json_fwd.hpp>

struct MealEntry;

class JsonHandler
{
friend class AppCore;
public:
    ~JsonHandler() = default;

    nlohmann::json deserialize_json(const std::string& json_path) const;
    void serialize_json(const std::string& json_path, const nlohmann::json& json) const;
    void add_meal_entry(nlohmann::json& j, const MealEntry& meal_entry) const;
    void test_func();

private:
    void init_json_if_needed(const std::string& dir_path, const std::string& filepath) const;

    JsonHandler() = default;
    JsonHandler(const JsonHandler& other) = delete;
    JsonHandler operator=(const JsonHandler& other) = delete;
    JsonHandler(const JsonHandler&& other) = delete;
    JsonHandler operator=(const JsonHandler&& other) = delete;

    static const std::string s_current_directory;
    static const std::string s_user_directory;
    static const std::string s_json_filepath;
};

