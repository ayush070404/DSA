class Solution {
public:
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;

        for (int num : a) s.insert(num);
        for (int num : b) s.insert(num);

        return s.size();
    }
};
