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
ll floorLogBase(ll n,ll b)
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


class Node{
    public:
    int valueHere = 0;
    vector<int> indexVec = vector<int>(0,0);
    int treeIndex = -1;
};

class Trie{
    private:
    vector<Node> nodeArray;
    const static int rootIndex = 1;
    int SIZE;
    const static char startCharacter = '0';
    
    static inline int fastNumberContained(const vector<int> &indexVec, const pair<int, int> &indexRange){
        
        if(indexVec.empty()){
            return 0;
        }
        
        auto higherCover = upper_bound(indexVec.begin(), indexVec.end(), indexRange.second);
        
        if(higherCover == indexVec.begin()){
            //In this case there can be no intersection since R is less than the first element of indexVec
            return 0;
        } else
        {   //because we want to find the last element of the array less than or equal to R
            higherCover--;
        }
        
        auto lowerCover = lower_bound(indexVec.begin(), indexVec.end(), indexRange.first);
        
        if(lowerCover == indexVec.end()){
            //In this case there can be no intersection since R is greater than the last element of indexVec
            return 0;
        }
        
        int numContained = distance(lowerCover, higherCover) + 1;
        
        if(numContained<0){
            return 0;
        } else{
            return numContained;
        }
    }
    
    static inline bool fastCheckIntersection(const vector<int> &indexVec, const pair<int, int> &indexRange) {
        return fastNumberContained(indexVec, indexRange) > 0;
    }
    
    inline int getRightChildIndex(int currentIndex){
        int rightChildIndex = 2*currentIndex + 1;
        assert(("Ricght child index higher than range", rightChildIndex<SIZE));
        return rightChildIndex;
    }
    
    inline int getLeftChildIndex(int currentIndex){
        int leftChildIndex = 2*currentIndex;
        assert(("Left child index higher than range", leftChildIndex<SIZE));
        return leftChildIndex;
    }
    
    inline bool isLeafIndex(int currentIndex){
        return currentIndex>=SIZE/2;
    }
    
    inline int getNextChildIndex( char c, int currentIndex){
        return (c == '0')?getLeftChildIndex(currentIndex): getRightChildIndex(currentIndex);
    }
    
    inline int getOppositeChildIndex(char c, int currentIndex){
        return (c == '1')?getLeftChildIndex(currentIndex): getRightChildIndex(currentIndex);
    }
    public:
    
    Trie(int maxLength = 19){
        SIZE = po(2,maxLength+1);
        nodeArray = vector<Node>(SIZE);
    }   
    
    void insertAtIndex(const string &word, int index){
       int currentIndex = rootIndex;
       
       for(char c: word){
          assert(("Index gone over SIZE",currentIndex<SIZE));
          nodeArray[currentIndex].indexVec.push_back(index);
          int nextIndex = getNextChildIndex(c, currentIndex);
          currentIndex = nextIndex;
       }
        assert(("Index gone over SIZE",currentIndex<SIZE));
        nodeArray[currentIndex].indexVec.push_back(index);
        nodeArray[currentIndex].valueHere = stoi(word, nullptr, 2);
    }
    
    void deleteAtIndex(const string &word, int index){
       int currentIndex = rootIndex;
       
       for(char c: word){
          assert(("Index gone over SIZE",currentIndex<SIZE));
          
        //   bool testDelete = *(nodeArray[currentIndex].indexVec.rbegin()) == index;
        //   assert(("Wrong index at back of indexVec",testDelete));
          if(nodeArray[currentIndex].indexVec.empty())
            return;

          nodeArray[currentIndex].indexVec.pop_back();
          int nextIndex = getNextChildIndex(c, currentIndex);
          currentIndex = nextIndex;
       }
      assert(("Index gone over SIZE",currentIndex<SIZE));
    //   bool testDelete = *(nodeArray[currentIndex].indexVec.rbegin()) == index;
    // assert(("Wrong index at back of indexVec",testDelete));
       nodeArray[currentIndex].indexVec.pop_back();
    }
    
    int getMaxXor(const string &word, const pair<int, int> &indexRange){
        return -1;
    }
    
