#include <iostream>
#include "group_scheduler.h"

int main() {
    std::vector<std::pair<std::string, std::string>> person1_Schedule = {
		{"07:00", "08:30"},
		{"12:00", "13:00"},
		{"16:00", "18:00"}
	};
    std::pair<std::string, std::string> person1_DailyAct = {"09:00", "19:00"};

    std::vector<std::pair<std::string, std::string>> person2_Schedule = {
		{"09:00", "10:30"},
		{"12:20", "13:30"},
		{"14:00", "15:00"},
		{"16:00", "17:00"}
	};
	
    std::pair<std::string, std::string> person2_DailyAct = {"09:00", "18:30"};

    std::vector<std::vector<std::pair<std::string, std::string>>> otherSchedules = {person2_Schedule};
    std::vector<std::pair<std::string, std::string>> otherDailyActs = {person2_DailyAct};

    int duration_of_meeting = 30;
	
	// Print the input schedules
    std::cout << "person1_Schedule = [";
    for (size_t i = 0; i < person1_Schedule.size(); ++i) {
        std::cout << "['" << person1_Schedule[i].first << "', '" << person1_Schedule[i].second << "']";
        if (i < person1_Schedule.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    std::cout << "person1_DailyAct = ['" << person1_DailyAct.first << "', '" << person1_DailyAct.second << "']\n\n";

    std::cout << "person2_Schedule = [";
    for (size_t i = 0; i < person2_Schedule.size(); ++i) {
        std::cout << "['" << person2_Schedule[i].first << "', '" << person2_Schedule[i].second << "']";
        if (i < person2_Schedule.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    std::cout << "person2_DailyAct = ['" << person2_DailyAct.first << "', '" << person2_DailyAct.second << "']\n\n";

    std::cout << "duration_of_meeting = " << duration_of_meeting << "\n\n";

    // Find available times
    std::set<std::map<std::string, std::string>> availableTimes = groupScheduler(
        person1_Schedule, person1_DailyAct, otherSchedules, otherDailyActs, duration_of_meeting);

    // Output the result
    std::cout << "[";
    bool first = true; 
    for (const auto& timeSlot : availableTimes) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << "['" << timeSlot.at("start") << "', '" << timeSlot.at("end") << "']";
        first = false;
    }
    std::cout << "]" << std::endl;

    return 0;
}