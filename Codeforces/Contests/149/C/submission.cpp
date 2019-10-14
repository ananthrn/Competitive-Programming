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
 #define rep(i,a,b) for(long long i=(a);i<=(b);i++)
#define reprev(i,a,b) for(long long i=(a);i>=(b);i--)
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
// Submission Link: https://codeforces.com/contest/149/submission/12636299
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pii> a(n);
    rep(i,0,n-1)
    {
        cin>>a[i].f;
        a[i].s=i+1;
    }
    sort(a.begin(),a.end());

    vi x,y;
    rep(i,0,n-1)
    {
        if(i%2==0)
            x.pb(a[i].s);
        else
            y.pb(a[i].s);
    }
    cout<<x.size()<<"\n";
    print(x);
    cout<<y.size()<<"\n";
    print(y);
    return 0;
}
 
