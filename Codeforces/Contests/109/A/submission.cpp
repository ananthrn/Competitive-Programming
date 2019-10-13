#include<bits/stdc++.h>
using namespace std;
 typedef pair<int,int> pii;
 typedef long long ll;
 typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define mod 1000000007
 #define f first
 #define s second
 #define rep(i,a,b) for(long long i=a;i<=b;i++)
#define reprev(i,a,b) for(long long i=a;i>=b;i--)
#define mp make_pair
#define pb push_back


//long long dp[500001][501];
//long long a[500001]={0};
//long long c[500001]={0};
// Submission Link: https://codeforces.com/contest/109/submission/12549876
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    bool chk = false;
    int mn = INT_MAX;
    int mn_b =0;
    int mn_a = 0;
    for(int b = 0;b<=(n/7);b++)
    {
        if((n-b*7)>=0 && (n-b*7)%4==0)
        {   chk=true;
            int a = (n-b*7)/4;
            if((a+b) < mn)
            {
                mn = a+b;
                mn_b = b;
                mn_a = a;
            }

        }
    }

    if(chk)
    {
        string an;
        an =string(mn_a,'4')+ string(mn_b,'7');
        cout<<an;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}
