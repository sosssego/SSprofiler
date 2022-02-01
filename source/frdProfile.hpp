#pragma once
#include <chrono>
#include <string>
#include <unordered_map>

namespace frd {

class Profiler {
  public:
    using timePoint = std::chrono::time_point<std::chrono::steady_clock>;
    using seconds_T = std::chrono::duration<double>;

    Profiler() {
        addNewTimer("_Total");
        startTimer("_Total");
    }

    void addNewTimer(const std::string& name) {
        if (!map.count(name)) {
            map[name].total_time = seconds_T(0);
            map[name].last_time = std::chrono::steady_clock::now();
        }
    }

    void startTimer(const std::string& name) {
        if (map.count(name)) {
            map[name].last_time = std::chrono::steady_clock::now();
        }
    }

    void addPartialTime(const std::string& name) {
        if (map.count(name)) {
            auto current_time = std::chrono::steady_clock::now();
            map[name].total_time += current_time - map[name].last_time;
            map[name].last_time = current_time;
        }
    }

    void clearStoredTime(const std::string& name) {
        if (map.count(name)) {
            map[name].total_time = seconds_T{0};
        }
    }

    seconds_T getTotalTime(const std::string& name) {
        if (map.count(name)) {
            return map[name].total_time;
        }
        return seconds_T(0);
    }

    void printTimeSummary() {
        addPartialTime("_Total");
        for (const auto& i : map) {
            if (i.first != "_Total") {
                printf("%15s\t%.12fsec,\t%.6f\t%% \n", i.first.c_str(), i.second.total_time.count(),
                       100 * (i.second.total_time.count()) / map["_Total"].total_time.count());
            }
        }
        printf("%15s\t%.12fsec,\t%.6f\t%% \n", "_Total", map["_Total"].total_time.count(),
               100 * (map["_Total"].total_time.count()) / map["_Total"].total_time.count());
    }

  private:
    struct time_info {
        seconds_T total_time;
        timePoint last_time;
    };
    std::unordered_map<std::string, time_info> map;
};

}  // namespace frd
