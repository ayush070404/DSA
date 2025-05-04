class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case
        
        int ans = 0;
        int minPrice = prices[0]; // Track the minimum price seen so far
        
        for (int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - minPrice); // Compute max profit
            minPrice = min(minPrice, prices[i]); // Update min price
        }
        
        return ans;
    }
};
