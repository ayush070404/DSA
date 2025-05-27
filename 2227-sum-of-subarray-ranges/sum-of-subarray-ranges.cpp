class Solution {
public:
    // Previous Less Element
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

    // Next Less Element
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

    // Previous Greater Element
    vector<int> computePGE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    // Next Greater Element
    vector<int> computeNGE(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ple = computePLE(arr);
        vector<int> nle = computeNLE(arr);

        long long resultMin = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            resultMin += (long long)arr[i] * left * right;
        }
        return resultMin;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge = computePGE(arr);
        vector<int> nge = computeNGE(arr);

        long long resultMax = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            resultMax += (long long)arr[i] * left * right;
        }
        return resultMax;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
