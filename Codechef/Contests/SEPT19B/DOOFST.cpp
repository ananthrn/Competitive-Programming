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
void print(vector<pii> &a)
{
 
    for(pll i:a)
    {
        cout<<"("<<i.f<<", "<<i.s<<") ";
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

void print(vector<string> &a)
{
 
    for(auto &s:a)
    {
        cout<<s<<"\n";
    }
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
ll ceillog2(ll n)
{
    ll h = 0;
    ll p = 1;
    while(p<n)
    {
        h++;
        p*=2;
    }
    
    return h;
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
    
    FenwickTree(int n)
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

vector<string> hateStrings;

// int helper_complete_graph(int lo, int hi, int n, int m){
//     int mid = (lo+hi)/2;
//     int max_hates = mx6/n;
    
    
//     if(hi<=lo)
//     {
//         return 0;
//     }
    
//     int left_ans = helper_complete_graph(lo,mid,n,m);
    
//     if(left_ans==-1 or left_ans>max_hates)
//     {
//         return -1;
//     }
    
//     int right_ans = helper_complete_graph(mid+1,hi,n,m);
    
//     if(right_ans==-1 or right_ans>max_hates)
//     {
//         return -1;
//     }
    
//     int this_ans = 1+ left_ans + right_ans;
    
//     if(this_ans>max_hates)
//         return -1;
        
//     string hateString = string((mid-0+1),'0') + string((n-1-mid),'1');
    
//     hateStrings.pb(hateString);
    
//     return this_ans;
    
// }
const bool DEBUG = false;

string construct_string(int lo, int hi, int divs)
{
    if(hi<lo)
    {
        return "";
    }
    
    if(hi==lo)
    {
        return "0";
    }
    
    int mid = (lo+hi)/2;
    if(divs==1)
    {
        string thisString = string((mid-lo+1),'0') + string((hi-mid),'1');
        return thisString;
    }
    
    
    string leftString = construct_string(lo, mid, divs-1);
    string rightString = construct_string(mid+1,hi,divs-1);
    
    return leftString+rightString;
}
int helper_complete_graph(int n, int divs)
{   
    
    if(divs>ceillog2(n))
    {
        return 0;
    }
    string thisString = construct_string(0,n-1,divs);
    
    // cout<<"n, divs: "<<n<<" "<<divs<<"\n";
    // cout<<"thisString: "<<thisString<<"\n\n";
    
    int lower_answer = helper_complete_graph(n, divs+1);
    int max_hates = mx6/n;
    
    if (lower_answer ==-1)
        return -1;
    
    int this_ans = 1+lower_answer;
    
    if(this_ans>max_hates)
        return -1;
    
    hateStrings.pb(thisString);
    
    return this_ans;
}

int helper_graph(int numComponents, int n, int divs)
{
    if(divs>ceillog2(numComponents))
    {
        return 0;
    }
    
    int lower_answer = helper_graph(numComponents, n ,divs+1);
    int max_hates = mx6/n;
    
    if(lower_answer==-1)
        return -1;
    
    int this_ans = 1+lower_answer;
    
    if(this_ans>max_hates)
        return -1;
    
    string thisString = construct_string(0,numComponents-1,divs);
    hateStrings.pb(thisString);
    
    return this_ans;
}

bool verify_hate_strings(const vector<string> & hateStrings, const vector<pii> &edges, int n)
{
    
    // vector<vb> adjMat(n+1,vb(n+1,false));
    
    
    // for(auto s: hateStrings)
    // {
    //     int s_sz = s.size();
    //     assert(n==s_sz);
    //     rep(i,0,n-1)
    //     {
    //         rep(j,i,n-1)
    //         {
    //             if(s[i]!=s[j])
    //             {
    //                 adjMat[i+1][j+1] = adjMat[j+1][i+1] = true;
    //             }
    //         }
    //     }
    // }
    
    vector<pii> missingEdges;
    
    bool ans = true;
    
    for(auto edge: edges)
    {
        bool found = false;
        
        for(auto &s: hateStrings){
            if(s[edge.f-1]!=s[edge.s-1])
            {
                found = true;
            }
        }
        
        if(!found)
        {
            missingEdges.pb(edge);
            ans = false;
        }
    }
    
    // print(missingEdges);
    return ans;
}
void compute_complete_graph(int n, int m, vector<pii> &edges){
    int hates = helper_complete_graph(n, 1);
    
    cout<<hates<<"\n";
    if(hates>0)
    {   
        bool verify = verify_hate_strings(hateStrings, edges, n);
        if(!verify)
        {
            throw logic_error("Edge missing\n");
        }
        print(hateStrings);
    }
}

// pair<bool, vi> getComponentNumbersInverse(int n, const vector<vi> &adj)
// {
//     vi componentNumbers (n+1,-1);
    
//     rep(vert,1,n)
//     {   
//         //Check that it is not part of a component yet
//         if(componentNumbers[vert]!=-1){
//             //Make it the primary of the component
//             componentNumbers[vert]=vert;
            
//             vb hasInverseEdge(n+1,true);
            
//             hasInverseEdge[vert]=false;
            
//             for(int u: adj[v])
//             {
//                 hasInverseEdge[u]=false;
//             }
            
//             rep(neb, 1, n)
//             {   
//                 //Check that it is indeed a neighbhor in the inverse graph
//                 if(neb!=vert and hasInverseEdge[neb])
//                 {
//                     if(componentNumbers[neb]!=-1)
//                     {
//                         // A neighbhor you  are connected to was already assigned to another component
//                         // This means that the connectedComponent you are part of was not a clique
//                         // Thus it is not possible
                        
//                         return mp(false, {});
//                     } else
//                     {   
//                         //Assign neb to have primary component number = vert
//                         componentNumbers[neb]=vert;
//                     }
//                 } 
//             }
//         }
//     }
    
//     return mp(true,componentNumbers);
// }

bool deleteFromVector(vi &vec, int ind)
{
    int vec_sz = vec.size();
    if(ind>=vec_sz)
    {
        return false;
    }
    
    swap(vec[ind],vec[vec_sz-1]);
    
    vec.pop_back();
    
    return true;
}

class ListWithDelete{
    unordered_map<int,int> indexMap;
    
    
    public:
    vi thisVec;
    
    ListWithDelete(vi thisVec)
    {
        this->thisVec = vector<int>(thisVec.begin(),thisVec.end());
        
        int thisVecSize = thisVec.size();
        
        rep(ind, 0 , thisVecSize-1)
        {   
            int val = thisVec[ind];
            indexMap[val] = ind;
        }
    }
    
    bool deleteElement(int elem)
    {
        if(thisVec.empty() or !indexMap.count(elem))
        {   if(DEBUG)
            {   cout<<"Elem: "<<elem<<"\n";
                if(thisVec.empty())
                {
                    cout<<"Deleting from empty array:\n";
                
                } else if(!indexMap.count(elem))
                {
                    cout<<"Element doesn't exist\n";
                }
            }
            return false;
        }
        
        int last_ind = thisVec.size();
        last_ind = last_ind -1;
        int last_val = thisVec[last_ind];
        
        
        int elem_ind = indexMap[elem];
        
        if(elem!=thisVec[elem_ind])
        {
            throw logic_error("Error in Delete");
        }
        
        //Swap values
        swap(thisVec[elem_ind], thisVec[last_ind]);
        indexMap[last_val] = elem_ind;
        
        //Delete 
        indexMap.erase(elem);
        thisVec.pop_back();
        
        return true;
        
    }
};


pair<vi, vector<vi> > getComponentNumbersInverse(int n, vector<unordered_map<int, bool>> &AdjMat){
    vector<int> unreachedVerts(n,0);
    
    rep(vert, 0 ,n-1)
    {
        unreachedVerts[vert]=vert+1;
    }
    
    ListWithDelete unreachedList(unreachedVerts);
    
    
    vi componentNumbers (n+1,-1);
    vector<vi> components;
    
    rep(src,1,n)
    {   
        //Doesnt belong to a component yet
        if(componentNumbers[src]==-1)
        {
            vi thisComponent;
            std::queue<int> Q;
            
            Q.push(src);
            
            componentNumbers[src]=src;
            thisComponent.pb(src);
            
            bool check = unreachedList.deleteElement(src);
            // assert(check);
            
            while(!Q.empty())
            {
                int tp = Q.front();
                Q.pop();
                
                // Look at all unreached vertices
                unsigned int cur_ind = 0;
                
                while(cur_ind<unreachedList.thisVec.size()){
                    int possibleNeb = unreachedList.thisVec[cur_ind];
                    
                    // Check that inverse edge exists and not already in component
                    if(!AdjMat[tp][possibleNeb] and componentNumbers[possibleNeb]==-1)
                    {   
                        
                        Q.push(possibleNeb);
                        
                        componentNumbers[possibleNeb]=src;
                        thisComponent.pb(possibleNeb);
                        
                        bool check = unreachedList.deleteElement(possibleNeb);
                        // assert(check);
                    } else
                    {
                        cur_ind+=1;
                    }
                }
            }
            
            components.pb(thisComponent);
        }
    }
    
    return mp(componentNumbers, components);
}

vector<unordered_map<int, bool>> computeAdjMat(int n, const vector<pii> &edges)
{
    vector<unordered_map<int,bool>> AdjMat(n+1);
    
    for(auto edge: edges){
        AdjMat[edge.f][edge.s] =true;
        AdjMat[edge.s][edge.f] =true;
    }
    
    return AdjMat;
}

bool verifyCliques(int n, const vector<pii> &edges, const vi &componentNumbers)
{
    // Check that every component in inverse graph is a clique
    
    for(auto edge: edges){
        if(componentNumbers[edge.f]==componentNumbers[edge.s])
        {
            return false;
        }
    }
    
    return true;
}

string convertHateStringComponent(const string &hateString, const vector<vi> & components, int n)
{   
    if(hateString.empty())
    {
        return "";
    }
    
    if(hateString.size()!=components.size())
    {
        throw logic_error("Something wrong with the hate strings");
    }
    
    string newStringComp(n,'*');
    
    int numComponents = components.size();
    
    rep(comp_ind, 0, numComponents-1)
    {
        char charAssigned = hateString[comp_ind];
        
        for(auto vert_num: components[comp_ind])
        {
            newStringComp[vert_num-1]=charAssigned;
        }
    }
    
    return newStringComp;
    
}

vector<string> getCompHateStrings(const vector<string> & hate_strings_comp, const vector<vi> & components, int n){
    vector<string> comp_hate_strings;
    for(const string &hateString:hate_strings_comp)
    {
        auto comp_hate_string = convertHateStringComponent(hateString, components, n);
        if(!comp_hate_string.empty())
            comp_hate_strings.pb(comp_hate_string);
    }
    return comp_hate_strings;
}
void compute_graph(int n, int m, const vector<pii> &edges){
    auto AdjMat = computeAdjMat(n, edges);
    auto compsInv = getComponentNumbersInverse(n, AdjMat);
    
    
    if(DEBUG)
    {   cout<<"Component Numbers: ";
        print(compsInv.f);
    
        cout<<"Components: ";
        print(compsInv.s);
    }
    
    auto componentNumbers = compsInv.f;
    auto components = compsInv.s;
    
    auto checkCliques = verifyCliques(n, edges, componentNumbers);
    
    if(DEBUG){
        cout<<"checkCliques: ";
        cout<<checkCliques<<"\n";
    }
    
    if(!checkCliques)
    {
        cout<<-1;
        return;
    }
    
    int numComponents = components.size();
    
    hateStrings.clear();
    
    int hates_num = helper_graph(numComponents, n, 1);
    
    cout<<hates_num<<"\n";
    
    if(hates_num>0)
    {
        int max_hates = mx6/n;
        
        if(hates_num>max_hates)
        {
            throw logic_error("Something wrong with hates_num\n");
        }
        
        auto comp_hate_strings = getCompHateStrings(hateStrings, components, n);
        
        // bool verify_hs = verify_hate_strings(hateStrings, edges, n);
        
        // if(!verify_hs)
        // {
        //     throw logic_error("Missing edges from hate strings\n");    
        // }
        
        print(comp_hate_strings);
    }
}
// Soln Link: https://www.codechef.com/viewsolution/26458202
int main(void)
{
    ios_base::sync_with_stdio(false);
    
    int n, m;
    
    cin>>n>>m;
    vector<vi> adj(n+1);
    vector<pii> edges(m);
    
    rep(j,1,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        
        edges[j-1]=mp(u,v);
    }
    
    // if(m==(n*(n-1))/2)
    // {
    //     compute_complete_graph(n,m, edges);
    //     return 0;
    // }
    
    compute_graph(n, m, edges);
    
    return 0;
}
