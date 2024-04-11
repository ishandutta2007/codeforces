#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
ll szint[200009];
ll gy[200009];
bool was[200009];
bool w2[200009];
vector<int> G[200009];
vector<int> w;
void dfs(int x)
{
  w2[x]=true;
  gy[x]++;
  for(int sz: G[x])
  {
    if(!w2[sz])
    {
      dfs(sz);
      gy[x]+=gy[sz];
    }
  }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin>>n>>k;
  for(int i=1; i<n; i++)
  {
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  queue<int> q;
  q.push(1);
  ll ans=0;
  int cnt=0;
  szint[1]=0;
  was[1]=true;
  while(q.size()>0)
  {
    int akt=q.front();
    w.push_back(szint[akt]-(gy[akt]-1));
    q.pop();
    for(int sz: G[akt])
    {
      if(!was[sz])
      {
        was[sz]=true;
        szint[sz]=szint[akt]+1;
        q.push(sz);
      }
    }
  }
  sort(w.begin(), w.end());
  reverse(w.begin(), w.end());
  for(int i=0; i<k; i++)
  {
    ans+=w[i];
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
  
	return 0;
}