#include "Includes.h"
#include "Lib.h"

#define LIMIT 100

bool breakLimit(int b, int p) {
    int res = 1;
    while (p > 0) {
        res *= b;
        --p;
        if (res > LIMIT) return true;
    }
    return false;
}

int main() {

    // Create vector of vectors to store possible ones
    int unique = 0;
    vector<vector<bool> > used(LIMIT + 1);
    for (vector<vector<bool> >::iterator iter = used.begin(); iter != used.end();
            ++iter) {
        *iter = vector<bool>(LIMIT + 1);
    }

    // Let's find a better way
    // For a^b = c^d, like 4^3 = 8^2, we note that 4 and 8 have a common "base". So we 
    // go through all of the possible pairs of powers and see how to get a common base
    // that has powers of the ratio of what we currently have
    //
    // Broken since cannot dtermine whether or ont two random pairs that 
    // arise are actually of the same value... so we overestimate the
    // number of unique values 
    int counter = (LIMIT - 1) * (LIMIT - 1);
    for (int i = 2; i <= LIMIT / 2; ++i) {
        for (int j = i + 1; j <= LIMIT; ++j) {
            int n = i, d = j;
            reduceFrac(n, d);
            int num = n, dem = d;
            while (!breakLimit(2, dem)) {
                for (int k = 2; !breakLimit(k, dem); ++k) {
                    if (used[intPow(k, dem)][i] && used[intPow(k, num)][j]) continue;
                    used[intPow(k, dem)][i] = true;
                    used[intPow(k, num)][j] = true; 
                    counter--;
                }
                num += n;
                dem += d;
            }
        }
    }
    cout << counter << endl;

    // This is the stupid way of doing it...
    set<vector<pair<int, int> > > nums;
    for (int i = 2; i <= LIMIT; ++i) {
        for (int j = 2; j <= LIMIT; ++j) {
            vector<pair<int, int> > pF = pFactor(i);
            for (vector<pair<int, int>>::size_type k = 0; k < pF.size(); ++k)
                pF[k].second *= j;
            nums.insert(pF);
        }
    }
    cout << nums.size() << endl;
}
