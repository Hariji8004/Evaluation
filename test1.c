#include <stdio.h>

void print_polynomial(int coefficients[], int degree) {
    int first_term = 1;
    for (int i = degree; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (!first_term) {
                if (coefficients[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            }
            if (i == 0 || coefficients[i] != 1) {
                printf("%d", abs(coefficients[i]));
            }
            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }
            first_term = 0;
        }
    }
    if (first_term) {
        printf("0");
    }
    printf("\n");
}

void compute_derivative(int coefficients[], int degree, int derivative[]) {
    for (int i = 0; i < degree; ++i) {
        derivative[i] = coefficients[i + 1] * (i + 1);
    }
}

int main() {
    int coefficients[6] = {0};
    int derivative[5] = {0};
    int degree;

    printf("Enter the degree of the polynomial (0 to 5): ");
    scanf("%d", &degree);

    if (degree < 0 || degree > 5) {
        printf("Invalid degree. Please enter a number between 0 and 5.\n");
        return 1;
    }

    printf("Enter the coefficients from the constant term to the highest degree term:\n");
    for (int i = 0; i <= degree; ++i) {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &coefficients[i]);
    }

    compute_derivative(coefficients, degree, derivative);

    printf("The derivative of the polynomial is:\n");
    print_polynomial(derivative, degree - 1);

    return 0;
}
