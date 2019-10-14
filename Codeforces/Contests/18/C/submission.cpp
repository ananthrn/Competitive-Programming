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
#define mx 1000000000
 #define f first
 #define s second
 #define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define reprev(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back

//long long dp[500001][501];
//long long a[500001]={0};
//long long c[500001]={0};


void print(vi &a)
{

    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
// Submission Link: https://codeforces.com/contest/18/submission/12675988
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> a(n,0),pre(n,0);
    cin>>a[0];
    pre[0]=a[0];
    rep(i,1,n-1)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    int ctr=0;
    rep(i,0,n-2)
    {
        if(pre[i]==pre[n-1]-pre[i])
            ctr++;
    }
    cout<<ctr;
    return 0;
}
