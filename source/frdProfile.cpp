#include "frdProfile.hpp"
#include <iostream>

using namespace std;

namespace frd {

	int Profiler::addNewTimer(string name) {
		long long temp;
		temp = 0;
		total_time.push_back(temp);
		temp = chrono::duration_cast<chrono::nanoseconds> (chrono::steady_clock::now().time_since_epoch()).count();
		last_time.push_back(temp);
		names.push_back(name);
		return int(total_time.size()) - 1;
	}
	void Profiler::startTimer(int i) {
		last_time[i] = chrono::duration_cast<chrono::nanoseconds> (chrono::steady_clock::now().time_since_epoch()).count();
	}
	void Profiler::addPartialTime(int i) {
		current_time = chrono::duration_cast<chrono::nanoseconds> (chrono::steady_clock::now().time_since_epoch()).count();
		total_time[i] += current_time - last_time[i];
		last_time[i] = current_time;
	}
	void Profiler::clearStoredTime(int i) {
		total_time[i] = 0;
	}
	void Profiler::printTimeSummary() {
		addPartialTime(0);
		for (int i = 0; i < (int)names.size(); ++i) {
			printf("%15s\t%12lld\t\tcounts, %.6fsec,\t%.6f\t%% \n", names[i].c_str(), total_time[i], double(total_time[i]) * 0.000000001, 100 * (float)(total_time[i]) / (float)total_time[0]);

		}
	}
	
}
