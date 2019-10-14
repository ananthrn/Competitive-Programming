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
#define mx5 100000
#define mx7 10000000
#define mx6 1000000
 #define f first
 #define s second
 #define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define reprev(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back


void print(vi &a)
{

    for(int i:a)
    {
        cout<<i<<"\n";
    }
    cout<<"\n";
}

bool check(string s)
{
    int sz = s.length();
    rep(i,0,sz-2)
    {
        if(s[i]==s[i+1]||(i<sz-2 && s[i]==s[i+2]))
            return false;
    }
    return true;
}
ll po(ll a, ll b) {
ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

ll modInverse(ll a) {
    return po(a,mod-2);
}
// submission link: https://codeforces.com/contest/135/submission/12778841
int main(void)
{
   ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vll a(n,0);
    rep(i,0,n-1)
        cin>>a[i];

    sort(a.begin(),a.end());
    if(*(a.rbegin())==1)
    {
        a[a.size()-1]=2;
    }
    else
    {
        a[a.size()-1]=1;
    }
    sort(a.begin(),a.end());

for(ll i:a)
    cout<<i<<" ";
    return 0;
}







 
