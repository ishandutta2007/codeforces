#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

int n, k;
vi G[200009];
vi leaves;
vi deg;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n>>k;
    leaves.assign(n+1, 0);
    deg.assign(n+1, 0);
    vector<bool> inside(n+1, false);
    for(int i=1; i<=n; i++)
    {
      G[i].clear();
    }
    for(int i=1; i<n; i++)
    {
      int a, b;
      cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
      deg[a]++;
      deg[b]++;
    }
    if(k==1)
    {
      cout<<n-1<<'\n';
      continue;
    }
    for(int i=1; i<=n; i++)
    {
      if(G[i].size()==1)
      {
        leaves[G[i][0]]++;
      }
    }
    vi Q;
    for(int i=1; i<=n; i++)
    {
      if(leaves[i]>=k)
      {
        Q.push_back(i);
        inside[i]=true;
      }
    }
    int ans=0;
    while(Q.size()>0)
    {
      int x=Q.back();
      Q.pop_back();
      inside[x]=false;
      while(leaves[x]>=k)
      {
        ans++;
        leaves[x]-=k;
        deg[x]-=k;
      }
      if(deg[x]==1)
      {
        int y=0;
        for(int nb: G[x])
        {
          if(deg[nb]>1)
          {
            y=nb;
            break;
          }
        }
        if(y>0)
        {
          leaves[y]++;
          if(leaves[y]>=k)
          {
            if(!inside[y])
            {
              Q.push_back(y);
              inside[y]=true;
            }
          }
        }
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}