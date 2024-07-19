#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <utility>
class PrimeCalculator { // Creating a class called PrimeCalculator
public:
    PrimeCalculator(int limit) : limit_(limit) { // variable assignment through constructor faster than initializing in constructor body
    primes_.reserve(limit / 2); // Reserving space for potential prime numbers
    }
    PrimeCalculator(const PrimeCalculator& other) : limit_(other.limit_), primes_(other.primes_) {} // Deep Copy Copy Constructor
    PrimeCalculator(PrimeCalculator&& other) noexcept : limit_(other.limit_), primes_(std::move(other.primes_)) {} // Move Constructor
    ~PrimeCalculator() = default; // Destructor
    void calculatePrimes() { // Function to calculate prime numbers using an optimized algorithm
        primes_.clear();
        if (limit_ < 2) return; // If the limit is less than 2, the function returns immediately since there are no prime numbers less than 2. This is an early exit condition to optimize performance.
        primes_.push_back(2); // The number 2 is the smallest and the only even prime number, so it is directly added to the primes_ vector. This also allows the subsequent loop to only consider odd numbers.
        for (int i = 3; i <= limit_; i += 2) { // loop starting at 3 and incrementing every 2 only for odds numbers. Optimizing looping time
            if (isPrime(i)) {
                primes_.push_back(i);
            }
        }
    }
    const std::vector<int>& getPrimes() const { // This function get the primes
        return primes_;
    }
    void measureTime() {  // Function to measure the calculation time
        auto start = std::chrono::high_resolution_clock::now();
        calculatePrimes();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Time taken: " << elapsed.count()*1000 << " milliseconds\n";
        std::cout << "Number of primes found: " << primes_.size() << "\n";
     }
    void test() {
        calculatePrimes();
        std::cout << "Number of primes found: " << primes_.size() << "\n";
    }
private:
    int limit_;
    std::vector<int> primes_;
    bool isPrime(int n) const { // Optimized function to check if a number is prime
        if (n <= 1) return false; // If n is less than or equal to 1, it is not a prime number
        if (n == 2) return true; // If n is 2, it is a prime number (the smallest prime).
        if (n % 2 == 0) return false; // If n is even and not 2, it is not a prime number.
        for (int i = 3; i * i <= n; i += 2) { // start loop at 3 and check if n is divisible by any odd number i, if yes then it is not a prime number
            if (n % i == 0) return false;
        }
        return true;
    }
};
int main() {
    constexpr int limit = 50000;
    PrimeCalculator calculator(limit); // We creat a Primecalculator object and measure the time it calculates
    calculator.measureTime();
    PrimeCalculator copiedCalculator = calculator;     // Then we use the copy constructor which executes even faster
    copiedCalculator.measureTime();
    PrimeCalculator movedCalculator = std::move(calculator); // Finally the Move Semantics constructor which exhibits the fastest calculation time
    movedCalculator.measureTime(); // the time of execution is greatly optimized (code executes more faster)
 return 0;
}