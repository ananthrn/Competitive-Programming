// Author: ananthrn
// Solution Link: https://leetcode.com/submissions/detail/175056400/
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        
        vector<int> sum(m+n,0);
        
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int pos = i + j + 1;
                
                int val = (int)(num1[i]-'0') *( int)(num2[j]-'0');
                sum[pos]+=val;
                
            }
        }
        int carry = 0;
        for(int pos = m+n-1;pos>=0;pos--)
        {
            int vl = sum[pos] + carry;
            
            sum[pos] = vl%10;
             carry = vl/10;
        
        }
        
        string ans;
        
        for(int pos = 0;pos<m+n;pos++)
        {
            ans = ans +(char)(sum[pos]+'0');
        }
        int i = 0;
        while(i<ans.size() and ans[i]=='0')
            i++;
        
        if(i==ans.size())
            return "0";
        return ans.substr(i);
            
    }
};
