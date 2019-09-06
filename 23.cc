#include "Includes.h"
#include "Lib.h"

#define LIMIT 28123

int main() {
    // Stores the status of abundancy of the number
    vector<bool> nums(2 * LIMIT + 1);

    // 12 given to us as smallest abundant number
    vector<int> abundants;
    for (int i = 12; i < LIMIT + 1; ++i) {
        // Since sumFactors returns with the actual number summed
        if (sumFactors(i) > i + i) {
            abundants.push_back(i);
            for (vector<int>::const_iterator iter = abundants.begin();
                    iter != abundants.end(); ++iter) {
                vector<bool>::size_type index = i + *iter;
                nums[index] = true;
            }
        }
    }

    long total = 0;
    for (vector<bool>::size_type i = 1; i < LIMIT + 1; ++i)
        if (!nums[i]) total += i;

    cout << total << endl;
}
