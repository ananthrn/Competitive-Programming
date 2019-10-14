 
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
#define mp make_pair
#define pb push_back
#define x first
#define y second
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
void print(vector<pll> &a)
{

    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
}
// Submission Link: https://codeforces.com/contest/121/submission/12807457
int main(void)
{
   ios_base::sync_with_stdio(false);
    ll l,r;
    cin>>l>>r;
    vll luck;
    ll val = 4;
    string s = "4";
    while(val<=last)
    {
        luck.pb(val);
        int j = s.length()-1;
        while(j>=0 && s[j]=='7')
        {
            s[j]='4';
            j--;
        }
        if(j>=0)
        {
            s[j]='7';
        }
        else
        {
            s = "4"+s;
        }
        val = atoll(s.c_str());
    }
    //cout<<luck[luck.size()-1]<<" ";
    int ind_l = -1;
    int ind_r = -1;
    //print(luck);
    //cout<<luck.size();
    rep(i,0,1022)
    {
        if(luck[i]>=l)
          {
              ind_l = i;
              break;
          }
    }
    rep(i,0,1022)
    {
        if(luck[i]>=r)
          {
              ind_r = i;
              break;
          }
    }
    ll ans = 0;
    rep(k,ind_l,ind_r)
    {
        ll lft,rgt;
        if(k==ind_l)
            lft = l;
        else
            lft = luck[k-1]+1;

         if(k==ind_r)
            rgt = r;
        else
            rgt = luck[k];

        ans = ans +(rgt-lft+1)*luck[k];


    }

    cout<<ans;
   return 0;
}












 
