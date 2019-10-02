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

const int DEBUG = 0;
const int MAX_VAL = mx5+1;
const int MAX_ROOT_NODE_SIZE = 4*mx5+5;
const int MAX_TREE_SIZE = 8*20*mx5+10;

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
        rootNodes = vector<int>((4*this->N)+5,-1);
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
        
        // if(DEBUG){
        //     cout<<"Querying indices: "<<" "<<Lindex<<" "<<Rindex<<"\n";
        //     cout<<"this->N: "<<this->N<<"\n";
        //     cout<<"Expanded Nodes: "<<complexity_counter<<endl<<endl;
        // } 
        
        return ans;
        
    }
    
    int getLatestKthVal(int k, int version){
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
    
    int getLatestKthVal(int k, int currentNodeIndex, int L, int R){
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

// const int DEBUG = 1;

vi compute_test_case_seg(int n, vll &a)
{   
    vi prev_location(n+1,0);
    
    vector<vi> new_vals_to_push(n+1);
    
    rep(j,1,n)
    {
        
        new_vals_to_push[prev_location[a[j]]+1].push_back(j);
        prev_location[a[j]] =j;
    }
    // print(prefix_types);
    
    PersistentSegmentTree segTree(n);
    vi versionNumber(n+1,0);
    
    rep(j,1,n)
    {   
        // if(j>1)
        //     segTree.updateCurrentVersion(j-1,-1);
            
        for(auto new_index: new_vals_to_push[j]){
            segTree.updateCurrentVersion(new_index,1);
        }
        versionNumber[j] = segTree.getCurrentVersion();
        
    }
    vi ans(n,0);
    
    if(DEBUG)
     {   
         rep(L,1,n)
        {   
            cout<<"Type array at L= " <<L<<"\n";
            segTree.debugPrint(versionNumber[L]);    
        }
        
     }
    
    
    rep(k,1,n)
    {
        int ans_k = 0;
        
        int L = 1;
        
        while(L<=n)
        {   
            ans_k+=1;
            // cout<<"Querying L: "<<L<<" for k: "<<k<<"\n";
            int R = segTree.getLatestKthVal(L-1 + k+1, versionNumber[L]);
            // cout<<"R: "<<R<<endl<<endl;
            L = R;
        }
        
        ans[k-1] = ans_k;
    }
    
    return ans;
    
    
}
// Problem 786C - Till I collapse 
// Submission link: https://codeforces.com/contest/786/submission/61679983
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vll a(n+1,0);
    
    rep(j,1,n){
        cin>>a[j];
    }
    
    vi ans = compute_test_case_seg(n, a);
    
    print(ans);
    return 0;
}
