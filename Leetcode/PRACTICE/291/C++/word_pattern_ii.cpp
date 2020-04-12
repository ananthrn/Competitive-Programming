// Author: ananthrn
// Solution Link: https://leetcode.com/submissions/detail/179659774/
class Solution {
public:
    
    bool helper(string &pattern, string &str, int patpos, int strpos, map<char,string> m, set<string> s) {
        //cout<<"\n\n\nSTATE:\n";
       // cout<<"pattern: " << pattern.substr(patpos)<<"\n";
        //cout<<"str: " << str.substr(strpos)<<"\n";
        if(strpos>=str.size() xor patpos>=pattern.size())
        {
            return false;
        }
        
        else if(strpos>=str.size() or patpos>=pattern.size())
        {
            return true;
        }
        
        char c = pattern[patpos];
        
        if(m.count(c))
        {
            string match = m[c];
            int j = 0;
            while(j<match.size() and j<str.size()-strpos)
            {
                if(str[strpos+j]!=match[j])
                {
                    break;
                }
                j+=1;
            }
            
            if(j==match.size())
            {
                return helper(pattern,str,patpos+1,strpos+match.size(),m,s);
            }
            else
            {
                return false;
            }
        }
        
        for(int k = strpos;k<str.size();k++)
        {
            string val = str.substr(strpos,k-strpos+1);
            if(s.count(val))
            {
                continue;
            }
            else
            {
                m[c]=val;
                s.insert(val);
                bool val = helper(pattern,str,patpos,strpos,m,s);
                if(val)
                    return true;
            }
        }
        return false;
    }
    bool wordPatternMatch(string pattern, string str) {
        map<char,string>m;
        set<string> s;
        return helper(pattern,str,0,0,m,s);
    }
};
