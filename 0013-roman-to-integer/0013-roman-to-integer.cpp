class Solution {
public:
    int romanToInt(string s) {
        int num=0,i=0;
        unordered_map<char,int> map={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        while(i<s.length()){
            if((i + 1 < s.length()) &&(
            ( s[i]=='I' && (s[i+1]=='V'||s[i+1]=='X')) ||
            ( s[i]=='X' && (s[i+1]=='L'||s[i+1]=='C')) ||
            ( s[i]=='C' && (s[i+1]=='D'||s[i+1]=='M'))

            )){
                int val=map[s[i+1]]-map[s[i]];
                num+=val;
                     i+=2;
            }else{
                int val=map[s[i]];
                num+=val;
                i++;
            }
       
        }
        return num;
        
    }
};