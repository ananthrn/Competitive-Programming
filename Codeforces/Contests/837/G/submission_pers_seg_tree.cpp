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


class PersistentSegmentTreeNode{
    private:
    public:
    pair<ll,ll> slopeConstant;
    
    int start,end;
    
    int leftChildIndex, rightChildIndex;
    
    int thisIndex;
    
    PersistentSegmentTreeNode(): slopeConstant(mp(0,0)), start(-1),end(-1), leftChildIndex(-1), rightChildIndex(-1), thisIndex(-1){} 
    
    void assignLeaf(pll value, int start, int end, int thisIndex){
        this->slopeConstant = value;
        this->start = start;
        this->end = end;
        this->thisIndex = thisIndex;
    }
    void merge( PersistentSegmentTreeNode &left,  PersistentSegmentTreeNode&right){
        this->start = left.start;
        this->end = right.end;
        auto leftSlopeConstant = left.getValue();
        auto rightSlopeConstant = right.getValue();
        
        this->leftChildIndex = left.thisIndex;
        this->rightChildIndex = right.thisIndex;
        
        this->slopeConstant = addPair(leftSlopeConstant, rightSlopeConstant);
        
    }
    void print(){
         cout<<"\nthisIndex:"<<thisIndex<<"\n";
        cout<<"(start, end): "<<start<<" "<<end<<"\n";
        cout<<"(leftChildIndex, rightChildIndex): "<<leftChildIndex<<" "<<rightChildIndex<<"\n";
        
        cout<<"slopeConstant: ";
        cout<<"("<<slopeConstant.f<<", "<<slopeConstant.s<<") ";
        cout<<endl<<endl;
        
       
    }
    pll getValue(){
        return slopeConstant;
    }

    int getSegmentSize(){
        return (end-start + 1);
    }
    
    pll addPair(const pll &a, const pll &b){
        return mp(a.f+b.f, a.s+b.s);
    }
};
class PersistentSegmentTree;

const int DEBUG = 0;
// const int MAX_VAL = mx5+1;
// const int MAX_ROOT_NODE_SIZE = 4*mx5+5;
// const int MAX_TREE_SIZE = 8*20*mx5+10;

// PersistentSegmentTreeNode nodes[MAX_TREE_SIZE];
// unordered_map<int, PersistentSegmentTreeNode> nodes;
// int rootNodes[MAX_ROOT_NODE_SIZE]={-1};

// unordered_map<int, int> rootNodes;

map<pii,int> versionSeen;

class PersistentSegmentTree{
    private:
    
    int NODE_COUNTER = 0;
    unordered_map<int, PersistentSegmentTreeNode> nodes;
    vector<int> rootNodes;
    
    int currentVersion = 0;
    int N = 0;
    int treeSize = 0;
    int rootNodeSize = 0;
    
    int complexity_counter = 0;
    
    public:
    
    PersistentSegmentTree(const vector<pll> &arr){
        
        this->N = arr.size();
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        //cout<<"N treeSize:" <<N<<" "<<treeSize<<"\n";
        rootNodes = vector<int>(this->rootNodeSize,-1);
        NODE_COUNTER = 0;
        
        currentVersion = 0;
        
        buildTree(arr);
        
    }
    
    PersistentSegmentTree(){
        
    }
    
