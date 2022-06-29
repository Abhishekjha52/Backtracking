//c++ program to solve rat maze problem
class Solution{
    public:
    void solve(int i, int j, vector<vector<int>>&m, int n, vector<string>&ans, string path, vector<vector<int>>&vis)
    {
        //base case
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        vis[i][j]=1;
        //up check
        if((i-1)>=0 && !vis[i-1][j] && m[i-1][j]==1)
            solve(i-1,j,m,n,ans,path+'U',vis);
            
        //right check
        if((j+1)<n && !vis[i][j+1] && m[i][j+1]==1)
            solve(i,j+1,m,n,ans,path+'R',vis);
            
        //down check
        if((i+1)<n && !vis[i+1][j] && m[i+1][j]==1)
            solve(i+1,j,m,n,ans,path+'D',vis);

        //left check
        if((j-1)>=0 && !vis[i][j-1] && m[i][j-1]==1)
            solve(i,j-1,m,n,ans,path+'L',vis);

        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        if(m[0][0]==1)
            solve(0,0,m,n,ans,"",visited);
        return ans;
    }
};

//Other solution
class Solution{
    public:
    int dirx[4]={1,0,0,-1};
    int diry[4]={0,-1,1,0};
    char dir[4]={'D','L','R','U'};
    //sorted answer: D,L,R,U
    bool isValid(int x, int y, vector<vector<int>>&m,int n, vector<vector<int>>&vis)
    {
        if(x>=0 && x<n && y>=0 && y<n && m[x][y]!=0 && !vis[x][y])
            return true;
        return false;
    }
    void solve(int row, int col, vector<vector<int>>&m, int n, vector<string>&ans, string path, vector<vector<int>>&vis)
    {
        //base case
        if(row==n-1 && col==n-1)
        {
            ans.push_back(path);
            return;
        }
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int new_x=row+dirx[i];
            int new_y=col+diry[i];
            if(isValid(new_x, new_y, m, n,vis))
            {
                solve(new_x,new_y, m, n, ans, path+dir[i],vis);
            }
        }
        vis[row][col]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        if(m[0][0]==1)
            solve(0,0,m,n,ans,"",visited);
        return ans;
    }
};