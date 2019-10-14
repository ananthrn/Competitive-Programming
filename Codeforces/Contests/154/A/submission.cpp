 
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
void print(vector<char> &a)
{

    for(char i:a)
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
// Submission Link: https://codeforces.com/contest/154/submission/12860664
int main(void)
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    vector<char> vc(s.begin(),s.end());
    vector<char> vc2;
    vector<int> freq;
    int k;
    cin>>k;
    map <char,char> m;
    rep(i,1,k)
    {
        string t;
        cin>>t;
        m[t[0]] = t[1];
        m[t[1]] = t[0];

            }

    int sz1 = vc.size();
    int ctr =1;
    rep(i,1,sz1-1)
    {
        if(vc[i]==vc[i-1])
        {
            ctr++;
        }
        else
        {
            freq.pb(ctr);
            vc2.pb(vc[i-1]);
            ctr=1;
        }
    }
    freq.pb(ctr);
    vc2.pb(vc[sz1-1]);
    //freq.pb(0);
    //vc2.pb('-');
    //print(vc2);
    //print(freq);
    int sz2 = vc2.size();
    vector<int> prev(vc2.size());
    rep(i,0,sz2-1)
        prev[i] = i-1;

    int ans =0;
    rep(i,0,sz2-1)
    {
        char c = vc2[i];
        if(m[c]==c)
        {   //cout<<"doing this cos\n";
            ans+=(freq[i]-1);
            freq[i]=1;
        }
    }
    vc2.pb('-');
    freq.pb(0);
    vc2.pb('-');
    freq.pb(0);
    int i = 0;


    while(i<=sz2-2)
    {   if(m[vc2[i]] == vc2[i+1])
        {
           // cout<<"here\n";
        //cout<<"i: "<<i<<" vc2[i]: "<<vc2[i]<<" vc2[i+2] : "<<vc2[i+2]<<"\n";
        int j = i;
        int st = i;
        while((vc2[i]==vc2[i+2]) && (m[vc2[i]] == vc2[i+1]))
        {   //cout<<"here";
            i=i+2;
        }
        if(m[vc2[i]] == vc2[i+1])
        {
            j = i+1;

        }
        else
            j = i;

        int evsum = 0,oddsum=0;;
        int ct = st;
        while(ct<=i)
        {
            evsum+=freq[ct];
            ct+=2;
        }
        ct = st+1;
        while(ct<=j)
        {
            oddsum+=freq[ct];
            ct+=2;
        }
        //cout<<i<<" "<<j<<" "<<oddsum<<" "<<evsum<<" "<<vc2[st]<<" "<<vc2[st+1]<<"\n";
        if(oddsum<=evsum)
            ans+=oddsum;
        else
            ans+=evsum;

        i = j+1;
        }
        else
        {
            i++;
        }

    }
    cout<<ans;
    return 0;
}
















 
