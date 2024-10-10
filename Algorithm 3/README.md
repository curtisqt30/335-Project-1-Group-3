# Algorithm 3: Ensuring Convenient Schedules

## Description

The purpose of the function groupScheduler is to compute the available times for group members to meet. It takes the person's schedule, their working hours as well as the schedules and working hours of any other group member. It also takes the minimum duration that meetings must be. It will then return the available times that the group members are able to meet.

The function takes 5 vectors as inputs: mySchedule, myDailyAct, otherSchedules, otherDailyActs, and duration. It will then compute the available times for the group to meet in a set hash map, availableTimes. 

The overall worst-case time complexity of the groupScheduler function is O(log n). 