    PersistentSegmentTree(int N){
        this->N = N+1;
        
        this-> treeSize = getPersistentSegmentTreeSize(this->N);
        this->rootNodeSize = getRootNodeSize(this->N);
        
        // nodes = vector<PersistentSegmentTreeNode>(this->treeSize);
        rootNodes = vector<int>(this->rootNodeSize,-1);
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
    
    void buildTree(const vector<pll> & arr){
        int firstRoot = buildTree(arr,0,N-1);
        rootNodes[currentVersion] =firstRoot;
    }
    
    void updateCurrentVersion(int index, pll val){
        
        if(currentVersion>this->rootNodeSize  or rootNodes[currentVersion]==-1){
            throw logic_error("weird currentVersion\n");
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
    
   pll queryVersion(int Lindex, int Rindex, int version){
         if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
            throw logic_error("weird version\n");
        }
        
        auto versionRoot = rootNodes[version];
        
        complexity_counter = 0;
        
        auto ans =  queryVersion(Lindex, Rindex, versionRoot, 0, N-1);
        
        // if(DEBUG){
        //     cout<<"Querying indices: "<<" "<<Lindex<<" "<<Rindex<<"\n";
        //     cout<<"this->N: "<<this->N<<"\n";
        //     cout<<"Expanded Nodes: "<<complexity_counter<<endl<<endl;
        // } 
        
        return ans;
        
    }
    
    // int getLatestKthVal(int k, int version){
    //     if(version>this->rootNodeSize or rootNodes[version]==-1 or version>currentVersion){
    //         throw logic_error("weird version\n");
    //     }
        
    //     int ans = getLatestKthVal(k, rootNodes[version], 0, N-1);
        
    //     return ans;
    // }
    
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
        
        vector<pll> prefix_array(N);
        
        rep(j,1,N-1)
        {
            prefix_array[j] = queryVersion(1,j,version);
        }
        
        cout<<"Type array: "; 
        print(prefix_array);
        
        cout<<endl<<endl;
    }
    private:
    
    int buildTree(const vector<pll> & arr, int L, int R){
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
    
    int update(int index, int currentNodeIndex, pll val, int L, int R){
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
    
    pll queryVersion(int Lindex, int Rindex, int currentNodeIndex, int L, int R){
        complexity_counter+=1;
        if(Rindex<Lindex or currentNodeIndex==-1)
        {
            return mp(0LL,0LL);
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
        
        auto leftValue = mp(0LL,0LL);
        auto rightValue = mp(0LL,0LL);
        
        if(Lindex<=mid and nodes[currentNodeIndex].leftChildIndex!=-1)
        {
            leftValue = queryVersion(Lindex, min(mid,Rindex), nodes[currentNodeIndex].leftChildIndex, L,mid);
        }
        
        if(Rindex>mid and nodes[currentNodeIndex].rightChildIndex!=-1){
            rightValue = queryVersion(max(mid+1,Lindex),Rindex,nodes[currentNodeIndex].rightChildIndex,mid+1, R );
        }
        
        return mp(leftValue.f+rightValue.f,leftValue.s+rightValue.s);
    }
    
    int createNewLeaf(pll val, int start, int end){
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        nodes[NODE_COUNTER].assignLeaf(val, start, end, NODE_COUNTER);
        
        return NODE_COUNTER;
    }
    
    int copyNewLeaf(pll val, int oldLeafIndex){
        
        NODE_COUNTER+=1;
        
        if(NODE_COUNTER>=this->treeSize)
        {
            throw logic_error("Too many nodes");
        }
        
        
        nodes[NODE_COUNTER] = nodes[oldLeafIndex];
        nodes[NODE_COUNTER].slopeConstant = val;
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

struct Interval{
    int x1 =0 , x2=0;
    ll a=0,b=0;
    ll y1=0,y2=0;

    int index = 0;
    
    Interval(int x1_this, int x2_this, ll a_this, ll b_this, ll y1_this, ll y2_this){
        x1 = x1_this;
        x2 = x2_this;
        a= a_this;
        b=b_this;
        y1=y1_this;
        y2 = y2_this;
    }
    
    Interval(){
        
    }
};

struct Event{
  int ending = 0;
  int x = 0;
  
  int index = 0;
    
  Event(int x_this, int end_this, int index_this){
      x = x_this;
      ending = end_this;
      index = index_this;
  }
  Event(){
  }
};

bool cmp_event(const Event & a, const Event&b){
    if(a.x==b.x){
        return a.ending<b.ending;
    }
    return a.x<b.x;
}

int getVersionBinSearch(vector<Event> &events, ll x){
    int best_index = -1;
    int lo = 0;
    int hi = events.size();
    hi--;
    
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        
        if(events[mid].x<x or (events[mid].x==x and events[mid].ending==0))
        {   
            best_index = max(best_index,mid);
            lo = mid+1;
            
        } else 
        {
            hi = mid-1;
        }
    }
    
    return best_index+1;
}
void process_all_events(const vector<Event> &events, const vector<Interval> &intervals, PersistentSegmentTree &segTree){
    for(auto event : events){
        
        int ind = event.index;
        
        if(event.ending==0){
            pll newVal = mp(intervals[ind].a, intervals[ind].b);
            segTree.updateCurrentVersion(ind, newVal);
        } else if (event.ending==1){
            pll newVal = mp(0, intervals[ind].y2);
            segTree.updateCurrentVersion(ind, newVal);
        } else {
            throw logic_error("What ending");
        }
    }
}
vll compute_test_case(int n, const vector<Interval> &intervals)
{
    vector<Event> events(2*intervals.size());
    int j = 0;
     vector<pll> arr(intervals.size()+1, mp(0,0));
     
    for(auto interval: intervals){
        if(interval.index!=0)
        {   auto startEvent = Event(interval.x1+1,0,interval.index);
            auto endEvent = Event(interval.x2,1,interval.index);
            events[j] = startEvent;
            events[j+1] = endEvent;
            j+=2;
            
            arr[interval.index] = mp(0,interval.y1);
        }
    }
    
    sort(events.begin(), events.end(), cmp_event);
    
    PersistentSegmentTree segTree(arr);
    
    process_all_events(events,intervals, segTree);
    
    int m;
    cin>>m;
    
    vll ans(m+1,0);
    rep(q_index,1,m){
        int L,R;
        ll x;
        cin>>L>>R>>x;
        
        x = (x+ans[q_index-1])%mx9;
        
        int version = getVersionBinSearch(events, x);
        
        pll slopeConstant = segTree.queryVersion(L,R,version);
        
        ans[q_index] = slopeConstant.f*x + slopeConstant.s;
        
    }
    
    // cout<<"ans: ";
    
    // print(ans);
    
    return ans;
    
    
}
// Problem Link: https://codeforces.com/contest/837/problem/G
// Submission link: https://codeforces.com/contest/837/submission/61801149
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    
    vector<Interval> intervals(n+1);
    
    rep(j,1,n)
    {
        cin>>intervals[j].x1>>intervals[j].x2>>intervals[j].y1>>intervals[j].a>>intervals[j].b>>intervals[j].y2;
        intervals[j].index=j;
        
    }
    auto ans = compute_test_case(n, intervals);
    
    int ans_sz = ans.size();
    
    rep(j,1,ans_sz-1)
    {
        cout<<ans[j]<<"\n";
    }
    return 0;
}
