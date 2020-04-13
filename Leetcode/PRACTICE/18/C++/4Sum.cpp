// Author: ananthrn
// Soln Link: https://leetcode.com/submissions/detail/175033841/
class Solution {
public:
    vector<vector <int> > helperSum(vector<int>& nums, int target, int start, int vals){
        if(vals==1){
            return {};
        }
        else if(vals == 2){
            if(start == nums.size())
                return {};
            
            int i = start;
            int j = nums.size()-1;
            vector< vector<int> > ans;
            
            while(i<j)
            {   
                int sum = nums[i] + nums[j];
                
                if(sum == target)
                {
                    ans.push_back({nums[i],nums[j]});
                    
                    i++;
                    while(i<j and nums[i]==nums[i-1])
                    {
                        i++;
                    }
                    
                    j--;
                    
                    while(i<j and nums[j]==nums[j+1])
                    {
                        j--;
                    }
                }
                else if (sum < target)
                {
                     i++;
                    while(i<j and nums[i]==nums[i-1])
                    {
                        i++;
                    }
                }
                else
                {
                     j--;
                    
                    while(i<j and nums[j]==nums[j+1])
                    {
                        j--;
                    }
                }
            }
            
            return ans;
        }
        else {
            
            if(start == nums.size())
                return {};
            vector< vector<int> > ans;
            
            for(int i = start;i<nums.size();i++)
            {
                if(i==start or nums[i]!=nums[i-1])
                {
                    vector< vector<int> > ans2 = helperSum(nums,target-nums[i],i+1,vals-1);
                    
                    for(auto v: ans2)
                    {
                        vector<int> toAdd = v;
                        toAdd.push_back(nums[i]);
                        ans.push_back(toAdd);
                    }
                }
            }
            
            return ans;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return helperSum(nums,target,0,4);
    }
};
