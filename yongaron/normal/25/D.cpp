#include<iostream>
#include<vector>

using namespace std;

bool edge[1234][1234];
vector<int> graf[123456];
int n;

bool was[1234];

void dfs(int v)
{
  was[v] = true;
  for(int i = 0; i < graf[v].size(); i++)
    if(!was[graf[v][i]] && edge[v][graf[v][i]])
      dfs(graf[v][i]);
}

vector<int> comps()
{
  vector<int> ans;
  for(int i = 0; i <= n; i++)
    was[i] = false;
  for(int i = 1; i <= n; i++)
  {
    if(!was[i])
    {
      ans.push_back(i);
      dfs(i);
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  cin>>n;
  int a, b;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
    edge[a][b] = edge[b][a] = true;
  }
  vector<int> v = comps();
  int cur = 0;
  cout<<v.size()-1<<endl;
  for(int i = 1; i <= n; i++)
  {
    for(int j = i+1; j <= n; j++)
    {
      if(edge[i][j])
      {
        edge[i][j] = edge[j][i] = false;
        if(comps().size() == v.size())
          cout<<i<<" "<<j<<" "<<v[cur]<<" "<<v[++cur]<<endl;
        else
          edge[i][j] = edge[j][i] = true;
      }
    }
  }
  return 0;
}