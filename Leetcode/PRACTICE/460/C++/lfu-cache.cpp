// Author: ananthrn
// soln link: https://leetcode.com/submissions/detail/174460932/
class LFUCache {
    int capacity = 0;
    int minFreq;
    map<int,int> keyVal;
    map<int,int> keyFreq;
    map<int, list<int> > freqList;
    map<int, list<int> ::iterator> keyIt;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    void updateFrequency(int key)
    {
        if(!keyFreq.count(key))
        {
            return;
        }
        
        int freq = keyFreq[key];
        auto it = keyIt[key];
        freqList[freq].erase(it);
        
        freq++;
        
        if(!freqList.count(freq))
        {
            freqList[freq] = {};
        }
        //Update values
        freqList[freq].push_back(key);
        keyIt[key] = freqList[freq].end();
        keyIt[key]--;
        keyFreq[key] = freq;
        
        if(freqList[minFreq].empty())
            minFreq++;
    }
    
    void eraseKey(int key)
    {
        int freq = keyFreq[key];
        auto it = keyIt[key];
        
        freqList[freq].erase(it);
        keyFreq.erase(key);
        keyIt.erase(key);
        keyVal.erase(key);
    }
    int get(int key) {
        if(this->capacity ==0 or keyVal.count(key)==0)
        {
            return -1;
        }
        
        int valRet = keyVal[key];
        
        updateFrequency(key);
        
        return valRet;
    }
    
    void put(int key, int value) {
        if(capacity ==0)
            return;
        
        if(keyVal.count(key)==0)
        {   
            
            if(keyVal.size() == capacity)
            {
                //delete LFU key
                
                auto it = freqList[minFreq].begin();
                int keyDel = *(it);
                eraseKey(keyDel);
//                 int freqDel = keyFreq[keyDel];
                
//                 freqList[minFreq].erase(it);
//                 keyVal.erase(keyDel);
//                 keyFreq.erase(keyDel);
//                 keyIt.erase(keyDel);
                
            }
            keyVal[key]= value;
            keyFreq[key] = 1;
            
            if(!freqList.count(1) or freqList[1].empty())
                minFreq = 1;
            
            freqList[1].push_back(key);
            keyIt[key] = freqList[1].end();
            keyIt[key]--;
            
        }
        else
        {
            keyVal[key] = value;
            updateFrequency(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
