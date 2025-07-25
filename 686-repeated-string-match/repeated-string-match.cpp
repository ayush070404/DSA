class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str = a;
        int count = 1;

        while (str.size() < b.size()) {
            str += a;
            count++;
        }

        if (str.find(b) != string::npos)
            return count;

        str += a;
        count++;
        if (str.find(b) != string::npos)
            return count;

        // Otherwise, b can't be formed
        return -1;
    }
};
