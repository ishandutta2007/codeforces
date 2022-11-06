#include<iostream>
#include<vector>

using namespace std;

vector<int> graf[123456];

int n, q;

int pre[123456][30];
int dep[123456], siz[123456];

int dfs(int v, int f, int d)
{
  dep[v] = d;
  pre[v][0] = f;
  siz[v] = 1;
  for(int i = 0; i < graf[v].size(); i++)
    if(graf[v][i] != f)
      siz[v] += dfs(graf[v][i], v, d+1);
  return siz[v];
}

void calc_pre()
{
  for(int i = 1; i < 30; i++)
    for(int j = 1; j <= n; j++)
      pre[j][i] = pre[pre[j][i-1]][i-1];
}

int get_pre(int a, int d)
{
  int shift = 0;
  while(d)
  {
    if(d&1)
      a = pre[a][shift];
    d /= 2;
    shift++;
  }
  return a;
}

int lca(int a, int b)
{
  if(dep[a] < dep[b])
    swap(a, b);
  int dif = dep[a]-dep[b];
  a = get_pre(a, dif);
  if(a == b)
    return a;
  for(int i = 25; i >= 0; i--)
  {
    if(pre[a][i] != pre[b][i])
    {
      a = pre[a][i];
      b = pre[b][i];
    }
  }
  return pre[a][0];
}

int main(int argc, char const *argv[]) {
  cin>>n;
  int a, b, c;
  for(int i = 0; i < n-1; i++)
  {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  dfs(1, 1, 0);
  calc_pre();
  cin>>q;
  for(int i = 0; i < q; i++)
  {
    cin>>a>>b;
    if(a == b)
    {
      cout<<n<<endl;
      continue;
    }
    c = lca(a, b);
    if(dep[a] == dep[b])
      cout<<n-siz[get_pre(a, dep[a]-dep[c]-1)]-siz[get_pre(b, dep[b]-dep[c]-1)]<<endl;
    else
    {
      int dist = dep[a]+dep[b]-2*dep[c];
      if(dist%2 != 0)
        cout<<0<<endl;
      else
      {
        if(dep[a] < dep[b])
          swap(a, b);
        cout<<siz[get_pre(a, dist/2)]-siz[get_pre(a, dist/2-1)]<<endl;
      }
    }
  }
  return 0;
}