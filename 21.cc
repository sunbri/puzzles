#include "Includes.h"
#include "Lib.h"

#define LIMIT 10000

int main() {
    // Looking for amicable numbers under 10000
    int n = LIMIT;
    long total = 0;

    // Storage for if number has been hit
    vector<bool> amicable(LIMIT + 1);

    // Loop through and search for amicable numbers 
    for (int i = 2; i <= LIMIT; ++i) {
        // Don't check if already hit
        if (amicable[i]) continue;

        // Check if i is amicable and if it has an amicable match
        int sumI = sumFactors(i) - i;
        int sumSum = sumFactors(sumI) - sumI;

        // Both of these numbers have been hit
        amicable[i] = amicable[sumI] = true;

        // Add the sum - make sure it's not the same number
        if ((i == sumSum) && (sumI != sumSum))
            total += sumI + i;
    }

    cout << total << endl;
    return 0;
}