    int getNumberOfSmaller(const string &word, const pair<int, int> &indexRange){
        
        int currentIndex = rootIndex;
        int numberOfSmaller = 0;
        
        for(char c: word){
            assert(("Index gone over SIZE",currentIndex<SIZE));
            int nextIndex = getNextChildIndex(c, currentIndex);
            int leftChildIndex = getLeftChildIndex(currentIndex);
            int rightChildIndex = getRightChildIndex(currentIndex);
            
            if(nextIndex == rightChildIndex){
                numberOfSmaller += fastNumberContained(nodeArray[leftChildIndex].indexVec, indexRange);        
            }
            if(nodeArray[nextIndex].indexVec.empty())
            {
                return numberOfSmaller;
            }
            // if(!fastCheckIntersection(nodeArray[nextIndex].indexVec, indexRange))
            // {
            //     return numberOfSmaller;
            // }
            currentIndex = nextIndex;
        }
      assert(("Did not reach leaf Node",isLeafIndex(currentIndex)));
       
       numberOfSmaller += fastNumberContained(nodeArray[currentIndex].indexVec, indexRange);
       
       return numberOfSmaller;
    }
    
    int getKthOrderStatistic(const pair<int, int> &indexRange, int k, int startIndex = rootIndex){
        int currentIndex = startIndex;
        
        while(true){
            assert(("Index gone over SIZE",currentIndex<SIZE));
            if(isLeafIndex(currentIndex)){
                return nodeArray[currentIndex].valueHere;
            }
            
            int leftChildIndex = getLeftChildIndex(currentIndex);
            int rightChildIndex = getRightChildIndex(currentIndex);
            
            int numLeftLessThan = fastNumberContained(nodeArray[leftChildIndex].indexVec, indexRange);
            
            if(numLeftLessThan==k){
                return findMaxinRange(indexRange, leftChildIndex);
            }
            else if (numLeftLessThan>k){
                return getKthOrderStatistic(indexRange, k, leftChildIndex);
            }
            else if(numLeftLessThan<k){
                return getKthOrderStatistic(indexRange, k - numLeftLessThan, rightChildIndex);
            }
        }
    }
    
    int getKthOrderStatisticNonRecursive(const pair<int, int> &indexRange, int k){
        int currentIndex = rootIndex;
        
        while(true){
            assert(("Index gone over SIZE",currentIndex<SIZE));
            if(isLeafIndex(currentIndex)){
                return nodeArray[currentIndex].valueHere;
            }
            
            int leftChildIndex = getLeftChildIndex(currentIndex);
            int rightChildIndex = getRightChildIndex(currentIndex);
            
            int numLeftLessThan = fastNumberContained(nodeArray[leftChildIndex].indexVec, indexRange);
            
            if(numLeftLessThan >=k){
                currentIndex = leftChildIndex;
            } else{
                currentIndex = rightChildIndex;
                k = k - numLeftLessThan;
            }
        }
    }
    
    int getKthOrderStatisticNonRecursiveOptimized(const pair<int, int> &indexRange, int k, const vector<int> &nums){
        int currentIndex = rootIndex;
        
        while(true){
            assert(("Index gone over SIZE",currentIndex<SIZE));
            if(isLeafIndex(currentIndex)){
                return nodeArray[currentIndex].valueHere;
            }
            if(nodeArray[currentIndex].indexVec.size() == 1){
                int kthIndex = nodeArray[currentIndex].indexVec[0];
                return nums[kthIndex-1];
            }
            int leftChildIndex = getLeftChildIndex(currentIndex);
            int rightChildIndex = getRightChildIndex(currentIndex);
            
            int numLeftLessThan = fastNumberContained(nodeArray[leftChildIndex].indexVec, indexRange);
            
            if(numLeftLessThan >=k){
                currentIndex = leftChildIndex;
            } else{
                currentIndex = rightChildIndex;
                k = k - numLeftLessThan;
            }
        }
    }
    
