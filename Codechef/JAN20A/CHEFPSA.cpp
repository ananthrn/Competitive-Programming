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
#define mod3 1000000009LL
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
 
ll powMod(ll a,ll b)
{
    a= a%mod;
    if(b<=0)
        return 1%mod;
    else if(b==1)
        return a%mod;
 
    ll vl = powMod((a*a)%mod,b/2);
    vl = vl%mod;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mod;
}

ll powMod(ll a,ll b,ll mo)
{
    a= a%mo;
    if(b<=0)
        return 1%mo;
    else if(b==1)
        return a%mo;
 
    ll vl = powMod((a*a)%mo,b/2);
    vl = vl%mo;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mo;
}
ll factorialMod(ll n, ll mo)
{
    ll val=n;
    ll ans =1;
    while(val>=1)
    {
        ans = (ans*val)%mo;
        val--;
    }
    
    return ans;
}

vll preComputeFactorialMod(ll n, ll mo){
    vll factorialMod(n+1,1LL);
    
    rep(j, 1, n){
        factorialMod[j] = (j*factorialMod[j-1])%mo;
    }
    
    return factorialMod;
}



ll inverseMod(ll a,ll mo)
{
    return powMod(a,mo-2,mo);
}

vll preComputeInverseFactorialMod(ll n, ll mo){
    vll inverseFactorialMod(n+1,1LL);
    
    rep(j, 1, n){
        inverseFactorialMod[j] = (inverseMod(j, mo)*inverseFactorialMod[j-1])%mo;
    }
    
    return inverseFactorialMod;
}

vll preComputePowMod(ll a, ll n, ll mo){
    vll powMod(n+1,1LL);
    rep(j, 1, n)
    {
        powMod[j] = (a * powMod[j-1])%mod;
    }
    return powMod;
}

