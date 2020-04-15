// Link: https://www.codechef.com/viewsolution/31890467
#define SUBMISSION
#define BRUTE_FORCE
#ifdef SUBMISSION
#undef BRUTE_FORCE
#define NDEBUG
#else
#define _GLIBCXX_DEBUG       // Iterator safety; out-of-bounds access for Containers, etc.
#pragma GCC optimize "trapv" // abort() on (signed) integer overflow.
#endif

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
typedef vector<char> vc;
typedef tuple<int,int,int> tiii;
#define rkmod 1125899906842597LL
#define mod1 1000000007LL
#define mod 1000000007LL
#define mod2 1000000007LL
#define mod3 998244353LL
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
const int stdLength = 25;
const ll max_number = 1048575;
typedef vector<bool> vb;
void print(vb &a)
{
 
    for(bool i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vi &a)
{
 
    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
void print(vc &a)
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

void print(deque<ll> &a)
{
 
    for(ll i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}

void print(const multiset<ll> &a)
{
    for(auto i: a){
        cout<<i<<' ';
    }
    cout<<'\n';
}
void print(vector<vi> &a)
{
    for(vi i:a)
    {
        print(i);
    }
    cout<<"\n";
}
void print(vector<vll> &a)
{
    for(vll i:a)
    {
        print(i);
    }
    cout<<"\n";
}
void print(vector<double> &a)
{
 
    for(double i:a)
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
    for(auto i:a)
    {
        cout<<"("<<i.f<<", "<<i.s<<") ";
    }
    cout<<"\n";
}
void print(vector<pii> &a)
{
 
    for(auto i:a)
    {
        cout<<"("<<i.f<<", "<<i.s<<") ";
    }
    cout<<"\n";
}
void print(pii &p)
{
    cout<<"("<<p.f<<", "<<p.s<<") ";

}
void print(deque<pll> &a)
{
 
    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
}
ll dist_sq(const pll& a, const pll& b)
{
    return ((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
}
 
ll  po(const ll& a, const ll& b)
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
 
ll  po(const ll& a, const ll& b, const ll& n)
{
    if(b<=0)
        return 1;
    else if(b==1)
        return (a<=n)?a:n+1;
    
    if(a > (n/a) )
        return n+1;
        
    ll  vl = po((a*a),b/2, n);
    
    if(b%2==0)
        return (vl<=n)?vl:n+1;
    else{
        if(vl > (n/a))
        {
            return n+1;
        }else{
            return (vl)*a;
        }
    }
}

inline long long fast_power(long long base, long long power, long long n) {
    long long result = 1;
    while(power > 0) {
        if(base > n)
            return n + 1;
        if(power & 1) { // Can also use (power & 1) to make code even faster
            if(result > (n/base) )
                return n + 1;
        
            result = (result*base);
        }
        if(base > (n/base))
        {
            base =  n + 1;
        } else {
            base = (base * base);
        }

        power >>= 1; // Can also use power >>= 1; to make code even faster
    }
    
    if(result > n)
        return n +1;
    
    return result;
}

inline long long power(const int& x, int k, const ll& n)
{
	__int128 res = 1;
	while(k--) res *= x;
	if (res > n) res = n + 1;
	return (long long) res;
}
// ll powMod(ll a,ll b)
// {
//     a= a%mod;
//     if(b<=0)
//         return 1%mod;
//     else if(b==1)
//         return a%mod;
 
//     ll vl = powMod((a*a)%mod,b/2);
//     vl = vl%mod;
//     if(b%2==0)
//         return vl;
//     else
//         return ((vl)*a)%mod;
// }

ll powMod(const ll& a, const ll& b, const ll& modVal)
{
    if(b<=0)
        return 1%modVal;
    else if(b==1)
        return a%modVal;
 
    ll vl = powMod((a*a)%modVal,b/2, modVal);
    vl = vl%modVal;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%modVal;
}

ll factorialMod(const ll& n, const ll& modVal)
{
    ll val=n;
    ll ans =1;
    while(val>=1)
    {
        ans = (ans*val)%modVal;
        val--;
    }
    
    return ans;
}

vll preComputeFactorialMod(const ll& n, const ll & modVal){
    vll factorialMod(n+1,1LL);
    
    rep(j, 1, n){
        factorialMod[j] = (j*factorialMod[j-1])%modVal;
    }
    
    return factorialMod;
}



ll inverseMod(const ll& a, const ll& modVal)
{
    return powMod(a, modVal-2, modVal);
}

vll preComputeInverseFactorialMod(const ll& n, const ll& modVal){
    vll inverseFactorialMod(n+1,1LL);
    
    rep(j, 1, n){
        inverseFactorialMod[j] = (inverseMod(j, modVal)*inverseFactorialMod[j-1])%modVal;
    }
    
    return inverseFactorialMod;
}

vll preComputePowMod(const ll& a, const ll& n, const ll& modVal){
    vll powMod(n+1,1LL);
    rep(j, 1, n)
    {
        powMod[j] = (a * powMod[j-1])%modVal;
    }
    return powMod;
}

ll combinationMod(const ll& n, const ll& i, const ll& modVal)
{
    ll ans = 1;
    ans = (ans * factorialMod(n, modVal))%modVal;
    ll invVal =  (inverseMod(factorialMod(i,modVal),modVal)%modVal * inverseMod(factorialMod(n-i,modVal),modVal)%modVal)%modVal;
    ans = (ans * invVal)%modVal;
    return ans;
}

ll combinationMod(const ll& n, const ll& i, const vll & factorialMod, const vll & inverseFactorialMod, const ll& modVal){
    
    ll numerator = factorialMod[n]%modVal;
    ll invVal = (inverseFactorialMod[i] * inverseFactorialMod[n-i])%modVal;
    
    auto ans = (numerator * invVal)%modVal;
    
    return ans;
}
ll greatestCommonDivisor(const ll& a, const ll& b){
    if(b>a){
        return greatestCommonDivisor(b,a);
    }
    if(b==0){
        return a;
    }
    
    if(a%b==0){
        return b;
    } else{
        return greatestCommonDivisor(b,a%b);
    }
}
ll greatestCommonDivisor( const vll &numList, int st, int en){
    assert(st>=0 and st<(int)numList.size());
    assert(en>=0 and en<(int)numList.size());
    if(st>en){
        return 0;
    } else if(st==en){
        return numList[st];
    } else if(en==st+1){
        return greatestCommonDivisor(numList[st],numList[st+1]);
    } else{
        return greatestCommonDivisor(numList[st],greatestCommonDivisor(numList,st+1,en));
    }
}
ll greatestCommonDivisor( const vll &numList){
    if(numList.size()==0){
        return 0;
    }
    int st = 0;
    int en = numList.size();
    en--;
    return greatestCommonDivisor(numList,st,en);
}
vector<vll> preComputeCombinationMod(int n)
{
    vector<vll> comb(n+1,vll(n+1,0));
    comb[0][0]=1;
    rep(i,1,n)
    {
        comb[i][0] = 1;
        comb[0][i] = 0;
    }
    
    rep(i,1,n)
    {
        rep(j,1,i)
        {
            comb[i][j] = (comb[i-1][j-1]%mod + comb[i-1][j]%mod)%mod;
        }
    }
    
    return comb;
}
ll floorlog2(const ll& n)
{
    ll h = 0;
    ll p = 1;
    while(p<=n)
    {
        h++;
        p*=2;
    }
    
    return h-1;
}

ll floorLogBase(const ll& n, const ll& b)
{
    ll h = 0;
    ll p = 1;
    while(p<=n)
    {
        h++;
        p*=b;
    }
    
    return h-1;
}

class Trie {
    private:
    vector<Trie*> children;
    bool this_inserted = false;
public:
    /** Initialize your data structure here. */
    Trie() {
        children.resize(26,NULL);
        this_inserted = false;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                cur->children[ind] = new Trie();
                
            }
            cur = cur->children[ind];
        }
        
        cur->this_inserted = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                return false;
            }        
                cur = cur->children[ind];
        }
        
        
        return cur->this_inserted;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        string word = prefix ;
        
      Trie * cur = this;
        
        for(char c: word)
        {
            int ind = c-'a';
            if(cur->children[ind]==NULL)
            {
                return false;
            }        
                cur = cur->children[ind];
        }
        
        
        return true;
    }
};

class FenwickTree
{
    public:
    vll BIT;
    
    FenwickTree(int n=mx5)
    {
        BIT.resize(n+1,0);
    }
    FenwickTree(vll a)
    {
        int n = a.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,a[i]);
        }
    }
    FenwickTree(vi a)
    {
        vll b(a.begin(),a.end());
        
        int n = b.size();
        
        BIT.resize(n+1,0);
        
        rep(i,0,n-1)
        {
            update(i+1,b[i]);
        }
    }
    
    void update(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        int x = ind;
        int sz = BIT.size();
        
        while(x<sz)
        {
            BIT[x]+=val;
            x += (x&-x);
        }
    }
    
    void set(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        ll currentVal = query(ind,ind);
        update(ind,val-currentVal);
    }
    ll query(int l, int r)
    {   
        assert(0<=l and r<BIT.size());
        
        if(r<l)
        {
            return 0;
        }
        else
            return prefQuery(r) - prefQuery(l-1);
    }
    ll prefQuery(int ind)
    {   
        assert(0<=ind and ind<BIT.size());
        int x = ind;
        ll sum = 0;
        while(x>0)
        {
            sum+=BIT[x];
            x-=(x&-x);
        }
        
        return sum;
    }
};

