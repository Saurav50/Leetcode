class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // DONT STORE WHOLE MERGED ARRAY JUST PLAY WITH POINTERS
        int i=0,j=0;
        int countIdx=0;
        int n=nums1.size()+nums2.size();
        int idx1=n/2-1;
        int idx2=n/2;
        int ele1=-1,ele2=-1;
        
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(countIdx==idx1) ele1=nums1[i];
                if(countIdx==idx2) ele2=nums1[i];
                countIdx++;
                i++;
            }else{
                if(countIdx==idx1) ele1=nums2[j];
                if(countIdx==idx2) ele2=nums2[j];
                countIdx++;
                j++;
            }
        }
        while(i<nums1.size()){
             if(countIdx==idx1) ele1=nums1[i];
                if(countIdx==idx2) ele2=nums1[i];
                countIdx++;
                i++;
        }
        while(j<nums2.size()){
            if(countIdx==idx1) ele1=nums2[j];
                if(countIdx==idx2) ele2=nums2[j];
                countIdx++;
                j++;
        }
        if(n%2==0) return (double)(ele1+ele2)/(double)2;
        return ele2;
        
        
        
    }
};