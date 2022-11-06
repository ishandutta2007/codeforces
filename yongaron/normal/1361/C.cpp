#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;

vector<int> graf[1234567];
int ended[1234567];
vector<pair<int, int> > edge[1234567];
bool was[1234567];
bool done[1234567];

int a[1234567], b[1234567];

vector<int> ans;

void dfs(int v)
{
  for(int i = ended[v]; i < graf[v].size(); i++)
  {
    ended[v] = i+1;
    if(!was[edge[v][i].first])
    {
      was[edge[v][i].first] = was[edge[v][i].second] = true;
      dfs(graf[v][i]);
      ans.push_back(edge[v][i].second);
      ans.push_back(edge[v][i].first);
    }
    if(done[v])
      return;
  }
  done[v] = true;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>a[i]>>b[i];
  for(int i = 20; i >= 0; i--)
  {
    int m = 1<<i;
    for(int j = 0; j < m; j++)
    {
      graf[j].clear();
      edge[j].clear();
      ended[j] = 0;
      done[j] = false;
    }
    for(int j = 0; j < n; j++)
    {
      graf[a[j]%m].push_back(b[j]%m);
      edge[a[j]%m].push_back({2*j+1, 2*j+2});
      graf[b[j]%m].push_back(a[j]%m);
      edge[b[j]%m].push_back({2*j+2, 2*j+1});
      was[2*j+1] = was[2*j+2] = false;
    }
    bool ok = true;
    for(int j = 0; j < m; j++)
      if(graf[j].size()%2)
        ok = false;
    if(ok)
    {
      ans.clear();
      dfs(a[0]%m);
      if(ans.size() == 2*n)
      {
        cout<<i<<endl;
        for(int j = 0; j < 2*n; j++)
          cout<<ans[j]<<" ";
        cout<<endl;
        return 0;
      }
    }
  }
  return 0;
}