#include "json/json_handler.h"
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"
#include "fmt/format.h"

using json = nlohmann::json;

const std::string JsonHandler::s_filepath = "JsonPath.json";

JsonHandler::~JsonHandler() { }

void JsonHandler::write_to_file()
{
    std::ifstream file(s_filepath);
    if (!file)
    {
        fmt::print("Filepath {} doesn't exist", s_filepath);
    }
    else
    {
        fmt::print("Filepath {} exists", s_filepath);

    }
}

