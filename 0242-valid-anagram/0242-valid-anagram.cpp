class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> m1;
        for(int i=0;i<s.length();i++){
            if(m1.find(s[i])!=m1.end()){
                m1[s[i]]+=1;
            }else{
                m1[s[i]]=1;
            }
        }
        unordered_map<char,int> m2;
        for(int i=0;i<t.length();i++){
            if(m2.find(t[i])!=m2.end()){
                m2[t[i]]+=1;
            }else{
                m2[t[i]]=1;
            }
        }
        bool check =true;
        for(auto it=m1.begin();it!=m1.end();it++){
            if(m2.find(it->first)!=m2.end()){
                if(it->second!=m2[it->first]){
                    check=false;
                    break;
                }

            }else{
                    check=false;
                    break;
            }
        }

        return check;
    }
};