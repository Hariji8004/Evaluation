#include <iostream>
#include <vector>

void sieve_of_eratosthenes(int n) {
    // Create a boolean array and initialize all entries as true.
    std::vector<bool> is_prime(n + 1, true);

    // 0 and 1 are not primes.
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    // Implement Sieve of Eratosthenes
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    // Output all prime numbers
    std::cout << "Prime numbers up to " << n << " are: ";
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int number;

    // Input from user
    std::cout << "Enter an integer: ";
    std::cin >> number;

    if (number < 2) {
        std::cout << "There are no prime numbers less than 2." << std::endl;
    } else {
        sieve_of_eratosthenes(number);
    }

    return 0;
}
