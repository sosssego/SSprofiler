#include "frdProfile.hpp"
#include <iostream>

using namespace std;

namespace frd {

	using namespace chrono;
	Profiler::Profiler() {
		addNewTimer("Total");
		startTimer(0);
	}

	int Profiler::addNewTimer(string name) {
		total_time.push_back(secondsDouble(0));
		timePoint temp = steady_clock::now();
		last_time.push_back(temp);
		names.push_back(name);
		return int(total_time.size()) - 1;
	}
	void Profiler::startTimer(int i) {
		last_time[i] = steady_clock::now();
	}
	void Profiler::addPartialTime(int i) {
		auto current_time = steady_clock::now();
		total_time[i] += current_time - last_time[i];
		last_time[i] = current_time;
	}
	void Profiler::clearStoredTime(int i) {
		total_time[i] = 0s;
	}
	void Profiler::printTimeSummary() {
		addPartialTime(0);
		for (int i = 0; i < (int)names.size(); ++i) {
			printf("%15s\t%.12fsec,\t%.6f\t%% \n",
				names[i].c_str(),
				total_time[i].count(),
				100 * (total_time[i].count()) / total_time[0].count());

		}
	}
	
}
