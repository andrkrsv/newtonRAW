#include <iostream>
#include <cmath>
#include <vector>

auto f(const std::vector<double>& x) {
    return std::vector<double>{
        std::sin(x[1]) - 2 * x[0] - 1,
        std::cos(x[0] + 0.5) - x[1] - 2
    };
}

auto jacobian(const std::vector<double>& x) {
    return std::vector<std::vector<double>>{
        {-std::sin(2*x[0] + 1), 1},
        {2, std::cos(x[1])}
    };
}

auto newton_raphson(const std::vector<double>& x, double eps) {
    std::vector<double> result = x;
    std::vector<double> delta_x(x.size());
    do {
        auto fx = f(result);
        auto J = jacobian(result);

        double det_inv = 1.0 / (J[0][0] * J[1][1] - J[0][1] * J[1][0]);
        std::vector<std::vector<double>> J_inv{
            {J[1][1] * det_inv, -J[0][1] * det_inv},
            {-J[1][0] * det_inv, J[0][0] * det_inv}
        };

        delta_x[0] = J_inv[0][0] * fx[0] + J_inv[0][1] * fx[1];
        delta_x[1] = J_inv[1][0] * fx[0] + J_inv[1][1] * fx[1];

        result[0] -= delta_x[0];
        result[1] -= delta_x[1];
    } while (std::sqrt(delta_x[0] * delta_x[0] + delta_x[1] * delta_x[1]) < eps);
    return result;
}

int main() {
    double eps = 1e-4;
    std::vector<double> x{0.0, 0.0};
    auto result = newton_raphson(x, eps);
    std::cout << "Solution: " << "\n" << result[0] << "\n" << result[1] << "\n";
    return 0;
}