class FenwickTreeRangeUpdate
{
    public:
    FenwickTree bitTree;
    
    FenwickTreeRangeUpdate(int n)
    {
        bitTree = FenwickTree(n+1);
    }

    void updateRange(pii indexRange, ll val)
    {   
        bitTree.update(indexRange.f, val);
        bitTree.update(indexRange.s + 1,-val);
    }
    
    ll query(int ind)
    {   
        return bitTree.prefQuery(ind);
    }
};

struct P{
	int data,version;
	P(int d=0,int ver=0):data(d),version(ver){}
	inline friend bool operator<(const P &a,const P &b){
		return a.version<b.version;
	}
};


class PersistentFenwickTree
{
    public:
    vector<vector<P> > BIT;
    int currentVersion;
    
    PersistentFenwickTree(int n=mx5)
    {
        BIT.resize(n+1,{P()});
        currentVersion = 0;
    }
    
    void update(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        int x = ind;
        int sz = BIT.size();
        currentVersion+=1;
        
        while(x<sz)
        {   
            if(BIT[x].empty())
            {
                throw logic_error("empty array spot");
            }
            auto newVal = P(BIT[x].back().data +val,currentVersion);
            BIT[x].push_back(newVal);
            x += (x&-x);
        }
    }
    
    // void set(int ind, ll val)
    // {   
    //     assert(0<=ind and ind<BIT.size());
        
