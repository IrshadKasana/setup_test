#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            vector<int> stack = {i};
            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();
                visited[node] = true;
                for (int j = 0; j < n; j++) {
                    if (isConnected[node][j] == 1 && !visited[j]) {
                        stack.push_back(j);
                    }
                }
            }
        }
    }
    return provinces;
}

int main() {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    cout << countProvinces(isConnected) << endl;
    return 0;
}
