#include "Lib.h"

/** PRINT FUNCTIONS **/

/* printContainer - template */

/** MATH FUNCTIONS **/

/* max - template */
/* min - template */

/* Simple loop to see if n is prime */
bool isPrime(int n) {

    if (n < 1) throw domain_error("Prime input less than 1!");

    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;

    return true;
}

/* Uses the Sieve of Eratosthenes to calculate primes up to n */
vector<int> eratosthenes(int n) {

    // Fill array with initial values
    vector<bool> primes;
    for (int i = 0; i <= n; ++i)
        primes.push_back(true);

    // Use indices since faster - do the sieve
    for (vector<bool>::size_type i = 2; i <= sqrt(n); ++i) {
        if (primes[i]) {
            for (vector<bool>::size_type j = i*i; j <= n; j += i)
                primes[j] = false;
        }
    }

    // Get the numbers that are primes in a vector
    vector<int> nums;
    for (vector<bool>::size_type i = 2; i <= n; ++i)
        if (primes[i]) nums.push_back(i);

    return nums;
}

/* Returns all factors by iterating up to sqrt(n) and pushing in a divisor and the 
 * corresponding divisor that adds up to it */
vector<int> getFactors(int n) {

    if (n < 1) throw domain_error("Getting factors of n < 1!");

    // Very simple
    vector<int> factors;
    factors.push_back(1);
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) factors.push_back(n/i);
        }
    }
    return factors;
}

/* 
 * Uses the formula that if the prime factorization of n = p_1^a_1 * p2_a_2 * ... * p_m^a_m,
 * then the sum of the factors will be:
 * (1 + p_1 + p_2^2 + ... + p_1^a_1)* ... *(1 + p_m + p_m^2 + ... + p_m^a_m)
 * as when this is expanded every possible combination of prime factors will be multiplied 
 * together and there would be no repeats.
 *
 * The algorithm starts with 2 and divides through with it as many times as possible. Then 3
 * would go, not 4 because 4 = 2*2, then 5 would go, not 6 because 6 = 2*3 - in essence the
 * while loop will only start dividing if i is prime since if i is composite, its primes would
 * be smaller than it and already worked through in the for loop.
 *
 * In the case of p = p*i + 1, just note that it is doing the following:
 * ((i + 1)*i + 1)*i + 1 ... which when expanded yields i^3 + i^2 + i + 1 ..., the sum that we
 * want
 *
 * Finally, the last test is there if n itself is a prime number
 */
int sumFactors(int n) {

    if (n < 2) throw domain_error("Sum of factors less than 2!");

    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        int p = 1;
        while (n % i == 0) {
            p = p * i + 1;
            n /= i;
        }
        sum *= p;
    }

    if (n > 1) sum *= (n+1);
    return sum;
}

/* Returns the prime factorization */
vector<pair<int, int> >pFactor (int n) {

    if (n <= 1) throw domain_error("Prime factorization of less than 2!");

    vector<pair<int, int> > res;
    vector<int> primes = eratosthenes((int) sqrt(n));

    for (vector<int>::size_type i = 0; n > 1 && i < primes.size(); ++i) {
        int counter = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            ++counter;
        }
        if (counter > 0) {
            res.push_back(pair<int, int>(primes[i], counter));
        }
    }
    if (n > 1) res.push_back(pair<int, int>(n, 1));
    return res;
}

/* Calculates factorial recursively */
int factorial(int n) {

    if (n < 1) throw domain_error("Factorial of less than 1!");

    if (n == 1) return n;
    n *= factorial(n-1);
    return n;
}

/* Calculates a^b where a, b are ints */
int intPow(int a, int b) {

    if (a < 0 || b < 0 || (a == 0 && b == 0)) 
        throw domain_error("One of intPow() arguments less than 0! (Or both 0!)");

    int result = 1;
    for (int i = 0; i < b; ++i)
        result *= a;
    return result;
}

/* Divides dividend / divisor up to n decimal places 
 * Returns a string for accuracy */
string divide(int dividend, int divisor, int n) {

    if (dividend == 0 || divisor == 0 || n == 0) 
        throw domain_error("Divide can't take in a 0!");

    // Immediately handle case of perfect division
    if (dividend % divisor == 0) return to_string(dividend / divisor);

    string ret;
    int quotient = dividend / divisor;
    int remainder = dividend - quotient * divisor;
    ret = to_string(quotient) + ".";
    
    for (int i = 0; i < n; ++i) {
        remainder *= 10;
        quotient = remainder / divisor;
        ret += to_string(quotient);
        remainder -= quotient * divisor;
    }
    return ret;
}

/* Reduces a fraction */
void reduceFrac(int& n, int& d) {
    int small = min(n, d);
    for (int i = 2; i <= small; ++i) {
        while (n % i == 0 && d % i == 0) {
            n /= i;
            d /= i;
        }
    }
}
