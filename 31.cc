#include "Includes.h"
#include "Lib.h"

#define LIMIT 200

// Disgusting backtracking solution
void backtrack(int total, int goal, int& counter) {

    static vector<int> possibleCoins { 1, 2, 5, 10, 20, 50, 100, 200 };
    static vector<int> results;

    if (total >= goal) {
        if (total == goal)
            counter++;
        return;
    }

    for (vector<int>::const_iterator iter = possibleCoins.begin();
            iter != possibleCoins.end(); ++iter) {
        bool flag = false;
        if (!results.empty()) {
            for (vector<int>::const_iterator iter2 = results.begin(); iter2 != results.end();
                    ++iter2)
                if (*iter2 > *iter) flag = true;
        }
        if (flag) continue;
        total += *iter;
        results.push_back(*iter);
        backtrack(total, goal, counter);
        results.pop_back();
        total -= *iter;
    }
}

// Elegant AF dynamic programming solution
int dynamic(int n) {

    vector<int> possibleCoins { 1, 2, 5, 10, 20, 50, 100, 200 };
    vector<int> results(n + 1);
    results[0] = 1;

    // Key here is that each coin is first used and then the next one is looped through
    // so that there is no way you end up with the same solution twice
    for (auto coin : possibleCoins) {
        for (int i = coin; i <= n; ++i)
            results[i] += results[i - coin];
    }
    return results[n];
}
int main() {
    cout << dynamic(LIMIT) << endl;
}
