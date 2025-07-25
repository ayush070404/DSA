class Solution {
public:

    long long calcTime(vector<int>&piles, int mid){
        int n = piles.size();
        long long totHour = 0;
        for(int i=0 ; i<n ; i++){
            totHour += (piles[i] + mid - 1) / mid;  // trick to simulate ceil division
        }
        return totHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int minSpeed = piles[n-1];
        
        int low = 1 , high = piles[n-1];

        while(low<= high){
            int mid = (low+high)/2;
            long long time = calcTime(piles , mid);

            if(time<= h){
                minSpeed = min(minSpeed ,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

    return minSpeed;
    }
};