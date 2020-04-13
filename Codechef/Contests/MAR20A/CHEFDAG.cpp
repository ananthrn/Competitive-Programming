// Author: ananthrn
// Solution Link: https://www.codechef.com/viewsolution/30246512
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

//Code courtesy of geeksforgeeks.org
// Code link: https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-2-impleme
#define NIL 0 
#define INF INT_MAX 
// A class to represent Bipartite graph for Hopcroft 
// Karp implementation 
class BipGraph 
{ 
    // m and n are number of vertices on left 
    // and right sides of Bipartite Graph 
    int m, n; 
  
    // adj[u] stores adjacents of left side 
    // vertex 'u'. The value of u ranges from 1 to m. 
    // 0 is used for dummy vertex 
    // list<int> *adj; 
    vector<vector<int> > adj;
  
    // These are basically pointers to arrays needed 
    // for hopcroftKarp() 
    // int *pairU, *pairV, *dist; 
    vector<int> pairU, pairV, dist;
    
public: 
    BipGraph(int m, int n); // Constructor 
    void addEdge(int u, int v); // To add edge 
  
    // Returns true if there is an augmenting path 
    bool bfs(); 
  
    // Adds augmenting path if there is one beginning 
    // with u 
    bool dfs(int u); 
  
    // Returns size of maximum matcing 
    int hopcroftKarp(); 
    
    int getPairU(int uIndex){
        assert(uIndex>0 and uIndex<=m);
        return pairU[uIndex];
    }
}; 
  
// Returns size of maximum matching 
int BipGraph::hopcroftKarp() 
{ 
    // // pairU[u] stores pair of u in matching where u 
    // // is a vertex on left side of Bipartite Graph. 
    // // If u doesn't have any pair, then pairU[u] is NIL 
    // pairU = new int[m+1]; 
  
    // // pairV[v] stores pair of v in matching. If v 
    // // doesn't have any pair, then pairU[v] is NIL 
    // pairV = new int[n+1]; 
  
    // // dist[u] stores distance of left side vertices 
    // // dist[u] is one more than dist[u'] if u is next 
    // // to u'in augmenting path 
    // dist = new int[m+1]; 
  
    // Initialize NIL as pair of all vertices 
    for (int u=0; u<m; u++) 
        pairU[u] = NIL; 
    for (int v=0; v<n; v++) 
        pairV[v] = NIL; 
  
    // Initialize result 
    int result = 0; 
  
    // Keep updating the result while there is an 
    // augmenting path. 
    while (bfs()) 
    { 
        // Find a free vertex 
        for (int u=1; u<=m; u++) 
  
            // If current vertex is free and there is 
            // an augmenting path from current vertex 
            if (pairU[u]==NIL && dfs(u)) 
                result++; 
    } 
    return result; 
} 
  
// Returns true if there is an augmenting path, else returns 
// false 
bool BipGraph::bfs() 
{ 
    queue<int> Q; //an integer queue 
  
    // First layer of vertices (set distance as 0) 
    for (int u=1; u<=m; u++) 
    { 
        // If this is a free vertex, add it to queue 
        if (pairU[u]==NIL) 
        { 
            // u is not matched 
            dist[u] = 0; 
            Q.push(u); 
        } 
  
        // Else set distance as infinite so that this vertex 
        // is considered next time 
        else dist[u] = INF; 
    } 
  
    // Initialize distance to NIL as infinite 
    dist[NIL] = INF; 
  
    // Q is going to contain vertices of left side only.  
    while (!Q.empty()) 
    { 
        // Dequeue a vertex 
        int u = Q.front(); 
        Q.pop(); 
  
        // If this node is not NIL and can provide a shorter path to NIL 
        if (dist[u] < dist[NIL]) 
        { 
            // Get all adjacent vertices of the dequeued vertex u 
            // list<int>::iterator i; 
            for (auto i=adj[u].begin(); i!=adj[u].end(); ++i) 
            { 
                int v = *i; 
  
                // If pair of v is not considered so far 
                // (v, pairV[V]) is not yet explored edge. 
                if (dist[pairV[v]] == INF) 
                { 
                    // Consider the pair and add it to queue 
                    dist[pairV[v]] = dist[u] + 1; 
                    Q.push(pairV[v]); 
                } 
            } 
        } 
    } 
  
    // If we could come back to NIL using alternating path of distinct 
    // vertices then there is an augmenting path 
    return (dist[NIL] != INF); 
} 
  
// Returns true if there is an augmenting path beginning with free vertex u 
bool BipGraph::dfs(int u) 
{ 
    if (u != NIL) 
    { 
        // list<int>::iterator i; 
        for (auto i=adj[u].begin(); i!=adj[u].end(); ++i) 
        { 
            // Adjacent to u 
            int v = *i; 
  
            // Follow the distances set by BFS 
            if (dist[pairV[v]] == dist[u]+1) 
            { 
                // If dfs for pair of v also returns 
                // true 
                if (dfs(pairV[v]) == true) 
                { 
                    pairV[v] = u; 
                    pairU[u] = v; 
                    return true; 
                } 
            } 
        } 
  
        // If there is no augmenting path beginning with u. 
        dist[u] = INF; 
        return false; 
    } 
    return true; 
} 
  
