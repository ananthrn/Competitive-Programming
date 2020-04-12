// Author: ananthrn
// Soln link: https://leetcode.com/submissions/detail/175051802/
class Solution {
public:
    long long mirror(long long n)
    {
        string val = to_string(n);
        
        int i = 0;
        int j = val.size()-1;
        
        while(i<j)
        {
            val[j]=val[i];
            i++;
            j--;
        }
        
        return stoll(val); 
    }
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        
        long long order = pow(10,n.size()/2);
        long long pal = mirror(num);
        long long small = mirror((num/order)*order-1);
        long long big = mirror((num/order+1)*order);
        
        cout<<order;
        if(pal>num)
        {
            big = min(big,pal);
        }
        else if(pal<num)
        {
            small = max(small,pal);
        }
        
        return (abs(small-num) <= abs(big-num))?to_string(small):to_string(big);
    }
};
