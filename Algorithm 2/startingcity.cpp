// Thi Nguyen
// ririchiroyo@csu.fullerton.edu
// Algorithm 2: Greeedy Approach to Hamiltonian Problem

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int findStartingCity(vector<int> &distances, vector<int> &fuel, int mpg)
{
  int cityCount = distances.size();
  int fuelBalance = 0;


  // Finding the starting city
  int start_city = 0;

  for (int i = 0; i < cityCount; i++)
  { // Iterate over each city
    fuelBalance += (fuel[i] * mpg) - distances[i];

    // If total_fuel is ever negative, reset starting city to next
    if (fuelBalance < 0)
    {
      start_city = i + 1;
      fuelBalance = 0;
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

  cout << "Preferred Starting City: " << starting_city << endl;

  return 0;
}
