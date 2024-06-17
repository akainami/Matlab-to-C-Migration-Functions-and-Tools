#include <iostream>
#include "interp2d.cpp"

int main() {
    // Example 2D data
    const double x_data[] = {1, 2, 3};
    const double y_data[] = {1, 2, 3};
    
    int m = sizeof(x_data) / sizeof(x_data[0]);
    int n = sizeof(y_data) / sizeof(y_data[0]);
    
    const double z_data[n][m] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}}; // Non-flattened 2D array

    // Convert z_data to a flattened array pointer
    const double* z_data_flat = &z_data[0][0];

    // Interpolation points
    double x_interp = 2;
    double y_interp = 2;

    // Perform 2D linear interpolation using flattened z_data
    double z_interp = interp2d(x_data, y_data, z_data_flat, x_interp, y_interp, m, n);

    // Output the interpolated value
    std::cout << "Linear interpolated value at (x, y) = (" << x_interp << ", " << y_interp << ") is " << z_interp << " with (n,m) = (" << n << "," << m << ")" << std::endl;

    return z_interp;
}

