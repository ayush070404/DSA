class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char , int> map;

        for(char ch: s){
            map[ch]++;
        }

        vector<pair<char , int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b) {
        return a.second > b.second; // Descending order
        });
        string ans = "";
        for(auto &p : vec){
            for(int i = 0 ; i<p.second ; i++){
                ans.insert(ans.end(),p.first);
            }
        }
    return ans;
    }
};