#pragma once
#include <string>
#include <map>

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

    bool file_exists(const std::string& filepath);
    Diary read_json();
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

