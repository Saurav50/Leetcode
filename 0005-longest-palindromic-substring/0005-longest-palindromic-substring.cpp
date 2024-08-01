class Solution {
public:
    string longestPalindrome(string s) {
          int n = s.length();
          string ans;
          int maxL=0;
          

            for(int i=0;i<n;i++){
                int l=i, r=i;
                
                while(l>=0&&r<n&&s[l]==s[r]){
                    l--,r++;   
                }
                int len=r-l-1;
                if(len>maxL){
                    ans=s.substr(l+1,len);
                    maxL=len;
                }
            
            
  
         
                l=i, r=i+1;
                if(s[l]!=s[r]) continue;
                
                while(l>=0&&r<n&&s[l]==s[r]){
                    l--,r++;   
                }
                len=r-l-1;
                if(len>maxL){
                    ans=s.substr(l+1,len);
                    maxL=len;
                }
            }

          
          return ans;
    }
};