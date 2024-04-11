#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int ans;
int hol[200009];
int ma[200009];
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  ans=n-1;
  vector<vector<int> > v(m+1); 
  for(int i=1; i<=n; i++)
  {
    cin>>hol[i];
    v[hol[i]].push_back(i);
    if(i>1 && hol[i]==hol[i-1]) ans--;
  }
  for(int i=1; i<=m; i++)
  {
    ma[i]=i;
  }
  cout<<ans<<'\n';
  for(int q=1; q<m; q++)
  {
    int a, b;
    cin>>a>>b;
    int AA=ma[a];
    int BB=ma[b];
    if(v[AA].size()<v[BB].size())
    {
      for(int x: v[AA])
      {
        if(hol[x+1]==BB) ans--;
        if(hol[x-1]==BB) ans--;
      }
      for(int x: v[AA])
      {
        v[BB].push_back(x);
        hol[x]=BB;
      }
      ma[a]=BB;
    }
    else
    {
      for(int x: v[BB])
      {
        if(hol[x+1]==AA) ans--;
        if(hol[x-1]==AA) ans--;
      }
      for(int x: v[BB])
      {
        v[AA].push_back(x);
        hol[x]=AA;
      }
      ma[a]=AA;
    }
    cout<<ans<<'\n';
  }
  
  
  
	return 0;
}