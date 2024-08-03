class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int k=INT_MAX;
        string minS="";
        for(int i=0;i<strs.size();i++){
            int len=0;
            if(strs[i].length()<k){
                minS=strs[i];
                k=strs[i].length();
            }

        }

        for(int i=0;i<strs.size();i++){
            string subStr=strs[i].substr(0,k);
            while(minS!=subStr){
                k--;
                minS=minS.substr(0,k);
                subStr=strs[i].substr(0,k);
            }

        }
        return minS;

        
    }
};