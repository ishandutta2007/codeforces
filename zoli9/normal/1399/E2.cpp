#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

ll infi=1e18;

int n;
vi G[100009];
vll w[100009];
vi w2[100009];
ll s;
bool was[100009];
ll children[100009];
int dad[100009];
ll dadw[100009];
int dadc[100009];

set<pair<ll, int> > q, q2;

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
      dadc[nb]=w2[x][i];
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
      w2[i].clear();
      was[i]=false;
    }
    cin>>s;
    for(int i=1; i<n; i++)
    {
      int a, b;
      ll c;
      int d;
      cin>>a>>b>>c>>d;
      G[a].push_back(b);
      w[a].push_back(c);
      w2[a].push_back(d);      
      G[b].push_back(a);
      w[b].push_back(c);
      w2[b].push_back(d);
    }
    dfs(1);
    q.clear();
    q2.clear();
    ll val=0;
    for(int i=2; i<=n; i++)
    {
      val+=(children[i]*dadw[i]);
      ll removeVal=dadw[i]/2;
      if(dadw[i]%2==1) removeVal++;
      if(dadc[i]==1) q.insert(make_pair(-children[i]*removeVal, i));
      else q2.insert(make_pair(-children[i]*removeVal, i));
    }
    ll minSingle=infi;
    int ans=0;
    bool check_ok=true;
    while(val>s)
    {
      if(q.empty())
      {
        pair<ll, int> pp=*q2.begin();
        q2.erase(q2.begin());
        val+=pp.F;
        dadw[pp.S]/=2;
        ll removeVal=dadw[pp.S]/2;
        if(dadw[pp.S]%2==1) removeVal++;
        q2.insert(make_pair(-children[pp.S]*removeVal, pp.S));
        ans+=2;
        continue;
      }
      if(q2.empty())
      {
        pair<ll, int> pp=*q.begin();
        q.erase(q.begin());
        val+=pp.F;
        minSingle=min(minSingle, -pp.F);
        dadw[pp.S]/=2;
        ll removeVal=dadw[pp.S]/2;
        if(dadw[pp.S]%2==1) removeVal++;
        q.insert(make_pair(-children[pp.S]*removeVal, pp.S));
        ans++;
        continue;
      }
      pair<ll, int> pp=*q.begin();
      pair<ll, int> p2=*q2.begin();
      if(val+pp.F<=s)
      {
        ans++;
        check_ok=false;
        break;
      }
      if(2*pp.F<p2.F)
      {
        q.erase(q.begin());
        val+=pp.F;
        minSingle=min(minSingle, -pp.F);
        dadw[pp.S]/=2;
        ll removeVal=dadw[pp.S]/2;
        if(dadw[pp.S]%2==1) removeVal++;
        q.insert(make_pair(-children[pp.S]*removeVal, pp.S));
        ans++;
      }
      else
      {
        pair<ll, int> pp=*q2.begin();
        q2.erase(q2.begin());
        val+=pp.F;
        dadw[pp.S]/=2;
        ll removeVal=dadw[pp.S]/2;
        if(dadw[pp.S]%2==1) removeVal++;
        q2.insert(make_pair(-children[pp.S]*removeVal, pp.S));
        ans+=2;
      }
    }
    if(check_ok && val+minSingle<=s) ans--;
    cout<<ans<<'\n';
  }
}