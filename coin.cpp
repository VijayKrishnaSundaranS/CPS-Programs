#include <iostream>

#include <vector>

#include <climits>


using namespace std;


vector<int> coinChange(vector<int>& coins, int amount, int& totalMinCoins) {

	vector<int> dp(amount + 1, INT_MAX - 1);

	vector<vector<int>> combinations(amount + 1, vector<int>(coins.size(), 0));

	dp[0] = 0;


	for (int i = 1; i <= amount; ++i) {

    	for (int j = 0; j < coins.size(); ++j) {

        	if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i]) {

            	dp[i] = dp[i - coins[j]] + 1;

            	combinations[i] = combinations[i - coins[j]];

            	combinations[i][j]++;

        	}

    	}

	}


	// Calculate total minimum coins used

	totalMinCoins = 0;

	for (int count : combinations[amount]) {

    	totalMinCoins += count;

	}


	return combinations[amount];

}


int main() {

	vector<int> coins = {1, 5, 10, 25};

	int amount = 38;


	int totalMinCoins = 0;

	vector<int> minCoins = coinChange(coins, amount, totalMinCoins);


	cout << "Combination of coins used: ";

	for (int i = 0; i < coins.size(); ++i) {

    	if (minCoins[i] > 0) {

        	cout << coins[i] << " used " << minCoins[i] << " times. ";

    	}

	}

	cout << endl;


	cout << "Total minimum coins used: " << totalMinCoins << endl;


	return 0;

}