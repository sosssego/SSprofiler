#pragma once
#include <chrono>
#include <vector>
#include <string>

namespace frd {
	class Profiler
	{
	public:
		std::vector<long long> total_time, last_time;
		std::vector<std::string> names;
		long long current_time;


		int addNewTimer(std::string name);
		void startTimer(int i);
		void addPartialTime(int i);
		void clearStoredTime(int i);
		void printTimeSummary();
		Profiler();
	};
}
