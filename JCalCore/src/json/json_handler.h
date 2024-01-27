#pragma once
#include <string>
#include <map>
#include <nlohmann/json_fwd.hpp>

using FoodEntry = std::map<std::string, int>;
using TimeEntries = std::map<std::string, FoodEntry>;

struct DateEntry
{
    int total_calories;
    TimeEntries entries;
};

using Diary = std::map<std::string, DateEntry>;

void from_json(const nlohmann::json& json, DateEntry& date_entry);
void to_json(nlohmann::json& json, const DateEntry& date_entry);

class JsonHandler
{
friend class AppCore;
public:
    ~JsonHandler() = default;

    [[nodiscard]] bool file_exists(const std::string& filepath);
    [[nodiscard]] Diary read_json(const std::string& filepath);
    void to_json(const std::string& filepath, const Diary& diary);
    void test_func();

private:
    JsonHandler() = default;
    JsonHandler(const JsonHandler& other) = delete;
    JsonHandler operator=(const JsonHandler& other) = delete;
    JsonHandler(const JsonHandler&& other) = delete;
    JsonHandler operator=(const JsonHandler&& other) = delete;

    static const std::string s_current_directory;
    static const std::string s_user_directory;
    static const std::string s_json_filepath;
};

