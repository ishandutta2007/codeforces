#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<int> ans;

map<pii, pii> ma;
int n;

pii ask(int x, int y)
{
  if(ma.find({x, y})!=ma.end())
  {
    return ma[{x, y}];
  }
  cout<<"? "<<x<<" "<<y<<endl;
  fflush(stdout);
  pii res;
  cin>>res.F>>res.S;
  ma[{x, y}]=res;
  return res;
}

void solve(int k, int v)
{
  if(k>v) return;
  pii p=ask(k, v);
  if(p.S==v-k+1)
  {
    for(int i=k; i<=v; i++)
    {
      ans[i]=p.F;
    }
    return;
  }
  int fel=(k+v)/2;
  pii f1=ask(k, fel);
  if(f1.S==p.S)
  {
    solve(k, fel);
    solve(fel+1, v);
    return;
  }
  pii f2=ask(fel+1, v);
  if(f2.S==p.S)
  {
    solve(k, fel);
    solve(fel+1, v);
    return;
  }
  if(f1.F==p.F)
  {
    for(int i=fel-f1.S+1; i<fel-f1.S+1+p.S; i++)
    {
      ans[i]=p.F;
    }
    solve(k, fel-f1.S);
    solve(fel-f1.S+p.S+1, v);
    return;
  }
  if(f2.F==p.F)
  {
    for(int i=fel+f2.S-p.S+1; i<=fel+f2.S; i++)
    {
      ans[i]=p.F;
    }
    solve(k, fel+f2.S-p.S);
    solve(fel+f2.S+1, v);
    return;
  }
  pii g1=ask(fel-f1.S+1, fel);
  if(g1.F==p.F)
  {
    for(int i=fel-g1.S+1; i<fel-g1.S+1+p.S; i++)
    {
      ans[i]=p.F;
    }
    solve(k, fel-g1.S);
    solve(fel-g1.S+p.S+1, v);
    return;
  }
  pii g2=ask(fel+1, fel+f2.S);
  if(g2.F==p.F)
  {
    for(int i=fel+g2.S-p.S+1; i<=fel+g2.S; i++)
    {
      ans[i]=p.F;
    }
    solve(k, fel+g2.S-p.S);
    solve(fel+g2.S+1, v);
    return;
  }
}

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  ans.resize(n+1);
  solve(1, n);
  cout<<"!";
  for(int i=1; i<=n; i++)
  {
    cout<<" "<<ans[i];
  }
  cout<<endl;
  fflush(stdout);
	return 0;
}