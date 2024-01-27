#include "json/json_handler.h"
#include "core/time.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <sstream>
#include "nlohmann/json.hpp"
#include "fmt/format.h"

using json = nlohmann::json;

const std::string JsonHandler::s_current_directory = std::filesystem::current_path().string();
const std::string JsonHandler::s_user_directory = s_current_directory + "\\user1";
const std::string JsonHandler::s_json_filepath = s_user_directory + "\\user_data.json";

void from_json(const json& j, DateEntry& date_entry)
{
    j.at("total_calories").get_to(date_entry.total_calories);
    j.at("entries").get_to(date_entry.entries);
}

void to_json(json& j, const DateEntry& date_entry)
{
    j = json{ date_entry.total_calories, { date_entry.entries } };
}

bool JsonHandler::file_exists(const std::string& filepath) { return std::filesystem::exists(filepath); }

Diary JsonHandler::read_json(const std::string& filepath)
{
    if (!file_exists(filepath))
    {
        fmt::print("Directory doesn't exist, can't read_json({})\n", s_user_directory);
        // TODO: Create a default user directory maybe
        return {};
    }

    std::ifstream file(filepath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string file_contents{ buffer.str() };

    json json{ json::parse(file_contents) };
    Diary diary = json.get<Diary>();
    return diary;
}

void JsonHandler::to_json(const std::string& filepath, const Diary& diary)
{

}

void JsonHandler::test_func()
{
    fmt::print("{}\n", jcaltime::get_current_time().get_full_time());

    Diary diary = read_json(s_json_filepath);

    //if (!std::filesystem::exists(s_user_directory))
    //{
    //    fmt::print("{} does not exist, creating folder\n", s_user_directory);
    //    std::filesystem::create_directory(s_user_directory);
    //}

    //if (!std::filesystem::exists(s_json_filepath))
    //{
    //    fmt::print("{} does not exist\n", s_json_filepath);
    //    std::ofstream file(s_json_filepath);
    //}

    //json json;
    //std::ifstream existing_file(s_json_filepath);
    //bool empty_file = existing_file.peek() == std::ifstream::traits_type::eof();

    //if (!empty_file)
    //{
    //    existing_file >> json;
    //}

    //jcaltime::time_struct curr_time{ jcaltime::get_current_time() };


    //std::cout << std::setw(4) << json << '\n';
}

