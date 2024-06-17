#include <iostream>
#include "interp1d.cpp"

int main() {
    double x_data[] = {1, 2, 3};
    double y_data[] = {10, 20, 30};
    int m = sizeof(x_data) / sizeof(x_data[0]);

    double x_interp = 1.5;

    double y_interp = interp1d(x_data, y_data, x_interp, m);

    std::cout << "Linear interpolated value at x = " << x_interp << " is " << y_interp << "." << std::endl;

    return 0;
}

