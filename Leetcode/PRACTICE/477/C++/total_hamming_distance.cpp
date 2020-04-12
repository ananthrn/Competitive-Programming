// Author: Ananth Ravi Narayan, @ananthrn
// Problem Link: https://leetcode.com/problems/total-hamming-distance/
class Solution {
public:
    int numOnes(int num){
        int cnt = 0;
        while(num!=0){
            cnt+=num&1;
            num>>=1;
        }
        return cnt;
    }
    int computeHamming(int a, int b){
        return numOnes(a^b);
    }
    int totalHammingDistance(vector<int>& nums) {
        if(nums.empty() or nums.size()==1)
            return 0;
        int ans = 0;
        vector<int> zeroOne(2,0);
        for(int i=1; i<=32;i++){
            zeroOne[0]=0;
            zeroOne[1]=0;
            for(int &n:nums){
                zeroOne[n%2]++;
                n>>=1;
            }
        ans+=zeroOne[0]*zeroOne[1];
        }
        
    return ans;
    }
};