// Constructor 
BipGraph::BipGraph(int m, int n) 
{ 
    this->m = m; 
    this->n = n; 
    adj = vector<vector<int> >(m+1);
    pairU = vector<int>(m+1, NIL);
    pairV = vector<int>(m+1, NIL);
    dist = vector<int>(m+1, NIL);
} 
  
// To add edge from u to v and v to u 
void BipGraph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); // Add u to v’s list. 
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
pair<int, vi> computeTestBrute(const int&n, const vector<vi> &perms){
    
    vi graph(n+1 , 0);
    
    rep(i, 0, n-2){
        graph[perms[0][i]] = perms[0][i+1];
    }
    
    auto k = (int)perms.size() ;
    
    vi pos(n + 1, 0);
    
    rep(j, 1, k-1)
    {
        rep(i, 0, n-1){
            pos[perms[j][i]] = i+1;
        }
        
        rep(i, 1, n)
        {
            if(graph[i] and pos[graph[i]] < pos[i]){
                graph[i] = 0;
            }
        }
    }
    
    auto zeros = 0;
    rep(i, 1, n)
    {
        if(!graph[i]){
            zeros+=1;
        }
    }
    
    return {zeros, graph};
}

pair<int, vi> computeTestAllBrute(const int&n, const vector<vi> &perms){
    
    vector<unordered_set<int> > graphOut(n+1);
    
    rep(i, 0, n-2){
        rep(j, i+1, n-1)
        {  
            graphOut[perms[0][i]].insert(perms[0][j]);
        }
    }
    
    auto k = (int)perms.size() ;
    
    vi pos(n + 1, 0);
    
    rep(j, 1, k-1)
    {
        rep(i, 0, n-1){
            pos[perms[j][i]] = i+1;
        }
        
        rep(node, 1, n)
        {   
            
            for(auto it = graphOut[node].begin(); it!=graphOut[node].end();){
                if(pos[node] > pos[*it]){
                    it = graphOut[node].erase(it);
                } else 
                {
                    it++;
                }
            }
        }
    }
    
    vector<int> finalGraphOut(n+1, 0);
    vector<bool> finalGraphIn(n+1, false);
    
    rep(node, 1, n){
        for(auto possibleNextNode : graphOut[node]){
            
            if(!finalGraphIn[possibleNextNode])
            {
                finalGraphOut[node] = possibleNextNode;
                finalGraphIn[possibleNextNode] = true;
                break;
            }
        }
    }
    auto zeros = 0;
    
    rep(node, 1, n){
        if(!finalGraphIn[node]){
            zeros+=1;
        }
    }
    
    return {zeros, finalGraphOut};
}

pair<int, vi> computeTestMaxMatch(const int&n, const vector<vi> &perms){
    
    vector<unordered_set<int> > graphOut(n+1);
    
    rep(i, 0, n-2){
        rep(j, i+1, n-1)
        {  
            graphOut[perms[0][i]].insert(perms[0][j]);
        }
    }
    
    auto k = (int)perms.size() ;
    
    vi pos(n + 1, 0);
    
    rep(j, 1, k-1)
    {
        rep(i, 0, n-1){
            pos[perms[j][i]] = i+1;
        }
        
        rep(node, 1, n)
        {   
            
            for(auto it = graphOut[node].begin(); it!=graphOut[node].end();){
                if(pos[node] > pos[*it]){
                    it = graphOut[node].erase(it);
                } else 
                {
                    it++;
                }
            }
        }
    }
    
    

    
    BipGraph biGraph(n, n);
    
    rep(node, 1, n){
        for(auto possibleNextNode: graphOut[node]){
            biGraph.addEdge(node, possibleNextNode);
        }
    }
    
    auto maxMatch = biGraph.hopcroftKarp();
    
    vector<int> finalGraphOut(n+1, 0);
    vector<bool> finalGraphIn(n+1, false);
        
    rep(node, 1, n){
        finalGraphOut[node] = biGraph.getPairU(node);
        
        if(finalGraphOut[node]!=0){
            finalGraphIn[finalGraphOut[node]] = true;
        }
    }

    auto zeros = 0;
    
    rep(node, 1, n){
        if(!finalGraphIn[node]){
            zeros+=1;
        }
    }
    return {zeros, finalGraphOut};
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    
    
    while(t--){
        int n, k;
        cin>>n>>k;
        
        vector<vector<int> > perms(k, vi(n, 0));
        
        rep(j, 0, k-1)
        {   
            rep(i, 0, n-1)
            {
                cin>>perms[j][i];
            }
        }
        
        // auto ans = computeTestBrute(n, perms);
        
        // cout<<ans.f<<'\n';
        
        // rep(j, 1, n)
        // {
        //     cout<<ans.s[j]<<' ';
        // }
        // cout<<'\n';
        
        // auto ansAllBrute = computeTestAllBrute(n, perms);
        
        // cout<<"ansAllBrute: "<<endl;
        // cout<<ansAllBrute.f<<'\n';
        
        // rep(j, 1, n)
        // {
        //     cout<<ansAllBrute.s[j]<<' ';
        // }
        // cout<<'\n';
        // cout<<endl;
        // cout<<"ansMaxMatch: "<<endl;
        auto ansMaxMatch = computeTestMaxMatch(n, perms);
        
        cout<<ansMaxMatch.f<<'\n';
        
        rep(j, 1, n)
        {
            cout<<ansMaxMatch.s[j]<<' ';
        }
        cout<<'\n';
        // cout<<endl<<endl<<endl;
        // print(ans);
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
