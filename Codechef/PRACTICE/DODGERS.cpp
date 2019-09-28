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
void print(deque<int> &a)
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
void print(vector<vi> &a)
{
    for(vi i:a)
    {
        print(i);
    }
    cout<<"\n";
}
void print(deque<vi> &a)
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
    // vector<unordered_map<int, int> > versionIndex;
    
    PersistentFenwickTree()
    {   
        currentVersion = 0;
    }
    
    PersistentFenwickTree(int n, int reserveMem = 0)
    {   
        auto defaultVal = {P()};
        
        BIT = vector<vector<P> > (n+1,{P()}); 
        // versionIndex.resize(n+1);
        
        if(reserveMem)
        {
            // for(auto &vec: BIT)
            // {
            //     vec.reserve(8);
            // }
            
            rep(j,1,n)
            {
                BIT[j].reserve(reserveMem);
            }
        }
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
            
            int sz = BIT[x].size();
            
            // versionIndex[x][currentVersion] = sz-1;
            
            x += (x&-x);
        }
    }
    
    void resetTree(int n){
        auto defaultVal = {P()};
        fill(BIT.begin(),BIT.begin()+n+1, defaultVal);
        currentVersion =0;
    }
    
    void set(int ind, ll val)
    {   
        assert(0<=ind and ind<BIT.size());
        
        ll currentVal = query(ind,ind, currentVersion);
        update(ind,val-currentVal);
    }
    
    ll query(int l, int r, int version)
    {   
        assert(0<=l and r<BIT.size());
        
        if(r<l)
        {
            return 0;
        }
        else
            return prefQuery(r, version) - prefQuery(l-1, version);
    }
    
    ll query(pii indexRange, int version)
    {   
        return query(indexRange.f, indexRange.s, version);
    }
    
    ll prefQuery(int ind, int version)
    {   
        assert(0<=ind and ind<BIT.size());
        int x = ind;
        ll sum = 0;
        auto versionVal = P(0,version);
        while(x>0)
        {   
            if(BIT[x].empty())
            {
                throw logic_error("empty array spot");
            }
            
            auto node_it = upper_bound(BIT[x].begin(),BIT[x].end(),versionVal)-1;
            
            sum+=node_it->data;
            

            x-=(x&-x);
        }
        
        return sum;
    }
    
    ll prefQueryCurrentVersion(int ind)
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
            
            
            sum+=BIT[x].back().data;

            x-=(x&-x);
        }
        
        return sum;
    }
};

class MapPersistentFenwickTree
{
    public:
    unordered_map<int,vector<P>> BIT;

    int currentVersion=0;
    int N = 0;
    // vector<unordered_map<int, int> > versionIndex;
    
    MapPersistentFenwickTree()
    {   
        currentVersion = 0;
        N = 0;
    }
    
    MapPersistentFenwickTree(int n)
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
            
            
            if(BIT.count(x))
            {  
                
                int sz = BIT[x].size();
                int newData = val + BIT[x][sz-1].data;
                auto newVal = P(newData,currentVersion);
            
                BIT[x].push_back(newVal);
            } else{
                auto newVal = P(val,currentVersion);
                BIT[x] = {newVal};
            }
            
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
    
    int prefQuery(int ind, int version)
    {   
        assert(0<=ind and ind<=N);
        int x = ind;
        int sum = 0;
        auto versionVal = P(0,version);
        while(x>0)
        {   
            if(BIT.count(x))
            {   
                if(BIT[x].empty())
                {
                    throw logic_error("Weird bit");
                }
                auto node_it = upper_bound(BIT[x].begin(),BIT[x].end(),versionVal);
                
                if(node_it!=BIT[x].begin())
                {   
    
                    sum+=(node_it-1)->data;
                }
                 
            //      cout<<"ind: "<<ind<<"\n";
            //      cout<<"version:" <<version<<" \n";
            //      cout<<"node_it - begin: "<<distance(BIT[x].begin(),node_it)<<"\n";
            //      cout<<"node_it, node_it->data "<< node_it->data<<"\n";
            //      cout<<"x: "<<x<<" BIT[x]: \n";
            //     for(auto val :BIT[x]){
            //         cout<<"val.data"<<" "<<val.data<<"\n";
            //         cout<<"val.version"<<" "<<val.version<<"\n\n";
            //     }
            //   cout<<endl<<endl;
                
            }

            x-=(x&-x);
        }
        
        return sum;
    }
    
