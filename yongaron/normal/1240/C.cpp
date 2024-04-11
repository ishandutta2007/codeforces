#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, q, k;
vector<int> tree[1234567];
vector<long long> w[1234567];

long long dp[1234567][2];

void dfs(int v, int f)
{
  for(int i = 0; i < tree[v].size(); i++)
    if(tree[v][i] != f)
      dfs(tree[v][i], v);
  vector<int> vv;
  long long sum = 0;
  for(int i = 0; i < tree[v].size(); i++)
  {
    if(tree[v][i] != f)
    {
      sum += dp[tree[v][i]][0];
      vv.push_back(w[v][i]-(dp[tree[v][i]][0]-dp[tree[v][i]][1]));
    }
  }
  sort(vv.begin(), vv.end());
  // cout<<v<<" "<<vv.size()<<endl;
  // cout<<"vv: ";
  // for(int i = 0; i < vv.size(); i++)
  //   cout<<vv[i]<<" ";
  // cout<<endl;
  long long all = 0;
  for(int i = 0; i < min(k, (int)vv.size()); i++)
    all = max(all, all+vv[vv.size()-1-i]);
  long long sall = 0;
  for(int i = 0; i < min(k-1, (int)vv.size()); i++)
    sall = max(sall, sall+vv[vv.size()-1-i]);
  dp[v][0] = sum+all;
  dp[v][1] = sum+sall;
  // cout<<"dp: "<<dp[v][0]<<" "<<dp[v][1]<<endl;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>q;
  for(int u = 0; u < q; u++)
  {
    cin>>n>>k;
    int a, b, d;
    for(int i = 0; i <= n; i++)
    {
      tree[i].clear();
      w[i].clear();
    }
    for(int i = 0; i < n-1; i++)
    {
      cin>>a>>b>>d;
      tree[a].push_back(b);
      tree[b].push_back(a);
      w[a].push_back(d);
      w[b].push_back(d);
    }
    dfs(1, 0);
    cout<<dp[1][0]<<endl;
  }
  return 0;
}