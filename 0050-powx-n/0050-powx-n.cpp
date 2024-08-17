class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        long long modN=n;
        if(modN<0) modN=-modN;
       
        while(modN>0){
            if(modN%2==0){
                x=x*x;
                modN=modN/2;
            }
                res*=x;
                modN--;
            
        }
        if(n>0) return res;
        return 1.0/res;
        
      
    }
};