    int prefQueryCurrentVersion(int ind)
    {   
        assert(0<=ind and ind<BIT.size());
        int x = ind;
        int sum = 0;
        while(x>0)
        {   
            if(BIT.count(x))
            {
                sum+=BIT[x].back().data;
                x-=(x&-x);
            }
            
        }
        
        return sum;
    }
};

class MapPersistentFenwickTreeRangeUpdate
{
    public:
    MapPersistentFenwickTree bitTree;
    
    // map<pii,int> prevComputed;
    // unordered_map<int,int> prevComputedCurrent;
    
    int currentVersion=0;
    
    MapPersistentFenwickTreeRangeUpdate()
    {
      
    }
    
    MapPersistentFenwickTreeRangeUpdate(int n)
    {
        bitTree = MapPersistentFenwickTree(n+1);
        currentVersion = 0;
    }

    void updateRange(pii indexRange, ll val)
    {   
        currentVersion+=1;
        bitTree.update(indexRange.f, val);
        bitTree.update(indexRange.s + 1,-val);
    }
    
    int queryVersion(int ind, int stableVersion)
    {   
        auto seenVal = mp(ind, stableVersion);
        // if(prevComputed.count(seenVal)){
        //     return prevComputed[seenVal];
        // }
        
        int ans = bitTree.prefQuery(ind, 2*stableVersion);
        // prevComputed[seenVal] = ans;
        return ans;
    }
    
    int queryCurrentVersion(int ind)
    {   
        // if(prevComputedCurrent.count(ind))
        // {
        //     return prevComputedCurrent[ind];
        // }
        return bitTree.prefQueryCurrentVersion(ind);
    }
    
    void resetTree(int n){
        // prevComputed.clear();
        bitTree.resetTree(n+1);
    }
};

class PersistentFenwickTreeRangeUpdate
{
    public:
    PersistentFenwickTree bitTree;
    int currentVersion;
    
    PersistentFenwickTreeRangeUpdate(int n, int reserveMem=0)
    {
        bitTree = PersistentFenwickTree(n+1, reserveMem);
        currentVersion = 0;
        
    }

    void updateRange(pii indexRange, ll val)
    {   
        currentVersion+=1;
        bitTree.update(indexRange.f, val);
        bitTree.update(indexRange.s + 1,-val);
    }
    
    ll queryVersion(int ind, int stableVersion)
    {   
        return bitTree.prefQuery(ind, 2*stableVersion);
    }
    
    ll queryCurrentVersion(int ind)
    {   
        return bitTree.prefQueryCurrentVersion(ind);
    }
    
    void resetTree(int n){
        bitTree.resetTree(n+1);
    }
};

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

class PersistentSegmentTreeNode{
    private:
    public:
    int total;
    
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
        int leftTotal = left.getValue();
        int rightTotal = right.getValue();
        
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
    int getValue(){
        return total;
    }

    int getSegmentSize(){
        return (end-start + 1);
    }
};
class PersistentSegmentTree;

const bool DEBUG = true;
const int MAX_VAL = mx6+1;
const int MAX_ROOT_NODE_SIZE = 4*mx6+5;
const int MAX_TREE_SIZE = 8*20*mx6+10;

// PersistentSegmentTreeNode nodes[MAX_TREE_SIZE];
unordered_map<int, PersistentSegmentTreeNode> nodes;
int rootNodes[MAX_ROOT_NODE_SIZE]={-1};

// unordered_map<int, int> rootNodes;

map<pii,int> versionSeen;

class PersistentSegmentTree{
    private:
    
    int NODE_COUNTER = 0;
    // vector<PersistentSegmentTreeNode> nodes;
    // vector<int> rootNodes;
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
        versionSeen.clear();
        
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
        
        if(val==0 or index>=this->N-1)
        {
            dummyUpdateVersion();
            return;
        }
        
        int oldNodeCount = NODE_COUNTER;
        
        int currentRoot = rootNodes[currentVersion];
       
