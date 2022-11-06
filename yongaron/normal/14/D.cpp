#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> graf[222];

int u, w;

bool edge[222][222];

int ma, mav;
void dfs(int v, int f, int d)
{
  if(d > ma)
  {
    ma = d;
    mav = v;
  }
  for(int i = 0; i < graf[v].size(); i++)
    if(graf[v][i] != f && !edge[v][graf[v][i]])
      dfs(graf[v][i], v, d+1);
}

int main(int argc, char const *argv[]) {
  cin>>n;
  int a, b;
  vector<pair<int, int>> v;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b;
    v.push_back({a, b});
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  int ans = 0;
  for(int i = 0; i < n-1; i++)
  {
    a = v[i].first;
    b = v[i].second;
    edge[a][b] = edge[b][a] = true;
    ma = -1;
    dfs(a, a, 0);
    dfs(mav, mav, 0);
    int x = ma;
    ma = -1;
    dfs(b, b, 0);
    dfs(mav, mav, 0);
    int y = ma;
    ans = max(ans, x*y);
    edge[a][b] = edge[b][a] = false;
  }
  cout<<ans<<endl;
  return 0;
}