class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int res = 0;
        int cntFresh = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(grid[i][j]==1)
                    ++cntFresh;
        
        while(true)
        {
            bool possible = false;
            
            for(int i=0; i<n; ++i)
                for(int j=0; j<m; ++j)
                    if(grid[i][j]-res==2)
                    {
                        if(i-1>=0 && grid[i-1][j]==1)
                        {
                            possible = true;
                            grid[i-1][j] = 2+res+1;
                            --cntFresh;
                        }
                        if(j-1>=0 && grid[i][j-1]==1)
                        {
                            possible = true;
                            grid[i][j-1] = 2+res+1;
                            --cntFresh;
                        }
                        if(i+1<n && grid[i+1][j]==1)
                        {
                            possible = true;
                            grid[i+1][j] = 2+res+1;
                            --cntFresh;
                        }
                        if(j+1<m && grid[i][j+1]==1)
                        {
                            possible = true;
                            grid[i][j+1] = 2+res+1;
                            --cntFresh;
                        }
                    }
                
            if(!possible)
                break;
            ++res;
        }
        
        if(cntFresh!=0)
            return -1;
        return res;
    }
};