#pragma once
#include <chrono>
#include <vector>
#include <string>
#include <cstdint>

namespace frd {
	class Profiler
	{
	public:
		std::vector<std::chrono::duration<double>> total_time;
		std::vector<std::chrono::time_point<std::chrono::high_resolution_clock>> last_time;
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
