 

#include<bits/stdc++.h>
using namespace std;
 typedef pair<int,int> pii;
 typedef pair<char,char> pcc;
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<ull> vull;
typedef vector<int> vi;
typedef vector<bool> vb;
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

ll pomod(ll a,ll b)
{
    a= a%mod;
    if(b<=0)
        return 1%mod;
    else if(b==1)
        return a%mod;

    ll vl = po((a*a)%mod,b/2);
    vl = vl%mod;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mod;
}

// Submission Link: https://codeforces.com/contest/160/submission/16907227
int main(void)
{
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vll a(n,0);
    rep(i,0,n-1)
    {
        cin>>a[i];
    }
    
    sort(a.begin(),a.end());
    
    vll b;
    vll ct;
    b.push_back(a[0]);
    int strk = 1;
    rep(i,1,n-1)
    {
        if(a[i]==a[i-1])
        {
            strk++;
            
        }
        else
        {   
            ct.pb(strk);
            strk=1;
            b.pb(a[i]);
        }
    }
    if(n==1)
    ct.pb(1);
    else
    {
        ct.pb(strk);
    }
    
   // print(b);print(ct);
   
     k--;
    int num = a[k/n];
    
    int j=0;
    rep(i,0,n-1)
    {
        if(a[i]==num)
        {
            j=i;
            break;
        }
    }
    k++;
    
    k-=j*n;
    
    int sz = ct.size();
    int fir=0,sec=0;
    rep(i,0,sz-1)
    {
        if(b[i]==num)
        {
            sec=i;
        }
    }
    
    ll sum = ct[sec]*ct[fir];
    
    while(k>sum)
    {
        fir++;
        sum+=ct[sec]*ct[fir];
        
    }
    cout<<num<<" "<<b[fir];
    
    
    
   /* vpll dub;    
    rep(i,0,n-1)
    {
        rep(j,0,n-1)
        {
            dub.pb(mp(a[i],a[j]));
        }
    }
    sort(dub.begin(),dub.end());
    
    for(pll p:dub)
    {
        cout<<"("<<p.f<<","<<p.s<<") ";
    }*/
    return 0;
}
 
