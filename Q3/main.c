#include <stdio.h>
#include <stdlib.h>
#include "poisson.h"

int main() {
    int k_values[] = {1, 10, 2, 3, 3};
    float lambda_values[] = {2.0, 2.0, 2.0, 3.0, 100.0};

    for (int i = 0; i < 5; i++) {
        float result = poisson(lambda_values[i], k_values[i]);
        printf("P(X = %d | λ = %.1f) = %.6f\n", k_values[i], lambda_values[i], result);
    }

    return 0;
}
