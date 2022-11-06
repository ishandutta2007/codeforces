#include<iostream>
#include<vector>

#define ll long long

using namespace std;

vector<int> graf[123456];

int ans = 0;

int here[123456];

int n;

void dfs(int v, int f)
{
  for(int i = 0; i < graf[v].size(); i++)
    if(graf[v][i] != f)
      dfs(graf[v][i], v);
  if(here[v] == v)
  {
    ans += 2;
    if(f)
      swap(here[v], here[f]);
    else
      swap(here[v], here[graf[v][0]]);
  }
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
  for(int i = 1; i <= n; i++)
    here[i] = i;
  dfs(1, 0);
  cout<<ans<<endl;
  for(int i = 1; i <= n; i++)
    cout<<here[i]<<" ";
  cout<<endl;
  return 0;
}