    //     ll currentVal = query(ind,ind, currentVersion);
    //     update(ind,val-currentVal);
    // }
    // ll query(int l, int r, int version)
    // {   
    //     assert(0<=l and r<BIT.size());
        
    //     if(r<l)
    //     {
    //         return 0;
    //     }
    //     else
    //         return prefQuery(r, version) - prefQuery(l-1, version);
    // }
    
    // ll query(pii indexRange, int version)
    // {   
    //     return query(indexRange.f, indexRange.s, version);
    // }
    ll prefQuery(int ind, int version)
    {   
        assert(0<=ind and ind<BIT.size());
        int x = ind;
        ll sum = 0;
        while(x>0)
        {   
            if(BIT[x].empty())
            {
                throw logic_error("empty array spot");
            }
            
            auto node = *(upper_bound(BIT[x].begin(),BIT[x].end(),P(0,version))-1);
            
            sum+=node.data;
            x-=(x&-x);
        }
        
        return sum;
    }
};

class PersistentFenwickTreeRangeUpdate
{
    public:
    PersistentFenwickTree bitTree;
    
    PersistentFenwickTreeRangeUpdate(int n)
    {
        bitTree = PersistentFenwickTree(n+1);
    }

    void updateRange(pii indexRange, ll val)
    {   
        bitTree.update(indexRange.f, val);
        bitTree.update(indexRange.s + 1,-val);
    }
    
    ll query(int ind, int version)
    {   
        return bitTree.prefQuery(ind, version);
    }
};

vll getPrimes(ll highestNum){
    
    vb isPrime(highestNum+5,true);
    vll primes;
    rep(i,2,highestNum){
        if(isPrime[i])
        {   primes.push_back(i);
            ll j = i;
            while(j*i<=highestNum){
                isPrime[j*i]=false;
                j++;
            }
        }
    }
    return primes;
}

ll getMultiplicity(ll num, ll prime){
    ll mult = 0;
    while(num%prime==0){
        mult+=1;
        num/=prime;
    }
    return mult;
}
vll getPrimeFactorization(ll num, vll &primes){
    int sz = primes.size();
    vll multcities(sz, 0);
    
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return multcities;
        else
        {
            multcities[i] = getMultiplicity(num, prime);
            ll di = po(prime, multcities[i]);
            num = num/di;
        }
    }
    return multcities;
}

