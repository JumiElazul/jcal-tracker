#include "json/json_handler.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <map>
#include <vector>
#include "nlohmann/json.hpp"
#include "fmt/format.h"

using json = nlohmann::json;

const std::string JsonHandler::s_filepath = std::filesystem::current_path().string() + "\\JsonPath.json";

JsonHandler::~JsonHandler() { }

void JsonHandler::write_to_file()
{
    //{
    //    "2023-01-01": {
    //        "entries": [
    //            { "item": "Apple", "calories": 95 },
    //            { "item": "Sandwich", "calories": 350 }
    //        ],
    //        "totalCalories": 445
    //    },
    //    "2023-01-02": {
    //        "entries": [
    //            { "item": "Banana", "calories": 105 },
    //            { "item": "Salad", "calories": 150 }
    //        ],
    //        "totalCalories": 255
    //    }
    //}

    std::vector<std::map<std::string, int>> vec
    {
        {
            { "one",   1 },
            { "two",   2 },
            { "three", 3 },
            { "four",  4 },
            { "five",  5 },
            { "six",   6 },
        },
    };

    if (!std::filesystem::exists(s_filepath))
    {
        fmt::print("Filepath {} did not exist\n", s_filepath);
        std::ofstream file(s_filepath);

        json json;
        for (const auto& item : vec)
        {
            for (const auto& elem : item)
            {
                json[elem.first] = elem.second;
            }
        }
        file << std::setw(4) << json;
    }
    else
    {
        fmt::print("Filepath {} exists\n", s_filepath);
        std::ifstream ifile(s_filepath);

        nlohmann::json existing_json;
        ifile >> existing_json;
        ifile.close();

        std::vector<std::map<std::string, int>> new_vec
        {
            { { "TEN", 10 } }
        };

        for (const auto& elem : new_vec)
        {
            for (const auto& item : elem)
            {
                existing_json[item.first] = item.second;
            }
        }

        std::ofstream ofile(s_filepath);
        ofile << std::setw(4) << existing_json;
    }
}



