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
vector<pii> jiro(100+5);
vi ciel(100+5);
vi ciel_pref(100+5);
int n,m;

// int calcTotal(int start_jiro, int end_jiro, int start_ciel, int end_ciel){
    
//     if(end_ciel<start_ciel or end_jiro<start_jiro){
//         return 0;
//     }
    
//     if(end_ciel==start_ciel and start_ciel==0){
//         return 0;    
//     }
    
//     if(end_jiro==start_jiro and start_jiro==0){
//         return ciel_pref[end_ciel] -ciel_pref[start_ciel];
//     }
    
   
//     int ans = 0;
    
//     rep(ciel_ind, start_ciel, end_ciel){
//         rep(jiro_ind, start_jiro, end_jiro){
            
//             bool firstCheck = jiro[jiro_ind].second and ciel[ciel_ind]>=jiro[jiro_ind];
//             bool secondCheck = jiro[jiro_ind].second==0 and ciel[ciel_ind]>jiro[jiro_ind];
            
//             int damage = 0;
            
//             if(firstCheck)
//                 damage = ciel[ciel_ind]-ciel
//         }
//     }
// }

map<pair<vector<pii>,vi>,int> dpAns;
int calcTotal(int end_jiro, int end_ciel){
    if(end_jiro<0 or end_jiro>n)
    {
        return 0;
    }
    
    if(end_ciel<0 or end_ciel>m){
        return 0;    
    }
    
    if(end_ciel==0){
        return 0;
    }
    
    if(end_jiro==0){
        int ans = 0;
        rep(j,1,end_ciel){
            if(ciel[j]>0){
                ans+=ciel[j];
            }
        }
        return ans;
    }
    
    auto seenBefore = mp(jiro, ciel);
    
    if(dpAns.count(seenBefore)){
        return dpAns[seenBefore];
    }
    bool isJiroEmpty = true;
    
    rep(jiro_ind,1,end_jiro){
        if( jiro[jiro_ind].first<=8000)
        {
            isJiroEmpty = false;
            break;
        }
    }
    
    if(isJiroEmpty){
        int ciel_sum = 0;
        rep(ciel_ind, 1, end_ciel){
            if(ciel[ciel_ind]>0){
                ciel_sum+=ciel[ciel_ind];
            }
        }
        dpAns[seenBefore]=ciel_sum;
        return ciel_sum;
    }
    int max_ans = 0;
    rep(ciel_ind, 1, end_ciel){
        rep(jiro_ind, 1, end_jiro){
            bool firstCheck = jiro[jiro_ind].second and ciel[ciel_ind]>=jiro[jiro_ind].first;
            bool secondCheck = jiro[jiro_ind].second==0 and ciel[ciel_ind]>jiro[jiro_ind].first;
            int damage = 0;
            if(!(firstCheck or secondCheck))
            {
                continue;
            }
            
            if(firstCheck){
                damage = ciel[ciel_ind] - jiro[jiro_ind].first;
            }
            
            int temp_ciel = ciel[ciel_ind];
            int temp_jiro = jiro[jiro_ind].first;
            
            ciel[ciel_ind] = -1;
            jiro[jiro_ind].first = 8001;
            
            int rest_damage = calcTotal(end_jiro, end_ciel);
            
            ciel[ciel_ind] = temp_ciel;
            jiro[jiro_ind].first = temp_jiro;
            
            max_ans = max(max_ans, damage+rest_damage);
        }
    }
    dpAns[seenBefore]=max_ans;
    return max_ans;
}

const int DEBUG = 0;