map<ll,ll> getMapPrimeFactorization(ll num, vll &primes){
    int sz = primes.size();
    map<ll,ll> primeFac;
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return primeFac;
        else
        {
            primeFac[prime] = getMultiplicity(num,prime);
            ll di = po(prime,primeFac[prime]);
            num = num/di;
        }
    }
    return primeFac;
}
vpll getListPrimeFactorization(ll num, vll &primes){
    int sz = primes.size();
    vpll primeFac;
    
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return primeFac;
        else
        {
            ll mult = getMultiplicity(num,prime);
            ll di = po(prime,mult);
            num = num/di;
        
            if(mult>0){
                primeFac.push_back(make_pair(prime,mult));
            }
        }
    }
    return primeFac;
}
vi compute_z(string s)
{
    int n = s.length();
    vi z(n,0);
    int l=0,r=0;
    z[0]=n;
    rep(i,1,n-1)
    {
        if(r<i)
        {
            l=r=i;
            int j = 0;
            if(s[0]!=s[i])
            {
                continue;
            }
            
            while(j<n and s[j] == s[i+j])
            {
                j++;
            }
            r = i+j-1;
            z[i] = r-i+1;
        }
        else
        {
            int beta = r-i+1;
            int k = i-l;
            
            if(z[k]<beta)
            {   
                
                z[i]=z[k];
              
            }
            else
            {
                int j = 0;
                l = i;
                while(r<n and s[r]==s[r-l])
                {   
                    r+=1;
                }
                r-=1;
                
                z[i] = r-i+1;
                
                
            }
        }
    }
    
    return z;
}

vi getOccurences(string s, string t){
    
     string comb = t + "$" + s;
    
     auto z_vals = compute_z(comb);
     
     int n = s.size();
     int t_sz = t.size();
 
     vi occ;
    
     rep(i,0,n-1)
     {
         if(z_vals[t_sz + 1 +  i]==t_sz){
             occ.push_back(i);
         }
     }
     return occ;
}

class DSU{
    private:
    vi parent;
    vi size;
    public:
    DSU(int n){
        parent.resize(n+5,0);
        size.resize(n+5,0);
        rep(i,1,n){
            parent[i]=i;
            size[i] = 1;
        }
    }
    vi getParents(){
        return parent;
    }
     vi getSizes(){
        return size;
    }
    int getRoot(int node){
       int par = parent[node];
       if(parent[par] == par){
           return par;
       }
       
       int root = getRoot(par);
       
       parent[node] = root;
       
       return root;
    }
    
    bool checkSame(int a, int b){
        return getRoot(a)==getRoot(b);
    }
    
    void connectNodes(int a, int b){
        int root1 = getRoot(a);
        int root2 = getRoot(b);
        
        if(size[root1] < size[root2]){
            swap(root1,root2);
        }
        
        parent[root2] = root1;
        size[root1] += size[root2];
    }
};

class SegmentTreeNode{
    private:
    
    ll total;
    ll pendingUpdate;
    
   
    public:
    int start,end;
    
    SegmentTreeNode(): total(0), start(-1),end(-1),pendingUpdate(0){} 
    
    void assignLeaf(ll value, int start, int end){
        total = value;
        this->start = start;
        this->end = end;
    }
    void merge(SegmentTreeNode &left, SegmentTreeNode&right){
        this->start = left.start;
        this->end = right.end;
        ll leftTotal = left.getValue();
        ll rightTotal = right.getValue();
        
        if(left.ifPendingUpdate()){
            leftTotal += left.getSegmentSize() * left.getPendingUpdate();
        }
        
        if(right.ifPendingUpdate()){
            rightTotal += right.getSegmentSize() * right.getPendingUpdate();
        }
        this->total = leftTotal + rightTotal;
        
    }
    ll getValue(){
        return total;
    }
    
    ll getPendingUpdate(){
        return pendingUpdate;
    }
    bool ifPendingUpdate(){
        return pendingUpdate!=0;
    }
    
    void applyPendingUpdate(){
        this->total += (this->pendingUpdate) * (this->getSegmentSize());
        this->pendingUpdate = 0;
    }
    
    void addUpdate(ll val){
        this->pendingUpdate += val;
    }
    
    int getSegmentSize(){
        return (end-start + 1);
    }
};

class SegmentTree{
   
    
    public:
    int N;
    SegmentTree(vll &arr){
        
        this->N = arr.size();
        this-> treeSize = getSegmentTreeSize(this->N);
        //cout<<"N treeSize:" <<N<<" "<<treeSize<<"\n";
        nodes.resize(this->treeSize);
        
        this->buildTree(arr,1,0,N-1);
    }
    
