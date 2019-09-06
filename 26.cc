#include "Includes.h"
#include "Lib.h"

#define LIMIT 1000

int main() {

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    int dividend = 1;
    int maxLen = 0;
    int maxIndex = 0;

    // Go through each divisor and keep track of the max using long division
    for (int divisor = 7; divisor < LIMIT; ++divisor) {
        map<int, int> indexes;
        int remainder = 1;
        int index = 1;
        while (remainder != 0) {
            int val = indexes[remainder];
            if (val != 0) {
                if (index - val > maxLen) {
                    maxLen = index - val;
                    maxIndex = divisor;
                }
                break;
            }
            indexes[remainder] = index;
            remainder *= 10;
            remainder %= divisor;
            ++index;
        }
    }
    cout << maxIndex << endl;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Time: " << duration << "ms" << endl;
}
