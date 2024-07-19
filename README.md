By Gnoitik Loic Vanes
This is a course assignment whereby we had to optmize a sample c++ code, and make it more efficient.
The example i used was a prime calculator use case, which a native implementation and later an optimized implementation
to improve on the time complexity. I applied most of the concepts i was taught in class, such as OOP, ....

Explanation of Project:
1. Naive Implementation: The naive implementation calculates prime numbers up to a given limit using a simple loop and checks for primality.
2. Optimized Implementation:
    - PrimeCalculator Class: Contains the constructor, copy constructor, move constructor, destructor, and functions to calculate primes.
    - Optimized Prime Calculation: The isPrime function is optimized to check divisibility only up to the square root of n and skips even numbers.
    - Time Measurement: Measures the time taken for prime calculation using std::chrono.
    - Deep Copy and Move Semantics: Demonstrates deep copy with the copy constructor and move semantics with the move constructor.

By comparing the naive and optimized versions, the performance gains can be illustrated. The optimized version with OOP concepts provides a more efficient and scalable solution for calculating prime numbers.
