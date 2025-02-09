#include<bits/stdc++.h>
using namespace std;
bool  dfs(unordered_map<int,vector<int>>&adj, int node)
{
    int n=adj.size();
    for(auto x:adj[node])
    { n--;
        dfs(adj,x);
    }
    if(n==0)
    return true;
    else
    return false;
}
int main()
{
    int n;
    cin>>n;
    int v[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];

        }
    }
    unordered_map<int,vector<int>>adj;
   unordered_map<int,int>mp;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
        if(v[i][j]==1)
        {
              v[i][j]--;
             for(int p=0;p<n;p++)
             {
             for(int q=0;q<n;q++)
             {
                if(v[p][q]==1)  adj[p].push_back(q);
             }
          }
           bool check=dfs(adj,i);
           if(check==false)
            mp[i]=j;
        }
        

    }
   }
   for(auto x:mp)
   cout<<x.first<<x.second;

   return 0;
}