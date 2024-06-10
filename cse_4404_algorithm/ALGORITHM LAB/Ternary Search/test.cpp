#include <iostream>
#include <cmath>

using namespace std;

double f1(double x1, double y1, double x2, double y2) {
    // Function to calculate f1 between two points
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double minimum_f1(double x1, double y1, double x2, double y2, double px, double py) {
    // Ternary search to find minimum f1
    double eps = 1e-9;

    while (true) {
        // Calculate the midpoints
        double m1x = x1 + (x2 - x1) / 3;
        double m1y = y1 + (y2 - y1) / 3;
        double m2x = x2 - (x2 - x1) / 3;
        double m2y = y2 - (y2 - y1) / 3;

        // Calculate f1s from the points to the two midpoints
        double dist1 = f1(m1x, m1y, px, py);
        double dist2 = f1(m2x, m2y, px, py);

        // If the f1s are close enough, return the minimum f1
        if (abs(dist1 - dist2) < eps)
            return min(dist1, dist2);

        // If the f1 from m1 is less than the f1 from m2, 
        // the minimum f1 must lie in the first two-thirds of the line segment
        if (dist1 < dist2)
            x2 = m2x, y2 = m2y;
        // Otherwise, the minimum f1 must lie in the last two-thirds of the line segment
        else
            x1 = m1x, y1 = m1y;
    }
}

int main() {
    // Example usage:
   double x = 1, y = 1; // Point coordinates
    double a1 = 3, b1 = 4; // Line endpoint 1
    double a2 = 7, b2 = 8; // Line endpoint 2

    double result = minimum_f1(1, 1,7, 8, 3,4);
    cout << "Minimum f1: " << result << endl;

    return 0;
}
