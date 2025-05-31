class Solution {
public:

    int countSwapsToSort(vector<int>& ans, vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int, int>, int>> arr(n); // {{digit_sum, value}, original_index}

        for (int i = 0; i < n; i++) {
            arr[i] = {{ans[i], nums[i]}, i};
        }

        sort(arr.begin(), arr.end()); // sort by digit sum, then by value

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i].second == i) continue;

            int cycle_length = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_length++;
            }

            if (cycle_length > 1) {
                swaps += (cycle_length - 1);
            }
        }

        return swaps;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;

            if (num == 0) sum = 0;
            else {
                while (num > 0) {
                    sum += num % 10;
                    num /= 10;
                }
            }

            ans[i] = sum;
        }

        return countSwapsToSort(ans, nums);
    }
};
