#include <iostream>
#include <iomanip>

using namespace std;

const int MIN_FAHRENHEIT = 0;
const int MAX_FAHRENHEIT = 20;

double getCelsius(int fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

int main() {
    // Print name
    cout << "Celcius Temperature Table" << endl;
    cout << "-------------------------" << endl;

    // Print labels
    cout << setw(12) << "Fahrenheit" << setw(12) << "Celsius" << endl;

    // Loop and print
    for (int fahrenheit = MIN_FAHRENHEIT; fahrenheit <= MAX_FAHRENHEIT; ++fahrenheit) {
        double celsius = getCelsius(fahrenheit);
        cout << setw(12) << fixed << setprecision(1) << fahrenheit
             << setw(12) << fixed << setprecision(1) << celsius << endl;
    }

    return 0;
}