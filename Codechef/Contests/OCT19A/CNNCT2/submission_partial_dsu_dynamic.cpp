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
    
    int getNodeSize(int node){
        return size[node];
    }
    
    int getRootNodeSize(int node){
        int root = getRoot(node);
        return size[root];
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
        
        if(root1 == root2)
        {
            return;
        }
        if(size[root1] < size[root2]){
            swap(root1,root2);
        }
        
        parent[root2] = root1;
        size[root1] += size[root2];
    }
};

class DSUDynamic{
    private:
    vector<vector<int>> parent;
    vector<vector<int>> size;
    vector<pii> edgesAdded;
    vector<pii> rootsConnected;
    
    public:
    DSUDynamic(){
    
    }
    
    void printDSU(){
        cout<<"DSUDynamic: "<<endl;
        cout<<"edgesAdded: "; print(edgesAdded);
        cout<<"rootsConnected: "; print(rootsConnected);
        cout<<"parents: "; print(parent);
        cout<<"sizes: ";print(size);
        cout<<endl;
    }
    DSUDynamic(int n){
        parent.resize(n+1);
        size.resize(n+1);
        rep(i,1,n){
            parent[i].push_back(i);
            size[i].push_back(1);
        }
    }
    auto getParents(){
        return parent;
    }
    auto getSizes(){
        return size;
    }
    
    int getNodeSize(int node){
        if(size[node].empty())
        {
            throw logic_error("size of node empty");
        }
        return size[node].back();
    }
    
    int getNodeParent(int node){
        if(parent[node].empty()){
            throw logic_error("parent of node empty");
        }
        return parent[node].back();
    }
    
    int getRootNodeSize(int node){
        int root = getRoot(node);
        return getNodeSize(root);
    }
    int getRoot(int node){
       int par = getNodeParent(node);
       if(getNodeParent(par) == par){
           return par;
       }
       
       int root = getRoot(par);
       
       if(parent[node].empty()){
           throw logic_error("parent of node empty");
       }
    //   parent[node].back() = root;
       
       return root;
    }
    
    bool checkSame(int a, int b){
        return getRoot(a)==getRoot(b);
    }
    
    void connectNodes(int a, int b){
        
        int root1 = getRoot(a);
        int root2 = getRoot(b);
        
        // if(root1 == root2)
        // {   
        //     return;
        // }
        if(getNodeSize(root1) < getNodeSize(root2)){
            swap(root1,root2);
            swap(a,b);
        }
        
        edgesAdded.push_back({a,b});
        rootsConnected.push_back({root1,root2});
        
        // cout<<"Pushing edge: "<<a<<' '<<b<<endl;
        // cout<<"Pushing roots: "<<root1<<' '<<root2<<endl;
        
        parent[root1].push_back(root1);
        parent[root2].push_back(root1);
        
        int root1_size = (root1==root2)?getNodeSize(root1):getNodeSize(root1)+getNodeSize(root2);
        
        size[root1].push_back(root1_size);
        size[root2].push_back(getNodeSize(root2));
        
    }
    
    void revertLatestEdge(){
        if(edgesAdded.empty())
            return;
        
        auto latestEdge = edgesAdded.back();
        auto latestRootConnect = rootsConnected.back();
        // auto a = latestEdge.f;
        // auto b = latestEdge.s;
        
        auto root1 = latestRootConnect.f;
        auto root2 = latestRootConnect.s;
        
        edgesAdded.pop_back();
        rootsConnected.pop_back();
        
        parent[root1].pop_back();
        parent[root2].pop_back();
        
        size[root1].pop_back();
        size[root2].pop_back();
        
    }
};

int bestAns = -1;
vi usedEdges;
DSUDynamic dsu_one, dsu_two;
const int DEBUG = 0;

