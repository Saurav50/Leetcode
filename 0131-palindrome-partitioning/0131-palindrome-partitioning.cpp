class Solution {
public:
    bool isPalindrome(string s){
        string r=s;
        reverse(r.begin(),r.end());
        return r==s;
    }
    void partitionCall(string s, int idx,int n,vector<string>& v,vector<vector<string>>& res){
        if(idx==n){
            res.push_back(v);
            return ;
        }
        for(int i=idx;i<n;i++){
            string sub=s.substr(idx,i-idx+1);
            if(isPalindrome(sub)){
               
                v.push_back(sub);
                partitionCall(s,i+1,n,v,res);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> res;
        partitionCall(s,0,s.length(),v,res);
        return res;
    }

};