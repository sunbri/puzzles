#include "Includes.h"
#include "Lib.h"

#define DIGITS 10
#define LIMIT  1000000

int getNth(const vector<bool>& vec, int n) {
    int result = 0;
    for (vector<bool>::size_type i = 0; n > 0; ++i) {
        if (!vec[i]) n--;
        if (n == 0) result = i;
    }
    return result;
}

int main() {

    // Available digits to choose from
    vector<bool> digits(10);

    // storage = how many permutations we have "left"
    int storage = LIMIT;
    long result = 0;

    // Iterate through all digits - adding numbers based on how many factorials still fit
    // into storage
    for (int i = DIGITS; i > 0; --i) {
        long fact = factorial(i);
        int count = 0;
        while (storage > fact && count < 10) {
            storage -= fact;
            count++;
        }
        int index = getNth(digits, count);
        result += index * intPow(10, i);
        digits[index] = true;
    }
    cout << result << endl;
}