bool checkConnectivity(const int &n, const vi &usedEdges, const vector<pii> & edges){
    DSU dsu(n);
    for(auto edge_index: usedEdges){
        if(dsu.getRootNodeSize(1)==n)
        {
            return true;
        }
        auto edge = edges[edge_index-1];
        dsu.connectNodes(edge.f, edge.s);
    }
    return dsu.getRootNodeSize(1) == n;
}
void backTrack(int edge_index, const int &n, const int &m, const vector<pii> & edges_one, vector<pii> &edges_two){
    if(edge_index==m+1){
        return;
    }
    
    if(usedEdges.size()>=bestAns)
        return;
        
    if(checkConnectivity(n, usedEdges, edges_one) and checkConnectivity(n, usedEdges, edges_two))
    {
        int ans = usedEdges.size();
        bestAns = min(bestAns,ans);
        
        if(DEBUG>=3)
        {
            cout<<"Candidate usedEdges:";
            print(usedEdges);
            cout<<"ans: "<<ans<<endl;
            
        }
        return;
    }
    
        
    backTrack(edge_index+1,n,m,edges_one,edges_two);
    
    usedEdges.pb(edge_index);
    
    if(usedEdges.size()>=bestAns)
        return;
        
    if(checkConnectivity(n, usedEdges, edges_one) and checkConnectivity(n, usedEdges, edges_two))
    {
        int ans = usedEdges.size();
        bestAns = min(bestAns,ans);
        if(DEBUG>=3)
        {
            cout<<"Candidate usedEdges:";
            print(usedEdges);
            cout<<"ans: "<<ans<<endl;
            
        }
        
        usedEdges.pop_back();
        
        return;
    }
    backTrack(edge_index+1,n,m,edges_one,edges_two);
    usedEdges.pop_back();
    
}

void backTrackDynamic(int edge_index, const int &n, const int &m, const vector<pii> & edges_one, vector<pii> &edges_two){
    
    if(usedEdges.size()>=bestAns)
        return;
    if(dsu_one.getRootNodeSize(1)==n and dsu_two.getRootNodeSize(1)==n){
        int ans = usedEdges.size();
        bestAns = min(bestAns, ans);
        if(DEBUG)
        {
            cout<<"Candidate usedEdges:";
            print(usedEdges);
            cout<<"dsu_one: ";dsu_one.printDSU();
            cout<<"dsu_two: ";dsu_two.printDSU();
            cout<<"ans: "<<ans<<endl;
            cout<<endl;
            
        }
        return;
    }
    if(edge_index==m+1){
        return;
    }
    //Back track without adding edge.
    backTrackDynamic(edge_index+1,n,m,edges_one,edges_two);
    
    
    if(usedEdges.size() >= bestAns-1)
    {
        return;
    }
    
    auto edgeOne = edges_one[edge_index-1];
    auto edgeTwo = edges_two[edge_index-1];
    
    //check if edge is redundant in both graphs
    // if(dsu_one.checkSame(edgeOne.f, edgeOne.s) and dsu_two.checkSame(edgeTwo.f, edgeTwo.s)){
    //     return;
    // }
    
    
    usedEdges.pb(edge_index);
        
    dsu_one.connectNodes(edgeOne.f, edgeOne.s);
    dsu_two.connectNodes(edgeTwo.f, edgeTwo.s);
    
    if(DEBUG>=2){
        cout<<endl;
        
        cout<<"Added edge number: "<<edge_index<<endl;
        cout<<"usedEdges: "; print(usedEdges);
        cout<<"n, m: "<<n<<", "<<m<<endl;
        cout<<"edge_one: "<<"("<<edgeOne.f<<", "<<edgeOne.s<<")"<<endl;
        cout<<"edge_two: "<<"("<<edgeTwo.f<<", "<<edgeTwo.s<<")"<<endl;
        cout<<"dsu_one.print "<<endl;
        dsu_one.printDSU();
        cout<<"dsu_two.print "<<endl;
        dsu_two.printDSU();
        cout<<endl;
    }
    
    if(dsu_one.getRootNodeSize(1)==n and dsu_two.getRootNodeSize(1)==n){
        int ans = usedEdges.size();
        bestAns = min(bestAns, ans);
        
        if(DEBUG)
        {
            cout<<"Candidate usedEdges:";
            print(usedEdges);
            cout<<"dsu_one: ";dsu_one.printDSU();
            cout<<"dsu_two: ";dsu_two.printDSU();
            cout<<"ans: "<<ans<<endl;
            cout<<endl;
            
        }
        
        usedEdges.pop_back();
        dsu_one.revertLatestEdge();
        dsu_two.revertLatestEdge();
        
        if(DEBUG>=2){
        cout<<endl;
        
        cout<<"Reverted edge number: "<<edge_index<<endl;
        cout<<"usedEdges: "; print(usedEdges);
        cout<<"n, m: "<<n<<", "<<m<<endl;
        cout<<"edge_one: "<<"("<<edgeOne.f<<", "<<edgeOne.s<<")"<<endl;
        cout<<"edge_two: "<<"("<<edgeTwo.f<<", "<<edgeTwo.s<<")"<<endl;
        cout<<"dsu_one .print "<<endl;
        dsu_one.printDSU();
        cout<<"dsu_two.print "<<endl;
        dsu_two.printDSU();
        cout<<endl;
    }
        
        return;
    }
    
    
    backTrackDynamic(edge_index+1,n,m,edges_one,edges_two);
    
    
    usedEdges.pop_back();
    dsu_one.revertLatestEdge();
    dsu_two.revertLatestEdge();
    
    if(DEBUG>=2){
        cout<<endl;
        
        cout<<"Reverted edge number: "<<edge_index<<endl;
        cout<<"usedEdges: "; print(usedEdges);
        cout<<"n, m: "<<n<<", "<<m<<endl;
        cout<<"edge_one: "<<"("<<edgeOne.f<<", "<<edgeOne.s<<")"<<endl;
        cout<<"edge_two: "<<"("<<edgeTwo.f<<", "<<edgeTwo.s<<")"<<endl;
        cout<<"dsu_one .print "<<endl;
        dsu_one.printDSU();
        cout<<"dsu_two.print "<<endl;
        dsu_two.printDSU();
        cout<<endl;
    }
    
    return;
    
}
void initState(const int &n, const int &m){
    bestAns = m+1;
    usedEdges = {};
    dsu_one = DSUDynamic(n);
    dsu_two = DSUDynamic(n);
}
int compute_test_case_dynamic(const int &n, const int &m, const vector<pii> & edges_one, vector<pii> &edges_two){
    initState(n ,m);

    backTrackDynamic(1,n,m,edges_one,edges_two);
    int best_ans_dynamic = bestAns;
    
    return bestAns;
}

