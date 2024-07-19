#include <iostream>
#include <vector>
#include <chrono>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Naive function to calculate prime numbers up to a given limit
std::vector<int> calculatePrimes(int limit) {
    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int limit = 50000;

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> primes = calculatePrimes(limit);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count()*1000 << " milliseconds\n";
    std::cout << "Number of primes found: " << primes.size() << "\n";

    return 0;
}
