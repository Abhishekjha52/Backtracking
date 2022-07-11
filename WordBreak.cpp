//c++ program to solve word break problem using backtracking
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(vector<string>&ans, string sentence, string word, unordered_set<string>&set, string s, int index)
    {
        //base case
        if(index==s.length())
        {
            sentence.pop_back();//removing last space from sentence
            ans.push_back(sentence);
            return;
        }

        //check whether the string in dict is present or not
        for(int i=index;i<s.length();i++)
        {
            word+=s[i];
            if(set.find(word)!=set.end())
            {
                //either take it or not
                //case 1: to move on

                if(i!=s.length())
                    solve(ans, sentence, word, set, s, i+1);

                //case 2:to include it
                word+=" ";
                solve(ans, sentence+word, "", set, s, i+1);
            }
        }
    }
    vector<string>wordBreak(int n, vector<string>&dict, string s)
    {
        vector<string>ans;

        unordered_set<string>set;
        for(auto x:dict)
            set.insert(x);

        string sentence="", word="";
        int index=0;
        solve(ans, sentence, word, set, s, index);
        return ans;
    }
};


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;
        vector<string>dict;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            dict.push_back(s);
        }

        for(auto x:dict)
            cout<<x<<" ";
        string input;cin>>input;


        Solution obj;
        vector<string>ans=obj.wordBreak(n, dict, input);
        if(ans.size()==0)
            cout<<"Empty"<<"\n";
        else
        {
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<"\n";
        }
    }
    return 0;
}