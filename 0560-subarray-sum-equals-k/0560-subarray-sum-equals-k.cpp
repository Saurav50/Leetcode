class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n=a.size();
        map<int, int> preSumMap;
        preSumMap[0]=1;
        int sum=0;
        int c = 0;
        for (int i = 0; i < n; i++) {
           sum +=a[i];
            c+=preSumMap[sum-k];
            preSumMap[sum]+=1;

        }

        return c;
    }
};