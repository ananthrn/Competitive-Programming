#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
 
    for(pll i:a)
    {
        cout<<i.f<<" "<<i.s<<"\n";
    }
    cout<<"\n";
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
 
ll pomod(ll a,ll b)
{
    a= a%mod;
    if(b<=0)
        return 1%mod;
    else if(b==1)
        return a%mod;
 
    ll vl = pomod((a*a)%mod,b/2);
    vl = vl%mod;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mod;
}

ll pomod(ll a,ll b,ll mo)
{
    a= a%mo;
    if(b<=0)
        return 1%mo;
    else if(b==1)
        return a%mo;
 
    ll vl = pomod((a*a)%mo,b/2);
    vl = vl%mo;
    if(b%2==0)
        return vl;
    else
        return ((vl)*a)%mo;
}
ll factmod(ll n, ll mo)
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
ll inv(ll a,ll mo)
{
    return pomod(a,mo-2,mo);
}

ll combinationMod(ll n, ll i)
{
    ll ans = 1;
    ans = (ans * factmod(n,mod))%mod;
    ll invVal =  (inv(factmod(i,mod),mod)%mod * inv(factmod(n-i,mod),mod)%mod)%mod;
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
    
    FenwickTree(int n=0)
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

class Node{
  private:
    int thisIndex = -1;
    int n;
    ll numSmallerThanThisIndex = 0;
    
    
    
    ll getNumGreaterThan(int subTreeNode) {
        auto getFirstHigher = upper_bound(allNodesInSubTree.begin(), allNodesInSubTree.end(), subTreeNode);
        return distance(getFirstHigher,  allNodesInSubTree.end());
    }
    
    ll getNumSmallerThanOutside(int subTreeNode) {
        return (subTreeNode-1) - getNumSmallerThan(subTreeNode);
    }
    
    ll getNumGreaterThanOutside(int subTreeNode) {
        return (n-subTreeNode)-getNumGreaterThan(subTreeNode);
    }
    
    ll getNumSmallerThanThisIndex() {
        return numSmallerThanThisIndex;
    }
    
    ll getNumGreaterThanThisIndex() {
        return allNodesInSubTree.size()-1-numSmallerThanThisIndex;
    }
    
    ll getNumSmallerThanThisIndexOutside() {
        return (thisIndex-1) - getNumSmallerThanThisIndex();
    }
    
    ll getNumGreaterThanThisIndexOutside() {
        return (n-thisIndex) - getNumGreaterThanThisIndex();
    }
    
    void addSubTreeNode(int subTreeNode) {
        // if(subTreeNode==thisIndex){
        //     throw logic_error("Duplicate subtree node found\n");
        // }
        
        if(subTreeNode<thisIndex){
            numSmallerThanThisIndex+=1;
        }
        
        allNodesInSubTree.push_back(subTreeNode);
    }
    
    ll computeAnsForSubTreeNode( int subTreeNode, int config){
        if(subTreeNode==thisIndex)
            return 0LL;
            
        if(config==1){
            if(subTreeNode<thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumGreaterThanThisIndex();
            return ansForSubTreeNode;
        } else if(config==2){
            ll ansForSubTreeNode = 0LL;
            if(subTreeNode>thisIndex){
                ansForSubTreeNode = getNumSmallerThanThisIndex();
            } else if(subTreeNode<thisIndex){
                ansForSubTreeNode = getNumGreaterThanThisIndex();
            }
            else
            {
                throw logic_error("Wrong config supplied\n");
            }
            return ansForSubTreeNode;
        } else if(config==3){
            if(subTreeNode>thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumSmallerThanThisIndex();
            return ansForSubTreeNode;
        } else{
            throw logic_error("Wrong config supplied\n");
        }
    }
    
    ll computeAnsForSubTreeNodeOutside(int subTreeNode, int config){
        if(subTreeNode==thisIndex)
            return 0LL;
        
        if(config==1){
            if(subTreeNode<thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumGreaterThanThisIndexOutside();
            return ansForSubTreeNode;
        } else if(config==2){
            ll ansForSubTreeNode = 0LL;
            if(subTreeNode<thisIndex){
                ansForSubTreeNode = getNumGreaterThanThisIndexOutside();
            } else if(subTreeNode > thisIndex){
                ansForSubTreeNode = getNumSmallerThanThisIndexOutside();
            }
    
            return ansForSubTreeNode;
        } else if(config==3){
            if(subTreeNode>thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumSmallerThanThisIndexOutside();
            return ansForSubTreeNode;
        } else{
            throw logic_error("Wrong config supplied\n");
        }
    }
    
    
    
  public:
    vector<int> allNodesInSubTree;
    
    Node(int n= mx5){
        this->n = n;
    }
    
    void sortNodeArray(){
        sort(allNodesInSubTree.begin(), allNodesInSubTree.end());

    }
    
    ll getNumSmallerThan(int subTreeNode) {
        auto getFirstEqualToOrHigher = lower_bound(allNodesInSubTree.begin(), allNodesInSubTree.end(), subTreeNode);
         return distance(allNodesInSubTree.begin(), getFirstEqualToOrHigher);
    }
    
    void mergeChildNode(const Node & childNode){
        for(auto subTreeNode: childNode.allNodesInSubTree){
            addSubTreeNode(subTreeNode);
        }
    }
    
    void mergeChildNode(const Node * childNode){
        for(auto subTreeNode: childNode->allNodesInSubTree){
            addSubTreeNode(subTreeNode);
        }
    }
    
    ll computeAnsForChildNode(const Node & childNode, int config){
        ll valAns = 0;
        for(auto subTreeNode:childNode.allNodesInSubTree){
            valAns += computeAnsForSubTreeNode(subTreeNode, config);   
        }
        
        return valAns;
    }
    
    ll computeAnsForChildNode(const Node * childNode, int config){
        ll valAns = 0;
        for(auto subTreeNode:childNode->allNodesInSubTree){
            valAns += computeAnsForSubTreeNode(subTreeNode, config);   
        }
        
        return valAns;
    }
    
    ll computeAnsOutsideSubtree(int config){
        ll valAns = 0;
        for(int subTreeNode: allNodesInSubTree){
            valAns += computeAnsForSubTreeNodeOutside(subTreeNode, config);
        }
        return valAns;
    }
    
    ll computeAnsOutsideSubtreeOptimized(int config){
        ll valAns = 0;
        if(config==1){
            ll valOutside = getNumGreaterThanThisIndexOutside();
            ll valInside = getNumGreaterThanThisIndex();
            return valOutside*valInside;
        }else if(config==2){
            
            ll valInsideSmall = getNumSmallerThanThisIndex();
            ll valInsideGreat = getNumGreaterThanThisIndex();
            
            ll valOutsideSmall = getNumSmallerThanThisIndexOutside();
            ll valOutsideGreat = getNumGreaterThanThisIndexOutside();
            
            return valInsideSmall*valOutsideGreat + valInsideGreat*valOutsideSmall;
            
        }else if(config==3){
            ll valOutside = getNumSmallerThanThisIndexOutside();
            ll valInside = getNumSmallerThanThisIndex();
            
            return valOutside*valInside;
        }else{
            throw logic_error("Wrong config supplied\n");
        }
        return valAns;
    }
    
    void setThisIndex(int thisIndex){
        this->thisIndex = thisIndex;
    }
    
    void setThisIndexAndNumSmallerThan(int thisIndex, ll numSmallerThanThisIndex){
        this->thisIndex = thisIndex;
        this->numSmallerThanThisIndex = numSmallerThanThisIndex;
    }
    
    void initThisIndex(int thisIndex){
        setThisIndex(thisIndex);
        allNodesInSubTree = vi(1, thisIndex);
    }
    
    void updateThisIndex(int thisIndex){
        setThisIndex(thisIndex);
        addSubTreeNode(thisIndex);
    }
    
    
};

class FenwickNode{
  private:
    int thisIndex = -1;
    int n;
    ll numSmallerThanThisIndex = 0;
    
    
    
    ll getNumGreaterThan(int subTreeNode) {
        if(subTreeNode==n){
            return 0LL;
        }
        return subTreeFenwick.query(subTreeNode+1, n);
    }
    
    ll getNumSmallerThanOutside(int subTreeNode) {
        return (subTreeNode-1) - getNumSmallerThan(subTreeNode);
    }
    
    ll getNumGreaterThanOutside(int subTreeNode) {
        return (n-subTreeNode)-getNumGreaterThan(subTreeNode);
    }
    
    ll getNumSmallerThanThisIndex() {
        return numSmallerThanThisIndex;
    }
    
    ll getNumGreaterThanThisIndex() {
        return allNodesInSubTree.size()-1-numSmallerThanThisIndex;
    }
    
    ll getNumSmallerThanThisIndexOutside() {
        return (thisIndex-1) - getNumSmallerThanThisIndex();
    }
    
    ll getNumGreaterThanThisIndexOutside() {
        return (n-thisIndex) - getNumGreaterThanThisIndex();
    }
    
    void addSubTreeNode(int subTreeNode) {
        
        
        if(subTreeNode<thisIndex){
            numSmallerThanThisIndex+=1;
        }
        
        allNodesInSubTree.push_back(subTreeNode);
        subTreeFenwick.update(subTreeNode, 1);
    }
    
    ll computeAnsForSubTreeNode( int subTreeNode, int config){
        if(subTreeNode==thisIndex)
            return 0LL;
            
        if(config==1){
            if(subTreeNode<thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumGreaterThanThisIndex();
            return ansForSubTreeNode;
        } else if(config==2){
            ll ansForSubTreeNode = 0LL;
            if(subTreeNode>thisIndex){
                ansForSubTreeNode = getNumSmallerThanThisIndex();
            } else if(subTreeNode<thisIndex){
                ansForSubTreeNode = getNumGreaterThanThisIndex();
            }
            else
            {
                throw logic_error("Wrong config supplied\n");
            }
            return ansForSubTreeNode;
        } else if(config==3){
            if(subTreeNode>thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumSmallerThanThisIndex();
            return ansForSubTreeNode;
        } else{
            throw logic_error("Wrong config supplied\n");
        }
    }
    
    ll computeAnsForSubTreeNodeOutside(int subTreeNode, int config){
        if(subTreeNode==thisIndex)
            return 0LL;
        
        if(config==1){
            if(subTreeNode<thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumGreaterThanThisIndexOutside();
            return ansForSubTreeNode;
        } else if(config==2){
            ll ansForSubTreeNode = 0LL;
            if(subTreeNode<thisIndex){
                ansForSubTreeNode = getNumGreaterThanThisIndexOutside();
            } else if(subTreeNode > thisIndex){
                ansForSubTreeNode = getNumSmallerThanThisIndexOutside();
            }
    
            return ansForSubTreeNode;
        } else if(config==3){
            if(subTreeNode>thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumSmallerThanThisIndexOutside();
            return ansForSubTreeNode;
        } else{
            throw logic_error("Wrong config supplied\n");
        }
    }
    
    
    
  public:
    vector<int> allNodesInSubTree;
    FenwickTree subTreeFenwick;
    
    FenwickNode(int n=mx5){
        subTreeFenwick = FenwickTree(n);
        this->n = n;
    }
    
    void sortNodeArray(){
        sort(allNodesInSubTree.begin(), allNodesInSubTree.end());

    }
    
    ll getNumSmallerThan(int subTreeNode) {
        return subTreeFenwick.prefQuery(subTreeNode-1);
    }
    
    void mergeChildNode(const FenwickNode & childNode){
        for(auto subTreeNode: childNode.allNodesInSubTree){
            addSubTreeNode(subTreeNode);
        }
    }
    
    void mergeChildNode(const FenwickNode * childNode){
        for(auto subTreeNode: childNode->allNodesInSubTree){
            addSubTreeNode(subTreeNode);
        }
    }
    
    ll computeAnsForChildNode(const FenwickNode & childNode, int config){
        ll valAns = 0;
        for(auto subTreeNode:childNode.allNodesInSubTree){
            valAns += computeAnsForSubTreeNode(subTreeNode, config);   
        }
        
        return valAns;
    }
    
    ll computeAnsForChildNode(const FenwickNode * childNode, int config){
        ll valAns = 0;
        for(auto subTreeNode:childNode->allNodesInSubTree){
            valAns += computeAnsForSubTreeNode(subTreeNode, config);   
        }
        
        return valAns;
    }
    
    ll computeAnsOutsideSubtree(int config){
        ll valAns = 0;
        for(int subTreeNode: allNodesInSubTree){
            valAns += computeAnsForSubTreeNodeOutside(subTreeNode, config);
        }
        return valAns;
    }
    
    ll computeAnsOutsideSubtreeOptimized(int config){
        ll valAns = 0;
        if(config==1){
            ll valOutside = getNumGreaterThanThisIndexOutside();
            ll valInside = getNumGreaterThanThisIndex();
            return valOutside*valInside;
        }else if(config==2){
            
            ll valInsideSmall = getNumSmallerThanThisIndex();
            ll valInsideGreat = getNumGreaterThanThisIndex();
            
            ll valOutsideSmall = getNumSmallerThanThisIndexOutside();
            ll valOutsideGreat = getNumGreaterThanThisIndexOutside();
            
            return valInsideSmall*valOutsideGreat + valInsideGreat*valOutsideSmall;
            
        }else if(config==3){
            ll valOutside = getNumSmallerThanThisIndexOutside();
            ll valInside = getNumSmallerThanThisIndex();
            
            return valOutside*valInside;
        }else{
            throw logic_error("Wrong config supplied\n");
        }
        return valAns;
    }
    
    void setThisIndex(int thisIndex){
        this->thisIndex = thisIndex;
    }
    
    void setThisIndexAndNumSmallerThan(int thisIndex, ll numSmallerThanThisIndex){
        this->thisIndex = thisIndex;
        this->numSmallerThanThisIndex = numSmallerThanThisIndex;
    }
    
    void initThisIndex(int thisIndex){
        setThisIndex(thisIndex);
        numSmallerThanThisIndex = 0;
        allNodesInSubTree = vi(1, thisIndex);
        subTreeFenwick.update(thisIndex, 1);
    }
    
    void updateThisIndex(int thisIndex){
        setThisIndex(thisIndex);
        addSubTreeNode(thisIndex);
    }
    
    
};

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
    
    
class OrderedSetNode{
  private:
    int thisIndex = -1;
    int n;
    ll numSmallerThanThisIndex = 0;
    
    ll getNumSmallerThanOutside(int subTreeNode) {
        return (subTreeNode-1) - getNumSmallerThan(subTreeNode);
    }
    
    ll getNumSmallerThanThisIndex() {
        return numSmallerThanThisIndex;
    }
    
    ll getNumGreaterThanThisIndex() {
        return allNodesInSubTree.size()-1-numSmallerThanThisIndex;
    }
    
    ll getNumSmallerThanThisIndexOutside() {
        return (thisIndex-1) - getNumSmallerThanThisIndex();
    }
    
    ll getNumGreaterThanThisIndexOutside() {
        return (n-thisIndex) - getNumGreaterThanThisIndex();
    }
    
    void addSubTreeNode(int subTreeNode) {
        
        
        if(subTreeNode<thisIndex){
            numSmallerThanThisIndex+=1;
        }
        
        allNodesInSubTree.push_back(subTreeNode);
        subTreeSet.insert(subTreeNode);
    }
    
    ll computeAnsForSubTreeNode( int subTreeNode, int config){
        if(subTreeNode==thisIndex)
            return 0LL;
            
        if(config==1){
            if(subTreeNode<thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumGreaterThanThisIndex();
            return ansForSubTreeNode;
        } else if(config==2){
            ll ansForSubTreeNode = 0LL;
            if(subTreeNode>thisIndex){
                ansForSubTreeNode = getNumSmallerThanThisIndex();
            } else if(subTreeNode<thisIndex){
                ansForSubTreeNode = getNumGreaterThanThisIndex();
            }
            else
            {
                throw logic_error("Wrong config supplied\n");
            }
            return ansForSubTreeNode;
        } else if(config==3){
            if(subTreeNode>thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumSmallerThanThisIndex();
            return ansForSubTreeNode;
        } else{
            throw logic_error("Wrong config supplied\n");
        }
    }
    
    ll computeAnsForSubTreeNodeOutside(int subTreeNode, int config){
        if(subTreeNode==thisIndex)
            return 0LL;
        
        if(config==1){
            if(subTreeNode<thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumGreaterThanThisIndexOutside();
            return ansForSubTreeNode;
        } else if(config==2){
            ll ansForSubTreeNode = 0LL;
            if(subTreeNode<thisIndex){
                ansForSubTreeNode = getNumGreaterThanThisIndexOutside();
            } else if(subTreeNode > thisIndex){
                ansForSubTreeNode = getNumSmallerThanThisIndexOutside();
            }
    
            return ansForSubTreeNode;
        } else if(config==3){
            if(subTreeNode>thisIndex){
                return 0LL;
            }
            ll ansForSubTreeNode = getNumSmallerThanThisIndexOutside();
            return ansForSubTreeNode;
        } else{
            throw logic_error("Wrong config supplied\n");
        }
    }
    
    
    
  public:
    vector<int> allNodesInSubTree;
    
    
    
    ordered_set subTreeSet;
    
    OrderedSetNode(int n=mx5){
        this->n = n;
    }
    
    void sortNodeArray(){
        sort(allNodesInSubTree.begin(), allNodesInSubTree.end());

    }
    
    ll getNumSmallerThan(int subTreeNode) {
        return subTreeSet.order_of_key(subTreeNode);
    }
    
    void mergeChildNode(const OrderedSetNode & childNode){
        for(auto subTreeNode: childNode.allNodesInSubTree){
            addSubTreeNode(subTreeNode);
        }
    }
    
    void mergeChildNode(const OrderedSetNode * childNode){
        for(auto subTreeNode: childNode->allNodesInSubTree){
            addSubTreeNode(subTreeNode);
        }
    }
    
    ll computeAnsForChildNode(const OrderedSetNode & childNode, int config){
        ll valAns = 0;
        for(auto subTreeNode:childNode.allNodesInSubTree){
            valAns += computeAnsForSubTreeNode(subTreeNode, config);   
        }
        
        return valAns;
    }
    
    ll computeAnsForChildNode(const OrderedSetNode * childNode, int config){
        ll valAns = 0;
        for(auto subTreeNode:childNode->allNodesInSubTree){
            valAns += computeAnsForSubTreeNode(subTreeNode, config);   
        }
        
        return valAns;
    }
    
    ll computeAnsOutsideSubtree(int config){
        ll valAns = 0;
        for(int subTreeNode: allNodesInSubTree){
            valAns += computeAnsForSubTreeNodeOutside(subTreeNode, config);
        }
        return valAns;
    }
    
    ll computeAnsOutsideSubtreeOptimized(int config){
        ll valAns = 0;
        if(config==1){
            ll valOutside = getNumGreaterThanThisIndexOutside();
            ll valInside = getNumGreaterThanThisIndex();
            return valOutside*valInside;
        }else if(config==2){
            
            ll valInsideSmall = getNumSmallerThanThisIndex();
            ll valInsideGreat = getNumGreaterThanThisIndex();
            
            ll valOutsideSmall = getNumSmallerThanThisIndexOutside();
            ll valOutsideGreat = getNumGreaterThanThisIndexOutside();
            
            return valInsideSmall*valOutsideGreat + valInsideGreat*valOutsideSmall;
            
        }else if(config==3){
            ll valOutside = getNumSmallerThanThisIndexOutside();
            ll valInside = getNumSmallerThanThisIndex();
            
            return valOutside*valInside;
        }else{
            throw logic_error("Wrong config supplied\n");
        }
        return valAns;
    }
    
    void setThisIndex(int thisIndex){
        this->thisIndex = thisIndex;
    }
    
    void setThisIndexAndNumSmallerThan(int thisIndex, ll numSmallerThanThisIndex){
        this->thisIndex = thisIndex;
        this->numSmallerThanThisIndex = numSmallerThanThisIndex;
    }
    
    void initThisIndex(int thisIndex){
        setThisIndex(thisIndex);
        numSmallerThanThisIndex = 0;
        allNodesInSubTree = {thisIndex};
        subTreeSet.insert(thisIndex);
    }
    
    void updateThisIndex(int thisIndex){
        setThisIndex(thisIndex);
        addSubTreeNode(thisIndex);
    }
    
    
};

ll dfsCompute(int u, int p, int config, const vector<vi> &adj, vector<Node> &nodeArray){
    ll subTreeWays = 0;
    ll thisNodeAns = 0;
    nodeArray[u].initThisIndex(u);
    for(auto v: adj[u]){
        if(v!=p){
            subTreeWays+=dfsCompute(v,u, config, adj, nodeArray);
            thisNodeAns += nodeArray[u].computeAnsForChildNode(nodeArray[v], config);
            nodeArray[u].mergeChildNode(nodeArray[v]);
        }
    }
    thisNodeAns+=nodeArray[u].computeAnsOutsideSubtree(config);
    return subTreeWays + thisNodeAns;
}
const bool DEBUG = false;

ll dfsComputeOptimized(int u, int p, int config, const vector<vi> &adj, vector<Node*> &nodeArray, int n){
    ll subTreeWays = 0;
    ll thisNodeAns = 0;
    
    // nodeArray[u].initThisIndex(u);
    
    int mx = -1;
    int mxChild = -1;
    
    
    for(auto v: adj[u]){
        if(v!=p){
            subTreeWays+=dfsComputeOptimized(v, u, config, adj, nodeArray, n);
            if(DEBUG){
                cout<<"Child v: "<<v<<"\n";
                cout<<"allNodesInSubTree.size: "<<nodeArray[v]->allNodesInSubTree.size()<<"\n";
                cout<<"allNodesInSubTree: ";
                print(nodeArray[v]->allNodesInSubTree);
                cout<<"\n\n";
            }
            int sz = nodeArray[v]->allNodesInSubTree.size();
            if(sz>mx){
                mx = sz;
                mxChild = v;
            }
        }
    }
    
    if(mxChild!=-1){
        nodeArray[u] = nodeArray[mxChild];
        ll numSmallerThan = 0;
        for(auto subTreeNode: nodeArray[u]->allNodesInSubTree){
            if(subTreeNode<u)
                numSmallerThan+=1;
        }
        nodeArray[u]->setThisIndexAndNumSmallerThan(u, numSmallerThan);
        nodeArray[u]->updateThisIndex(u);
    } else
    {   
        nodeArray[u] = new Node(n);
        nodeArray[u]->initThisIndex(u);
    }
    
    if(DEBUG){
        cout<<"u: "<<u<<"\n";
        cout<<"mxChild: "<<mxChild<<"\n";
        print(nodeArray[u]->allNodesInSubTree);
        cout<<"\n\n";
    }
    
    for(auto v: adj[u]){
        if(v!=p and v!=mxChild){
            thisNodeAns += nodeArray[u]->computeAnsForChildNode(nodeArray[v], config);
            nodeArray[u]->mergeChildNode(nodeArray[v]);
        }
    }
    thisNodeAns+=nodeArray[u]->computeAnsOutsideSubtreeOptimized(config);
    if(DEBUG){
        cout<<"u: "<<u<<"\n";
        cout<<"thisNodeAns: "<<thisNodeAns<<"\n";
        cout<<"subTreeWays: "<<subTreeWays<<"\n";
        cout<<"allNodesInSubTree: ";
        print(nodeArray[u]->allNodesInSubTree);
        cout<<"\n\n";
    }
    return subTreeWays + thisNodeAns;
}

ll dfsComputeOptimized(int u, int p, int config, const vector<vi> &adj, vector<FenwickNode*> &nodeArray, int n){
    ll subTreeWays = 0;
    ll thisNodeAns = 0;
    
    // nodeArray[u].initThisIndex(u);
    
    int mx = -1;
    int mxChild = -1;
    
    
    for(auto v: adj[u]){
        if(v!=p){
            subTreeWays+=dfsComputeOptimized(v, u, config, adj, nodeArray, n);
            int sz = nodeArray[v]->allNodesInSubTree.size();
            if(sz>mx){
                mx = sz;
                mxChild = v;
            }
        }
    }
    
    if(mxChild!=-1){
        nodeArray[u] = nodeArray[mxChild];
        ll numSmallerThan = 0;
        numSmallerThan = nodeArray[u]->getNumSmallerThan(u);
        nodeArray[u]->setThisIndexAndNumSmallerThan(u, numSmallerThan);
        nodeArray[u]->updateThisIndex(u);
    } else
    {   
        nodeArray[u] = new FenwickNode(n);
        nodeArray[u]->initThisIndex(u);
    }
    
    for(auto v: adj[u]){
        if(v!=p and v!=mxChild){
            thisNodeAns += nodeArray[u]->computeAnsForChildNode(nodeArray[v], config);
            nodeArray[u]->mergeChildNode(nodeArray[v]);
        }
    }
    thisNodeAns+=nodeArray[u]->computeAnsOutsideSubtreeOptimized(config);
    if(DEBUG){
        cout<<"u: "<<u<<"\n";
        cout<<"thisNodeAns: "<<thisNodeAns<<"\n";
        cout<<"subTreeWays: "<<subTreeWays<<"\n";
        cout<<"allNodesInSubTree: ";
        print(nodeArray[u]->allNodesInSubTree);
        cout<<"\n\n";
    }
    
    
    return subTreeWays + thisNodeAns;
}

ll dfsComputeOptimized(int u, int p, int config, const vector<vi> &adj, vector<OrderedSetNode*> &nodeArray, int n){
    ll subTreeWays = 0;
    ll thisNodeAns = 0;
    
    // nodeArray[u].initThisIndex(u);
    
    int mx = -1;
    int mxChild = -1;
    
    
    for(auto v: adj[u]){
        if(v!=p){
            subTreeWays+=dfsComputeOptimized(v, u, config, adj, nodeArray, n);
            int sz = nodeArray[v]->allNodesInSubTree.size();
            if(sz>mx){
                mx = sz;
                mxChild = v;
            }
        }
    }
    
    if(mxChild!=-1){
        nodeArray[u] = nodeArray[mxChild];
        ll numSmallerThan = 0;
        numSmallerThan = nodeArray[u]->getNumSmallerThan(u);
        nodeArray[u]->setThisIndexAndNumSmallerThan(u, numSmallerThan);
        nodeArray[u]->updateThisIndex(u);
    } else
    {   
        nodeArray[u] = new OrderedSetNode(n);
        nodeArray[u]->initThisIndex(u);
    }
    
    for(auto v: adj[u]){
        if(v!=p and v!=mxChild){
            thisNodeAns += nodeArray[u]->computeAnsForChildNode(nodeArray[v], config);
            nodeArray[u]->mergeChildNode(nodeArray[v]);
        }
    }
    thisNodeAns+=nodeArray[u]->computeAnsOutsideSubtreeOptimized(config);
    if(DEBUG){
        cout<<"u: "<<u<<"\n";
        cout<<"thisNodeAns: "<<thisNodeAns<<"\n";
        cout<<"subTreeWays: "<<subTreeWays<<"\n";
        cout<<"allNodesInSubTree: ";
        print(nodeArray[u]->allNodesInSubTree);
        cout<<"\n\n";
    }
    
    
    return subTreeWays + thisNodeAns;
}

ll compute_ans(const vector<vi> &adj, int config, int n){
    vector<Node> nodeArray(n+5,Node(n));
    return dfsCompute(1, 0, config, adj, nodeArray);
}

ll compute_ans_optimized(const vector<vi> &adj, int config, int n){
    vector<Node*> nodeArray(n+5);
    return dfsComputeOptimized(1, 0, config, adj, nodeArray, n);
}

// ll compute_ans_optimized_global(const vector<vi> &adj, int config, int n){
//     ll ans =  dfsComputeOptimizedGlobal(1, 0, config, adj,n);
//     // clearNodeArray(nodeArray);
//     return ans;
// }

ll compute_ans_fenwick(const vector<vi> &adj, int config, int n){
    vector<FenwickNode*> nodeArray(n+5);
    return dfsComputeOptimized(1, 0, config, adj, nodeArray, n);
}
ll compute_ans_ordered_set(const vector<vi> &adj, int config, int n, int root = 1){
    vector<OrderedSetNode*> nodeArray(n+5);
    return dfsComputeOptimized(root, 0, config, adj, nodeArray, n);
}

pair<bool, int> isPathGraph(const vector<vi>&adj, int n){
    int numOnes = 0;
    int numTwos = 0;
    int startVert = -1;    
    rep(i,1,n){
        int sz = adj[i].size();
        
        if(sz==1){
            numOnes+=1;
            startVert = i;
        } else if(sz==2)
        {
            numTwos+=1;
        } else {
            return make_pair(false,-1);
        }
    }
    
    if(numOnes==2 and numTwos==n-2){
        return make_pair(true, startVert);
    } else
    {
        return make_pair(false,-1);
    }
}
ll compute_ans_dynamic(const vector<vi> &adj, int config, int n){
    auto isPath = isPathGraph(adj, n);
    
    if(!isPath.first){
        return compute_ans_optimized(adj, config, n);
    } else
    {
        return compute_ans_ordered_set(adj, config, n, 1);
    }
}

// Solution Link: https://www.codechef.com/viewsolution/26054283
int main(void)
{
    ios_base::sync_with_stdio(false);
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p1, p2, p3;
        cin>>p1>>p2>>p3;
        vector<vi> adj(n+5);
        rep(j,1,n-1){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cout<<compute_ans_dynamic(adj, p2, n)<<"\n";
    }
    
    
    return 0;
}
