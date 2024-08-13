class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int maxLen=0;
        unordered_map<int,int> map;
        while(j<fruits.size()){
            map[fruits[j]]++;
            // if(map.size()<2) j++;
            if(map.size()<=2){
                int l=j-i+1;
                maxLen=max(maxLen,l);
                j++;
            }
            else if(map.size()>2){
                while(map.size()>2){
                    map[fruits[i]]--;
                    if(map[fruits[i]]==0) map.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return maxLen;
    }
};