#include "Includes.h"
#include "Lib.h"

#define LIMIT 1000

int main() {

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // For n^2 + an + b to generate consecutive primes, a and b must both be odd
    // If b is even, then n even yields a multiple of 2
    // If a is even, then n odd yields a multiple of 2
    //
    // Since we are checking n = 0, b must be positive and prime
    // First, we generate a list of primes up to LIMIT (1000)
    vector<int> primes = eratosthenes(1000);

    // Put it into a map for easy lookup for non-primes / primes
    map<int, bool> index;
    for (vector<int>::const_iterator iter = primes.begin(); iter != primes.end(); ++iter)
        index[*iter] = 1;

    int maxChain = 0, maxA = 0, maxB = 0;

    // Iterate through and test chains
    for (int b = 3; b < LIMIT; b += 2) {
        if (!index[b]) continue;
        // 2 - b to ensure odd since we're incrementing by 2
        for (int a = 2 - b; a < LIMIT; a += 2) {
            int counter = 0;
            int poly = 0;
            while (true) {
                int poly = counter * counter + a * counter + b;
                if (poly < 0) break;
                if (!isPrime(poly)) break;
                ++counter;
            }
            if (counter > maxChain) {
                maxChain = counter;
                maxA = a;
                maxB = b;
            }
        }
    }
    cout << maxA * maxB << endl;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Time: " << duration << "ms" << endl;
}