     void updateRange(int startPos, int endPos, ll val){
         //flip all coins in [startPos,endPos]
         updateRange(1,startPos,endPos,val);
     }
    ll getValue(int startPos, int endPos){
        auto res = getValue(1,startPos,endPos);
        return res.getValue();
    }
    private:
     vector<SegmentTreeNode> nodes;
     
     int treeSize;
     
     
     void buildTree(vll &arr,int stIndex, int left, int right){
         if(left==right){
             this->nodes[stIndex].assignLeaf(arr[left],left,right);
             return;
         } 
         
         int mid = (left+right)/2;
         int leftIndex = 2*stIndex,rightIndex = leftIndex+1;
         
         buildTree(arr,leftIndex,left,mid);
         buildTree(arr,rightIndex,mid+1,right);
         
         nodes[stIndex].merge(nodes[leftIndex],nodes[rightIndex]);
     }
     
    void updateRange(int stIndex, int startPos, int endPos, ll val){
        if(startPos == nodes[stIndex].start and endPos == nodes[stIndex].end){
            nodes[stIndex].addUpdate(val);
            return;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end)/2;
        int leftChildIndex = 2*stIndex, rightChildIndex = leftChildIndex + 1;
        
        if(endPos<=mid){
            updateRange(leftChildIndex,startPos,endPos,val);
        }else if(startPos>mid){
            updateRange(rightChildIndex,startPos,endPos,val);
        }else{
            updateRange(leftChildIndex,startPos,mid,val);
            updateRange(rightChildIndex,mid+1,endPos,val);
        }
        
        nodes[stIndex].merge(nodes[leftChildIndex],nodes[rightChildIndex]);
    }
    
    SegmentTreeNode getValue(int stIndex,int startPos, int endPos){
        if(startPos == nodes[stIndex].start and endPos == nodes[stIndex].end){
            auto result = nodes[stIndex];
            if(result.ifPendingUpdate())
                result.applyPendingUpdate();
                
            return result;
        }
        
        int mid = (nodes[stIndex].start + nodes[stIndex].end)/2;
        int leftChildIndex = 2*stIndex, rightChildIndex = leftChildIndex + 1;
        
        SegmentTreeNode result;
        
        if(endPos<=mid){
            result = getValue(leftChildIndex,startPos,endPos);
        }else if(startPos>mid){
            result = getValue(rightChildIndex,startPos,endPos);
        }else{
            auto leftResult = getValue(leftChildIndex,startPos,mid);
            auto rightResult = getValue(rightChildIndex,mid+1,endPos);
            
            result.merge(leftResult,rightResult);
        }
        
        if(nodes[stIndex].ifPendingUpdate()){
            result.addUpdate(nodes[stIndex].getPendingUpdate());
            result.applyPendingUpdate();
        }
        
        return result;
    }
     int getSegmentTreeSize(int N){
         int x = 1;
         while(x<N){
             x = x*2;
         }
         return x*2;
     }
};


unordered_map<ll, int> getCount(vll &arr) {
    sort(arr.begin(), arr.end());
    
    int sz = arr.size();
    unordered_map<ll, int> counts;
    int cnt = 1;
    
    rep(j, 1, sz-1)
    {
        if(arr[j]!=arr[j-1])
        {
            counts[arr[j-1]] = cnt;
            cnt = 1;
        }else{
            cnt+=1;
        }
    }
    
    counts[arr[sz-1]] = cnt;
    
    return counts;
}

vector<pair<ll ,ll > > getVectorCount(vll &arr) {
    sort(arr.begin(), arr.end());
    
    int sz = arr.size();
    vector<pair<ll ,ll > > counts;
    int cnt = 1;
    
    rep(j, 1, sz-1)
    {
        if(arr[j]!=arr[j-1])
        {
            counts.pb(mp(arr[j-1], cnt));
            cnt = 1;
        }else{
            cnt+=1;
        }
    }
    counts.pb(mp(arr[sz-1], cnt));
    
    return counts;
}



ll computeMultiplicity(const ll & number, const ll & factor)
{   
    ll totalMult = 0;
    ll currentNumber = number;
    
    if(currentNumber == 0)
    {
        return 0LL;
    }
    
    while(currentNumber%factor==0)
    {  
       ll prevFactor = 1LL;
       ll currentFactor = factor;
       ll currentMult = 1LL;
       
       
       while(currentFactor <= currentNumber and currentNumber%currentFactor == 0){  
           
           assert(currentFactor!=0);
           prevFactor = currentFactor;
           currentFactor = currentFactor * currentFactor;
           currentMult = currentMult * 2;
       }
       assert(prevFactor!=0);
       
       totalMult += (currentMult/2);
       currentNumber/= prevFactor;

    }
    
    return totalMult;
}

