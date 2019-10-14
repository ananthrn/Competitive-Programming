 

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
#define mod 1000000007LL
#define mx9 1000000000LL
#define mx10 10000000000LL
#define mx5 100000
#define mx8 100000000LL
#define mx7 10000000LL
#define mx6 1000000LL
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

// submission link: https://codeforces.com/contest/198/submission/13087306


int main(void)
{
    ios_base::sync_with_stdio(false);
    long double k,b,n,t;
    cin>>k>>b>>n>>t;
    ll n2;
    if(k>1)
    n2 =ceil(n - log10((t*(k-1)+b)/(k-1+b))/log10(k));
    else
        n2 = ceil( (b*n+1-t)/b );
    cout<<max(n2,0LL)<<"\n";
  // cout<< (log10(t*(k-1)+b) - log10((k-1)+b))<<" "<<log10((t*(k-1)+b)/(k-1+b))<<" "<<log10(k)<<" "<<log10((t*(k-1)+b)/(k-1+b))/log10(k);
    return 0;
}
