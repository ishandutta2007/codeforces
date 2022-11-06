#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> graf[123456];
int leaves[123456];
int mi = 1;

bool dfs(int v, int f)
{
  bool seen0 = false;
  bool seen1 = false;
  for(int i = 0; i < graf[v].size(); i++)
  {
    if(graf[v][i] != f)
    {
      bool f = dfs(graf[v][i], v);
      if(f)
        seen1 = true;
      if(!f)
        seen0 = true;
    }
  }
  if(seen0 && seen1)
    mi = 3;
  return !seen1;
}

int main(int argc, char const *argv[]) {
  cin>>n;
  int a, b;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  int ma = n-1;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < graf[i].size(); j++)
      if(graf[graf[i][j]].size() == 1)
        leaves[i]++;
    ma -= (max(0, leaves[i]-1));
  }
  for(int i = 1; i <= n; i++)
  {
    if(graf[i].size() > 1)
    {
      dfs(i, 0);
      break;
    }
  }
  cout<<mi<<" "<<ma<<endl;
  return 0;
}