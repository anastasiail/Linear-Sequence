#include <stdio.h>
#include "../include/formula.h"

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