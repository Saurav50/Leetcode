class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.length();
        while(i<n&&s[i]==' ') i++;
        bool isNegative=false;
        if(s[i]=='-'){
            isNegative=true;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        while(i<n&&s[i]=='0') i++;
        if(!isdigit(s[i])) return 0;
        string ans="";
        ans+=s[i];
        i++;
        while(i<n&&isdigit(s[i])){
            ans+=s[i];
            i++;
        };
        
        int p=ans.length()-1;
        long long num=0;
       #include <unordered_map>

unordered_map<char, int> map = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9}
};

        for(int i=0;i<ans.length();i++){
             if (isNegative && -(num+(ans[i]-'0')*(pow(10,p))) < INT_MIN) return INT_MIN;
             if (!isNegative && (num+(ans[i]-'0')*(pow(10,p))) > INT_MAX) return INT_MAX;
            num+=(ans[i]-'0')*(pow(10,p));
            p--;
        }
       
       return isNegative ? -num : num;


    }
};