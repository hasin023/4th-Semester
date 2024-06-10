#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate distance between two points (x1, y1) and (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Function to find the value of a function for a given parameter t
double f(double x, double y, double a, double b, double t) {
    return distance(x, y, a + t, b + t);
}

// Ternary search to find the minimum value of function f
double ternary_search(double x, double y, double a, double b) {
    double l = -1e9, r = 1e9;
    while (r - l > 1e-9) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(x, y, a, b, m1) < f(x, y, a, b, m2))
            r = m2;
        else
            l = m1;
    }
    return f(x, y, a, b, (l + r) / 2);
}

int main() {
    // Example: Point (1, 1) and Line (3, 4) to (7, 8)
    double x = 1, y = 1; // Point coordinates
    double a1 = 3, b1 = 4; // Line endpoint 1
    double a2 = 7, b2 = 8; // Line endpoint 2

    double min_distance = ternary_search(x, y, a1, b1);
    cout << "Minimum distance between point and line: " << min_distance << endl;

    return 0;
}
