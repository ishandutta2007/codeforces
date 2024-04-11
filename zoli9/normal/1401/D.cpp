#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

vi G[100009];
bool was[100009];
ll ch[100009];

vll w;
ll n;

ll MOD=1000000007;

void dfs(int x)
{
  was[x]=true;
  ch[x]=1;
  for(int sz: G[x])
  {
    if(!was[sz])
    {
      dfs(sz);
      w.push_back(ch[sz]*(n-ch[sz]));
      ch[x]+=ch[sz];
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
    w.clear();
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
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    ll ans=0;
    int m;
    cin>>m;
    vll p(m);
    for(int i=0; i<m; i++)
    {
      cin>>p[i];
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    while(p.size()<w.size()) p.push_back(1);
    int ww=w.size();
    int pp=p.size();
    int df=pp-ww;
    for(int i=0; i<p.size(); i++)
    {
      int j=i-df;
      if(j<0)
      {
        w[0]=(w[0]*p[i])%MOD;
        continue;
      }
      ll plus=(w[j]*p[i])%MOD;
      ans=(ans+plus)%MOD;
    }
    cout<<ans<<'\n';
  }
	return 0;
}