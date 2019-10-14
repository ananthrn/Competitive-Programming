#include<bits/stdc++.h>
using namespace std;
 typedef pair<int,int> pii;
 typedef pair<char,char> pcc;
 typedef long long ll;
 typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef tuple<int,int,int> tiii;
#define mod 1000000007
#define mx 10000000
 #define f first
 #define s second
 #define rep(i,a,b) for(long long i=a;i<=b;i++)
#define reprev(i,a,b) for(long long i=a;i>=b;i--)
#define mp make_pair
#define pb push_back

//long long dp[500001][501];
//long long a[500001]={0};
//long long c[500001]={0};
vector<bool> pr(mx+1,true);
vector<ll> f(mx+1,0);
vector<ll> cnt(mx+1,0);
vector<ll> pre(mx+1,0);

void mod_sieve()
{
    pr[0]=false;
    pr[1]=false;
    rep(i,2,mx)
    {

        if(pr[i])
        {
            for(ll j=i;j<=mx;j+=i)
            {   pr[j]=false;
                f[i]+=cnt[j];
            }
        }
        pre[i]=pre[i-1]+f[i];
    }
}

// Submission Link: https://codeforces.com/contest/137/submission/12629702
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n;
    vector<pll> a(n);
    vector<ll> max_b(n);
    rep(i,0,n-1)
        cin>>a[i].f>>a[i].s;
    sort(a.begin(),a.end());
    max_b[0] = a[0].s;
    rep(i,1,n-1)
    {
        max_b[i]=max(max_b[i-1],a[i].s);
    }
    int ctr=0;
    rep(i,1,n-1)
    {
        if(a[i].s<max_b[i])
            ctr++;
    }
    cout<<ctr;
    return 0;
}
