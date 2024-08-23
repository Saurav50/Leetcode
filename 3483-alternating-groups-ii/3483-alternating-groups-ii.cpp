class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i=0,j=0,n=colors.size();
        map<int,int> map;
        int c=j;
        bool isAlternative=true;
        int idx=-1;
        int count=0;
        while(i<n){
            map[colors[j]]++;
            if(c-i+1<k){
                if (j != i && j != 0 && (colors[j] == colors[j-1] )) {
                    isAlternative = false;
                    idx = j;
                }
                j = (j + 1) % n;
                c++;
            }
            else if(c-i+1==k){
                if (j != i && j != 0 && colors[j] == colors[j - 1]) {
                    isAlternative = false;
                    idx = j;
                }
                if(j==0&&i>j&&colors[j] == colors[n-1]){
                    isAlternative = false;
                    idx = n+j;
                }
                if(j!=0&&i>j&&colors[j] == colors[j-1]){
                    isAlternative = false;
                    idx = n+j;
                }
                if(map.find(0)!=map.end()&&map.find(1)!=map.end()){
                    if(k%2==0&&map[0]==map[1]){
                        // check for alternative
                        if(isAlternative) count++;
                    }else if(k%2!=0&&((map[0]==map[1]+1)||(map[1]==map[0]+1))){
                        // check for consecutive
                         if(isAlternative) count++;
                    }
                }
                    // Slide the window
                    map[colors[i]]--;
                    if (map[colors[i]] == 0) map.erase(colors[i]);
                    i++;
                    j = (j + 1) % n;
                    c++;
                    
                    // Reset isAlternative if idx is not within the current window
                   
                    if (idx <= i) {
                        
                        isAlternative = true;
                    }
                
            }
        }
        return count;
    }
};