int compute_test_case_brute(const int &n, const int &m, const vector<pii> & edges_one, vector<pii> &edges_two){
    // initState(n ,m);

    // backTrackDynamic(1,n,m,edges_one,edges_two);
    // int best_ans_dynamic = bestAns;
    initState(n,m);
    backTrack(1,n,m,edges_one, edges_two);
    int best_ans_brute = bestAns;
    
    return bestAns;
}
pair<pii, pair<vector<pii>,vector<pii>> > getRandomGraph(int N, int M){
    // int n = (rand()%N)+1;
    // int m = (rand()%M)+1;
    
    int n = N;
    int m = M;
    
    m = min(m, (n*(n-1))/2);
    // cout<<"n, m: "<<n<<" "<<m<<endl;
    
    vi edgeSet(n*n,0);
    
    rep(j,0,n*n-1){
        edgeSet[j] = j;
    }
    
    random_shuffle ( edgeSet.begin(), edgeSet.end());
    
    vector<pii> edges_one;
    int size_val = edgeSet.size();
    int next_ind = 0;
    
    vector<vb> AdjMat(n+1,vb(n+1,false));
    
    // while(next_ind<size_val){
    //     int edges_one_sz = edges_one.size();
    //     if(edges_one_sz>=m or size_val==0)
    //     {
    //         break;
    //     }
        
    //     int u = edgeSet[rand_ind]/n + 1;
    //     int v = edgeSet[rand_ind]%n + 1;
        
    //     if(!AdjMat[u][v] and u!=v)
    //         edges_one.pb({u,v});
        
    //     AdjMat[u][v]=AdjMat[v][u] = true;
        
    //     swap(edgeSet[rand_ind], edgeSet[size_val-1]);
        
    //     size_val-=1;
        
    // }
    
    rep(next_ind,0,size_val-1){
        int edges_one_sz = edges_one.size();
        if(edges_one_sz>=m or size_val==0)
        {
            break;
        }    
        
        int u = edgeSet[next_ind]/n+1;
        int v = edgeSet[next_ind]%n +1;
        if(!AdjMat[u][v] and u!=v)
            edges_one.pb({u,v});
        AdjMat[u][v]=AdjMat[v][u] = true;
    }
    
    
    
    // print(edges_one);
    // cout<<endl;
    size_val = edgeSet.size();
    AdjMat = vector<vb> (n+1,vb(n+1,false));
    vector<pii> edges_two;
    random_shuffle (edgeSet.begin(), edgeSet.end());
    // while(true){
    //     int edges_two_sz = edges_two.size();
    //     if(edges_two_sz>=m or size_val==0)
    //     {
    //         break;
    //     }


    //     int rand_ind = rand()%(size_val);
        
    //     int u = edgeSet[rand_ind]/n + 1;
    //     int v = edgeSet[rand_ind]%n + 1;
        
    //     if(!AdjMat[u][v] and u!=v)
    //         edges_two.pb({u,v});
        
    //     AdjMat[u][v]=AdjMat[v][u]=true;
        
    //     swap(edgeSet[rand_ind], edgeSet[size_val-1]);
        
    //     size_val-=1;
        
    // }
    // print(edges_two);
    // cout<<endl;
    
    rep(next_ind,0,size_val-1){
        int edges_two_sz = edges_two.size();
        if(edges_two_sz>=m or size_val==0)
        {
            break;
        }    
        
        int u = edgeSet[next_ind]/n+1;
        int v = edgeSet[next_ind]%n +1;
        if(!AdjMat[u][v] and u!=v)
            edges_two.pb({u,v});
        AdjMat[u][v]=AdjMat[v][u] = true;
    }
    return {{n,m},{edges_one, edges_two}};
}

