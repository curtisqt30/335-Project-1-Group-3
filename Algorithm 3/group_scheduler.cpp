#include "group_scheduler.h"

// Helper function to convert time (HH:MM) to minutes
int timeToMin(std::string time) {
    int hours = std::stoi(time.substr(0, 2));
    int minutes = std::stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

// Helper function to convert minutes back to time (HH:MM)
std::string minToTime(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;
    std::string hoursStr = (hours < 10 ? "0" : "") + std::to_string(hours);
    std::string minsStr = (mins < 10 ? "0" : "") + std::to_string(mins);
    return hoursStr + ":" + minsStr;
}

// Group Scheduler function
std::set<std::map<std::string, std::string>> groupScheduler(
    std::vector<std::pair<std::string, std::string>>& mySchedule,
    std::pair<std::string, std::string> myDailyAct,
    std::vector<std::vector<std::pair<std::string, std::string>>>& otherSchedules,
    std::vector<std::pair<std::string, std::string>>& otherDailyActs,
    int duration) {

    // Combine all schedules into a single list while converting each time to minutes
    std::vector<std::pair<int, int>> combinedBusyTimes;

    for (const auto& slot : mySchedule) {
        combinedBusyTimes.push_back({timeToMin(slot.first), timeToMin(slot.second)});
    }

    for (const auto& schedule : otherSchedules) {
        for (const auto& slot : schedule) {
            combinedBusyTimes.push_back({timeToMin(slot.first), timeToMin(slot.second)});
        }
    }

    // Sort the busy times by start time
    std::sort(combinedBusyTimes.begin(), combinedBusyTimes.end());

    // Merge overlapping intervals
    std::vector<std::pair<int, int>> mergedBusyTimes;
    mergedBusyTimes.push_back(combinedBusyTimes[0]);

    for (size_t i = 1; i < combinedBusyTimes.size(); ++i) {
        if (combinedBusyTimes[i].first <= mergedBusyTimes.back().second) {
            mergedBusyTimes.back().second = std::max(mergedBusyTimes.back().second, combinedBusyTimes[i].second);
        } else {
            mergedBusyTimes.push_back(combinedBusyTimes[i]);
        }
    }

    // Find the earliest start and latest end across all working periods
    int earliestStart = std::max(timeToMin(myDailyAct.first), timeToMin(otherDailyActs[0].first));
    int latestEnd = std::min(timeToMin(myDailyAct.second), timeToMin(otherDailyActs[0].second));

    // Calculate available slots
    std::set<std::map<std::string, std::string>> availableTimes;
    int previousEnd = earliestStart;

    for (const auto& busyTime : mergedBusyTimes) {
        if (previousEnd < busyTime.first && busyTime.first - previousEnd >= duration) {
            std::map<std::string, std::string> availableSlot;
            availableSlot["start"] = minToTime(previousEnd);
            availableSlot["end"] = minToTime(busyTime.first);
            availableTimes.insert(availableSlot);
        }
        previousEnd = std::max(previousEnd, busyTime.second);
    }

    // Check for available time after the last busy period
    if (latestEnd - previousEnd >= duration) {
        std::map<std::string, std::string> availableSlot;
        availableSlot["start"] = minToTime(previousEnd);
        availableSlot["end"] = minToTime(latestEnd);
        availableTimes.insert(availableSlot);
    }

    return availableTimes;
}

