#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
   // pair<int,char>
priority_queue<pair<int,char>>pq;
 unordered_map<char,int>mp;
 for(auto x:str)
 mp[x]++;
 for(auto x:mp)
 pq.push({x.second,x.first});
 while(pq.size()>0&&k)
 {
    int topchar=pq.top().second;
    int cnt=pq.top().first;
    cnt=cnt-1;
    pq.pop();
    pq.push({cnt,topchar});
  k--;
 }
 int cost=0;
 while(pq.size()>0)
 {
    cost+=pq.top().first*pq.top().first;
    pq.pop();
 }
 cout<<cost;
 return 0;

}