#pragma once
#include <string>
#include <map>

class json;

using FoodEntry = std::map<std::string, int>;
using TimeEntries = std::map<std::string, FoodEntry>;

struct DateEntry
{
    int total_calories;
    TimeEntries entries;
};

using Diary = std::map<std::string, DateEntry>;

class JsonHandler
{
friend class AppCore;
public:
    ~JsonHandler();

    void to_json();

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

