#include <stdio.h>
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
