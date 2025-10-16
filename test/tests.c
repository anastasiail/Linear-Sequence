#include <stdio.h>
#include "../include/formula.h"
#include "../include/tests.h"

// Тесты
void test_fibonacci() {
    printf("\n1. Последовательность Фибоначчи:\n");
    find_and_print_formula(1, 1, 1, 1);
}

void test_geometric_progression() {
    printf("\n2. Геометрическая прогрессия:\n");
    find_and_print_formula(3, -2, 1, 3);
}

void test_single_root() {
    printf("\n3. Один корень:\n");
    find_and_print_formula(2, -1, 1, 2);
}

void test_complex_roots() {
    printf("\n4. Комплексные корни:\n");
    find_and_print_formula(0, 1, 1, 0);
}

void test_negative_values() {
    printf("\n5. Отрицательные значения:\n");
    find_and_print_formula(-2, 3, 1, -2);
}

void test_zero_sequence() {
    printf("\n6. Нулевая последовательность:\n");
    find_and_print_formula(0, 0, 0, 0);
}

void test_arithmetic_progression() {
    printf("\n7. Арифметическая прогрессия:\n");
    find_and_print_formula(2, -1, 1, 3);
}

void test_edge_case_zero_b() {
    printf("\n8. b=0:\n");
    find_and_print_formula(2, 0, 1, 2);
}

void test_edge_case_zero_a_b() {
    printf("\n9. a=0, b=0:\n");
    find_and_print_formula(0, 0, 1, 0);
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