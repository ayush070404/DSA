class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int length = 0;

        for (int i = 1; i < n - 1; i++) {
            // Check if current element is a peak
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int l = i - 1;
                int r = i + 1;

                // Expand left
                while (l > 0 && arr[l - 1] < arr[l]) {
                    l--;
                }

                // Expand right
                while (r < n - 1 && arr[r] > arr[r + 1]) {
                    r++;
                }

                // Update max length
                int currLen = r - l + 1;
                length = max(length, currLen);

                // Move i to r to skip checked region
                i = r;
            }
        }

        return length;
    }
};
