//c++ program to solve sudoku using backtracking
#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int>>&a, int row, int col, int val)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        //row check
        if(a[row][i]==val)
            return false;
        
        //col check
        if(a[i][col]==val)
            return false;

        //3*3 box check
        if(a[3*(row/3)+ i/3][3*(col/3)+ i%3]==val)
            return false;
    }
    return true;

}
bool sudokuSolver(vector<vector<int>>&a)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                for(int val=1;val<=9;val++)
                {
                    if(isValid(a, i, j, val))
                    {
                        a[i][j]=val;
                        if(sudokuSolver(a))
                            return true;
                        //backtrack
                        a[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    }
    if(sudokuSolver(v))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<v[i][j]<<" ";
            cout<<"\n";
        }
    }
    else
        cout<<"NO"<<"\n";
}