ll computeMultSum(const ll& x){
    
    auto tempX =x;
    
    auto multSum = 0;
    
    auto twoMult = computeMultiplicity(tempX, 2ll);
    
    // multSum += twoMult;
    
    while(tempX %2 ==0)
    {
        tempX/=2;
        multSum+=1;
    }
    
    
    for(ll i = 3; i*i <= tempX; i+=2){
        while(tempX%i == 0){
            tempX = tempX/i;
            multSum+=1;
        }
    }
    
    if(tempX > 2)
        multSum+=1;
    
    return multSum;
}
const int DEBUG =  0;

const ll MOD_VAL = 1000000007LL;
const ll SQRT_VAL = 1000000000LL;// + 1000LL;
const ll MAX_VAL = SQRT_VAL * SQRT_VAL;
ll MAX_LOG_VAL = floorLogBase(MAX_VAL, 2ll);
const ll sixDenomInverse = inverseMod(6LL, MOD_VAL)%MOD_VAL;

vll computeNonPerfectPowers(const ll& maxValue){
    bitset<SQRT_VAL+1> isPerfectPower;
    
    
    vll nonPerfectPowers;
    
    rep(j, 2, SQRT_VAL)
    {
        if(!isPerfectPower[j])
        {
            nonPerfectPowers.push_back(j);
            
            auto currentPower = j*j;
            
            while(currentPower<=SQRT_VAL)
            {   
                isPerfectPower[currentPower] = 1;
                
                currentPower*=j;
            }
        }
  
    }
    
    return nonPerfectPowers;
}

// bitset<(ll)SQRT_VAL + 1LL> isPerfectPower;

vll computePerfectPowers(const ll& maxValue){
    
    vll perfectPowers;
    //set<ll> perfectPowerSet;
    bitset<SQRT_VAL + 1> isPerfectPower;
    
    ll j = 2LL;
    
    // while(j *j <= maxValue)
    // {
    //     if(perfectPowerSet.count(j)==0)
    //     {
    //         ll currentPower = j*j;
    //         while(currentPower <= maxValue)
    //         {
    //             perfectPowerSet.insert(currentPower);
    //             currentPower = currentPower * j;
    //         }
    //     }
        
    //     j+=1;
    // }
    
    while(j *j <= maxValue){
        if(isPerfectPower[j] == 0)
        {
            ll currentPower = j*j;
            while(currentPower <= maxValue)
            {   
                if(currentPower<=SQRT_VAL)
                {
                    isPerfectPower[currentPower] = 1;
                }
                
                perfectPowers.pb(currentPower);
                currentPower = currentPower * j;
            }
        }
        j+=1;
    }
    
    
    // perfectPowers = vector<ll>(perfectPowerSet.begin(), perfectPowerSet.end());
    sort(perfectPowers.begin(), perfectPowers.end());
    
    return perfectPowers;
}



// auto nonPerfectPowers = computeNonPerfectPowers(SQRT_VAL);
// auto perfectPowers = computePerfectPowers(MAX_VAL);


ll computeTestWithPerfectPowers(const ll& n, const vll& perfectPowers){
    
    ll ans = (n%MOD_VAL);
    
    for(const auto& perfectPower: perfectPowers){
        if(perfectPower > n)
        {
            return ans;
        }
        
        ll thisContribution = (n - (n%perfectPower))%MOD_VAL; //(((n/perfectPower)%MOD_VAL)*perfectPower)%MOD_VAL;
        // if(DEBUG)
        // {
        //     cout<<"n: "<<n<<endl;
        //     cout<<"perfectPower: "<<perfectPower<<endl;
        //     cout<<"thisContribution: "<<thisContribution<<endl;
        //     cout<<endl;
        // }
        ans =( ans +thisContribution)%MOD_VAL;
    }
    
    return ans;
}

