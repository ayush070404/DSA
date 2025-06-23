class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());  // Required for adjacent difference

        int minDiff = INT_MAX;

        // First Pass: Find minimum absolute difference
        for (int i = 1; i < arr.size(); i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> result;

        // Second Pass: Collect pairs with that difference
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        return result;
    }
};
