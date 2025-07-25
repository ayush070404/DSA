class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        int totalWater = 0;
        for (int i = 1; i < n; i++) {
            int leftmax = prefixMax[i], rightmax = suffixMax[i];
            if(height[i]< leftmax && height[i]<rightmax){
                totalWater += min(leftmax, rightmax) - height[i];
            }
        }

        return totalWater;
    }
};
