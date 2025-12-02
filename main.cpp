#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function prototypes
int getNumberOfRooms();
double getSquareFeet(int roomNumber);
double getPaintPrice();
int calculateGallons(double squareFeet);
double calculateLaborHours(double squareFeet);
double calculatePaintCost(int gallons, double paintPrice);
double calculateLaborCost(double laborHours);
void displayEstimate(int gallons, double laborHours, double paintCost, double laborCost, double totalCost);

int main() {
    int numRooms;
    double totalSquareFeet = 0.0;
    double paintPrice;
    int totalGallons = 0;
    double totalLaborHours = 0.0;
    double totalPaintCost = 0.0;
    double totalLaborCost = 0.0;
    double totalCost = 0.0;

    // # of rooms
    numRooms = getNumberOfRooms();

    // paint price
    paintPrice = getPaintPrice();

    // rooms
    for (int i = 1; i <= numRooms; i++) {
        double squareFeet = getSquareFeet(i);
        totalSquareFeet += squareFeet;

        int gallons = calculateGallons(squareFeet);
        totalGallons += gallons;

        double laborHours = calculateLaborHours(squareFeet);
        totalLaborHours += laborHours;

        double paintCost = calculatePaintCost(gallons, paintPrice);
        totalPaintCost += paintCost;

        double laborCost = calculateLaborCost(laborHours);
        totalLaborCost += laborCost;
    }

    // total cost
    totalCost = totalPaintCost + totalLaborCost;

    // estimate
    displayEstimate(totalGallons, totalLaborHours, totalPaintCost, totalLaborCost, totalCost);

    return 0;
}

// # of rooms
int getNumberOfRooms() {
    int numRooms;
    do {
        cout << "Enter the number of rooms to be painted: ";
        cin >> numRooms;
        if (numRooms < 1) {
            cout << "Number of rooms must be at least 1. Please enter again." << endl;
        }
    } while (numRooms < 1);
    return numRooms;
}

// sq ft of wall
double getSquareFeet(int roomNumber) {
    double squareFeet;
    do {
        cout << "Enter the square footage of room " << roomNumber << ": ";
        cin >> squareFeet;
        if (squareFeet < 0) {
            cout << "Square footage cannot be negative. Please enter again." << endl;
        }
    } while (squareFeet < 0);
    return squareFeet;
}

// price of paint per gallon
double getPaintPrice() {
    double paintPrice;
    do {
        cout << "Enter the price of paint per gallon: $";
        cin >> paintPrice;
        if (paintPrice < 10.00) {
            cout << "Price of paint must be at least $10.00. Please enter again." << endl;
        }
    } while (paintPrice < 10.00);
    return paintPrice;
}

// # of gallons of paint required
int calculateGallons(double squareFeet) {
    return ceil(squareFeet / 110.0);
}

// # of labor hours
double calculateLaborHours(double squareFeet) {
    return (squareFeet / 110.0) * 8.0;
}

// cost of paint
double calculatePaintCost(int gallons, double paintPrice) {
    return gallons * paintPrice;
}

// cost of labor
double calculateLaborCost(double laborHours) {
    return laborHours * 25.0;
}

// estimate
void displayEstimate(int gallons, double laborHours, double paintCost, double laborCost, double totalCost) {
    cout << fixed << setprecision(2);
    cout << "\nEstimate:" << endl;
    cout << "Number of gallons of paint required: " << gallons << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of the paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl;
}