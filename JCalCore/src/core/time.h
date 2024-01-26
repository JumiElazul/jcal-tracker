#pragma once
#include <chrono>
#include <string>

namespace jcaltime
{

    struct time_struct
    {
        time_struct(const std::tm& tm)
            : sec(tm.tm_sec)
            , min(tm.tm_min)
            , hour(tm.tm_hour)
            , mday(tm.tm_mday)
            , mon(tm.tm_mon + 1)
            , year(tm.tm_year + 1900)
            , wday(tm.tm_wday + 1)
            , yday(tm.tm_yday)
            , isdst(tm.tm_isdst)
        {
        }

        int sec;   // seconds after the minute - [0, 60] including leap second
        int min;   // minutes after the hour - [0, 59]
        int hour;  // hours since midnight - [0, 23]
        int mday;  // day of the month - [1, 31]
        int mon;   // months since January - [0, 11]
        int year;  // years since 1900
        int wday;  // days since Sunday - [0, 6]
        int yday;  // days since January 1 - [0, 365]
        int isdst; // daylight savings time flag

        inline std::string get_ymd_string() const
        {
            std::string month{ std::to_string(mon) };
            std::string day{ std::to_string(mday) };

            if (std::stoi(month) < 10) { month = prefix_zero(month); }
            if (std::stoi(day) < 10) { day = prefix_zero(day); }

            return std::to_string(year) + "-" + month + "-" + day;
        }

        inline std::string get_hms_string() const
        {
            std::string hour_{ std::to_string(hour) };
            std::string minute{ std::to_string(min) };
            std::string second{ std::to_string(sec) };
            std::string postfix;

            if (std::stoi(hour_) > 11) { postfix = "PM"; }
            else { postfix = "AM"; }
            if (hour == 0) { hour_ = "12"; }
            else if (hour > 12) { hour_ = std::to_string(hour - 12); }

            if (std::stoi(minute) < 10) { minute = prefix_zero(minute); }
            if (std::stoi(second) < 10) { second = prefix_zero(second); }

            return hour_ + ":" + minute + ":" + second + " " + postfix;
        }

        inline std::string get_full_time() const
        {
            return get_ymd_string() + " " + get_hms_string();
        }

    private:
        std::string prefix_zero(std::string& str) const { return str.insert(0, "0"); }
    };

    inline time_struct get_current_time()
    {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(now);
        std::tm local_tm = *std::localtime(&tt);
        return time_struct(local_tm);
    }

}
