// author: ananthrn
// solution link: https://leetcode.com/submissions/detail/175049601/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<vector<NestedInteger>::iterator> st_beg;
    stack<vector<NestedInteger>::iterator> st_end;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
            st_beg.push(nestedList.begin());
            st_end.push(nestedList.end());
    }

    int next() {
        auto it = st_beg.top();
        st_beg.pop();
        int val = (*it).getInteger();
        it++;
        st_beg.push(it);
        
        return val;
    }

    bool hasNext() {
        if(st_beg.empty())
            return false;
        
        while(!st_beg.empty())
        {
            auto beg = st_beg.top();
            auto en = st_end.top();
            
            if(beg == en)
            {
                st_beg.pop();
                st_end.pop();
            }
            else if(!(*beg).isInteger())
            {   
                auto new_beg = (*beg).getList().begin();
                auto new_en = (*beg).getList().end();
                
                
                
                
                st_beg.pop();
                beg++;
                st_beg.push(beg);
                
                
                st_beg.push(new_beg);
                st_end.push(new_en);
                
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
