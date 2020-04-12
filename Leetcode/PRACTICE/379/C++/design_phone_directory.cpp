// Author: ananthrn
// Problem Link: https://leetcode.com/problems/design-phone-directory/
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    vector<int> freeList;
    vector<bool> thisFree;
    int count;
    int freeIndex;
    PhoneDirectory(int maxNumbers): count(maxNumbers),freeIndex(0),thisFree(maxNumbers,true),freeList(maxNumbers,-1){
        for(int i = 0;i<maxNumbers;i+=1)
        {
            freeList[i]=i;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(freeIndex==count)
        {
            return -1;
        }
        int n = freeList[freeIndex++];
        thisFree[n]=false;
        
        return n;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number<0 or number>=count)
        {
            return false;
        }
        
        return thisFree[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number<0 or number>=count or thisFree[number])
        {
            return;
        }
        thisFree[number]=true;
        freeList[--freeIndex]=number;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
