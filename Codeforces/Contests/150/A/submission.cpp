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
#define mx6_5 5000000
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




vb isPrime(mx6_5+1,true);
vll primes;
void sieve()
{
    isPrime[0]=false;
    isPrime[1]=false;
    rep(i,2,mx6_5)
    {
        if(isPrime[i])
        {
            primes.pb(i);
            for(ll j = i*i;j<=mx6_5;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}
bool checkprime(ll n)
{
    if(n<mx6_5)
        return isPrime[n];
    else
    {
        rep(i,0,primes.size()-1)
        {
            if(n%primes[i]==0)
                return false;
        }
    }
    return true;
}
// Submission Link: https://codeforces.com/contest/150/submission/12795353
int main(void)
{
   ios_base::sync_with_stdio(false);
    sieve();
   // print(primes);
    ll q;
    cin>>q;
   // cout<<checkprime(q)<<"\n";
    if(q==1||checkprime(q))
    {
        cout<<"1\n0";
        return 0;

    }
    
    vll multipl(primes.size(),0);
    ll sum = 0;
    ll t= q;
    rep(i,0,primes.size()-1)
    {
        
        //bool chk = checkprime(f2);
        while(t%primes[i]==0)
        {
            multipl[i]++;
            t/=primes[i];
        }
        sum+=multipl[i];
    }
    
    //print(primes);
    //print(multipl);
    //cout<<"sum "<<sum<<"\n";
    if(sum<=1)
    {
            rep(j,0,primes.size()-1)
            {
                if(multipl[j]==1)
                {
                    ll f2 = q/primes[j];
                    if(checkprime(f2))
                    {
                        cout<<2;
                        return 0;
                    }
                }
            }
          cout<<"1\n0";
    }
    else if(sum==2)
    {
        ll ans = 1;
        bool chk1 = false;
        rep(j,0,primes.size()-1)
        {
            if(multipl[j]>=2)
            {
                ans = primes[j]*primes[j];
                chk1 = true;
                break;
            }
        }
        int ind_1=0;
        int ind_2=0;
        if(!chk1)
        {   bool chk2 = false;
            rep(j,0,primes.size()-1)
            {
                if(multipl[j]==1)
                {
                    ans*=primes[j];
                    multipl[j]=0;
                    rep(i,j+1,primes.size()-1)
                    {
                        if(multipl[i]==1)
                        {
                            ans*=primes[i];
                            //cout<<1<<"\n"<<ans;
                            //return 0;
                            chk2 = true;
                            break;
                        }
                    }
                    if(chk2)
                        break;
                }
            }
        }
        
        ll f = q/ans;
        if(checkprime(f))
        {
            cout<<1<<"\n"<<ans;
            return 0;
        }
        else
        cout<<"2";
    }
    else
    {
        rep(j,0,primes.size()-1)
        {
            if(multipl[j]>=2)
            {
                cout<<1<<"\n"<<primes[j]*primes[j];
                return 0;
            }
        }
        int ind_1=0;
        int ind_2=0;
        ll ans = 1;
        rep(j,0,primes.size()-1)
        {
            if(multipl[j]==1)
            {
                ans*=primes[j];
                multipl[j]=0;
                rep(i,j+1,primes.size()-1)
                {
                    if(multipl[i]==1)
                    {
                        ans*=primes[i];
                         cout<<1<<"\n"<<ans;
                        return 0;
                    }
                }
            }
        }

    }
   return 0;
}









 
