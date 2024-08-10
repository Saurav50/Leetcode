class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int n1=version1.length(),n2=version2.length();
        while(i<n1&&j<n2){
            string t1="",t2="";
            while(i<n1&&version1[i]!='.'){
                t1+=version1[i];
                i++;
            }
            while(j<n2&&version2[j]!='.'){
                t2+=version2[j];
                j++;
            }
            
            int c1=stoi(t1);
          
            int c2=stoi(t2);
            
            if(c1<c2) return -1;
            else if(c1>c2) return 1;
            else {
                i++,j++;
            }


        }
        while(i<n1){
            string t1="";
            while(i<n1&&version1[i]!='.'){
                t1+=version1[i];
                i++;
            }
          
            int c1=stoi(t1);
          
            int c2=0;
            
            if(c1<c2) return -1;
            else if(c1>c2) return 1;
            else {
                i++;
            }
        }
        while(j<n2){
            string t2="";
            while(j<n2&&version2[j]!='.'){
                t2+=version2[j];
                j++;
            }
            int c1=0;
            
            int c2=stoi(t2);
          
            if(c1<c2) return -1;
            else if(c1>c2) return 1;
            else {
                j++;
            }
        }
        return 0;
        
    }
};