int computeAnsJiroDefeated(vi &ciel, vi &jiro_att, vi &jiro_def){
    vector<bool> cielUsed(ciel.size(),false);
    int ciel_sz = ciel.size();
    for(auto jiro_def_card: jiro_def){
        bool found_card = false;
        rep(j,0,ciel_sz-1){
            if(ciel[j]>jiro_def_card and !cielUsed[j]){
                cielUsed[j]=1;
                found_card = true;
                break;
            }
        }
        if(!found_card)
            return 0;
    }
    
    int ans = 0;
    int jiro_sz = jiro_att.size();
    
    reprev(jiro_ind,jiro_sz-1,0){
        auto jiro_att_card = jiro_att[jiro_ind];
        
        bool found_card = false;
        reprev(j,ciel_sz-1,0){
            if(ciel[j]>=jiro_att_card and !cielUsed[j]){
                cielUsed[j]=1;
                found_card = true;
                ans+=ciel[j]-jiro_att_card;
                break;
            }
        }
        if(!found_card)
            return 0;
    }
    
    rep(j,0,ciel_sz-1){
        if(!cielUsed[j])
        {
            ans+=ciel[j];
        }
    }
    return ans;
    
}

int kPossible(vi &ciel, vi &jiro_att, int k){
    int ciel_sz = ciel.size();
    int jiro_sz = jiro_att.size();
    
    if(k>jiro_sz or k>ciel_sz)
        return 0;
    
    int ans = 0;   
    rep(jiro_ind, 0,k-1)
    {
        int ciel_ind = ciel_sz-k+jiro_ind;
        
        if(ciel[ciel_ind]>=jiro_att[jiro_ind]){
            ans+=ciel[ciel_ind]-jiro_att[jiro_ind];
        } else
        {
            return 0;
        }
    }
    return ans;
}
int computeAnsJiroUndefeated(vi &ciel, vi &jiro_att, vi &jiro_def){
    int ciel_sz = ciel.size();
    int jiro_sz = jiro_att.size();
    
    int maxk = min(jiro_sz,ciel_sz);
    int ans = 0;
    reprev(k, maxk, 1){
        int kthAns = kPossible(ciel, jiro_att, k);
        if(DEBUG){
            cout<<"k, kthAns: "<<k<<" "<<kthAns<<"\n";
        }
        ans = max(kthAns,ans);
    }
    return ans;
}

int computeAns(vi &ciel,vi &jiro_att,vi &jiro_def){
    int ansJiroDefeated = computeAnsJiroDefeated(ciel, jiro_att, jiro_def);
    int ansJiroUndefeated = computeAnsJiroUndefeated(ciel, jiro_att, jiro_def);
    if(DEBUG){
        cout<<"ansJiroDefeated: "<<ansJiroDefeated<<"\n";
        cout<<"ansJiroUndefeated: "<<ansJiroUndefeated<<"\n";
    }
    return max(ansJiroDefeated, ansJiroUndefeated);
}
// Submission Link: https://codeforces.com/contest/203/submission/59646820
int main(void)
{
    ios_base::sync_with_stdio(false);
    double a,b,m;
    vector<double> pos(3, 0.0);
    vector<double> v(3,0.0);
    vector<double> posFinal(3,0.0);
    cin>>a>>b>>m;
    
    rep(j,0,2){
        cin>>v[j];
        
    }
    int xReflects = 0;
    int zReflects = 0;
    if(v[0]<0)
        {
            v[0]=-v[0];
            xReflects+=1;
        }
     if(v[2]<0)
        {
            v[2]=-v[2];
            zReflects+=1;
        }  
        
    pos[0] = a/2.0;
    pos[1] = m;
    pos[2] = 0;
    
    double t = -pos[1]/v[1];
    
    posFinal[0] = pos[0]+v[0]*t;
    posFinal[2] = pos[2] + v[2]*t;
    
    
    
    rep(i,0,2){
        assert(posFinal[i]>=0);
    }
    
    int numXCols = (posFinal[0]/a);
    int numZCols = (posFinal[2]/b);
    
    double xRelative = posFinal[0] - numXCols*a;
    double zRelative = posFinal[2] - numZCols*b;
    
    double xFinal = (numXCols+xReflects)%2?a-xRelative:xRelative;
    double zFinal =  (numZCols+zReflects)%2?b-zRelative:zRelative;
    cout<<fixed;
    cout<<setprecision(9)<<xFinal<<" "<<zFinal;
    return 0;
}