ll combinationMod(ll n, ll i)
{
    ll ans = 1;
    ans = (ans * factorialMod(n,mod))%mod;
    ll invVal =  (inverseMod(factorialMod(i,mod),mod)%mod * inverseMod(factorialMod(n-i,mod),mod)%mod)%mod;
    ans = (ans * invVal)%mod;
    return ans;
}
ll greatestCommonDivisor(ll a, ll b){
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
ll floorlog2(ll n)
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
ll floorlog2(ll n,ll b)
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
    vll multcities(sz,0);
    
    rep(i,0,sz-1)
    {
        ll prime = primes[i];
        if(prime>num)
           return multcities;
        else
        {
            multcities[i] = getMultiplicity(num,prime);
            ll di = po(prime,multcities[i]);
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

const int DEBUG = 0;

int depth = 0;

ll backtrack(deque<ll> &pref, deque<ll> &suff, multiset<ll> &rem, int n){
    
    // if(DEBUG)
    // {   
    //     cout<<"Detph:" <<depth<<endl;
    //     cout<<"pref: ";print(pref);
    //     cout<<"suff: ";print(suff);
    //     cout<<"rem: ";print(rem);
    //     cout<<endl;
    // }
    if(pref.size() ==n)
    {
        
        assert(suff.size()==n-1 and rem.size()==1);
        // if(DEBUG)
        // {
        //     cout<<"rem.begin():" <<*(rem.begin())<<endl;
        //     cout<<"pref.back(): "<<pref.back()<<endl;
        // }
        
        if(DEBUG==1)
    {   
        cout<<"Detph:" <<depth<<endl;
        cout<<"pref: ";print(pref);
        cout<<"suff: ";print(suff);
        cout<<"rem: ";print(rem);
        cout<<endl;
    }
    
        if(*(rem.begin()) == pref.back())
            return 1;
        else
            return 0;
    }
    

    
    auto ans = 0;
    
    set <ll> rem_set(rem.begin(), rem.end());
    
    vector<ll> rem_vec(rem_set.begin(), rem_set.end());
    
    for (auto val: rem_vec)
    {   
        rem.erase(rem.find(val));
        depth+=1;
        
        if(pref.empty())
        {   
            
            pref.push_front(val);
            
            auto int_ans = (rem.count(val)?backtrack(pref, suff, rem, n):0);
            ans+=int_ans;
            
            pref.pop_front();
            
            
        } else 
        {
            auto diff = pref.front() - val;
            auto lastSuff = (suff.empty())?0:suff.front();
            
            auto newSuffVal = lastSuff + diff;
            
            if(rem.count(newSuffVal)){
                 rem.erase(rem.find(newSuffVal));
                 pref.push_front(val);
                 suff.push_front(newSuffVal);
                 
                //  cout<<"Adding val: "<<val<<endl;
                 auto int_ans = backtrack(pref, suff, rem, n);
                 ans+=int_ans;
                 
                 pref.pop_front();
                 suff.pop_front();
                 rem.insert(newSuffVal);
            }
        }
        depth-=1;
        
        rem.insert(val);
    }
    
    
    return ans;
}


ll compute_test_case(vll &arr){
    int sz = arr.size();
    int n = sz/2;
    
    multiset<ll> rem(arr.begin(), arr.end());
    deque<ll> pref = {};
    deque<ll> suff = {};
    auto ans = backtrack(pref, suff, rem, n);
    return ans;
}

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

vector<pair<ll ,ll > > getVectorCountDel(vll &arr, ll sumVal) {
    sort(arr.begin(), arr.end());
    
    int sz = arr.size();
    vector<pair<ll ,ll > > counts;
    int cnt = 1;
    bool found = false;
    
    rep(j, 1, sz)
    {
        if(j==sz or arr[j]!=arr[j-1])
        {   
            if(arr[j-1] == sumVal)
            {
                cnt-=2;
                found = true;
            }
            
            if(cnt<0)
                return {};
            
            if(cnt>0)
                counts.pb(mp(arr[j-1], cnt));
            cnt = 1;
        }else{
            cnt+=1;
        }
    }
    
    if(found)
    {
        return counts;
    }else{
        return {};
    }
}

vector<pair<ll, ll> > computeSumCounts(unordered_map<ll, int> &arrCounts, ll sum){
    
    unordered_map<ll, bool> seen;
    vector<pair<ll, ll> > counts;
    
    // if(DEBUG){
    //     cout<<"Computing val for sum: "<<sum<<endl<<endl;
    // }
    
    for(auto vl: arrCounts){
        ll firstVal = vl.f;
        ll firstCount = vl.s;
        

        
        ll secondVal = sum - firstVal;
        ll secondCount = (arrCounts.count(secondVal))? arrCounts[secondVal]:0;
        
        // if(DEBUG==2)
        // {
        //     cout<<"firstVal: "<<firstVal<<endl;
        //     cout<<"firstCount: "<<firstCount<<endl;
        //     cout<<"secondVal: "<<secondVal<<endl;
        //     cout<<"secondCount: "<<secondCount<<endl;
        //     cout<<endl;
            
        // }
        if(seen[firstVal])
        {
            continue;
        }
        
        if(firstCount != secondCount)
            return {mp(-1, -1)};
        
        if(firstVal==secondVal){
            if(firstCount%2==1)
            {
                return {mp(-1, -1)};
            } else {
                counts.pb({firstCount/2, 0});
            }
        } else 
        {
            counts.pb({firstCount, 1});
        }
        
        
        seen[firstVal] = seen[secondVal] = true;
    }
    
    return counts;
}

auto factMod = preComputeFactorialMod(mx5+5, mod);
auto inverseFactMod = preComputeInverseFactorialMod(mx5+5, mod);
auto twoPowMod = preComputePowMod(2, mx5+5, mod);

ll computeAnswerForSum(unordered_map<ll, int> &arrCounts, ll sum, int n){
    if(arrCounts.count(sum)==0 or arrCounts[sum]<2)
    {
        return 0;
    }
    
    arrCounts[sum] -=2;
    
    auto counts = computeSumCounts(arrCounts, sum);
    
    arrCounts[sum] +=2;
    
    // if(DEBUG==2)
    //     {   
    //         cout<<"computing sum: "<<sum<<endl;
    //         cout<<endl;
    //     }
        
    if(counts == vector<pll>(1, mp(-1, -1))){
        // if(DEBUG==2)
        // {   
        //     cout<<"sum: "<<sum<<endl;
        //     // cout<<"counts: ";print(counts);
        //     cout<<"ans_sum: "<<0;
        //     // cout<<"arrCounts: "; print(arrCounts);
        //     cout<<endl<<endl;
        // }
        return 0;
        
    } else if(counts.empty()) {
        // if(DEBUG==2)
        // {   
        //     cout<<"sum: "<<sum<<endl;
        //     // cout<<"counts: ";print(counts);
        //     cout<<"ans_sum: "<<1;
        //     // cout<<"arrCounts: "; print(arrCounts);
        //     cout<<endl<<endl;
        // }
        return 1;
    }
    
    ll ans = factMod[n-1];
    
    // assert(counts.size() == n-1);
    
    for(auto vl: counts){
        auto po_ans = (vl.s==1)? powMod(2, vl.f, mod):1LL;
        
        auto inv_ans = factMod[vl.f];
        inv_ans = inverseMod(inv_ans, mod)%mod;
        
        auto int_ans = (po_ans * inv_ans)%mod;
        
        ans = (ans*int_ans)%mod;
    }
    
        // if(DEBUG==2)
        // {   
        //     cout<<"sum: "<<sum<<endl;
        //     // cout<<"counts: ";print(counts);
        //     cout<<"ans_sum: "<<ans;
        //     // cout<<"arrCounts: "; print(arrCounts);
        //     cout<<endl<<endl;
        // }
    return ans%mod;
}

bool checkSufficient(vector<pll> &arrCounts, ll sum){
    
    for(auto val:arrCounts){
        if(val.first == sum and val.second>=2)
        {
            return true;
        }
    }
    
    return false;
}

void deleteCountSum(vector<pll> &arrCounts, ll sum){
    
    int sz = arrCounts.size();
    bool found = false;
    
    rep( j, 0 ,sz-1)
    {
        if(arrCounts[j].first == sum)
        {
            if(arrCounts[j].second ==2)
            {
                arrCounts.erase(j + arrCounts.begin());
                return;
                
            } else if(arrCounts[j].second>2)
            {
                arrCounts[j].second = arrCounts[j].second -2;
                return;
            } else
            {
                throw logic_error("");
            }
        }
    }
    
}
// void reAddCountSum(vector<pll> &arrCounts, ll sum){
//     sort(arrCounts.begin(), arrCounts.end());
// }

bool checkPossible(const vector<pll> &arrCounts, ll sum){
    
    int start_ptr = 0, end_ptr = arrCounts.size();
    end_ptr-=1;
    
    while(start_ptr<=end_ptr)
    {
        auto firstVal = arrCounts[start_ptr].f;
        auto firstCount = arrCounts[start_ptr].s;


        auto secondVal = arrCounts[end_ptr].f;
        auto secondCount = arrCounts[end_ptr].s;
        
        
        if(firstVal+secondVal!= sum or firstCount!=secondCount)
        {
            return false;
        }
        
        start_ptr+=1;
        end_ptr-=1;
    }
    return true;
}

// bool checkPossible(vector<pll> &arrCounts, ll sum){
    
//     int start_ptr = 0, end_ptr = arrCounts.size();
//     end_ptr-=1;
    
//     while(start_ptr<=end_ptr)
//     {
//         auto firstVal = arrCounts[start_ptr].f;
//         auto firstCount = arrCounts[start_ptr].s;


//         auto secondVal = arrCounts[end_ptr].f;
//         auto secondCount = arrCounts[end_ptr].s;
        
        
//         if(firstVal+secondVal!= sum or firstCount!=secondCount)
//         {
//             return false;
//         }
        
//         start_ptr+=1;
//         end_ptr-=1;
//     }
//     return true;
// }

ll computeAnswerForSumOpt(const vector<pll> &arrCounts, ll sum, int n){
   
    // auto sumFind = find(arrCounts.begin(), arrCounts.end(), sum);
    // if(sumFind== arrCounts.end() or *sumFind.second < 2)
    //     return 0;
    
    // if(!checkSufficient(arrCounts, sum))
    //     return 0;
    
    // deleteCountSum(arrCounts, sum);
    
    if(!checkPossible(arrCounts, sum)){
        return 0;
    }
    
    int start_ptr = 0, end_ptr = arrCounts.size();
    end_ptr-=1;
    
    ll ans = factMod[n-1];
    
    while(start_ptr<=end_ptr)
    {
        auto firstVal = arrCounts[start_ptr].f;
        auto firstCount = arrCounts[start_ptr].s;


        auto secondVal = arrCounts[end_ptr].f;
        auto secondCount = arrCounts[end_ptr].s;
        

        if(firstVal+secondVal!= sum or firstCount!=secondCount)
        {
            return 0;
        }
        
        auto countVal = (firstVal==secondVal)?firstCount/2:firstCount;
        
        
        auto po_ans = (firstVal!=secondVal)? twoPowMod[countVal]:1LL;
        
        auto inv_ans = inverseFactMod[countVal];
        
        // inv_ans = inverseMod(inv_ans, mod)%mod;
        
        auto int_ans = (po_ans * inv_ans)%mod;
        
        ans = (ans*int_ans)%mod;
        
        start_ptr+=1;
        end_ptr-=1;
        
    }
        // if(DEBUG==2)
        // {   
        //     cout<<"sum: "<<sum<<endl;
        //     // cout<<"counts: ";print(counts);
        //     cout<<"ans_sum: "<<ans;
        //     // cout<<"arrCounts: "; print(arrCounts);
        //     cout<<endl<<endl;
        // }
    return ans%mod;
}

ll compute_test_case_opt(vll &arr){
    int sz = arr.size();
    int n = sz/2;
    
    if(n==1)
    {
        return arr[0]==arr[1];
    }
    
    
    auto arrCounts = getCount(arr);
    
    set<ll> arrSet(arr.begin(), arr.end());
    
    auto ans = 0LL;
    
    for(auto sum: arrSet){
        
        auto ans_sum = computeAnswerForSum(arrCounts, sum, n)%mod;
        ans = (ans + ans_sum)%mod;
    }
    
    return ans;
}

ll compute_test_case_opt_2(vll &arr){
    int sz = arr.size();
    int n = sz/2;
    
    if(n==1)
    {
        return arr[0]==arr[1];
    }
    // print(arr);
    // print(arrSet);
    
    auto arrCounts = getCount(arr);
    
    // set<ll> arrSet(arr.begin(), arr.end());
    
    auto ans = 0LL;
    
    auto minVal = arr[0];
    auto maxVal = arr[sz-1];
    
    auto nonZeroCtr = 0;
    
    if(minVal>=0)
    {
        ans = computeAnswerForSum(arrCounts, maxVal, n)%mod;
    } else if(maxVal<0){
        ans = computeAnswerForSum(arrCounts, minVal, n)%mod;
    }
    else{
        
        ans = computeAnswerForSum(arrCounts, maxVal+minVal, n)%mod;

        // for(auto sum: arrSet){
        //     // if(DEBUG==2)
        //     // {
        //     //     cout<<sum<<" "<<arrCounts[sum]<<endl;
        //     // }
        //     auto ans_sum = computeAnswerForSum(arrCounts, sum, n)%mod;
        //     ans = (ans + ans_sum)%mod;
            
        //     if(ans_sum>0)
        //     {
        //         nonZeroCtr+=1;
        //     }
        //     if(ans_sum>0 and DEBUG==2){   
        //         cout<<"sum: "<<sum<<endl;
        //         // cout<<"counts: ";print(counts);
        //         cout<<"ans_sum: "<<ans;
        //         // cout<<"arrCounts: "; print(arrCounts);
        //         cout<<endl<<endl;
        //     }
        // }
    }
    
    assert(nonZeroCtr<=1);
    
    return ans;
}

ll compute_test_case_opt_3(vll &arr){
    int sz = arr.size();
    int n = sz/2;
    
    if(n==1)
    {
        return arr[0]==arr[1];
    }
    // print(arr);
    // print(arrSet);
    
    // auto arrCounts = getVectorCount(arr);
    // print(arrCounts);
    
    // set<ll> arrSet(arr.begin(), arr.end());
    
    auto ans = 0LL;
    
    // sort(arr.begin(), arr.end());
    
    auto minVal = arr[0];
    auto maxVal = arr[0];
    
    for(auto vl: arr)
    {
        minVal = min(minVal, vl);
        maxVal = max(maxVal, vl);
    }
    
    auto nonZeroCtr = 0;
    
    
    ll sumVal = max(minVal, min(maxVal, maxVal+minVal));
    
    auto delCounts = getVectorCountDel(arr, sumVal);
    // print(arrCounts);
    // print(delCounts);
    
    ans = (delCounts.empty())?0:computeAnswerForSumOpt(delCounts, sumVal, n)%mod;
    
    assert(nonZeroCtr<=1);
    
    return ans;
}

bool findAndDelete(vll &arr, ll sumVal){
    auto sumFind = find(arr.begin(), arr.end(), sumVal);
    if(sumFind!= arr.end())
    {   
        arr.erase(sumFind);
        return true;
    }
    return false;
}
ll compute_test_case_opt_4(vll &arr){
    int sz = arr.size();
    int n = sz/2;
    
    if(n==1)
    {
        return arr[0]==arr[1];
    }
    // print(arr);
    // print(arrSet);
    
    // auto arrCounts = getVectorCount(arr);
    // print(arrCounts);
    
    // set<ll> arrSet(arr.begin(), arr.end());
    
    auto ans = 0LL;
    
    // sort(arr.begin(), arr.end());
    
    auto minVal = arr[0];
    auto maxVal = arr[0];
    
    for(auto vl: arr)
    {
        minVal = min(minVal, vl);
        maxVal = max(maxVal, vl);
    }
    
    ll sumVal = max(minVal, min(maxVal, maxVal+minVal));
    
    sort(arr.begin(), arr.end());
    
    
    rep(delCnt, 1, 2){
        bool check = findAndDelete(arr, sumVal);
        
        if(!check)
        {
            return 0;
        }
    }
    
    // cout<<"sumVal: "<<sumVal<<endl; 
    // cout<<"arr: "; print(arr);
    
    sz-=2;
    // auto delCounts = getVectorCount(arr);
    
   
    
    vector<pair<ll ,ll > > delCounts;
    int cnt = 1;
    
    rep(j, 1, sz)
    {
        if(j==sz or arr[j]!=arr[j-1])
        {
            delCounts.pb(mp(arr[j-1], cnt));
            cnt = 1;
        }else{
            cnt+=1;
        }
    }
    
    // print(delCounts);
    ans = (delCounts.empty())?0:computeAnswerForSumOpt(delCounts, sumVal, n)%mod;
    
    return ans;
}
//Solution Link: https://www.codechef.com/viewsolution/28762304
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vll arr(2*n, 0);
        
        rep(j, 0, 2*n-1){
            cin>>arr[j];
        }
        
        // auto ans = compute_test_case(arr);
        // auto ans_opt = compute_test_case_opt(arr);
        auto ans_opt_2 = compute_test_case_opt_2(arr);
        // auto ans_opt_3 = compute_test_case_opt_3(arr);
        // auto ans_opt_4 = compute_test_case_opt_4(arr);
        // if(ans_opt_2!=ans_opt_3){
        //     throw logic_error("ans_opt!=ans_opt_2");
        // }
        cout<<ans_opt_2<<'\n';
    }
    return 0;
}

// 5
// 1 2 3 4 5 5 4 3 2 1
// 1
// -1 1
// 1
// 0 0
// 2
// 4 3 1 4
// 3
// 5 3 7 10 5 10
// 10
// 1 2 3 4 5 6 7 8 9 10 10 9 8 7 6 5 4 3 2 1
// 5
// -1 -2 -3 -4 -5 -5 -4 -3 -2 -1
