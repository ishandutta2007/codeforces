#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, m;

vector<int> graf[223456];

int f[2234567];
int a[223456];

void update(int k, int x)
{
  while(k <= 2*n)
  {
    f[k] += x;
    k += k&-k;
  }
}

int sum(int k)
{
  int ans = 0;
  while(k)
  {
    ans += f[k];
    k -= k&-k;
  }
  return ans;
}

int cur = 1;

int dep[223456];
int beg[223456], en[223456];

void dfs(int v, int f, int d)
{
  dep[v] = d;
  beg[v] = cur++;
  for(int i = 0; i < graf[v].size(); i++)
    if(graf[v][i] != f)
      dfs(graf[v][i], v, d+1);
  en[v] = cur++;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  int b, c, q;
  for(int i = 0; i < n; i++)
    cin>>a[i+1];
  for(int i = 0; i < n-1; i++)
  {
    cin>>b>>c;
    graf[b].push_back(c);
    graf[c].push_back(b);
  }
  dfs(1, 1, 0);
  int x, val;
  for(int i = 0; i < m; i++)
  {
    cin>>q;
    if(q == 1)
    {
      cin>>x>>val;
      if(dep[x]%2)
        val = -val;
      update(beg[x], val);
      update(en[x], -val);
    }
    else
    {
      cin>>x;
      val = sum(beg[x]);
      if(dep[x]%2)
        val = -val;
      cout<<a[x]+val<<endl;
    }
  }
  return 0;
}