        int newRoot = update(index, currentRoot, val,0,N-1);
        
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
            throw logic_error("weird currentVersion\n");
        }
        
        int currentRoot = rootNodes[currentVersion];
        currentVersion+=1;
        rootNodes[currentVersion] = currentRoot;
        
    }
    
    int queryVersion(int Lindex, int Rindex, int version){
         if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
            throw logic_error("weird version\n");
        }
        
        int versionRoot = rootNodes[version];
        
        complexity_counter = 0;
        
        int ans =  queryVersion(Lindex, Rindex, versionRoot, 0, N-1);
        
        if(DEBUG){
            cout<<"Querying indices: "<<" "<<Lindex<<" "<<Rindex<<"\n";
            cout<<"this->N: "<<this->N<<"\n";
            cout<<"Expanded Nodes: "<<complexity_counter<<endl<<endl;
        } 
        
        return ans;
        
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
    
    int update(int index, int currentNodeIndex, ll val, int L, int R){
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
            currentLeftChildIndex = update(index, currentLeftChildIndex, val, L, mid);    
        }else if(index>mid and index<=R)
        {
            
            currentRightChildIndex = update(index, currentRightChildIndex, val, mid+1, R);
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
    
    int queryVersion(int Lindex, int Rindex, int currentNodeIndex, int L, int R){
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
        
        int leftValue = 0, rightValue = 0;
        
        if(Lindex<=mid and nodes[currentNodeIndex].leftChildIndex!=-1)
        {
            leftValue = queryVersion(Lindex, min(mid,Rindex), nodes[currentNodeIndex].leftChildIndex, L,mid);
        }
        
        if(Rindex>mid and nodes[currentNodeIndex].rightChildIndex!=-1){
            rightValue = queryVersion(max(mid+1,Lindex),Rindex,nodes[currentNodeIndex].rightChildIndex,mid+1, R );
        }
        
        return leftValue + rightValue;
    }
    int createNewLeaf(int val, int start, int end){
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        nodes[NODE_COUNTER].assignLeaf(val, start, end, NODE_COUNTER);
        
        return NODE_COUNTER;
    }
    
    int copyNewLeaf(int val, int oldLeafIndex){
        
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

class RangeUpdatePersistentSegmentTree{
    private:
    
    PersistentSegmentTree segTree;
    
    
    public:
    int currentStableVersion = 0;
    RangeUpdatePersistentSegmentTree(int N){
        this->segTree = PersistentSegmentTree(N+1);
        currentStableVersion = 0;
    }
    
    void updateRange(pii indexRange, ll val){
        currentStableVersion+=1;
        segTree.updateCurrentVersion(indexRange.f, val);
        segTree.updateCurrentVersion(indexRange.s+1,-val);
    }
    
    int queryVersion(int index, int version){
        return segTree.queryVersion(1, index, 2*version);      
    }
    
    int queryCurrentVersion(int index){
        return queryVersion(index, currentStableVersion);      
    }
    
    void resetTree(int n){
        currentStableVersion=0;
        segTree.resetTree(n+1);
    }
};

// vi pos(mx6+5,-1);

int compute_brute(int L, int R, const vector<vi> &adj, const vi &pos)
{   
    int num_fairs = 0;
    rep(ind, L, R)
    {   
        bool fair = true;
        for(int v:adj[ind])
        {
            if(L<=v and v<=R and pos[v]<pos[ind] )
            {
                fair = false;
                break;
            }
        }
        
        if(fair)
            num_fairs+=1;
    }
    // cout<<"L, R, num_fairs: "<<L<<" "<<R<<" "<<num_fairs<<"\n";
    return num_fairs;
}
int cur_pos = 1;

void considerFriends(int u, int v, vector<pii> & LRGuest, vi &pos)
{
    if(u>v) {
        swap(u,v);
    }
    
    if(pos[u]<pos[v]) {
        
        LRGuest[v].f = max(LRGuest[v].f,u);
    } else if(pos[v] <pos[u]){
        LRGuest[u].s = min(LRGuest[u].s,v);
    }
}
void DFSRunner(int src, const vector<vi> &adj, vb &seen, vi &pos, 
                vector<pii> & LRGuest){
   
    pos[src]=cur_pos++;
    seen[src]=true;
    
    for(int v:adj[src])
    {   
        
        
        if(!seen[v])
        {
            DFSRunner(v, adj, seen, pos, LRGuest);
        }
    }
    
    for(int v:adj[src])
    {
        considerFriends(src, v, LRGuest, pos);
    }
}

pair<vi, vector<pii> > DFSPreCompute(int n, const vector<vi> &adj)
{   
    cur_pos = 1;
    vb seen(n+1,false);
    vi pos(n+1,-1);
    vector<pii> LRGuest(n+1, mp(0,n+1));
    
    rep(src, 1, n)
    {
        if(!seen[src])
        {
            DFSRunner(src, adj, seen, pos, LRGuest);
        }
    }
    
    return mp(pos, LRGuest);
}
vi processEventsOffline(int n, int Q,  vector<vi> &events){
    
    sort(events.begin(), events.end());
    
    FenwickTreeRangeUpdate rangeTree(n+5);
    
    vi answers(Q+1,0);
    
    for(auto event: events)
    {   
        // cout<<"event: ";
        // print(event);
        
        if(event[1]==0){
            //Start of a rectangle;
            
            int Lindex = event[2];
            int Rindex = event[3];
            
            rangeTree.updateRange(mp(Lindex, Rindex),1);
        } else if(event[1]==1){
            
            int pos = event[2];
            int qu = event[4];
            
            int ans = rangeTree.query(pos);
            
            answers[qu]=ans;
            
        } else if(event[1]==2){
            
            int Lindex = event[2];
            int Rindex = event[3];
            
            rangeTree.updateRange(mp(Lindex, Rindex),-1);
        } else{
            throw logic_error("Weird event\n");
        }
    }
    
    return answers;
    
}
int max_val = mx6;
    
RangeUpdatePersistentSegmentTree pTree(max_val);  

vi processEventsOfflinePerst(int n, int Q,  vector<vi> &events){
    
    sort(events.begin(), events.end());
    
    // PersistentFenwickTreeRangeUpdate rangeTree(n+5, 32);
    
    // int balanceVal = 0;
    
    pTree.resetTree(n);
    
    deque<int> special_vals;
    
    vi answers(Q+1,0);
    
    int numBalanceVals = 0;
    
    for(auto event: events)
    {   
        // cout<<"event: ";
        // print(event);
        // if(DEBUG)
        // {
        //     cout<<"special_vals: ";
        //     print(special_vals);
        // }
        if(event[1]==0){
            //Start of a rectangle;
            
            int Lindex = event[2];
            int Rindex = event[3];
            
            if(event[5]){
                special_vals.push_back(event[2]);
                continue;
            }
            
            pTree.updateRange(mp(Lindex, Rindex),1);
        } else if(event[1]==1){
            
            int pos = event[2];
            int qu = event[4];
            
            int ans = pTree.queryCurrentVersion(pos);
            
            
            
            int extra_ans = upper_bound(special_vals.begin(), special_vals.end(),pos) - special_vals.begin();
            
            answers[qu] = ans+extra_ans;
            
        } else if(event[1]==2){
            
            int Lindex = event[2];
            int Rindex = event[3];
            
            if(event[5]){
                special_vals.pop_front();
                continue;
            }
            
            pTree.updateRange(mp(Lindex, Rindex),-1);
        } else{
            throw logic_error("Weird event\n");
        }
    }
    //cout<<"numBalanceVals: "<<numBalanceVals<<endl;
    return answers;
    
}
 void compute_test_case_offline(
            int n, int m, int Q, 
            const vector<vi> &adj)
{
    auto computeAns = DFSPreCompute(n, adj);
    auto pos = computeAns.f;
    auto LRGuest = computeAns.s;
    
    vector<vi> events;
    
    //event format
    //0: x 
    //1: type (0: left line, 1: query, 2: right line)
    //2: y 
    //3: y2 (-1 for type 1)
    //4: query Number (-1 for type 0 or type 2)
    //5: if special event
    repi(g, 1 , n){
        int Lg = LRGuest[g].f+1;
        int Rg = LRGuest[g].s-1;
        
        if(Lg > Rg)
            continue;
        
        vi rectStart = {Lg,0,g, Rg,-1};
        vi rectEnd = {g,2,g, Rg,-1};
        
        events.pb(rectStart);
        events.pb(rectEnd);
    }
    
    
    repi(qu,1,Q)
    {
        int x,y;
        cin>>x>>y;
        int L = (x-1)%n + 1;
        int R = (y-1)%n + 1;
        if(L>R)
            swap(L,R);
        
        events.pb({L,1,R,-1,qu});
    }
    
    
    vi answers = processEventsOffline(n,Q, events);
    
    rep(qu,1,Q)
    {
        cout<<answers[qu]<<"\n";
    }
}

 void compute_test_case_offline_pers(
            int n, int m, int Q, 
            const vector<vi> &adj)
{
    auto computeAns = DFSPreCompute(n, adj);
    auto pos = computeAns.f;
    auto LRGuest = computeAns.s;
    
    vector<vi> events;
    
    //event format
    //0: x 
    //1: type (0: left line, 1: query, 2: right line)
    //2: y 
    //3: y2 (-1 for type 1)
    //4: query Number (-1 for type 0 or type 2)
    //5: if special event
    repi(g, 1 , n){
        int Lg = LRGuest[g].f+1;
        int Rg = LRGuest[g].s-1;
        
        if(Lg > Rg)
            continue;
        
        int special_event = (Lg==1 and Rg==n)?1:0;
        
        vi rectStart = {Lg,0,g, Rg,-1, special_event};
        vi rectEnd = {g,2,g, Rg,-1, special_event};
        
        events.pb(rectStart);
        events.pb(rectEnd);
    }
    
    
    repi(qu,1,Q)
    {
        int x,y;
        cin>>x>>y;
        int L = (x-1)%n + 1;
        int R = (y-1)%n + 1;
        if(L>R)
            swap(L,R);
        
        events.pb({L,1,R,-1,qu});
    }
    
    
    vi answers = processEventsOfflinePerst(n,Q, events);
    
    rep(qu,1,Q)
    {
        cout<<answers[qu]<<"\n";
    }
}

void compute_test_case()
{
    int n, m;
    int Q,S;
    cin>>n>>m>>Q>>S;
    

    vector<vi> adj(n+5);
    vector<map<int,bool>> adjMat(n+5);
    
    rep(e,1,m)
    {
        int u;
        int v;
        
        cin>>u>>v;
        
        adj[u].pb(v);
        adj[v].pb(u);
        
        adjMat[u][v] =true;
        adjMat[v][u]=true;
        
    }
    
    if(S==0)
    {
        compute_test_case_offline(n, m, Q, adj);
        return;
    }
    auto computeAns = DFSPreCompute(n, adj);
    auto pos = computeAns.f;
    
    
    // cout<<"pos: ";
    // print(pos);
    
    int lst = 0;
    int md = n;
    rep(qu,1,Q)
    {
        int x,y;
        cin>>x>>y;
        int L = (x+(S*lst)-1)%n + 1;
        int R = (y+(S*lst)-1)%n + 1;
        if(L>R)
            swap(L,R);
        // cout<<"qu x y: "<<qu<<" "<<x<<" "<<y<<"\n";
        // cout<<"L,R: "<<L<<" "<<R<<"\n";
        lst = compute_brute(L,R,adj,pos);
        cout<<lst<<"\n";
    }
}

inline int bin_search(int x, const vector<vi> &events)
{
    int lo = 0;
    int hi = events.size();
    hi--;
    
    int best_ver = -1;
    
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        
        //Either less than or a start rectangle at the same point
        if(events[mid][0]<x or (events[mid][0]==x and events[mid][1]==0)){
            best_ver = max(best_ver, mid);
            lo = mid+1;
        } else if(events[mid][0]>x or (events[mid][0]==x and events[mid][1]==2)){
            hi = mid-1;
        } else{
            throw logic_error("Weird event");
        }
    }
    
    return best_ver+1;
    
    return 0;
}
// PersistentFenwickTreeRangeUpdate pTree(mx6+1);
int compute_opt(int L, int R, const vector<vi> &events, PersistentFenwickTreeRangeUpdate & pTree){
    int version = bin_search(L, events);
    // int version = posVerson[L];
    // cout<<"Query L:"<<L<<"  at R: "<<R<<" with version: "<<version<<"\n";
    int lst = pTree.queryVersion(R,version);
    
    return lst;
}


void process_events_opt(vector<vi> &events,
    PersistentFenwickTreeRangeUpdate &pTree)
{   
    
    // vi posVerson(n+1,0);
    
    sort(events.begin(), events.end());
    
    int ver = 0;
    for(auto event:events)
    {   
        ver+=1;
        
        if(event[1]==0){
            //Start of a rectangle;
            
            int Lindex = event[2];
            int Rindex = event[3];
            // cout<<"Updating at pos:"<<event[0]<<" " <<"["<<Lindex<<", "<<Rindex<<"] with "<<1<<endl;
            pTree.updateRange(mp(Lindex, Rindex),1);
            
            // posVerson[event[0]] = ver;
        } else if(event[1]==2){
            
            int Lindex = event[2];
            int Rindex = event[3];
            // cout<<"Updating at pos:"<<event[0]<<" " <<"["<<Lindex<<", "<<Rindex<<"] with "<<-1<<endl;
            pTree.updateRange(mp(Lindex, Rindex),-1);
        } else{
            throw logic_error("Weird event\n");
        }
    }
    
    // return posVerson;
}
MapPersistentFenwickTreeRangeUpdate pFenwickTree;

 void process_events_and_queries_opt_fenwick_tree(int n, int Q, int S,  
vector<vi> &events){
    
    
    sort(events.begin(), events.end());
    
    // PersistentFenwickTreeRangeUpdate pFenwickTree(n);
    
    pFenwickTree.resetTree(n);
    
    int ver = 0;
    for(auto event:events)
    {   
        ver+=1;
        
        if(event[1]==0){
            //Start of a rectangle;
            
            int Lindex = event[2];
            int Rindex = event[3];
            // cout<<"Updating at pos:"<<event[0]<<" " <<"["<<Lindex<<", "<<Rindex<<"] with "<<1<<endl;
            pFenwickTree.updateRange(mp(Lindex, Rindex),1);
            
            // posVerson[event[0]] = ver;
        } else if(event[1]==2){
            
            int Lindex = event[2];
            int Rindex = event[3];
            // cout<<"Updating at pos:"<<event[0]<<" " <<"["<<Lindex<<", "<<Rindex<<"] with "<<-1<<endl;
            pFenwickTree.updateRange(mp(Lindex, Rindex),-1);
        } else{
            throw logic_error("Weird event\n");
        }
    }
    
    int lst = 0;
    int md = n;
    rep(qu,1,Q)
    {
        int x,y;
        cin>>x>>y;
        int L = (x+(S*lst)-1)%n + 1;
        int R = (y+(S*lst)-1)%n + 1;
        if(L>R)
            swap(L,R);
        
        int version = bin_search(L, events);
        lst = pFenwickTree.queryVersion(R,version);
        
        cout<<lst<<"\n";
    }
    // cout<<endl;
}


 void process_events_and_queries_opt_seg_tree(int n, int Q, int S,  
vector<vi> &events){
    
    
    sort(events.begin(), events.end());
      
    pTree.resetTree(n);
    
    int ver = 0;
    for(auto event:events)
    {   
        ver+=1;
        
        if(event[1]==0){
            //Start of a rectangle;
            
            int Lindex = event[2];
            int Rindex = event[3];
            // cout<<"Updating at pos:"<<event[0]<<" " <<"["<<Lindex<<", "<<Rindex<<"] with "<<1<<endl;
            pTree.updateRange(mp(Lindex, Rindex),1);
            
            // posVerson[event[0]] = ver;
        } else if(event[1]==2){
            
            int Lindex = event[2];
            int Rindex = event[3];
            // cout<<"Updating at pos:"<<event[0]<<" " <<"["<<Lindex<<", "<<Rindex<<"] with "<<-1<<endl;
            pTree.updateRange(mp(Lindex, Rindex),-1);
        } else{
            throw logic_error("Weird event\n");
        }
    }
    
    int lst = 0;
    int md = n;
    rep(qu,1,Q)
    {
        int x,y;
        cin>>x>>y;
        int L = (x+(S*lst)-1)%n + 1;
        int R = (y+(S*lst)-1)%n + 1;
        if(L>R)
            swap(L,R);
        
        int version = bin_search(L, events);
        lst = pTree.queryVersion(R,version);
        
        cout<<lst<<"\n";
    }
    // cout<<endl;
}
 void compute_test_case_opt()
{
    int n, m;
    int Q,S;
    cin>>n>>m>>Q>>S;
    
    
    vector<vi> adj(n+5);
    
    rep(e,1,m)
    {
        int u;
        int v;
        
        cin>>u>>v;
        
        adj[u].pb(v);
        adj[v].pb(u);
        
        
    }
    // cout<<"n m Q S:"<<n<<" "<<m<<" "<<Q<<" "<<S<<endl;
    // if(S==0)
    // {
    //     compute_test_case_offline_pers(n, m, Q, adj);
    //     return;
    // }
    auto computeAns = DFSPreCompute(n, adj);
    auto pos = computeAns.f;
    auto LRGuest = computeAns.s;
    
    vector<vi> events;
    
    //event format
    //0: x 
    //1: type (0: left line, 2: right line)
    //2: y 
    //3: y2 
    
    repi(g, 1 , n){
        int Lg = LRGuest[g].f+1;
        int Rg = LRGuest[g].s-1;
        
        if(Lg > Rg)
            continue;
        
        vi rectStart = {Lg,0,g, Rg};
        vi rectEnd = {g,2,g, Rg};
        
        events.pb(rectStart);
        events.pb(rectEnd);
    }
    
    process_events_and_queries_opt_seg_tree(n, Q, S, events);
    
    // cout<<"pos: ";
    // print(pos);
    
    // PersistentFenwickTreeRangeUpdate pTree(n);
    
    // // pTree.resetTree(n);
    
    // // auto posVerson = process_events_opt(events, pTree, n);
    
    // process_events_opt(events, pTree);
    
    // int lst = 0;
    // int md = n;
    // rep(qu,1,Q)
    // {
    //     int x,y;
    //     cin>>x>>y;
    //     int L = (x+(S*lst)-1)%n + 1;
    //     int R = (y+(S*lst)-1)%n + 1;
    //     if(L>R)
    //         swap(L,R);
    //     // cout<<"qu x y: "<<qu<<" "<<x<<" "<<y<<"\n";
    //     // cout<<"L,R: "<<L<<" "<<R<<"\n";
    //     lst = compute_opt(L,R,events, pTree);
    //     // lst = compute_opt(L,R,events, pTree,  posVerson);
    //     // int lst_brute = compute_brute(L,R,adj,pos);
    //     // if(lst!=lst_brute)
    //     // {
    //     //     throw logic_error("Incorrect answer lst!=lst_brute");
    //     // }
    //     // lst = lst_brute;
    //     cout<<lst<<"\n";
    // }
}
// 1
// 1000000 3 5 0
// 1 2
// 1 3
// 2 4
// 3 4
// 1 5000
// 323 767
// 123 598
// 1 1000

// 5
// 1 1 5 5
// 1 6 10 3
// 1 1 10 -1
// 1 9 10 50
// 1 7 7 63
// 4
// 1 1 5 -10
// 1 1 3 9
// 1 4 5 -10
// 1 5 5 -30
int main(void)
{
    ios_base::sync_with_stdio(false);
    
    
    
    int t;
    cin>>t;
    
    while(t--)
    {
        compute_test_case_opt();
    }
    
    // MapPersistentFenwickTreeRangeUpdate tr(15);
    
    // while(t--)
    // {
    //     int opt,L,R, val;
    //     int ind;
    //     cin>>opt;
        
    //     if(opt==1)
    //     {
    //         cin>>L>>R>>val;
    //     }
    //     cout<<"Updating :"<<"["<<L<<", "<<R<<"] with "<<val<<endl; 
    //     tr.updateRange(mp(L,R), val);
    // }
    // cout<<"Cur Version: "<<tr.currentVersion<<endl;
    // rep(ver,0,tr.currentVersion)
    // {   
    //     cout<<"Version: "<<ver<<endl;
    //     rep(i,1,14)
    //     {
    //         int val = tr.queryVersion(i,ver);
    //         cout<<val<<" ";
    //     }
    //     cout<<endl<<endl;
    // }
    
    // cout<<"RESETTING TREEE:"<<endl<<endl;
    // tr.resetTree(5);
    
    // cin>>t;
    
    // while(t--)
    // {
    //     int opt,L,R, val;
    //     int ind;
    //     cin>>opt;
        
    //     if(opt==1)
    //     {
    //         cin>>L>>R>>val;
    //     }
    //     cout<<"Updating :"<<"["<<L<<", "<<R<<"] with "<<val<<endl; 
    //     tr.updateRange(mp(L,R), val);
    // }
    // cout<<"Cur Version: "<<tr.currentVersion<<endl;
    // rep(ver,0,tr.currentVersion)
    // {   
    //     cout<<"Version: "<<ver<<endl;
    //     rep(i,1,5)
    //     {
    //         int val = tr.queryVersion(i,ver);
    //         cout<<val<<" ";
    //     }
    //     cout<<endl<<endl;
    // }
    
    return 0;
}
