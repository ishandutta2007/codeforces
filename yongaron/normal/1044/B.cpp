#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

vector<int> graf[1234];
bool my[1234], his[1234];

int dfs(int v, int f)
{
  if(my[v])
    return v;
  for(int i = 0; i < graf[v].size(); i++)
  {
    if(graf[v][i] == f)
      continue;
    int x = dfs(graf[v][i], v);
    if(x)
      return x;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    int a, b;
    for(int i = 1; i <= n; i++)
    {
      my[i] = his[i] = false;
      graf[i].clear();
    }
    for(int i = 0; i < n-1; i++)
    {
      cin>>a>>b;
      graf[a].push_back(b);
      graf[b].push_back(a);
    }
    int k;
    cin>>k;
    for(int i = 0; i < k; i++)
    {
      cin>>a;
      my[a] = true;
    }
    cin>>k;
    for(int i = 0; i < k; i++)
    {
      cin>>a;
      his[a] = true;
    }
    cout<<"B "<<a<<endl;
    int ans;
    cin>>ans;
    if(my[ans])
    {
      cout<<"C "<<ans<<endl;
      continue;
    }
    int v = dfs(ans, 0);
    cout<<"A "<<v<<endl;
    cin>>ans;
    if(his[ans])
      cout<<"C "<<v<<endl;
    else
      cout<<"C -1"<<endl;
  }
  return 0;
}