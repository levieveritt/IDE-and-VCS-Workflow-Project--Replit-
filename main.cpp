#include <iostream>
#include <string>
#include <limits> 

using namespace std;

// get region name and # of accidents
void getRegionData(string& regionName, int& accidents) {
    cout << "Enter the region name: ";
    getline(cin >> ws, regionName); 

    cout << "Enter the number of accidents reported last year: ";
    cin >> accidents;

    // Input val
    while (accidents < 0) {
        cout << "Invalid input. Number of accidents cannot be negative." << endl;
        cout << "Enter the number of accidents reported last year: ";
        cin >> accidents;
        //Clear errors
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    //Clear errors
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    string lowestRegionName;
    int lowestAccidents;

    // Get region and # of accidents
    getRegionData(lowestRegionName, lowestAccidents);

    // data hold
    string regionName;
    int accidents;
    const int NUM_REGIONS = 4; 

    for (int i = 0; i < NUM_REGIONS; ++i) {
        // Get info
        getRegionData(regionName, accidents);

        if (accidents < lowestAccidents) {
            lowestAccidents = accidents;
            lowestRegionName = regionName;
        }
    }

    // Display
    cout << "\nThe region with the fewest accidents is " << lowestRegionName << " with " << lowestAccidents << " accidents." << endl;

    return 0;
}