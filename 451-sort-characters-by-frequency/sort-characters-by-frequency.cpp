class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Create buckets: index = frequency
        vector<vector<char>> buckets(s.size() + 1);
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);  // character p.first appears p.second times
        }

        // Step 3: Build result from buckets (from high to low freq)
        string result = "";
        for (int i = s.size(); i >= 1; --i) {
            for (char c : buckets[i]) {
                result += string(i, c);  // append 'c' i times
            }
        }

        return result;
    }
};
