class Solution {
public:
    const int mod = 1e9 + 7;

    // Function to compute Previous Less Element indices
    vector<int> computePLE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ple(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ple;
    }

    // Function to compute Next Less Element indices
    vector<int> computeNLE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nle(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nle;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple = computePLE(arr);
        vector<int> nle = computeNLE(arr);

        long long result = 0;

        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            result = (result + arr[i] * left % mod * right % mod) % mod;
        }

        return result;
    }
};
