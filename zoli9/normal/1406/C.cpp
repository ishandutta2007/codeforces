#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vi G[100009];
bool was[100009];
int children[100009];
int cmp[100009];
int dad[100009];
int someleaf[100009];

void dfs(int x)
{
  was[x]=true;
  children[x]=1;
  someleaf[x]=x;
  cmp[x]=0;
  for(int nb: G[x])
  {
    if(!was[nb])
    {
      dad[nb]=x;
      dfs(nb);
      someleaf[x]=someleaf[nb];
      cmp[x]=max(cmp[x], children[nb]);
      children[x]+=children[nb];
    }
  }
  cmp[x]=max(cmp[x], n-children[x]);
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
      for(int i=1; i<=n; i++)
      {
        G[i].clear();
        was[i]=false;
      }
      for(int i=1; i<n; i++)
      {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
      }
      dfs(1);
      int best=n;
      vi bests;
      for(int i=1; i<=n; i++)
      {
        if(cmp[i]<best)
        {
          best=cmp[i];
          bests.clear();
          bests.push_back(i);
        }
        else if(cmp[i]==best)
        {
          bests.push_back(i);
        }
      }
      if(bests.size()==1)
      {
        cout<<1<<" "<<G[1][0]<<'\n';
        cout<<1<<" "<<G[1][0]<<'\n';
        continue;
      }
      int kid=bests[0];
      if(kid==dad[bests[1]]) kid=bests[1];
      cout<<someleaf[kid]<<" "<<dad[someleaf[kid]]<<'\n';
      cout<<someleaf[kid]<<" "<<dad[kid]<<'\n';
    }

    return 0;
}