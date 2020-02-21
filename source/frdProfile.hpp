#pragma once
#include <chrono>
#include <vector>
#include <string>
#include <cstdint>

namespace frd {
	using secondsDouble = std::chrono::duration<double>;
	using timePoint = std::chrono::time_point<std::chrono::steady_clock>;
	class Profiler
	{
	public:
		std::vector<secondsDouble> total_time;
		std::vector<timePoint> last_time;
		std::vector<std::string> names;
		//std::chrono::time_point<int64_t> current_time;


		int addNewTimer(std::string name);
		void startTimer(int i);
		void addPartialTime(int i);
		void clearStoredTime(int i);
		void printTimeSummary();
		Profiler();
	};
}
