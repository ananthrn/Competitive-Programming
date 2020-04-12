// Author: ananthrn
// Soln link: 
class RandomizedSet{
  private:
    
  public:
    vector<int> vals;
    unordered_map<int,int> valPos;
  
    RandomizedSet(){
    }
  
    bool insert(int val)
    {
      if(valPos.count(val))
      {
        return false; 
      }
      else
      {  
        vals.push_back(val);
        valPos[val] = (int)vals.size()-1;
        return true; 
      }
    }
    
    int getRandom()
    {
      if(vals.empty())
      {
        return -1;
      }
      else
      {
        int sz = vals.size();
        int pos = rand()%sz;
        return vals[pos];
      }
    }
  
    bool remove(int val)
    {
      if(valPos.count(val))
      {  
        int sz = vals.size();
        int lastVal = vals[sz-1]; 
        int pos = valPos[val];
        
        swap(vals[pos],vals[sz-1]);
        valPos[lastVal] = pos;
        
        vals.pop_back();
        valPos.erase(val);
        
        return true;
      }
      else
      {
        return false; 
      }
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
