// Author: ananthrn
// Soln Link: https://leetcode.com/submissions/detail/175035571/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string sent = "";
        
        for(auto w:sentence)
        {
            sent+=w + " ";
        }
        int len = sent.size();
        int pos = 0;
        
        for(int i = 1;i<=rows;i++)
        {
            pos = pos + cols;
            
            if(sent[pos%len] == ' ')
            {
                pos++;
            }
            else
            {
                while(pos>=0 and sent[pos%len]!=' ')
                    pos--;
                pos++;
            }
        }
        
        return pos/len;
    }
};
