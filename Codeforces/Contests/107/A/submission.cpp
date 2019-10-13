 
#include<bits/stdc++.h>
using namespace std;
 typedef pair<int,int> pii;
 typedef pair<char,char> pcc;
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<int> vi;
typedef tuple<int,int,int> tiii;
#define mod 1000000009
#define mx9 1000000000
#define mx10 10000000000
#define mx5 100000
#define mx7 10000000
#define mx6 1000000
#define mx6_5 5000000
#define last 4444444444
 #define f first
 #define s second
 #define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define reprev(i,a,b) for(ll i=(a);i>=(b);i--)
 #define repi(i,a,b) for(int i=(a);i<=(b);i++)
#define reprevi(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define x first
#define y second
//#define PI 3.14159265
const long double PI = 2*acos(0.0);

typedef vector<bool> vb;
void print(vi &a)
{

    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vll &a)
{

    for(ll i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vector<long double> &a)
{

    for(long double i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vector<pll> &a)
{

    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
}
ll dist_sq(pll a,pll b)
{
    return ((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}

ll po(ll a,ll b)
{
    if(b<=0)
        return 1;
    else if(b==1)
        return a;

    ll vl = po((a*a),b/2);
    if(b%2==0)
        return vl;
    else
        return (vl)*a;
}

ll func(string num)
{
    ll len = num.length();
    if(len==1)
    {
        return (num[0]-'0');
    }

    ll dig = (ll)(num[0]-'0');
    ll ans = 0;
    rep(i,1,len-1)
    {
        ans+=9*po(10,i-2);
        // cout<<ans<<"\n";
    }

    ans+=(dig-1)*po(10,len-2);

    vector<ll> nzd;
    vector<ll> nzp;
    rep(i,1,len-1)
    {
        if(num[i]!='0')
        {
            nzd.pb((ll)(num[i]-'0'));
            nzp.pb(i);


        }
    }

    int len2 = nzd.size();
    if(len2!=0)
    {   rep(i,0,len2-1)
        {
            if(nzp[i]!=(len-1))
                ans+=(nzd[i])*po(10,(len-1)-nzp[i]-1);
        }

        if(nzp[len2-1]==len-1)
        {
            if(num[len-1]>=num[0])
                ans++;
        }
    }


    return ans;
}
vector<pii> adj(1001,mp(-1,-1));
vector < bool> seen(1001);

pii dfs(int i)
{
    seen[i]=true;

    int t = i;
    int mn = INT_MAX;
    while(adj[t].f!=-1)
    {
        mn = min(mn,adj[t].s);
        t = adj[t].f;
    }
    return mp(mn,t);
}

// Submission Link: https://codeforces.com/contest/107/submission/12888439
int main(void)
{
    ios_base::sync_with_stdio(false);


    int n,t;
    cin>>n>>t;
    vi indeg(n+1,0);
    rep(i,1,t)
    {
        int a,b,d;
        cin>>a>>b>>d;
        adj[a] = mp(b,d);
        indeg[b]++;
    }
    int ctr = 0;
    rep(i,1,n)
    {
        if(indeg[i]==0 && adj[i].f!=-1)
        {
            ctr++;
        }
    }
    cout<<ctr<<"\n";
    rep(i,1,n)
    {   //cout<<i<<" "<<adj[i].f<<"\n";
        if(indeg[i]==0 && adj[i].f!=-1)
            {   pii ans = dfs(i);
                cout<<i<<" "<<ans.s<<" "<<ans.f<<"\n";

            }
    }


    return 0;
}

















 
