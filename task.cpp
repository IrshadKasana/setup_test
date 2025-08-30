#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>

int main() {
    int len;
    cin >> len;
    vector<char> tasks(len);
    for (int i = 0; i < len; i++) {
        cin >> tasks[i];
    }
    int n;
    cin >> n;

    // Frequency of tasks
    vector<int> freq(26, 0);
    for (char task : tasks) {
        freq[task - 'A']++;
    }

    // Find max frequency
    int maxFreq = *max_element(freq.begin(), freq.end());

    // Count how many tasks have max frequency
    int maxCount = count(freq.begin(), freq.end(), maxFreq);

    // Calculate result using formula
    int part1 = (maxFreq - 1) * (n + 1) + maxCount;
    int result = max((int)tasks.size(), part1);

    cout << result << endl;
    return 0;
}

