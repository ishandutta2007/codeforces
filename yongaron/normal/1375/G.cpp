#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;

vector<int> graf[1234567];

int par[2];

void dfs(int v, int f, int p)
{
  par[p]++;
  for(int i = 0; i < graf[v].size(); i++)
    if(graf[v][i] != f)
      dfs(graf[v][i], v, p^1);
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  int a, b;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  dfs(1, 0, 0);
  cout<<min(par[0]-1, par[1]-1)<<endl;
  return 0;
}