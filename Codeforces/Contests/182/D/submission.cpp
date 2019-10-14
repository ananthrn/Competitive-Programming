 

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



vi divisors(int n)
{
    int val = floor(sqrt(n));
    vi ans;

    rep(i,1,val)
    {
        if(n%i==0)
        {
            int oth = n/i;
            ans.pb(i);
            if(i!=oth)
                ans.pb(oth);
        }
    }
    return ans;
}
// Submission Link: https://codeforces.com/contest/182/submission/13063532
int main(void)
{
    ios_base::sync_with_stdio(false);
    string a,b;
   cin>>a>>b;

    vi diva,divb;
    int lena = (int)a.length();
    int lenb = (int)b.length();
    diva = divisors(lena);
    divb = divisors(lenb);
    sort(diva.begin(),diva.end());
    sort(divb.begin(),divb.end());

    string mina,minb;
    for(int i: diva)
    {
        string one = a.substr(0,i);
        bool chk = false;
        //cout<<i<<" "<<one<<"\n";
        rep(j,1,lena/i - 1)
        {
            string two = a.substr(j*i,i);
            if(two!=one)
            {
                chk = true;
                break;
            }
        }
        if(!chk)
        {
            mina = one;
            break;
        }
    }

    for(int i: divb)
    {
        string one = b.substr(0,i);
        bool chk = false;
        //cout<<i<<" "<<one<<"\n";
        rep(j,1,lenb/i - 1)
        {
            string two = b.substr(j*i,i);
            if(two!=one)
            {
                chk = true;
                break;
            }
        }
        if(!chk)
        {
            minb = one;
            break;
        }
    }
    //cout<<mina<<" "<<minb<<"\n";
    if(mina!=minb)
    {
        cout<<0;
        return 0;
    }
    vi n_diva=divisors(lena/mina.length());
    vi n_divb=divisors(lenb/minb.length());

    sort(n_diva.begin(),n_diva.end());
    sort(n_divb.begin(),n_divb.end());
    //sort(n_divb);
    /*cout<<"n_diva: ";
    print(n_diva);
     cout<<"n_divb: ";
    print(n_divb);*/

   vi common(min(n_diva.size(),n_divb.size()),0);
    vi::iterator it=set_intersection(n_diva.begin(),n_diva.end(),n_divb.begin(),n_divb.end(),common.begin());
    common.resize(it-common.begin());
    cout<<common.size();
    return 0;
}

 
