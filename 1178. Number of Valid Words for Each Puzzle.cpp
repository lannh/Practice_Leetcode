class Solution {
public:
    
    int mask(string s)
    {
        int curMask = 0;
        
        for(char c: s)
            curMask |= 1<<(c-'a');
        
        return curMask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
    {
        unordered_map<int, int> mp;
        int n = words.size();
        int m = puzzles.size();
        vector<int> res(m);
        
        for(int i=0; i<n; ++i)
            ++mp[mask(words[i])];
        
        for(int i=0; i<m; ++i)
        {
            int first = 1 << (puzzles[i][0] - 'a');
            int cnt = 0;
            int curMask = mask(puzzles[i]);
        
            int subMask = curMask;
            while(subMask>0)
            {
                if((subMask & first)!=0)
                    if(mp.find(subMask)!=mp.end())
                    cnt+=mp[subMask];
                
                subMask = (subMask - 1) & curMask;
            }
                
            res[i] = cnt;
        }
        
        
        return res;
    }
};