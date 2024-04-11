#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

ll n;

bool lucky(int x)
{
  while(x)
  {
    if(x%10 != 4 && x%10 != 7)
      return false;
    x /= 10;
  }
  return true;
}

vector<int> graf[123456];

bool was[123456];

ll dfs(int v)
{
  ll ans = 1;
  was[v] = true;
  for(int i = 0; i < graf[v].size(); i++)
    if(!was[graf[v][i]])
      ans += dfs(graf[v][i]);
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, w;
  cin>>n;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b>>w;
    if(!lucky(w))
    {
      graf[a].push_back(b);
      graf[b].push_back(a);
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++)
  {
    if(!was[i])
    {
      ll x = dfs(i);
      ans += x*(n-x)*(n-x-1);
    }
  }
  cout<<ans<<endl;
  return 0;
}