    //Returns number which maximisizes XOR
    int getMaximisingNumberForXor(const string &word, const pair<int, int> &indexRange){
       int currentIndex = rootIndex;
       
       for(char c: word){
          
          
          int nextIndex = getNextChildIndex(c, currentIndex);
          int maxXORIndex = getOppositeChildIndex(c, currentIndex);
          
          if(fastCheckIntersection(nodeArray[maxXORIndex].indexVec, indexRange)){
              currentIndex = maxXORIndex;
          }
          else if(nextIndex < SIZE){
              currentIndex = nextIndex;
          }
          else{
              assert(("No node to travel to", false));
          }
       }
      assert(("Index gone over SIZE",currentIndex<SIZE));
       return nodeArray[currentIndex].valueHere;
    }
    
    //Returns index which maximisizes XOR
    int getMaximisingIndexForXor(const string &word, const pair<int, int> &indexRange){
       int currentIndex = rootIndex;
       
       for(char c: word){
          
          if(nodeArray[currentIndex].indexVec.size() == 1){
            return  *(nodeArray[currentIndex].indexVec.begin());
          }
          
          int nextIndex = getNextChildIndex(c, currentIndex);
          int maxXORIndex = getOppositeChildIndex(c, currentIndex);
          
          if(fastCheckIntersection(nodeArray[maxXORIndex].indexVec, indexRange)){
              currentIndex = maxXORIndex;
          }
          else if(nextIndex<SIZE){
              currentIndex = nextIndex;
          }
          else{
              assert(("No node to travel to", false));
          }
       }
      assert(("Index gone over SIZE",currentIndex<SIZE));
      
      auto lowerCover = lower_bound(nodeArray[currentIndex].indexVec.begin(), nodeArray[currentIndex].indexVec.end(), indexRange.first);
      
       return *(lowerCover);
    }
    
    //returns max in inserted range
    int findMaxinRange(const pair<int,int> &indexRange, int startIndex = rootIndex){
        int currentIndex = startIndex;
        
        while(true){
            assert(("Index gone over SIZE",currentIndex<SIZE));
            
            if(isLeafIndex(currentIndex)){
                return nodeArray[currentIndex].valueHere;
            }
            
            int rightChildIndex = getRightChildIndex(currentIndex);
            int leftChildIndex = getLeftChildIndex(currentIndex);
            
            bool rightPossible = fastCheckIntersection(nodeArray[rightChildIndex].indexVec, indexRange);
            // bool leftPossible = fastCheckIntersection(nodeArray[leftChildIndex].indexVec, indexRange);
            
            if(rightPossible){
                currentIndex = rightChildIndex;
            } else if (fastCheckIntersection(nodeArray[leftChildIndex].indexVec, indexRange)) {
                currentIndex = leftChildIndex;
            }
            else { 
                return nodeArray[currentIndex].valueHere;
            }
        }
        return 0;
    }
};
const bool DEBUG = false;
unordered_map<int, string> binRep;

