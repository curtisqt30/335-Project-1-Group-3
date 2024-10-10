#ifndef GROUP_SCHEDULER_H
#define GROUP_SCHEDULER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

// Helper function to convert time (HH:MM) to minutes
int timeToMin(std::string time);

// Helper function to convert minutes back to time (HH:MM)
std::string minToTime(int minutes);

// Group Scheduler function
std::set<std::map<std::string, std::string>> groupScheduler(
    std::vector<std::pair<std::string, std::string>>& mySchedule,
    std::pair<std::string, std::string> myDailyAct,
    std::vector<std::vector<std::pair<std::string, std::string>>>& otherSchedules,
    std::vector<std::pair<std::string, std::string>>& otherDailyActs,
    int duration);

#endif