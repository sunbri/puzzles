#include "Includes.h"
#include "Lib.h"

int main() {

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // Stores the numbers
    vector<vector<int> > triangle;

    // Read file line by line into the vector
    ifstream infile("67.txt");
    string input;
    int line = 0;
    while (getline(infile, input)) {
        // Create a new container for each line
        triangle.push_back(vector<int>());
        // Get the input stream for a string and read the integers until it fails
        int num;
        istringstream iss(input);
        while (iss >> num)
            triangle[line].push_back(num);
        line++;
    }

    // Dynamic programming esque solver - uses indexes instead of iterators for ease
    // just adds and keeps track of the max each time - goes from bottom up
    for (vector<vector<int> >::size_type i = triangle.size() - 1; i > 0; --i) {
        int p_size = triangle[i-1].size();
        for (vector<int>::size_type j = 0; j != p_size; ++j)
            triangle[i-1][j] += max(triangle[i][j], triangle[i][j+1]);
    }

    // Print the solution
    cout << triangle[0][0] << endl;

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    cout << "Time: " << duration << "ms" << endl;
}
