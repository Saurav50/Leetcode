class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minRepatationReq=b.length()/a.length();
        // repeat 'a'
        int k=0;
        string na="";
        while(k<minRepatationReq) na+=a,k++;
        cout<<a;

        // check if b in founded in a;
        if(na.find(b)!=string::npos) return minRepatationReq==0? 1:minRepatationReq;
        // add suffix or prefix;
        na+=a;
        // now check if b is found
        if(na.find(b)!=string::npos) return minRepatationReq+1;
        // add prefix/suffix;
        na+=a;
        if(na.find(b)!=string::npos) return minRepatationReq+2;

        return -1;
        
    }
};