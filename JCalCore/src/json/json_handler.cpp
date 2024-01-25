#include "json/json_handler.h"
#include "core/time.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "nlohmann/json.hpp"
#include "fmt/format.h"

using json = nlohmann::json;

const std::string JsonHandler::s_current_directory = std::filesystem::current_path().string();
const std::string JsonHandler::s_user_directory = s_current_directory + "\\user1";
const std::string JsonHandler::s_json_filepath = s_user_directory + "\\user_data.json";

JsonHandler::~JsonHandler() { }

void JsonHandler::to_json()
{
    if (!std::filesystem::exists(s_user_directory))
    {
        fmt::print("{} does not exist, creating folder\n", s_user_directory);
        std::filesystem::create_directory(s_user_directory);
    }

    if (!std::filesystem::exists(s_json_filepath))
    {
        fmt::print("{} does not exist\n", s_json_filepath);
        std::ofstream file(s_json_filepath);
    }

    json json;
    std::ifstream existing_file(s_json_filepath);
    bool empty_file = existing_file.peek() == std::ifstream::traits_type::eof();

    if (!empty_file)
    {
        existing_file >> json;
    }

    jcaltime::time_struct curr_time{ jcaltime::get_current_time() };


    std::cout << std::setw(4) << json << '\n';
}
