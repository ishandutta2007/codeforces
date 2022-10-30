#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  ll x, k, y;
  cin>>n>>m>>x>>k>>y;
  vector<int> a;
  a.push_back(0);
  for(int i=1; i<=n; i++)
  {
    int aa;
    cin>>aa;
    a.push_back(aa);
  }
  a.push_back(0);
  vector<int> b;
  b.push_back(0);
  for(int i=1; i<=m; i++)
  {
    int bb;
    cin>>bb;
    b.push_back(bb);
  }
  b.push_back(n+1);
  int acnt=1;
  for(int i=1; i<=m; i++)
  {
    while(acnt<=n && a[acnt]!=b[i]) acnt++;
    if(acnt==n+1)
    {
      cout<<-1<<endl;
      return 0;
    }
    b[i]=acnt;
    acnt++;
  }
  ll ans=0;
  for(int bi=0; bi<=m; bi++)
  {
    int pwr=max(a[b[bi]], a[b[bi+1]]);
    if(b[bi]+1==b[bi+1]) continue;
    int maxi=a[b[bi]+1];
    for(int i=b[bi]+1; i<b[bi+1]; i++)
    {
      maxi=max(maxi, a[i]);
    }
    ll le=b[bi+1]-b[bi]-1;
    if(maxi>pwr)
    {
      if(le<k)
      {
        cout<<-1<<endl;
        return 0;
      }
      le-=k;
      ans+=x;
    }
    ll kk=le/k;
    ll mm=le%k;
    if(k*y<x)
    {
      ans+=(le*y);
    }
    else
    {
      ans+=(mm*y);
      ans+=(kk*x);
    }
  }
  cout<<ans<<endl;
  
  
  
  
	return 0;
}