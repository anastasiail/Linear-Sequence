#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/formula.h"

void find_and_print_formula(int a, int b, int c, int d) {
    // Характеристическое ур-ие x**2 - ax - b = 0
    double D = (double)a * a + 4.0 * b;

    // Если два различных действительных корня
    if (D > 1e-10) {
        double sqrt_D = sqrt(D);
        double r1 = ((double)a + sqrt_D) / 2.0;
        double r2 = ((double)a - sqrt_D) / 2.0;

        // Решаем систему:
        // x1 = c = C1 + C2
        // x2 = d = C1*r1 + C2*r2
        double det = r2 - r1;
        double C1, C2;
        
        if (fabs(det) > 1e-10) {
            C1 = (d - c * r2) / (r1 - r2);
            C2 = (d - c * r1) / (r2 - r1);
        } else {
            C1 = c;
            C2 = 0;
        }
        printf("\nФормула:\n");
        if (fabs(C2) < 1e-10) {
            printf("x_n = %.6f * %.6f^(n-1)\n", C1, r1);
        } else {
            printf("x_n = %.6f * %.6f^(n-1) + %.6f * %.6f^(n-1)\n", C1, r1, C2, r2);
        }
        
        // Первые несколько членов
        printf("\nПроверка:\n");
        for (int n = 1; n <= 5; n++) {
            double xn = C1 * pow(r1, n-1) + C2 * pow(r2, n-1);
            printf("x_%d = %.6f", n, xn);
            printf("\n");
        }
    }
    // Если один действительный корень
    else if (fabs(D) <= 1e-10) {
        double r = (double)a / 2.0;

        // Формула: x_n = (C1 + C2*(n-1)) * r^(n-1)
        // x1 = c = C1
        // x2 = d = (C1 + C2) * r
        double C1 = c;
        double C2;
        
        if (fabs(r) > 1e-10) {
            C2 = (double)d / r - C1;
        } else {
            // Если r = 0, то последовательность: c, d, 0, 0,..
            C2 = d;
        }

        printf("\nФормула:\n");
        printf("x_n = (%.6f + %.6f * (n-1)) * %.6f^(n-1)\n", C1, C2, r);
        
        // Первые несколько членов
        printf("\nПроверка:\n");
        for (int n = 1; n <= 5; n++) {
            double xn = (C1 + C2 * (n-1)) * pow(r, n-1);
            printf("x_%d = %.6f", n, xn);
            printf("\n");
        }
    }
    // Если комплексные корни
    else {
        double real_part = a / 2.0;
        double imag_part = sqrt(-D) / 2.0;

        // Модуль и аргумент
        double R = sqrt(real_part * real_part + imag_part * imag_part);
        double theta = atan2(imag_part, real_part);

        printf("Модуль R = %.6f, аргумент θ = %.6f\n", R, theta);

        // Формула: x_n = R^(n-1) * (C1 * cos((n-1)*θ) + C2 * sin((n-1)*θ))
        // Решаем систему:
        // x1 = c = R^0 * (C1 * cos(0) + C2 * sin(0)) = C1
        // x2 = d = R^1 * (C1 * cos(θ) + C2 * sin(θ))
        double C1 = c;
        double C2;
        
        if (fabs(R * sin(theta)) > 1e-10) {
            C2 = (d / R - C1 * cos(theta)) / sin(theta);
        } else {
            C2 = 0;
        }

        printf("\nФормула:\n");
        printf("x_n = %.6f^(n-1) * (%.6f * cos((n-1)*%.6f) + %.6f * sin((n-1)*%.6f))\n", 
               R, C1, theta, C2, theta);
        
        // Проверка
        printf("\nПроверка:\n");
        for (int n = 1; n <= 5; n++) {
            double xn = pow(R, n-1) * (C1 * cos((n-1) * theta) + C2 * sin((n-1) * theta));
            printf("x_%d = %.6f", n, xn);
            printf("\n");
        }
    }
}

int main() {
    printf("Тестирование:\n\n");
    
    test_fibonacci();
    test_geometric_progression();
    test_single_root();
    test_complex_roots();
    test_negative_values();
    test_zero_sequence();
    test_arithmetic_progression();
    test_edge_case_zero_b();
    test_edge_case_zero_a_b();

    return 0;
}
