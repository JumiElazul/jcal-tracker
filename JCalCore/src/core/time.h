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
            , wday(tm.tm_wday)
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

        inline std::string to_string() const
        {
            bool am = hour < 12;
            int new_hour = hour % 12;
            std::string postfix = am ? "AM" : "PM";

            std::string new_min = std::to_string(min);
            std::string new_sec = std::to_string(sec);

            if (min < 10)
            {
                char c = new_min[0];
                new_min += c;
                new_min[0] = '0';
            }

            if (sec < 10)
            {
                char c = new_sec[0];
                new_sec += c;
                new_sec[0] = '0';
            }

            std::string result = std::to_string(year) + '-'
                + std::to_string(mon) + '-'
                + std::to_string(mday) + ' '
                + std::to_string(new_hour) + ':'
                + new_min + ':'
                + new_sec + ' ' + postfix;

            return result;
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const time_struct& ts)
    {
        os << ts.to_string();
        return os;
    }

    inline time_struct get_current_time()
    {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(now);
        std::tm local_tm = *std::localtime(&tt);
        return time_struct(local_tm);
    }

}
