#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge
{
  int a, b;
  long long w;
  int i;
};

bool operator<(const edge &a, const edge &b)
{
  return a.w < b.w;
}

int n, m;

edge e[223456], ue[223456];

int fa[223456], ra[223456];
vector<int> graf[223456];
vector<int> ind[223456];
vector<long long> wes[223456];

bool used[223456];

long long faw[223456];
int pre[223456][25];
long long prema[223456][25];

int depth[223456];

void dfs(int v, int f, long long w, int d)
{
  pre[v][0] = f;
  prema[v][0] = w;
  depth[v] = d;
  for(int i = 0; i < graf[v].size(); i++)
  {
    if(graf[v][i] != f && used[ind[v][i]])
      dfs(graf[v][i], v, wes[v][i], d+1);
  }
}

void calcpre()
{
  for(int i = 1; i < 22; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      pre[j][i] = pre[pre[j][i-1]][i-1];
      prema[j][i] = max(prema[j][i-1], prema[pre[j][i-1]][i-1]);
    }
  }
}

int getfa(int a)
{
  if(fa[a] != a)
    fa[a] = getfa(fa[a]);
  return fa[a];
}

bool same(int a, int b)
{
  return getfa(a) == getfa(b);
}

void connect(int a, int b)
{
  a = getfa(a);
  b = getfa(b);
  if(a == b)
    return;
  if(ra[a] > ra[b])
    fa[b] = a;
  else if(ra[a] < ra[b])
    fa[a] = b;
  else
  {
    ra[a]++;
    fa[b] = a;
  }
}

long long lcama(int a, int b)
{
  long long ans = 0;
  if(depth[a] < depth[b])
    swap(a, b);
  for(int i = 21; i >= 0; i--)
  {
    if(depth[pre[a][i]] >= depth[b])
    {
      ans = max(ans, prema[a][i]);
      a = pre[a][i];
    }
  }
  if(a == b)
    return ans;
  for(int i = 21; i >= 0; i--)
  {
    if(pre[a][i] != pre[b][i])
    {
      ans = max(ans, prema[a][i]);
      ans = max(ans, prema[b][i]);
      a = pre[a][i];
      b = pre[b][i];
    }
  }
  return max(ans, max(prema[a][0], prema[b][0]));
}

int main() {
  ios::sync_with_stdio(false);
  cin>>n>>m;
  for(int i = 1; i <= n; i++)
    fa[i] = i;
  for(int i = 0; i < m; i++)
  {
    cin>>e[i].a>>e[i].b>>e[i].w;
    e[i].i = i;
    graf[e[i].a].push_back(e[i].b);
    graf[e[i].b].push_back(e[i].a);
    ind[e[i].a].push_back(i);
    ind[e[i].b].push_back(i);
    wes[e[i].a].push_back(e[i].w);
    wes[e[i].b].push_back(e[i].w);
    ue[i] = e[i];
  }
  sort(e, e+m);
  long long sum = 0;
  for(int i = 0; i < m; i++)
  {
    if(!same(e[i].a, e[i].b))
    {
      connect(e[i].a, e[i].b);
      sum += e[i].w;
      used[e[i].i] = true;
    }
  }
  dfs(1, 1, 0, 0);
  calcpre();
  for(int i = 0; i < m; i++)
    cout<<sum+ue[i].w-lcama(ue[i].a, ue[i].b)<<endl;
  return 0;
}