#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

int n;
vi G[200009];
vi w[200009];

int was[200009];

vi w0, w1;
int starter;
int stedge;

void dfs(int x)
{
  was[x]=true;
  for(int i=0; i<G[x].size(); i++)
  {
    int nb=G[x][i];
    if(!was[nb])
    {
      if(w[x][i]>0) w0.push_back(w[x][i]);
      else w1.push_back(-w[x][i]);
      dfs(nb);
    }
    else if(nb==starter && abs(w[x][i])!=stedge)
    {
      if(w[x][i]>0) w0.push_back(w[x][i]);
      else w1.push_back(-w[x][i]);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n;
    vi a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    for(int i=1; i<=n; i++)
    {
      G[i].clear();
      w[i].clear();
      was[i]=false;
    }
    for(int i=0; i<n; i++)
    {
      G[a[i]].push_back(b[i]);
      w[a[i]].push_back(i+1);
      G[b[i]].push_back(a[i]);
      w[b[i]].push_back(-i-1);
    }
    bool answer=true;
    for(int i=1; i<=n; i++)
    {
      if(G[i].size()!=2)
      {
        answer=false;
      }
    }
    if(!answer)
    {
      cout<<-1<<'\n';
      continue;
    }
    vi ans;
    for(int i=1; i<=n; i++)
    {
      if(!was[i])
      {
        w0.clear();
        w1.clear();
        starter=i;
        stedge=abs(w[i][0]);
        dfs(i);
        if(w0.size()<w1.size()) for(int j: w0) ans.push_back(j);
        else for(int j: w1) ans.push_back(j);
      }
    }
    cout<<ans.size()<<'\n';
    for(int j: ans) cout<<j<<" ";
    cout<<'\n';
  }
  return 0;
}