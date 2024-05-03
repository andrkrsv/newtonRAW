#include <iostream>
#include <cmath>

using namespace std;

double f1(double x, double y) {
    return x * x + y * y - 5;
}

double f2(double x, double y) {
    return x - y - 1;
}

double f1_x(double x, double y) {
    return 2 * x;
}

double f1_y(double x, double y) {
    return 2 * y;
}

double f2_x(double x, double y) {
    return 1;
}

double f2_y(double x, double y) {
    return -1;
}

// Решение СЛАУ методом Ньютона-Рафсона
void solve_SLAE_NR(double x0, double y0, double eps) {
    for (int i = 0; i < 100; ++i) {
        double det = f1_x(x0, y0) * f2_y(x0, y0) - f1_y(x0, y0) * f2_x(x0, y0);

        double delta_x = (f2(x0, y0) * f1_y(x0, y0) - f1(x0, y0) * f2_y(x0, y0)) / det;
        double delta_y = (f1(x0, y0) * f2_x(x0, y0) - f2(x0, y0) * f1_x(x0, y0)) / det;

        x0 += delta_x;
        y0 += delta_y;

        if (abs(delta_x) < eps && abs(delta_y) < eps) {
            break;
        }
    }

    cout << "x = " << x0 << ", y = " << y0 << endl;
}