void preComputeBinRep(int num, int SIZE = 20) {
    binRep[0] = string(SIZE, '0');
    rep(j, 1, num){
        binRep[j] = binRep[j-1];
        
        int lst = SIZE-1;
        
        while(binRep[j][lst]=='1'){
            binRep[j][lst] = '0';
            lst--;
        }
        binRep[j][lst]='1';
    }
}
// Soln Link: https://www.codechef.com/viewsolution/28762436
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int SIZE = 19;
    vector<int> nums;
    int q;
    cin>>q;
    Trie trie(SIZE);
    
    // preComputeBinRep(5*mx5, SIZE);
    
    //Testing large number of inserts
    // for(int i = 0;i<q;i++){
    //     int type = i%5;
    //     if(type==0 or type==2){
    //         int x =i;
            
    //         nums.push_back(x);
    //         string word = bitset<SIZE>(x).to_string();
    //         // string word = binRep[x];
    //         int index = nums.size();
            
    //         trie.insertAtIndex(word, index);
    //         if(DEBUG){
    //         cout<<"Inserting x, word, index: " <<x<<" "<<word<<" "<<index<<"\n";
    //         cout<<"nums: "; print(nums);cout<<"\n\n";
    //         }
    //     } 
    //     else if (type==1){
    //         int x, L, R;
    //         x = i;
    //         L = 1;
    //         R = nums.size();
            
    //         string word = bitset<SIZE>(x).to_string();
    //         // string word = binRep[x];
    //         if(DEBUG){
    //         cout<<"MAxxor x, word, L, R: " <<x<<" "<<word<<" "<<L<<" "<<R<<"\n";
    //         cout<<"nums: "; print(nums);
    //         }
            
    //         cout<<trie.getMaximisingNumberForXor(word, make_pair(L, R))<<"\n";
    //     }
    //     else if(type==3)
    //     {
    //         int x, L, R;
            
    //         x = i/2;
    //         L = 1;
    //         R = nums.size();
            
    //         string word = bitset<SIZE>(x).to_string();
    //         // string word = binRep[x];
    //         if(DEBUG)
    //         {   cout<<"NumSmaller x, word, L, R: " <<x<<" "<<word<<" "<<L<<" "<<R<<"\n";
    //             cout<<"nums: "; print(nums);cout<<"\n";
    //         }
    //         cout<<trie.getNumberOfSmaller(word, make_pair(L,R))<<"\n";
            
            
    //     }
    //     else if (type==4){
    //         int k, L, R;
            
    //         k = nums.size()/2;
    //         L  = 1;
    //         R = nums.size();
            
    //         cout<<trie.getKthOrderStatisticNonRecursive(make_pair(L,R), k)<<"\n";
            
            
    //     }
    //     else
    //     {
            
    //     }
    // }
    for (int i = 1;i<=q; i++){
        int type;
        
        cin>>type;
        if(DEBUG){
        cout<<"\n\n\n\nQUERY TYPE: " << i<<" "<<type<<"\n\n";
        }
        if(type==0){
            
            int x;
            cin>>x;
            
            nums.push_back(x);
            string word = bitset<SIZE>(x).to_string();
            // string word = binRep[x];
            int index = nums.size();
            
            trie.insertAtIndex(word, index);
            if(DEBUG){
            cout<<"Inserting x, word, index: " <<x<<" "<<word<<" "<<index<<"\n";
            cout<<"nums: "; print(nums);cout<<"\n\n";
            }
        } else if(type==1){
            
            int x, L, R;
            
            cin>>L >>R>>x;
            string word = bitset<SIZE>(x).to_string();
            // string word = binRep[x];
            if(DEBUG){
            cout<<"MAxxor x, word, L, R: " <<x<<" "<<word<<" "<<L<<" "<<R<<"\n";
            cout<<"nums: "; print(nums);
            }
            
            // int maxIndex = trie.getMaximisingIndexForXor(word, make_pair(L, R));
            // cout<<nums[maxIndex-1]<<"\n";
            
            cout<<trie.getMaximisingNumberForXor(word, make_pair(L,R))<<"\n";
            
            
        } else if(type==2){
            
            int k;
            cin >> k;
            
            while(k--){
                int x = *(nums.rbegin());
                string word = bitset<SIZE>(x).to_string();
                // string word = binRep[x];
                int index = nums.size();
                
                trie.deleteAtIndex(word, index);
                
                nums.pop_back();
                if(DEBUG){
                cout<<"deleting x, word, index: " <<x<<" "<<word<<" "<<index<<"\n";
                cout<<"nums: "; print(nums);
                }
            }
            
            
        } else if(type==3){
            int x, L, R;
            
            cin>>L >>R>>x;
            string word = bitset<SIZE>(x).to_string();
            // string word = binRep[x];
            if(DEBUG)
            {   cout<<"NumSmaller x, word, L, R: " <<x<<" "<<word<<" "<<L<<" "<<R<<"\n";
                cout<<"nums: "; print(nums);cout<<"\n";
            }
            cout<<trie.getNumberOfSmaller(word, make_pair(L,R))<<"\n";
            
            
            
        } else if(type ==4){
            
            int k, L, R;
            
            cin>>L >>R>>k;
            
            
            cout<<trie.getKthOrderStatisticNonRecursiveOptimized(make_pair(L,R), k, nums)<<"\n";
            // cout<<"nums: "; print(nums);
            
        } else
        {
            assert(("Wrong input", false));
        }
    }
    // trie.deleteTrie();
    return 0;
}
