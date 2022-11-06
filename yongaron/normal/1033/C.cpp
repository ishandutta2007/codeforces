#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
int a[123456], edges[123456];
vector<int> backgraph[123456];
bool won[123456];

queue<int> q;

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; i+j*a[i] < n; j++)
    {
      if(a[i] < a[i+j*a[i]])
      {
        edges[i]++;
        backgraph[i+j*a[i]].push_back(i);
      }
    }
    for(int j = -1; i+j*a[i] >= 0; j--)
    {
      if(a[i] < a[i+j*a[i]])
      {
        edges[i]++;
        backgraph[i+j*a[i]].push_back(i);
      }
    }
  }
  for(int i = 0; i < n; i++)
    if(!edges[i])
      q.push(i);
  while(!q.empty())
  {
    int v = q.front();
    q.pop();
    for(int i = 0; i < backgraph[v].size(); i++)
    {
      edges[backgraph[v][i]]--;
      if(!edges[backgraph[v][i]])
        q.push(backgraph[v][i]);
      if(!won[v])
        won[backgraph[v][i]] = true;
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(won[i])
      cout<<"A";
    else
      cout<<"B";
  }
  cout<<endl;
  return 0;
}