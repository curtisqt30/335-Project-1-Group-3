#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int findStartingCity(vector<int> &distances, vector<int> &fuel, int mpg)
{
  int n = distances.size();
  int total_fuel = 0;
  int current_fuel = 0;

  // Checks if there is enough fuel for 1 pass
  // Calculates fuel gained from city i and subtracts distance to next city
  // Value added to total fuel
  for (int i = 0; i < n; i++)
  {
    total_fuel += fuel[i] * mpg - distances[i];
  }

  if (total_fuel < 0)
    return -1; // If total fuel is less than 0; no solution

  // Finding the starting city
  int start_city = 0;
  total_fuel = 0;

  for (int i = 0; i < n; i++)
  { // Iterate over each city
    total_fuel += fuel[i] * mpg - distances[i];

    // If total_fuel is ever negative, reset starting city to next
    if (total_fuel < 0)
    {
      start_city = i + 1;
      total_fuel = 0;
    }
  }

  return start_city;
}

void readInput(vector<int> &vec)
{ // For inputting distance/fuel in one line
  string input;
  getline(cin, input);         // Read the whole line
  istringstream stream(input); // Create a stream from the input
  int value;

  while (stream >> value)
  {
    vec.push_back(value); // Add each value to the vector
    if (stream.peek() == ',')
    { // If the next character is a comma, skip it
      stream.ignore();
    }
  }
}

int main()
{
  vector<int> distances, fuel; // Vectors to store distances and fuel

  // Input distances between cities
  cout << "Enter the distances between the cities (comma or space-separated): ";
  readInput(distances);

  // Input fuel available at each city
  cout << "Enter the fuel available at each city (comma or space-separated): ";
  readInput(fuel);

  // Input miles per gallon (MPG)
  int mpg;
  cout << "Enter miles per gallon (MPG): ";
  cin >> mpg;

  // Call the function to find the starting city
  int starting_city = findStartingCity(distances, fuel, mpg);
  cout << "Starting City: " << starting_city << endl;

  return 0;
}
