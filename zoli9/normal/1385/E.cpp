#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

int n, m;
vi G[200009];
bool was[200009];
vi toposort;
int topotime;

void dfs(int x)
{
  was[x]=true;
  for(int nb: G[x]) if(!was[nb]) dfs(nb);
  topotime++;
  toposort[x]=topotime;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    vpii dir;
    vpii undir;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
      G[i].clear();
      was[i]=false;
    }
    for(int i=1; i<=m; i++)
    {
      int tp, a, b;
      cin>>tp>>a>>b;
      if(tp==0) undir.push_back({a, b});
      else
      {
        dir.push_back({a, b});
        G[a].push_back(b);
      }
    }
    topotime=0;
    toposort.assign(n+1, 0);
    for(int i=1; i<=n; i++)
    {
      if(!was[i])
      {
        dfs(i);
      }
    }
    bool answer=true;
    for(pii edge: dir)
    {
      if(toposort[edge.F]<toposort[edge.S])
      {
        answer=false;
        break;
      }
    }
    if(answer)
    {
      cout<<"YES"<<'\n';
      for(pii edge: dir)
      {
        cout<<edge.F<<" "<<edge.S<<'\n';
      }
      for(pii edge: undir)
      {
        if(toposort[edge.F]<toposort[edge.S])
        {
          swap(edge.F, edge.S);
        }
        cout<<edge.F<<" "<<edge.S<<'\n';
      }
    }
    else
    {
      cout<<"NO"<<'\n';
    }
  }
  return 0;
}