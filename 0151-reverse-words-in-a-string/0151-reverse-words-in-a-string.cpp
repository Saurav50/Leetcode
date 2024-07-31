class Solution {
public:
    string reverseWords(string s) {
            // reverse and add to ans string
            string ans="";
            int i=0,N=s.length();
            while(i<N){
                while(i<N&&s[i]==' ') i++;
                if (i >= N) break;
                int j=i+1;
                while(j<N&&s[j]!=' ') j++;
                
               string w=s.substr(i,j-i);
                if(ans.length()>0) ans=w+" "+ans;
                else ans+=w;
                i=j+1;
            }
          
         return ans;
        
    }
};
    