ll computeTestWithNonPerfectPowers(const ll& n, const vll& nonPerfectPowers){
    
    ll ans = (n%MOD_VAL);
    
    for(const ll& nonPerfectPower: nonPerfectPowers){
        if(nonPerfectPower * nonPerfectPower > n)
        {
            return ans;
        }
            ll currentPower = nonPerfectPower * nonPerfectPower;
            ll thisContribution = 0LL;
            
            while(currentPower<=n)
            {   
              
                thisContribution = (thisContribution + (n - n%currentPower)%MOD_VAL)%MOD_VAL;
                
                currentPower = currentPower*nonPerfectPower;
            }
            
            ans = (ans + thisContribution)%MOD_VAL;        
        
    }
    
    return ans;
}
ll computeTestBrute(const ll& n){
    
    // if(n>SQRT_VAL * SQRT_VAL)
    // {
    //     throw logic_error("too big");
    // }
    
    // perfectPower = perfectPower.reset();
    bitset<SQRT_VAL+1> isPerfectPower;
    isPerfectPower.reset();
    
    ll j = 2;
    ll ans = 0LL;
    
    while(j*j <= n)
    {
        if(isPerfectPower[j] == 0)
        {
            ll currentPower = j*j;
            ll thisContribution = 0LL;
            
            while(currentPower<=n)
            {   
                if(currentPower<=SQRT_VAL)
                    isPerfectPower[currentPower] = 1;
                
                // perfectPower[currentPower] = 1;
                
                thisContribution = (thisContribution + (currentPower * (n/currentPower))%MOD_VAL)%MOD_VAL;
                
                
                
                currentPower = currentPower*j;
            }
            
            // auto fastPowerContribution = computePowerContribution(n, j);
            
            // if(DEBUG)
            // {   
            //     cout<<"j: "<<j<<endl;
            //     cout<<"thisContribution: "<<thisContribution<<endl;
            //     cout<<"fastPowerContribution: "<<fastPowerContribution<<endl;
            //     cout<<endl;
                
            // }
            // assert(fastPowerContribution == thisContribution);
            ans = (ans + thisContribution)%MOD_VAL;
        }
        j = j+1;
    }
    
    ans = (ans + n)%MOD_VAL;
    
    return ans;
}


inline ll sumOfSquares(const ll& n){
    assert(n>=1);
    
    // auto numerator = (2 * powMod(n, 3, MOD_VAL) + 3*powMod(n, 2, MOD_VAL) + n)%MOD_VAL;
    
    auto nModVal = n%MOD_VAL;
    
    auto squareN = (nModVal * nModVal)%MOD_VAL;
    auto cubeN = (nModVal * squareN)%MOD_VAL;
    
    auto numerator = ((2*cubeN) + (3*squareN) + nModVal)%MOD_VAL;
    // auto denomInverse = inverseMod(6LL, MOD_VAL);
    
    auto ans = (numerator * sixDenomInverse)%MOD_VAL;
    
    return ans;
    
}

inline ll sumOfSquares(const ll& st, const ll& en){
    assert(en>=st);
    
    ll addVal = sumOfSquares(en);
    ll subVal = sumOfSquares(st - 1);
    
    return (addVal + MOD_VAL - subVal)%MOD_VAL;
}

inline ll get_sqrt(long long x)
{
	ll r = sqrtl(x);
	//sqrt function can give a small error
	while(r * (long long) r > x) r--;
	while((r + 1) * (long long)(r + 1) <= x) r++;
	return r;
}

ll computeContributionTwo(const ll& n){
    
        ll contrib = 0LL;
        ll st = 2; 
        
        // auto MAXST = sqrtl(n);
        
        while(st*st <= n){
            ll val = (n/(st*st));
            
            if(val == 0)
            {
                return contrib;
            }
            
            ll en = get_sqrt(n/val);
            
            auto thisContr = (val%MOD_VAL * (sumOfSquares(st, en)%MOD_VAL))%MOD_VAL;
            
            if(DEBUG){
                cout<<"st: "<<st<<endl;
                cout<<"en:" <<en<<endl;
                cout<<"val: "<<val<<endl;
                cout<<"n: "<<n<<endl;
                cout<<"thisContr: "<<thisContr<<endl;
                cout<<"sumOfSquares: "<<sumOfSquares(st, en)<<endl;
                cout<<endl;
            }
            
            // if( not((n/(en * en)) == val)){
            //     cout<<"st: "<<st<<endl;
            //     cout<<"en:" <<en<<endl;
            //     cout<<"val: "<<val<<endl;
            // }
            assert((n/(en * en)) == val); 
            assert (en>=st);
            
      
            contrib = (contrib + thisContr)%MOD_VAL;
            
            st = max(st, en) + 1;
        }
        
        return contrib; 
        
     
}
ll computeExponentContribution(const ll& n, const ll& exponent){
    
    if(exponent==2){
        ll contrib = computeContributionTwo(n);
        return contrib;
    } else {  
        
        ll contrib = 0LL;
        for(ll base = 2LL; ; base+=1)
        {
            ll PP = fast_power(base, exponent, n);//po(base, exponent, n);//power(base, exponent, n);
            if(PP > n)
                return contrib;
            
            // contrib = (contrib + ((n%MOD_VAL) + (MOD_VAL - (n%PP))%MOD_VAL )%MOD_VAL)%MOD_VAL;
            
            contrib = (contrib + ((n/PP)%MOD_VAL * (PP))%MOD_VAL)%MOD_VAL;
        }
        return contrib;
    }
    
    
}

