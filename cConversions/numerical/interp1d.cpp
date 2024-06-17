#include <iostream>

double interp1d(const double* x_data, const double* y_data, double x_interp, int n) {
    if (x_interp <= x_data[0])
        return y_data[0];
    if (x_interp >= x_data[n - 1])
        return y_data[n - 1];

    for (int i = 0; i < n - 1; ++i) {
        if (x_interp >= x_data[i] && x_interp <= x_data[i + 1]) {
            double t = (x_interp - x_data[i]) / (x_data[i + 1] - x_data[i]);
            return y_data[i] * (1 - t) + y_data[i + 1] * t;
        }
    }

    return 0; 
}
