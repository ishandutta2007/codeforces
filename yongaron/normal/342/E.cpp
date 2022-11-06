#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>

using namespace std;

int n, m;

vector<int> tree[123456];
int cfa[123456];
int subsize[123456];
bool blocked[123456];
int dst[123456];

vector<int> trav;
int depth[123456];
int be[123456], en[123456];
int table[323456][23];
int lg[323456], pw[323456];

void dfs(int v, int f, int d)
{
  be[v] = trav.size();
  depth[v] = d;
  for(int i = 0; i < tree[v].size(); i++)
  {
    trav.push_back(d);
    if(tree[v][i] != f)
      dfs(tree[v][i], v, d+1);
  }
  en[v] = trav.size();
  trav.push_back(d);
}

void make_table()
{
  for(int i = 0; i < trav.size(); i++)
    table[i][0] = trav[i];
  int po = 1;
  for(int i = 1; i < 23; i++)
  {
    for(int j = 0; j+po < trav.size(); j++)
    {
      table[j][i] = min(table[j][i-1], table[j+po][i-1]);
    }
    po *= 2;
  }
  int ex = 0;
  po = 1;
  for(int i = 1; i <= trav.size(); i++)
  {
    if(2*po <= i)
    {
      po *= 2;
      ex++;
    }
    pw[i] = po;
    lg[i] = ex;
  }
}

int lca(int c, int d)
{
  int b = max(en[c], en[d]);
  int a = min(be[c], be[d]);
  int len = b-a-1;
  return min(table[a][lg[len]], table[b-pw[len]][lg[len]]);
}

int dist(int a, int b)
{
  return depth[a]+depth[b]-2*lca(a, b);
}

int subtree_size(int v, int f)
{
  int c = 1;
  for(int i = 0; i < tree[v].size(); i++)
    if(tree[v][i] != f && !blocked[tree[v][i]])
      c += subtree_size(tree[v][i], v);
  subsize[v] = c;
  return c;
}

pair<int, int> find_centroid(int v, int f, int t)
{
  int ma = t-subsize[v];
  int mi = 1e9, mii = 0;
  for(int i = 0; i < tree[v].size(); i++)
  {
    if(!blocked[tree[v][i]] && tree[v][i] != f)
    {
      ma = max(ma, subsize[tree[v][i]]);
      pair<int, int> p = find_centroid(tree[v][i], v, t);
      if(p.second < mi)
      {
        mi = p.second;
        mii = p.first;
      }
    }
  }
  if(ma < mi)
  {
    mi = ma;
    mii = v;
  }
  return {mii, mi};
}

void make_centroid(int v, int f)
{
  int c = find_centroid(v, 0, subtree_size(v, 0)).first;
  blocked[c] = true;
  cfa[c] = f;
  for(int i = 0; i < tree[c].size(); i++)
    if(!blocked[tree[c][i]])
      make_centroid(tree[c][i], c);
}

void color(int v, int colored)
{
  if(!v)
    return;
  dst[v] = min(dst[v], dist(v, colored));
  color(cfa[v], colored);
}

int quer(int v, int quered)
{
  if(!v)
    return 1e9;
  return min(dst[v]+dist(quered, v), quer(cfa[v], quered));
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin>>n>>m;
  for(int i = 0; i < n-1; i++)
  {
    int a, b;
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  for(int i = 1; i <= n; i++)
    dst[i] = 1e9;
  dfs(1, 0, 0);
  make_table();
  make_centroid(1, 0);
  color(1, 1);
  for(int i = 0; i < m; i++)
  {
    int a, b;
    cin>>a>>b;
    if(a == 1)
      color(b, b);
    else
      cout<<quer(b, b)<<endl;
  }
  return 0;
}