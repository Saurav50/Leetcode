class Solution {
public:
    void computeLPS(vector<int>& LPS,string needle){
        int i=1,len=0;
        LPS[0]=0;
        while(i<needle.length()){
            if(needle[i]==needle[len]){
                len++;
                LPS[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=LPS[len-1];
                }else{
                    LPS[i]=0;
                    i++;
                }
            }
        }
        
    }
    int strStr(string haystack, string needle) {
        int i=0,j=0;
        int n1=haystack.length(),n2=needle.length();
        if(n1<n2) return -1;
        if(haystack==needle) return 0;

        // compute pie/lps table
        vector<int> LPS(n2,0);
        computeLPS(LPS,needle);
        while(i<n1){
            if(haystack[i]==needle[j]){
                i++,j++;
            }else{
                if(j!=0) j=LPS[j-1];
                else i++;
            }
            if(j==n2) return i-j;
        }
        
        return -1;
    }
};