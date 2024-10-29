#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float poisson(float lambda, int k) {
    float e_neg_lambda = expf(-lambda);
    float lambda_pow_k = powf(lambda, k);
    int factorial = 1;

    for (int i = 1; i <= k; i++) {
        factorial *= i;
    }

    return (e_neg_lambda * lambda_pow_k) / factorial;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }

    float lambda = atof(argv[1]);
    int k = atoi(argv[2]);

    float result = poisson(lambda, k);

    printf("%.6f\n", result);

    return 0;
}