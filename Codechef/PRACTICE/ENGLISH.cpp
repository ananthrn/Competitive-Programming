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

class Node{
    public:
    
    Node(int treeIndex, int parentIndex, int alphabetSize, int depth){
        this->treeIndex = treeIndex;
        this->parentIndex = parentIndex;
        children = vector<int>(alphabetSize, 0);
        this->depth = depth;
    }
    
    Node(){
        vector<int> children = vi(0);
        int treeIndex = -1;
        int parentIndex = -1;
        int depth = -1;
        int count = 0;
        int alphabetSize =0;
    }
    
    // int valueHere = 0;
    // unordered_set<int> indexVec; //= vector<int>(0,0);
    vector<int> children = vi(0);
    int treeIndex = -1;
    int parentIndex = -1;
    int depth = -1;
    int count = 0;
     int alphabetSize =0;
     
    bool isLeaf(){
        if(children.empty())
        {
            return true;
        }
        
        for(auto childIndex: children)
        {
            if(childIndex!=0)
            {
                return false;
            }
        }
        
        return true;
    }
    
    // int getSize(){
    //     return indexVec.size();
    // }
    // void insertAtIndex(const int &indexInsert){
    //     indexVec.insert(indexInsert);
    // }
    // void deleteAtIndex(const int& indexDelete){
    //     if(!indexVec.count(indexDelete)){
    //         throw logic_error("indexDelete not in indexVec");
    //     }
    //     indexVec.erase(indexDelete);
    // }
    
    
};

const int DEBUG = 0;

class Trie{
    private:
    vector<Node> nodeArray;
    int SIZE = 0;
    
    vector<int> indexVec;
    

    
    int currentArraySize = 0;
    
    int getNewNode(int depth, int parentIndex){
        currentArraySize+=1;
        
        if(currentArraySize>=SIZE)
        {
            throw logic_error("currentArraySize>=SIZE");
        }
        
        nodeArray[currentArraySize] = Node(currentArraySize, parentIndex, alphabetSize, depth);
        
        return currentArraySize;
    }
    
    public:
    const static char startCharacter = 'a';
    const static int alphabetSize = 26*26+ 1;
    const static int rootIndex = 1;
    
    
    Trie(int maxLength = 100005){
        SIZE = (maxLength +5) * (alphabetSize+5) +10;
        nodeArray = vector<Node> (SIZE);
        
        currentArraySize = 0;
        getNewNode(0, 0);
    }
    
    void resetTrie(){
        currentArraySize = 0;
        getNewNode(0, 0);
    }
    void insertWord(const vector<int> &word){
        auto currentNodeIndex = rootIndex;
        int depth = 1;
        
        
        for(auto ch: word){
            
            int childIndex = ch;
            
            // nodeArray[currentNodeIndex].count+=1;
            
            if(nodeArray[currentNodeIndex].children[childIndex]==0)
            {
                auto nextChildIndex = getNewNode(depth, currentNodeIndex);
                nodeArray[currentNodeIndex].children[childIndex] = nextChildIndex;
            }
            
            currentNodeIndex = nodeArray[currentNodeIndex].children[childIndex];
            depth+=1;
        }
        
        nodeArray[currentNodeIndex].count+=1;
        
    }
    
    pair<ll, ll> matchLongestPrefixes(int startIndex,  ll depth){
        ll thisCount =  nodeArray[startIndex].count;
        ll totalAns = 0;
        
        for(auto childIndex: nodeArray[startIndex].children){
            if(childIndex!=0){
                auto childAns = matchLongestPrefixes(childIndex, depth+1);
                
                thisCount+=childAns.second;
                totalAns+=childAns.first;
            }
        }
        
        ll thisAns = (thisCount/2)*(depth*depth);
        totalAns+= thisAns;
        
        return make_pair(totalAns, thisCount%2);
    }

    
};

vector<int> convertWord(const string &word){
    if(word.empty()){
        return vi(0);
    }
    vector<int> convertedWord(word.length(), -1);
    
    int n = word.length();
    
    rep(j, 0, n-1){
        char fir = word[j];
        char sec = word[n-1-j];
        
        int firstInt = fir -'a';
        int secInt = sec -'a';
        
        int val = 26*firstInt + secInt;
        
        convertedWord[j] = val;
    }
    
    return convertedWord;
}
 Trie prefTrie;
ll compute_test_trie(const vector<string> &words){
    
    size_t maxLen = 0;
    
    for(const auto &word: words){
        maxLen = max(maxLen, words.size());
    }
    
    prefTrie.resetTrie();
    
    // Trie prefTrie(maxLen+10);
    
    int n = words.size();
    
    for(const auto &word: words){
        auto convertedWord = convertWord(word);
        // print(convertedWord);
        prefTrie.insertWord(convertedWord);
    }
    
    auto ans = prefTrie.matchLongestPrefixes(prefTrie.rootIndex, 0);
    return ans.first;
}

// Solution: https://www.codechef.com/viewsolution/28996841
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<string> words(n, "");
        
        rep(j, 0 , n-1){
            cin>>words[j];
        }
        
        if(n%2==1){
            words.pb("");
        }
        
         
        auto ans = compute_test_trie(words);
        
        // rhymeComp = vector< unordered_map<int, ll> > (words.size() + words.size()%2);
        
        // auto ans_brute = compute_test_brute(words);
        
        // if(ans!=ans_brute)
        // {
        //     throw logic_error("ans!=ans_brute");
        // }
        
        cout<<ans<<'\n';
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
