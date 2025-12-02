#include <iostream>

using namespace std;

// Function to calculate the perimeter of a rectangle
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate the area of a rectangle
double calculateArea(double length, double width) {
    return length * width;
}

int main() {
    double length, width;
    char continueCalculation;

    do {
        // Get input from the user
        cout << "Enter the length of the rectangle: ";
        cin >> length;

        cout << "Enter the width of the rectangle: ";
        cin >> width;

        // Calculate the perimeter and area
        double perimeter = calculatePerimeter(length, width);
        double area = calculateArea(length, width);

        // Display the results
        cout << "Perimeter: " << perimeter << endl;
        cout << "Area: " << area << endl;

        // Ask if the user wants to process another rectangle
        cout << "Do you want to process another rectangle? (y/n): ";
        cin >> continueCalculation;

    } while (continueCalculation == 'y' || continueCalculation == 'Y');

    cout << "Program terminated." << endl;

    return 0;
}