void stressTest(int N, int M, int testRuns = 50, int seed = 42){
    srand(seed);
    rep(test_index, 1, testRuns){
        auto randomGraph = getRandomGraph(N,M);
        auto n = randomGraph.f.f;
        auto m = randomGraph.f.s;
        auto edges_one = randomGraph.s.f;
        auto edges_two = randomGraph.s.s;
        
        auto ans_dynamic = compute_test_case_dynamic(n,m,edges_one,edges_two);
        auto ans_brute = compute_test_case_brute(n,m,edges_one,edges_two);
        
        if(ans_brute!=ans_dynamic or true)
        {   
            cout<<"n, m: "<<n<<" "<<m<<endl;
            cout<<"edges_one: ";print(edges_one);
            cout<<"edges_two: ";print(edges_two);
            cout<<"ans_brute: "<<ans_brute<<endl;
            cout<<"ans_dynamic: "<<ans_dynamic<<endl<<endl;
        }
    }
}
// Submission Link: https://www.codechef.com/viewsolution/27314153
// Problem Link: Fault System: https://www.codechef.com/OCT19A/problems/CNNCT2
int main(void)
{
    ios_base::sync_with_stdio(false);
    // stressTest(10,15,10,42);
    int t;
    cin>>t;
    rep(t_index,1,t)
    {
        int n,m;
        cin>>n>>m;
        vector<pii> edges_one;
        vector<pii> edges_two;
        
        rep(edge_index,1,m){
            int u,v;
            cin>>u>>v;
            edges_one.pb({u,v});
        }
        
        rep(edge_index,1,m){
            int u,v;
            cin>>u>>v;
            edges_two.pb({u,v});
        }
        if(DEBUG)
        {
            cout<<"Test case: "<<t_index<<endl;
        }
        auto ansNext = compute_test_case_dynamic(n, m, edges_one, edges_two);
        // auto ansNextBrute = compute_test_case_brute(n ,m , edges_one, edges_two);
        
        // if(ansNext != ansNextBrute){
        //     cout<<ansNext<<" "<<ansNextBrute<<endl;
        //     throw logic_error("ansNext!=ansNextBrute");
        // }
        cout<<ansNext<<'\n';
    }
    return 0;
}
