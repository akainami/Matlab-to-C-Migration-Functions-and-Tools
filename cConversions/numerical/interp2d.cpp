#include <iostream>
#include "interp1d.cpp"

double interp2d(const double* x_data, const double* y_data, const double* z_data, double x, double y, int m, int n) {
    // Find indices for x and y
    int idx_x = -1, idx_y = -1;
    for (int i = 0; i < m - 1; ++i) {
        if (x >= x_data[i] && x <= x_data[i + 1]) {
            idx_x = i;
            break;
        }
    }
    for (int j = 0; j < n - 1; ++j) {
        if (y >= y_data[j] && y <= y_data[j + 1]) {
            idx_y = j;
            break;
        }
    }

    // Perform interpolation along x and y dimensions
    if (idx_x != -1 && idx_y != -1) {
        double x1 = x_data[idx_x];
        double x2 = x_data[idx_x + 1];
        double y1 = y_data[idx_y];
        double y2 = y_data[idx_y + 1];

        // Calculate indices for z_data
        int index00 = idx_x * n + idx_y;
        int index01 = idx_x * n + (idx_y + 1);
        int index10 = (idx_x + 1) * n + idx_y;
        int index11 = (idx_x + 1) * n + (idx_y + 1);

        // Interpolate along x dimension
        double z_interp_x[2];
        z_interp_x[0] = z_data[index00] * (x2 - x) / (x2 - x1) + z_data[index10] * (x - x1) / (x2 - x1);
        z_interp_x[1] = z_data[index01] * (x2 - x) / (x2 - x1) + z_data[index11] * (x - x1) / (x2 - x1);

        // Interpolate along y dimension
        double z_interp = z_interp_x[0] * (y2 - y) / (y2 - y1) + z_interp_x[1] * (y - y1) / (y2 - y1);

        return z_interp;
    }

    return 0; // Default return value, ideally should not happen
}