vector<ll> deduplicateContributions(const vector<ll> &exponentContributions){
    vector<ll> dedupedContributions = exponentContributions;
    
    int sz = exponentContributions.size();
    
    reprev(i, sz-1, 2){
        
        // All j>i are deduped
        for(int j = 2*i; j< sz; j+=i){
            dedupedContributions[i] =(dedupedContributions[i] + MOD_VAL - dedupedContributions[j])%MOD_VAL;
        }
    }
    
    return dedupedContributions;
}


ll computeTestOpt(const ll& n){
    
    vector<ll> exponentContributions(MAX_LOG_VAL+1, 0);
    
    rep(j, 2, MAX_LOG_VAL)
    {
        exponentContributions[j] = computeExponentContribution(n, j)%MOD_VAL;
    }
    
    // int sz = exponentContributions.size();
    
    // reprev(i, sz-1, 2){
        
    //     // All j>i are deduped
    //     for(int j = 2*i; j< sz; j+=i){
    //         exponentContributions[i] =(exponentContributions[i] + MOD_VAL - exponentContributions[j])%MOD_VAL;
    //     }
    // }
    
    exponentContributions = deduplicateContributions(exponentContributions);
    
    auto ans = (n%MOD_VAL);
    
    for(const auto& contrib: exponentContributions){
        ans = (ans + contrib)%MOD_VAL;
    }
    
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    
    // print(nonPerfectPowers);
    if(DEBUG)
    {
        cout<<"SQRT_VAL: "<<SQRT_VAL<<endl;
        cout<<"MAX_VAL: "<<MAX_VAL<<endl;
        cout<<"MAX_LOG_VAL: "<<MAX_LOG_VAL<<endl;
        // cout<<"nonPerfectPowers size: "<<nonPerfectPowers.size()<<endl; 
        // cout<<"perfectPowers size: "<<SQRT_VAL - nonPerfectPowers.size()<<endl;
        // cout<<"PP fraction: "<< (1.0*SQRT_VAL - 1.0*nonPerfectPowers.size())/SQRT_VAL<<endl;
        
        
        // cout<<"perfectPowers: "; print(perfectPowers); 
        // cout<<"perfectPowers size: "<<perfectPowers.size()<<endl;
        // cout<<"biggest perfect power:" <<perfectPowers.back()<<endl;
        // 
        cout<<endl;
        
    }
    rep(testNum, 1, t){
        
        string dash = string(20, '-') + "\n";
        if(DEBUG){
            
            cout<<dash<<"Test Case Number: "<<testNum<<endl;
            
        }
        
        ll n; cin>>n;
        
        if(n > MAX_VAL)
            throw logic_error("n > MAX_VAL");
            
        // auto ansBrute = computeTestBrute(n);
        // auto ansNonPerfect = computeTestWithNonPerfectPowers(n);
        // auto ansPerfect = computeTestWithPerfectPowers(n, perfectPowers);
        auto ansOpt = computeTestOpt(n);
        
        // if(ansBrute!=ansNonPerfect)
        // {   
        //     throw logic_error("");
        //     cout<<"ansNonPerfect: "<<ansNonPerfect<<endl;
        //     cout<<"ansBrute: "<<ansBrute<<endl;
        //     cout<<endl;
            
        // }
        
        // if(ansPerfect!=ansNonPerfect)
        // {   
        //     throw logic_error("");
        //     cout<<"ansNonPerfect: "<<ansNonPerfect<<endl;
        //     cout<<"ansPerfect: "<<ansPerfect<<endl;
        //     cout<<endl;
            
        // }
        

        
        // if(ansBrute!=ansOpt)
        // {
        // //     throw logic_error("");
        //     cout<<"ansOpt: "<<ansOpt<<endl;
        //     cout<<"ansBrute: "<<ansBrute<<endl;
        //     cout<<endl; 
        // }
        
        // cout<<ansPerfect<<'\n';
        // cout<<ansBrute<<'\n';
        cout<<ansOpt<<'\n';
        
        if(DEBUG){
                cout<<dash<<endl<<endl;
        }
        
    }
    return 0;
}

