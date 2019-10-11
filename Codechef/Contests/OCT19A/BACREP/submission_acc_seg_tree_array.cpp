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
void print(unordered_map<int, ll> mp){
    for(auto i:mp)
    {
         cout<<"("<<i.f<<", "<<i.s<<") ";
    }
    cout<<"\n";
}
void print(map<int, ll> mp){
    for(auto i:mp)
    {
         cout<<"("<<i.f<<", "<<i.s<<") ";
    }
    cout<<"\n";
}
ll dist_sq(pll a,pll b)
{
    return ((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
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
    
    FenwickTree()
    {
        
    }
    
    FenwickTree(int n)
    {
        BIT.resize(n+1,0);
    }
    // FenwickTree(vll a)
    // {
    //     int n = a.size();
        
    //     BIT.resize(n+1,0);
        
    //     rep(i,0,n-1)
    //     {
    //         update(i+1,a[i]);
    //     }
    // }
    // FenwickTree(vi a)
    // {
    //     vll b(a.begin(),a.end());
        
    //     int n = b.size();
        
    //     BIT.resize(n+1,0);
        
    //     rep(i,0,n-1)
    //     {
    //         update(i+1,b[i]);
    //     }
    // }
    
    void update(int ind, ll val)
    {   
        // assert(0<=ind and ind<BIT.size());
        
        int x = ind;
        int sz = BIT.size();
        
        while(x<sz)
        {
            BIT[x]+=val;
            x += (x&-x);
        }
    }
    
    // void set(int ind, ll val)
    // {   
    //     assert(0<=ind and ind<BIT.size());
        
    //     ll currentVal = query(ind,ind);
    //     update(ind,val-currentVal);
    // }
    // ll query(int l, int r)
    // {   
    //     assert(0<=l and r<BIT.size());
        
    //     if(r<l)
    //     {
    //         return 0;
    //     }
    //     else
    //         return prefQuery(r) - prefQuery(l-1);
    // }
    ll prefQuery(int ind)
    {   
        // assert(0<=ind and ind<BIT.size());
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


class MapFenwickTree
{
    public:
    unordered_map<int,ll> BIT;

    int currentVersion=0;
    int N = 0;
    // vector<unordered_map<int, int> > versionIndex;
    
    MapFenwickTree()
    {   
        currentVersion = 0;
        N = 0;
    }
    
    MapFenwickTree(int n)
    {   
        this->N = n;
    }
    
    void update(int ind, ll val)
    {   
        assert(0<=ind and ind<=N);
        
        int x = ind;
        currentVersion+=1;
        
        while(x<=N)
        {   
            
            
            // if(BIT.count(x))
            // {  
            //     BIT[x]+=val;
            // } else{
            //     BIT[x] = val;
            // }
            
            BIT[x]+=val;
            
            x += (x&-x);
        }
    }
    
    void resetTree(int n){
        BIT.clear();
        this->N = n;
        currentVersion =0;
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
    
    ll prefQuery(int ind)
    {   
        assert(0<=ind and ind<=N);
        int x = ind;
        ll sum = 0;
        
        while(x>0)
        {   
            if(BIT.count(x)!=0)
            {   
                sum+=BIT[x];
            }

            x-=(x&-x);
        }
        
        return sum;
    }
    
};

class PersistentSegmentTreeNode{
    private:
    public:
    
    ll total;
    
    int start,end;
    
    int leftChildIndex, rightChildIndex;
    
    int thisIndex;
    
    PersistentSegmentTreeNode(): total(0), start(-1),end(-1), leftChildIndex(-1), rightChildIndex(-1), thisIndex(-1){} 
    
    void assignLeaf(ll value, int start, int end, int thisIndex){
        total = value;
        this->start = start;
        this->end = end;
        this->thisIndex = thisIndex;
    }
    void merge( PersistentSegmentTreeNode &left,  PersistentSegmentTreeNode&right){
        this->start = left.start;
        this->end = right.end;
        auto leftTotal = left.getValue();
        auto rightTotal = right.getValue();
        
        this->leftChildIndex = left.thisIndex;
        this->rightChildIndex = right.thisIndex;
        
        this->total = leftTotal + rightTotal;
        
    }
    void print(){
         cout<<"\nthisIndex:"<<thisIndex<<"\n";
        cout<<"(start, end): "<<start<<" "<<end<<"\n";
        cout<<"(leftChildIndex, rightChildIndex): "<<leftChildIndex<<" "<<rightChildIndex<<"\n";
        
        cout<<"total: "<<total<<endl<<endl;
        
       
    }
    ll getValue(){
        return total;
    }

    int getSegmentSize(){
        return (end-start + 1);
    }
};
class PersistentSegmentTree;

const int DEBUG = 0;
const int MAX_VAL = mx6+1;
const int MAX_ROOT_NODE_SIZE = 4*mx6+5;
const int MAX_TREE_SIZE = 4*10*mx6+10;

PersistentSegmentTreeNode nodes[MAX_TREE_SIZE];
// unordered_map<int, PersistentSegmentTreeNode> nodes;
int rootNodes[MAX_ROOT_NODE_SIZE]={-1};

// unordered_map<int, int> rootNodes;

map<pii,int> versionSeen;

class PersistentSegmentTree{
    private:
    
    int NODE_COUNTER = 0;
    // unordered_map<int, PersistentSegmentTreeNode> nodes;
    // vector<int> rootNodes;
    // unordered_map<int,int> rootNodes;
    
    int currentVersion = 0;
    int N = 0;
    int treeSize = 0;
    int rootNodeSize = 0;
    
    int complexity_counter = 0;
    
    public:
    
    // PersistentSegmentTree(const vll &arr){
        
    //     this->N = arr.size();
    //     this-> treeSize = getPersistentSegmentTreeSize(this->N);
    //     this->rootNodeSize = getRootNodeSize(this->N);
    //     //cout<<"N treeSize:" <<N<<" "<<treeSize<<"\n";
    //     nodes = vector<PersistentSegmentTreeNode>(this->treeSize);
    //     rootNodes = vector<int>((4*this->N)+5,-1);
    //     NODE_COUNTER = 0;
        
    //     currentVersion = 0;
        
    //     buildTree(arr);
        
    // }
    
    PersistentSegmentTree(){
        
    }
    
    PersistentSegmentTree(int N){
        

        
        this->N = N+1;
        
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        
        // nodes = vector<PersistentSegmentTreeNode>(this->treeSize);
        // rootNodes = vector<int>((4*this->N)+5,-1);
        NODE_COUNTER = 0;
        
        currentVersion = 0;
        rootNodes[currentVersion] = createParent(-1,-1,0, this->N-1);
        
    }
    void resetTree(int N){
        this->N = N+1;
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        
        NODE_COUNTER=0;
        currentVersion = 0;
        
        rootNodes[currentVersion] = createParent(-1,-1,0,this->N-1);
    }
    
    void buildTree(const vll & arr){
        int firstRoot = buildTree(arr,0,N-1);
        rootNodes[currentVersion] =firstRoot;
    }
    
    void updateCurrentVersion(int index, ll val){
        
        if(currentVersion>this->rootNodeSize  or rootNodes[currentVersion]==-1){
            throw logic_error("weird currentVersion\n");
        }
        
        int oldNodeCount = NODE_COUNTER;
        
        int currentRoot = rootNodes[currentVersion];
       
        int newRoot = updateCurrentVersion(index, currentRoot, val,0,N-1);
        
        // if(DEBUG){
        //     cout<<"Updated index: "<<" "<<index<<"\n";
        //     cout<<"val: "<<val<<"\n";
        //     cout<<"this->N: "<<this->N<<"\n";
        //     cout<<"Expanded Nodes: "<<NODE_COUNTER-oldNodeCount<<endl<<endl;
        // } 
        
        currentVersion+=1;
        rootNodes[currentVersion] =newRoot;
        
        // cout<<"rootNodes: ";
        // print(rootNodes);
        
        // for(auto ind: rootNodes)
        // {
        //     nodes[ind].print();
        // }
        
        if(currentVersion>this->rootNodeSize or rootNodes[currentVersion]==-1){
            throw logic_error("weird next currentVersion\n");
        }
    }
    
    void dummyUpdateVersion(){
        if(currentVersion>this->rootNodeSize  or rootNodes[currentVersion]==-1){
            throw logic_error("weird currentVersion");
        }
        
        int currentRoot = rootNodes[currentVersion];
        currentVersion+=1;
        rootNodes[currentVersion] = currentRoot;
        
    }
    
    void revertToVersion(int oldVersion){
        if(oldVersion>currentVersion or rootNodes[oldVersion]==-1)
        {
            throw logic_error("Weird old version provided");
        }
        
        int oldRoot = rootNodes[oldVersion];
        currentVersion+=1;
        rootNodes[currentVersion] = oldRoot;
    }
    ll queryVersion(int Lindex, int Rindex, int version){
         if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
            throw logic_error("weird version\n");
        }
        
        int versionRoot = rootNodes[version];
        
        complexity_counter = 0;
        
        ll ans =  queryVersion(Lindex, Rindex, versionRoot, 0, N-1);
        
        // if(DEBUG){
        //     cout<<"Querying indices: "<<" "<<Lindex<<" "<<Rindex<<"\n";
        //     cout<<"this->N: "<<this->N<<"\n";
        //     cout<<"Expanded Nodes: "<<complexity_counter<<endl<<endl;
        // } 
        
        return ans;
        
    }
    
    ll getLatestKthVal(int k, int version){
        if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
            throw logic_error("weird version\n");
        }
        
        int ans = getLatestKthVal(k, rootNodes[version], 0, N-1);
        
        return ans;
    }
    
    int getCurrentVersion(){
        return this->currentVersion;
    }
    
    static int getPersistentSegmentTreeSize(int N)
    {
        int val = floorlog2(N) + 1;
        
        return val * 6*N+10;
    }
    
    static int getRootNodeSize(int N)
    {
        return 4*N+5;
    }
    
    void debugPrint(int version = 0){
        cout<<"N: "<<N<<"\n";
        cout<<"Latest version: "<<currentVersion<<"\n";
        
        cout<<"Debug version: "<<version<<"\n";
        
        vi prefix_array(N,0);
        
        rep(j,1,N-1)
        {
            prefix_array[j] = queryVersion(1,j,version);
        }
        
        cout<<"Type array: "; 
        print(prefix_array);
        
        cout<<endl<<endl;
    }
    private:
    
    int buildTree(const vll & arr, int L, int R){
        if(L==R)
        {
            int nodeIndex = createNewLeaf(arr[L], L, R);
            return nodeIndex;
        }
        int mid = (L+R)/2;
        
        int leftChildIndex = buildTree(arr,L,mid);
        int rightChildIndex = buildTree(arr,mid+1,R);
        
        int nodeIndex = createParent(leftChildIndex, rightChildIndex, L, R);
        return nodeIndex;
    }
    
    int updateCurrentVersion(int index, int currentNodeIndex, ll val, int L, int R){
        if(L==R)
        {   
            
            if(currentNodeIndex==-1)
            {
                int nodeIndex = createNewLeaf(val, L, R);
                return nodeIndex;
            }
            
            int nodeIndex = copyNewLeaf(val, currentNodeIndex);
            
            // if(DEBUG)
            // {   
            //     cout<<"Leaf id: "<<nodeIndex<<endl;
            //     nodes[nodeIndex].print();
            // }
            return nodeIndex;
        }
        
        int mid = (L+R)/2;
        
        int currentLeftChildIndex = (currentNodeIndex==-1)?-1:nodes[currentNodeIndex].leftChildIndex;
        int currentRightChildIndex = (currentNodeIndex==-1)?-1:nodes[currentNodeIndex].rightChildIndex;
        
        if(0<=index and index<=mid)
        {
            currentLeftChildIndex = updateCurrentVersion(index, currentLeftChildIndex, val, L, mid);    
        }else if(index>mid and index<=R)
        {
            
            currentRightChildIndex = updateCurrentVersion(index, currentRightChildIndex, val, mid+1, R);
        } else 
        {   
            string message = string("Weird index provided") + string(" L:") + to_string(L) + string(" R: ") + to_string(R)+ string(" index: ")+to_string(index);
            throw logic_error(message);
        }
        
        int nodeIndex = createParent(currentLeftChildIndex, currentRightChildIndex, L, R);
        // if(DEBUG)
        // {   cout<<"Internal id: "<<nodeIndex<<endl;
        //     nodes[nodeIndex].print();
        // }
        
        return nodeIndex;
    }
    
    // int updateCurrentVersionInPlace(int index, int currentNodeIndex, ll val, int L, int R){
    //     if(L==R)
    //     {   
            
    //         if(currentNodeIndex==-1)
    //         {
    //             int nodeIndex = createNewLeaf(val, L, R);
    //             return nodeIndex;
    //         }
            
    //         // int nodeIndex = copyNewLeaf(val, currentNodeIndex);
            
    //         // if(DEBUG)
    //         // {   
    //         //     cout<<"Leaf id: "<<nodeIndex<<endl;
    //         //     nodes[nodeIndex].print();
    //         // }
            
    //         nodes[currentNodeIndex].total+=val;
    //         return currentNodeIndex;
    //     }
        
    //     int mid = (L+R)/2;
        
    //     int currentLeftChildIndex = (currentNodeIndex==-1)?-1:nodes[currentNodeIndex].leftChildIndex;
    //     int currentRightChildIndex = (currentNodeIndex==-1)?-1:nodes[currentNodeIndex].rightChildIndex;
        
    //     if(0<=index and index<=mid)
    //     {
    //         currentLeftChildIndex = updateCurrentVersion(index, currentLeftChildIndex, val, L, mid);    
    //     }else if(index>mid and index<=R)
    //     {
            
    //         currentRightChildIndex = updateCurrentVersion(index, currentRightChildIndex, val, mid+1, R);
    //     } else 
    //     {   
    //         string message = string("Weird index provided") + string(" L:") + to_string(L) + string(" R: ") + to_string(R)+ string(" index: ")+to_string(index);
    //         throw logic_error(message);
    //     }
        
    //     if(currentNodeIndex==-1)
    //     {
    //         int nodeIndex = createParent(currentLeftChildIndex, currentRightChildIndex, L, R);
    //         return nodeIndex;
    //     }
    //     // int nodeIndex = createParent(currentLeftChildIndex, currentRightChildIndex, L, R);
    //     // if(DEBUG)
    //     // {   cout<<"Internal id: "<<nodeIndex<<endl;
    //     //     nodes[nodeIndex].print();
    //     // }
        
    //     nodes[currentNodeIndex]
    //     return nodeIndex;
    // }
    
    ll queryVersion(int Lindex, int Rindex, int currentNodeIndex, int L, int R){
        complexity_counter+=1;
        if(Rindex<Lindex or currentNodeIndex==-1)
        {
            return 0;
        }
        
        if(L==R)
        {
            return nodes[currentNodeIndex].getValue();
        }
        
        if(Lindex ==L and Rindex ==R)
        {
            return nodes[currentNodeIndex].getValue();
        }
        
        int mid = (L+R)/2;
        
        ll leftValue = 0LL, rightValue = 0LL;
        
        if(Lindex<=mid and nodes[currentNodeIndex].leftChildIndex!=-1)
        {
            leftValue = queryVersion(Lindex, min(mid,Rindex), nodes[currentNodeIndex].leftChildIndex, L,mid);
        }
        
        if(Rindex>mid and nodes[currentNodeIndex].rightChildIndex!=-1){
            rightValue = queryVersion(max(mid+1,Lindex),Rindex,nodes[currentNodeIndex].rightChildIndex,mid+1, R );
        }
        
        return leftValue + rightValue;
    }
    
    ll getLatestKthVal(int k, int currentNodeIndex, int L, int R){
        if(currentNodeIndex == -1 or nodes[currentNodeIndex].getValue()<k)
            return this->N;
        
        if(L==R)
        {   
            // int val = nodes[currentNodeIndex].getValue();
            
            // if(k<val)
            //     return -1;
            // else if(k==val)
            //     return L;
            // else 
            //     throw logic_error("Weird k");
            
            return L;

        }
        
        int mid = (L+R)/2;
        
        int leftChildIndex = nodes[currentNodeIndex].leftChildIndex;
        int rightChildIndex = nodes[currentNodeIndex].rightChildIndex;
        
        int leftTotal = leftChildIndex==-1?0:nodes[leftChildIndex].getValue();
        
        if(leftTotal>=k)
            return getLatestKthVal(k, leftChildIndex, L, mid);
        else 
            return getLatestKthVal(k-leftTotal, rightChildIndex, mid+1,R);
    }
    
    int createNewLeaf(ll val, int start, int end){
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        nodes[NODE_COUNTER].assignLeaf(val, start, end, NODE_COUNTER);
        
        return NODE_COUNTER;
    }
    
    int copyNewLeaf(ll val, int oldLeafIndex){
        
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        
        nodes[NODE_COUNTER] = nodes[oldLeafIndex];
        nodes[NODE_COUNTER].total+=val;
        nodes[NODE_COUNTER].thisIndex = NODE_COUNTER;
        
        return NODE_COUNTER;
    }
    
    int createParent(int leftChildIndex, int rightChildIndex, int start, int end){
        NODE_COUNTER+=1;
        
        int node_sz = this->treeSize;
        if(NODE_COUNTER>=node_sz)
        {
            throw logic_error("Too many nodes");
        }
        // if(DEBUG)
        // {   cout<<"leftChildIndex rightChildIndex"<<leftChildIndex<<" "<<rightChildIndex<<endl;
        //     cout<<"start, end: "<<start<<" "<<end<<endl;
        //     cout<<"rootNodeSize "<<rootNodeSize<<endl;
        // }
        
        if(leftChildIndex>=node_sz){
            throw logic_error("bad left child index provided");
        }
        if(rightChildIndex>=node_sz){
            throw logic_error("bad right child index provided");
        }
        
        auto defaultNode =  PersistentSegmentTreeNode();
        
        auto leftNode = (leftChildIndex==-1)?defaultNode:nodes[leftChildIndex];
        auto rightNode = (rightChildIndex==-1)?defaultNode:nodes[rightChildIndex];
        
        nodes[NODE_COUNTER].merge(leftNode, rightNode);
        
        nodes[NODE_COUNTER].thisIndex = NODE_COUNTER;
        nodes[NODE_COUNTER].start = start;
        nodes[NODE_COUNTER].end = end;
        
        
        return NODE_COUNTER;
    }
    
};

struct Query{
    char opt;
    int q_time;
    
    int v;
    ll k;
    
    Query(char opt_val, int q_time_val, int v_val, ll k_val){
        opt = opt_val;
        q_time = q_time_val;
        v = v_val;
        k = k_val;
    }
    
     Query(){
        
    }
    
    void debugPrint()
    {
        cout<<"Query: "<<endl;
        cout<<"opt: "<<opt<<endl;
        cout<<"v: "<<v<<endl;
        cout<<"q_time: "<<q_time<<endl;
        
        cout<<"k: "<<k<<endl;
        
    }
};

vector<map<int, ll>> valOfNodeAtTime;
// vector<vll> valOfNodeAtTime;
vector<vector<Query> > query_by_node;
vll ans_by_time;
vi depth;

PersistentSegmentTree perstSegTree(mx6+100);

void DfsComputePersistentLeaf(int src, int par, int n, int q, const vll &a, const vector<vi> &adj)
{
    int adj_sz = adj[src].size();;
    bool isLeaf = src!=1 and adj_sz==1;
    
    assert(isLeaf);
    
    depth[src] = depth[par]+1;
    
    int OFFSET = n+2;
    
    int currentParVersion = perstSegTree.getCurrentVersion();
    
    ll accumulated_val = 0LL;
    
    accumulated_val = a[src];
    
    for(auto query: query_by_node[src]){
        if(query.opt=='+')
        {
            accumulated_val += query.k;
            
            if(DEBUG)
            {   
                // query.debugPrint();
                cout<<"+ "<<src<<" "<<query.k<<" at time: "<<query.q_time<<endl<<endl;
            }
        } else if(query.opt =='?'){
            int Lindex = (isLeaf)?-1:query.q_time;
            int Rindex = query.q_time;
            
            ll ans = perstSegTree.queryVersion(Lindex - depth[src] + OFFSET, Rindex -depth[src] + OFFSET, currentParVersion);
            
            ans_by_time[query.q_time] = ans + accumulated_val;
            
            if(DEBUG)
            {   
                // query.debugPrint();
                cout<<"? "<<src<<"  at time: "<<query.q_time<<endl;
                cout<<"ans: "<<ans<<endl<<endl;
            }
        }  
    }
    
    int currentSrcVersion = perstSegTree.getCurrentVersion();
    
    if(DEBUG)
    {
        cout<<"Current src: "<<src<<endl;
        cout<<"depth[src]: "<<depth[src]<<endl;
        cout<<"currentSrcVersion: "<<currentSrcVersion<<endl;
        cout<<"Values: ";
        rep(q_time, -1 ,q-1)
        {
            int Lindex = (isLeaf)?-1:q_time;
            int Rindex = q_time;
            
            ll ans = perstSegTree.queryVersion(Lindex - depth[src] + OFFSET, Rindex -depth[src] + OFFSET, currentSrcVersion);
            
            cout<<"("<<q_time<<": "<<ans<<") ";
            
        }
        cout<<endl;
    }

    perstSegTree.revertToVersion(currentParVersion);
}

void DfsComputePersistent(int src, int par, int n, int q, const vll & a, const vector<vi> &adj){
    int adj_sz = adj[src].size();;
    bool isLeaf = src!=1 and adj_sz==1;
    
    if(isLeaf){
        DfsComputePersistentLeaf(src, par, n, q, a, adj);
        return;
    }
    
    depth[src] = depth[par]+1;
    
    int OFFSET = n+2;
    
    int currentParVersion = perstSegTree.getCurrentVersion();
    
    perstSegTree.updateCurrentVersion(-1 - depth[src] + OFFSET, a[src]);
    
    for(auto query: query_by_node[src]){
        if(query.opt=='+')
        {
            perstSegTree.updateCurrentVersion(query.q_time - depth[src] +OFFSET, query.k);
            if(DEBUG)
            {   
                // query.debugPrint();
                cout<<"+ "<<src<<" "<<query.k<<" at time: "<<query.q_time<<endl<<endl;
            }
        } else if(query.opt =='?'){
            int Lindex = (isLeaf)?-1:query.q_time;
            int Rindex = query.q_time;
            
            int currentSrcVersion = perstSegTree.getCurrentVersion();
            ll ans = perstSegTree.queryVersion(Lindex - depth[src] + OFFSET, Rindex -depth[src] + OFFSET, currentSrcVersion);
            ans_by_time[query.q_time] = ans;
            
            if(DEBUG)
            {   
                // query.debugPrint();
                cout<<"? "<<src<<"  at time: "<<query.q_time<<endl;
                cout<<"ans: "<<ans<<endl<<endl;
            }
        }
    }
    
    
    
    if(DEBUG)
    {   
        int currentSrcVersion = perstSegTree.getCurrentVersion();
        cout<<"Current src: "<<src<<endl;
        cout<<"depth[src]: "<<depth[src]<<endl;
        cout<<"currentSrcVersion: "<<currentSrcVersion<<endl;
        cout<<"Values: ";
        rep(q_time, -1 ,q-1)
        {
            int Lindex = (isLeaf)?-1:q_time;
            int Rindex = q_time;
            
            ll ans = perstSegTree.queryVersion(Lindex - depth[src] + OFFSET, Rindex -depth[src] + OFFSET, currentSrcVersion);
            
            cout<<"("<<q_time<<": "<<ans<<") ";
            
        }
        cout<<endl;
    }
    
    // for(auto query: query_by_node[src]){
    //     if(query.opt =='?'){
    //         int Lindex = (isLeaf)?-1:query.q_time;
    //         int Rindex = query.q_time;
            
    //         ll ans = perstSegTree.queryVersion(Lindex - depth[src] + OFFSET, Rindex -depth[src] + OFFSET, currentSrcVersion);
    //         ans_by_time[query.q_time] = ans;
            
    //         if(DEBUG)
    //         {   
    //             // query.debugPrint();
    //             cout<<"? "<<src<<"  at time: "<<query.q_time<<endl;
    //             cout<<"ans: "<<ans<<endl<<endl;
    //         }
    //     }
    // }
    
    
    for(int v: adj[src])
    {
        if(v!=par)
        {
            DfsComputePersistent(v, src, n, q, a, adj);
        }
        
    }
    
    perstSegTree.revertToVersion(currentParVersion);
}


void DfsComputeOptimized(int src, int par, int q,  const vll & a, const vector<vi> &adj, unordered_map<int,ll> valAtTime){
    
    int adj_sz = adj[src].size();
    bool isLeaf = src!=1 and adj_sz==1;
    
    depth[src] = (src==1)?0:depth[par]+1;
    
    if(isLeaf)
    {   
        vector<vll> queryIndices;
        valAtTime[-1-depth[src]] = a[src];
         for(auto query: query_by_node[src]){
             if(query.opt=='+')
            {   
                vll to_push = {query.q_time - depth[src], 0, query.k};
                queryIndices.pb(to_push);
            } else if(query.opt=='?'){
                vll to_push = {query.q_time - depth[src], 1, query.q_time};
                queryIndices.pb(to_push);
            } 
         }
         
         for(auto q: valAtTime)
         {
             queryIndices.pb({q.f,-1});
         }
         
         sort(queryIndices.begin
         (), queryIndices.end());
         
         int prev_val = -1-depth[src];
         if(DEBUG)
         {
             cout<<"src: "<<src<<"\n";
             cout<<"valAtTime: \n";
         }
         for(auto vl : queryIndices){
             
             if(prev_val!=vl[0]){
                 valAtTime[vl[0]] += valAtTime[prev_val];
             }
             if(vl[1] ==0)
             {
                 valAtTime[vl[0]]+=vl[2];
             } else if(vl[1]==1)
             {
                 ans_by_time[vl[2]] = valAtTime[vl[0]];
             }
             if(DEBUG)
             {      
                 cout<<"queryIndex: ";
                 print(vl);
                 cout<<"prev_val: " <<prev_val<<"\n";
                 
                 cout<<"valAtTime: ";
                 print(valAtTime);
                 cout<<"\n\n";
             }
             prev_val = vl[0];
         }
         
         return;
    }
    valAtTime[-1-depth[src]] = a[src];
    for(auto query: query_by_node[src]){
        if(query.opt=='+')
        {
            valAtTime[query.q_time-depth[src]] += query.k;
 
            if(DEBUG)
            {   cout<<"+ "<<src<<" "<<query.k<<" at time: "<<query.q_time<<"\n";
            }
        } else if(query.opt=='?'){
            
            ll ans = valAtTime[query.q_time-depth[src]];
            ans_by_time[query.q_time] = ans;
            if(DEBUG)
            {   cout<<"? "<<src<<"  at time: "<<query.q_time<<"\n";
                cout<<"ans: "<<ans<<"\n";
            }
        } 
    }
    
    if(DEBUG==2)
    {   
        cout<<"\n\nDEBUGGING VALS:\n";
        // cout<<"par: "<<par<<" : "; print(valOfNodeAtTime[par]);
        cout<<"src: "<<src<<" : "; print(valAtTime);
        cout<<"depth[src]: "<<depth[src]<<'\n';
        cout<<"par: "<<par<<"\n";
        cout<<"depth[par]: "<<depth[par]<<'\n';
        cout<<'\n';
    }
    
    for(auto v: adj[src]){
        if(v!=par)
        {
            DfsComputeOptimized(v, src, q, a, adj, valAtTime);
        }
    }
}

void initState(int n, int q)
{
    query_by_node = vector<vector<Query> >(n+1);
    valOfNodeAtTime = vector<map<int, ll> > (n+1);
    // valOfNodeAtTime = vector<vll> (n+1,vll(q,0));
    ans_by_time = vll(q,-1);
    depth = vi(n+1,0);
}
vll compute_test_case(int n, int q, const vector<Query> &queries, const vll & a, const vector<vi> & adj){
    
    initState(n,q);
    
    for(auto query: queries)
    {
        query_by_node[query.v].pb(query);
    }
    
    unordered_map<int,ll> valAtTime;
    DfsComputeOptimized(1, 0, q, a, adj, valAtTime);
    // DfsCompute(1, 0, n, q, a, adj);
    
    // vll new_ans_by_time;
    // // print(ans_by_time);
    // rep(j,0,q-1)
    // {
    //     if(ans_by_time[j]!=-1){
    //         new_ans_by_time.pb(ans_by_time[j]);
    //     }
    // }
    return ans_by_time;
}

vll compute_test_case_perst(int n, int q, const vector<Query> &queries, const vll & a, const vector<vi> & adj){
    
    initState(n,q);
    
    for(auto query: queries)
    {   
        // query.debugPrint();
        query_by_node[query.v].pb(query);
    }
    
    DfsComputePersistent(1, 0, n, q, a, adj);
    
    // vll new_ans_by_time;
    
    // rep(j,0,q-1)
    // {
    //     if(ans_by_time[j]!=-1){
    //         new_ans_by_time.pb(ans_by_time[j]);
    //     }
    // }
    return ans_by_time;
}

// Problem Link: BACREP: https://www.codechef.com/OCT19A/problems/BACREP
// Submission Link: https://www.codechef.com/viewsolution/27271194
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vll a(n+1,0);
    vector<vi> adj(n+1);
    
    vector<Query> queries;
    
    rep(edge,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        
    }
    
    rep(j,1,n)
    {
        cin>>a[j];
    }
    rep(q_time,0,q-1)
    {
        char opt;
        cin>>opt;
        int v=-1;
        ll k=-1;
        
        if(opt=='+')
        {   
            cin>>v>>k;
        } else if(opt=='?') 
        {
            cin>>v;
        }
        
        auto quer = Query(opt, q_time, v, k);
        
        queries.pb(quer);
        
        
    }
    
    vll perst_ans_by_time = compute_test_case_perst(n, q, queries, a, adj);
    // vll old_ans_by_time = compute_test_case(n, q, queries, a, adj);
    
    // if(perst_ans_by_time != old_ans_by_time){
    //     cout<<"perst_ans_by_time: ";
    //     print(perst_ans_by_time);
    //     cout<<"old_ans_by_time: ";
    //     print(old_ans_by_time);
    //     cout<<endl;
    //     throw logic_error("Answers do not match\n");
    // }
    for(auto i: perst_ans_by_time){
        if(i!=-1)
            cout<<i<<"\n";
    }
    return 0;
}
