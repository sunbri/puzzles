#ifndef _LIB_H
#define _LIB_H

#include "Includes.h"

/** PRINTING FUNCTIONS **/

// Prints the contents of an arbitrary container
template<class Container>
void printContainer(const Container& cont) {
    for (typename Container::const_iterator iter = cont.begin(); iter != cont.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

/** MATH FUNCTIONS **/

// Finds the max of two things
template<class T>
T max(const T& left, const T& right) {
    return left > right ? left : right;
}

// Finds the min of two things
template<class T>
T min(const T& left, const T& right) {
    return left <= right ? left : right;
}

// Checks if n is prime
bool isPrime(int n);

// Returns primes up to (and including) n using the sieve of eratosthenes
vector<int> eratosthenes(int n);

// Returns the factors of n not including n - not necessarily sorted
vector<int> getFactors(int n);

// Returns the sum of factors of n including n
int sumFactors(int n);

// Returns the prime factorization of n
vector<pair<int, int> > pFactor(int n);

// Returns the factorial of n
int factorial(int n);

// Returns a^b where a, b are ints
int intPow(int a, int b);

// Divides two numbers up to n decimal places
string divide(int dividend, int divisor, int n);

// Reduces a fraction with n being numberator and d being denominator
void reduceFrac(int& n, int& d);

#endif
