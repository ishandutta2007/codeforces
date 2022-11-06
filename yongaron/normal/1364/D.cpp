#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, m, k;

vector<int> graf[123456];

int comp[123456];
int from[123456];
int siz[3];

bool ok = true;

int visi;

vector<int> w, u;

void dfs(int v)
{
  if(visi >= k)
    return;
  visi++;
  for(int i = 0; i < graf[v].size(); i++)
  {
    if(!ok)
      return;
    if(!comp[graf[v][i]] && visi < k)
    {
      comp[graf[v][i]] = comp[v]%2+1;
      siz[comp[graf[v][i]]]++;
      from[graf[v][i]] = v;
      dfs(graf[v][i]);
    }
    else if(comp[graf[v][i]] && comp[v]%2+1 != comp[graf[v][i]])
    {
      ok = false;
      cout<<2<<endl;
      int x = v;
      w.push_back(x);
      while(x != 1)
      {
        x = from[x];
        w.push_back(x);
      }
      x = graf[v][i];
      u.push_back(x);
      while(x != 1)
      {
        x = from[x];
        u.push_back(x);
      }
      int last = 1;
      while(w.size() && u.size() && w.back() == u.back())
      {
        last = u.back();
        u.pop_back();
        w.pop_back();
      }
      cout<<u.size()+w.size()+1<<endl;
      for(int j = 0; j < u.size(); j++)
        cout<<u[j]<<" ";
      cout<<last<<" ";
      for(int j = w.size()-1; j >= 0; j--)
        cout<<w[j]<<" ";
      cout<<endl;
    }
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>k;
  int a, b;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  comp[1] = 1;
  siz[1]++;
  dfs(1);
  if(!ok)
    return 0;
  cout<<1<<endl;
  int t = 1;
  if(siz[2] >= siz[1])
    t = 2;
  int x = 0;
  for(int i = 1; i <= n; i++)
  {
    if(x >= (k+1)/2)
      break;
    if(comp[i] == t)
    {
      cout<<i<<" ";
      x++;
    }
  }
  cout<<endl;
  return 0;
}