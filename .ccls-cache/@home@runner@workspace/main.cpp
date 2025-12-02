#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

using namespace std;

// Function to get region name and number of accidents
void getRegionData(string& regionName, int& accidents) {
    cout << "Enter the region name: ";
    getline(cin >> ws, regionName); // Use getline to handle spaces in region names

    cout << "Enter the number of accidents reported last year: ";
    cin >> accidents;

    // Input validation: Do not accept an accident number that is less than 0
    while (accidents < 0) {
        cout << "Invalid input. Number of accidents cannot be negative." << endl;
        cout << "Enter the number of accidents reported last year: ";
        cin >> accidents;
        //Clear error flags and ignore any remaining input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Clear error flags and ignore any remaining input
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    string lowestRegionName;
    int lowestAccidents;

    // Get the name of a region and the number of accidents reported last year from interactive input.
    getRegionData(lowestRegionName, lowestAccidents);

    // Use those values to initialize variables to hold the name and number of accidents of the region which had the lowest number of accidents.
    string regionName;
    int accidents;
    const int NUM_REGIONS = 4;  // Already got first region above

    // For each remaining region
    for (int i = 0; i < NUM_REGIONS; ++i) {
        // Get the name of a region and the number of accidents reported last year from interactive input.
        getRegionData(regionName, accidents);

        // Determine if its number of accidents is less than the current lowest.
        // if it is, store the name and number of accident values in the variables holding the lowest accident number.
        if (accidents < lowestAccidents) {
            lowestAccidents = accidents;
            lowestRegionName = regionName;
        }
    }

    // Display the name and number of accidents for the region with the lowest accident rate.
    cout << "\nThe region with the fewest accidents is " << lowestRegionName << " with " << lowestAccidents << " accidents." << endl;

    return 0;
}