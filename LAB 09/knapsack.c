#include <stdio.h>

#define N 4  // Number of objects

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int weights[], int profits[], int included[]) {
    int dp[N + 1][W + 1];

    // Build dp table in bottom-up manner
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w) {
                int includeProfit = profits[i - 1] + dp[i - 1][w - weights[i - 1]];
                int excludeProfit = dp[i - 1][w];
                if (includeProfit > excludeProfit) {
                    dp[i][w] = includeProfit;
                    included[i - 1] = 1; // Mark this object as included
                } else {
                    dp[i][w] = excludeProfit;
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum profit achieved
    return dp[N][W];
}

int main() {
    int weights[N];   // weights of the objects
    int profits[N];   // profits of the objects
    int W;            // capacity of the knapsack
    int included[N] = {0}; // Array to mark which objects are included (1 means included, 0 means not included)

    // Input weights and profits from the user
    printf("Enter weights of %d objects:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter profits of %d objects:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &profits[i]);
    }

    printf("Enter capacity of the knapsack:\n");
    scanf("%d", &W);

    // Calculate maximum profit and objects included
    int maxProfit = knapsack(W, weights, profits, included);

    printf("Maximum profit achievable: %d\n", maxProfit);
    printf("Weights included in the knapsack:\n");

    for (int i = 0; i < N; i++) {
        if (included[i]) {
            printf("Object %d: Weight %d\n", i + 1, weights[i]);
        }
    }

    return 0;
}
