// Author: ananthrn
// Soln Link: https://leetcode.com/submissions/detail/175037563/
class Solution {
public:
    map<string,bool> dp;
    
    bool isPref(string a, string b)
    {   
        if(b.size()>a.size())
            return false;
        
        int minLen = b.size();
        
        for(int i = 0;i<minLen;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    
    bool helper(string s, vector<string> & wordDict){
        if(s.empty())
            return true;
        
        if(dp.count(s))
            return dp[s];
        
        dp[s] = false;
        for(auto word: wordDict)
        {
            bool pref = isPref(s,word);
            
            if(pref)
            {   
           
                bool check = helper(s.substr(word.size()),wordDict);
                if(check)
                {
                    dp[s] = true;
                    break;
                }
            }
        }
        
        return dp[s];
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s,wordDict);
    }
};
