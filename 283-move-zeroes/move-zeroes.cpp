class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int pos = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[pos] = arr[i];
                pos++;
            }
         }

        // Fill the rest of the array with zeros
        while (pos < n) {
            arr[pos++] = 0;
        }
    }
};