#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

vector<int> graf[123456];
vector<double> weight[123456];

double ans[123456];

vector<double> sign[123456];
vector<double> shift[123456];

bool was[123456];

vector<int> done;

void dfs(int v, double sg, double sh)
{
  sign[v].push_back(sg);
  shift[v].push_back(sh);
  if(was[v])
    return;
  was[v] = true;
  done.push_back(v);
  for(int i = 0; i < graf[v].size(); i++)
    dfs(graf[v][i], -sg, weight[v][i] - sh);
}

bool ok = true;
vector<int> sorted;

void solve(int v)
{
  bool fixed = false;
  double x;
  done.clear();
  dfs(v, 1, 0);
  for(int i = 0; i < done.size(); i++)
  {
    int u = done[i];
    for(int j = 1; j < sign[u].size(); j++)
    {
      if(sign[u][j-1] == sign[u][j])
      {
        if(shift[u][j-1] != shift[u][j])
          ok = false;
      }
      else
      {
        double y;
        if(sign[u][j] == 1)
          y = (shift[u][j-1]-shift[u][j])/2;
        else
          y = (-shift[u][j-1]+shift[u][j])/2;
        if(fixed && y != x)
          ok = false;
        else
          x = y;
        fixed = true;
      }
    }
  }
  if(fixed)
  {
    for(int i = 0; i < done.size(); i++)
      ans[done[i]] = sign[done[i]][0]*x+shift[done[i]][0];
  }
  else
  {
    sorted.clear();
    for(int i = 0; i < done.size(); i++)
    {
      int u = done[i];
      if(sign[u][0] == 1)
        sorted.push_back(-shift[u][0]);
      else
        sorted.push_back(shift[u][0]);
    }
    sort(sorted.begin(), sorted.end());
    x = sorted[(sorted.size())/2];
    for(int i = 0; i < done.size(); i++)
      ans[done[i]] = sign[done[i]][0]*x+shift[done[i]][0];
  }
}

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  int a, b, c;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b>>c;
    graf[a].push_back(b);
    graf[b].push_back(a);
    weight[a].push_back(c);
    weight[b].push_back(c);
  }
  for(int i = 1; i <= n; i++)
    if(!was[i])
      solve(i);

  if(ok)
  {
    cout<<"YES"<<endl;
    for(int i = 1; i <= n; i++)
      cout<<ans[i]<<" ";
    cout<<endl;
  }
  else
    cout<<"NO"<<endl;
  return 0;
}