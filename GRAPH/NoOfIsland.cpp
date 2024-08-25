class Solution {
  public:
    // Function to find the number of islands.
    int r;
    int c;
    int row[8] = {-1,-1,-1,1,1,1,0,0};
    int col[8] = {-1,0,1,-1,0,-1,-1,1};
    
     bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        r = grid.size();
        c=grid[0].size();
        
        queue<pair<int,int>>q;
        int count = 0;
        
        //check the char 1 in our grid
        for(int i=0;i<r;i++)
        {
        for(int j=0;j<c;j++)
        {
           if(grid[i][j]=='1')
            {
                count++;
                
                //make all 1 convert to zero
                //jishe pata chal gaya ki 1 visited hai or repeat nhi hoi
                q.push(make_pair(i,j));
                grid[i][j]='0';
                
                while(!q.empty()){
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();
                    
                    //8 directions mein check kar 
                    for(int k=0;k<8;k++){
                        if(valid(new_i+row[k],new_j+col[k])&&grid[new_i+row[k]][new_j+col[k]]=='1')
                        {
                            grid[new_i+row[k]][new_j+col[k]]='0';
                            q.push(make_pair(new_i+row[k],new_j+col[k]));
                        }
                    }
                }
            }
        }
    }
        return count;
    }
};