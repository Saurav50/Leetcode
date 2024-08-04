class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0;
        int n1=haystack.length(),n2=needle.length();
        if(n1<n2) return -1;
        if(n1==n2&&haystack==needle) return 0;
        for(int i=0;i<n1-n2+1;i++){
            // string temp="";
            for(int j=0;j<n2;j++){
                // temp+=haystack[i+j];
                if(haystack[i+j]!=needle[j]) break;
                if(j==n2-1) return i;
            }
            // if(temp==needle) return i;

        }
        return -1;
    }
};