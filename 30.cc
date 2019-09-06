#include "Includes.h"
#include "Lib.h"

int main() {

    int max = 1000000; // too small for millions as 9^5 * 7 is still in hundred thousands
    int total = 0;
    for (int i = 2; i < max; ++i) {
        string num = to_string(i);
        int sum = 0;
        for (int j = 0; j < num.size(); ++j)
            sum += intPow(num[j] - '0', 5);
        if (sum == i) total += sum;
    }
    cout << total << endl;
}
