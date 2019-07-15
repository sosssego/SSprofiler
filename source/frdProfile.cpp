#include "frdProfile.hpp"
#include <iostream>

using namespace std;

namespace frd {


	Profiler::Profiler() {
		addNewTimer("Total");
		startTimer(0);
	}
	int Profiler::addNewTimer(string name) {
		total_time.push_back(std::chrono::duration < int64_t>(0));
		std::chrono::time_point<std::chrono::high_resolution_clock> temp = std::chrono::high_resolution_clock::now();
		last_time.push_back(temp);
		names.push_back(name);
		return int(total_time.size()) - 1;
	}
	void Profiler::startTimer(int i) {
		last_time[i] = std::chrono::high_resolution_clock::now();
	}
	void Profiler::addPartialTime(int i) {
		auto current_time = std::chrono::high_resolution_clock::now();
		total_time[i] += current_time - last_time[i];
		last_time[i] = current_time;
	}
	void Profiler::clearStoredTime(int i) {
		total_time[i] = 0ms;
	}
	void Profiler::printTimeSummary() {
		addPartialTime(0);
		for (int i = 0; i < (int)names.size(); ++i) {
			printf("%15s\t%.12fsec,\t%.6f\t%% \n",
				names[i].c_str(),
				total_time[i].count(),
				//double(total_time[i].count()) * 0.000000001,
				100 * (float)(total_time[i].count()) / (float)total_time[0].count());

		}
	}
	
}
