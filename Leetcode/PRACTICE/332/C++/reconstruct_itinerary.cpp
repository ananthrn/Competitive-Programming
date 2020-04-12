// Author: ananthrn
// Solution Link: https://leetcode.com/submissions/detail/175055182/
class Solution {
public:
    void findHelper(string src, map<string,multiset<string> > &adj,vector<string> &iten)
    {
        while(!adj[src].empty())
        {
            string nex = *adj[src].begin();
            adj[src].erase(adj[src].begin());
            
            findHelper(nex,adj,iten);
        }
        
        iten.push_back(src);
            
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> iten;
        map<string,multiset<string> > adj;
        
        for(auto p: tickets)
        {
            if(!adj.count(p.first))
            {   multiset<string> m;
                adj[p.first] = m;
            }
            
            adj[p.first].insert(p.second);
        }
        
        findHelper("JFK",adj,iten);
        reverse(iten.begin(),iten.end());
        return iten;
    }
};
