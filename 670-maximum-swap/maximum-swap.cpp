class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num);  
        int n = num_str.size();

        for (int i = 0; i < n; ++i) {
            int ind = i;
            // Find the max digit after the current one
            for (int j = i + 1; j < n; ++j) {
                if (num_str[ind] <= num_str[j]) {
                    ind = j;
                }
            }
        
            if (ind != i && num_str[ind] != num_str[i]) {
                swap(num_str[i], num_str[ind]);
                break; 
            }
        }

        return stoi(num_str);  
    }
};
