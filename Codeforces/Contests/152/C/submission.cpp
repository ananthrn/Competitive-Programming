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
// Submission Link: https://codeforces.com/contest/152/submission/12548662
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<string> bk(n,"");
    vector<int> cnt(m,0);
    for(int i=0;i<n;i++)
    {
        cin>>bk[i];
    }
    ll ans = 1;
    for(int i=0;i<m;i++)
    {
        vector<bool> seen(26,false);
        for(int j=0;j<n;j++)
        {
            if(!seen[bk[j][i]-'A'])
            {
                seen[bk[j][i]-'A']= true;
                cnt[i]++;
            }
        }
        ans = (ans*cnt[i])%mod;
    }
    cout<<ans;
    return 0;
}
