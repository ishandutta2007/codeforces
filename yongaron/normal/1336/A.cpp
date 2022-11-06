#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int k, n;


vector<int> graf[223456];

long long ans;

vector<int> u;

int dfs(int v, int f, int d)
{
  int siz = 1;
  for(int i = 0; i < graf[v].size(); i++)
    if(graf[v][i] != f)
      siz += dfs(graf[v][i], v, d+1);
  u.push_back(d-siz+1);
  return siz;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>k;
  int a, b;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  dfs(1, 0, 0);
  sort(u.begin(), u.end());
  for(int i = n-1; i > n-k-1; i--)
    ans += u[i];
  cout<<ans<<endl;
  return 0;
}