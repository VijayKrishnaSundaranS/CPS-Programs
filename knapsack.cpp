#include <iostream>
#include <vector>

using namespace std;

// Function to solve the Knapsack problem
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W, n; // Capacity of knapsack and number of items
    cout << "Enter the capacity of knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> val(n); // Values of items
    vector<int> wt(n); // Weights of items

    cout << "Enter the values and weights of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Value: ";
        cin >> val[i];
        cout << "Weight: ";
        cin >> wt[i];
    }

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}