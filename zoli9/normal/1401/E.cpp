#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int m1, m2;

int N=1000001;

int m[10000009];

void modosit(int cs, int k, int v, int hol, int d)
{
  if(hol<k || v<hol) return;
  m[cs]+=d;
  if(k==v) return;
  modosit(2*cs, k, (k+v)/2, hol, d);
  modosit(2*cs+1, (k+v)/2+1, v, hol, d);
}
int kerdez(int cs, int k, int v, int x, int y)
{
  if(v<x || y<k) return 0;
  if(x<=k && v<=y) return m[cs];
  int cs1=kerdez(2*cs, k, (k+v)/2, x, y);
  int cs2=kerdez(2*cs+1, (k+v)/2+1, v, x, y);
  return cs1+cs2;
}

vector<pair<pii, pii> > Q;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>m1>>m2;
  ll ans=1;
  modosit(1, 0, N-1, 0, 1);
  modosit(1, 0, N-1, 1000000, 1);
  for(int i=1; i<=m1; i++)
  {
    int yy, lx, rx;
    cin>>yy>>lx>>rx;
    Q.push_back({{lx, -1}, {yy, 0}});
    Q.push_back({{rx, 1}, {yy, 0}});
    if(lx==0 && rx==1000000) ans++;
  }
  for(int i=1; i<=m2; i++)
  {
    int xx, ly, ry;
    cin>>xx>>ly>>ry;
    Q.push_back({{xx, 0}, {ly, ry}});
  }
  sort(Q.begin(), Q.end());
  
  for(pair<pii, pii> q: Q)
  {
    if(q.F.S == 0)
    {
      ll pl=kerdez(1, 0, N-1, q.second.first, q.second.second);
      ans+=(pl-1);
      //cout<<pl<<endl;
    }
    else
    {
      if(q.F.S<0)
      {
        modosit(1, 0, N-1, q.second.first, 1);
      }
      else
      {
        modosit(1, 0, N-1, q.second.first, -1);
      }
    }
  }
  cout<<ans<<endl;
	return 0;
}