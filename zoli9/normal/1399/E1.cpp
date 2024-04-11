#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int n;
vi G[100009];
vll w[100009];
ll s;
bool was[100009];
ll children[100009];
int dad[100009];
ll dadw[100009];

set<pair<ll, int> > q;

void dfs(int x)
{
  was[x]=true;
  children[x]=0;
  if(G[x].size()==1) children[x]=1;
  for(int i=0; i<G[x].size(); i++)
  {
    int nb=G[x][i];
    if(!was[nb])
    {
      dfs(nb);
      children[x]+=children[nb];
      dad[nb]=x;
      dadw[nb]=w[x][i];
    }
  }
}

int main() {
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
      w[i].clear();
      was[i]=false;
    }
    cin>>s;
    for(int i=1; i<n; i++)
    {
      int a, b;
      ll c;
      cin>>a>>b>>c;
      G[a].push_back(b);
      w[a].push_back(c);
      G[b].push_back(a);
      w[b].push_back(c);
    }
    dfs(1);
    q.clear();
    ll val=0;
    for(int i=2; i<=n; i++)
    {
      val+=(children[i]*dadw[i]);
      //cout<<i<<" ch: "<<children[i]<<endl;
      ll removeVal=dadw[i]/2;
      if(dadw[i]%2==1) removeVal++;
      q.insert({-children[i]*removeVal, i});
    }
    int ans=0;
    while(val>s)
    {
      pair<ll, int> pp=*q.begin();
      q.erase(q.begin());
      val+=pp.F;
      dadw[pp.S]/=2;
      ll removeVal=dadw[pp.S]/2;
      if(dadw[pp.S]%2==1) removeVal++;
      q.insert({-children[pp.S]*removeVal, pp.S});
      ans++;
    }
    cout<<ans<<'\n';
  }
}