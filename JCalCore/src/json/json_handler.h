#pragma once
#include <string>
#include <map>

class JsonHandler
{
friend class AppCore;
public:
    ~JsonHandler();

    void write_to_file();

private:
    std::map<std::string, int> entries;

    JsonHandler() = default;
    JsonHandler(const JsonHandler& other) = delete;
    JsonHandler operator=(const JsonHandler& other) = delete;
    JsonHandler(const JsonHandler&& other) = delete;
    JsonHandler operator=(const JsonHandler&& other) = delete;

    static const std::string s_filepath;
};
