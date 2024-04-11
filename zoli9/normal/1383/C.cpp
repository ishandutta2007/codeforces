#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
string s, z;
int db[29][29];
bool was[29];
vi S;
int infi=10000009;
int l2[1100009];
int iedge[29][1100009];

int calc()
{
  int m=S.size();
  vi res((1<<m), infi);
  
  for(int i=0; i<m; i++)
  {
    iedge[i][0]=false;
    for(int msk=1; msk<(1<<m); msk++)
    {
      if(db[S[l2[msk]]][S[i]]>0) iedge[i][msk]=true;
      else iedge[i][msk]=iedge[i][msk-(1<<(l2[msk]))];
    }
  }
  
  
  res[0]=0;
  for(int msk=1; msk<(1<<m); msk++)
  {
    for(int i=0; i<20; i++)
    {
      if(msk==(1<<i))
      {
        res[msk]=0;
      }
      else if((msk&(1<<i))>0)
      {
        if(iedge[i][msk]) res[msk]=min(res[msk], 2+res[msk-(1<<i)]);
        else res[msk]=min(res[msk], 1+res[msk-(1<<i)]);
      }
    }
  }
  return res[(1<<m)-1];
}

void dfs(int x)
{
  was[x]=true;
  S.push_back(x);
  for(int i=0; i<20; i++)
  {
    if(was[i] || i==x) continue;
    if(db[i][x]>0 || db[x][i]>0)
    {
      dfs(i);
    }
  }
}
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  l2[1]=0;
  for(int i=2; i<=1100000; i++)
  {
    l2[i]=l2[i/2]+1;
  }
  while(test--)
  {
    for(int i=0; i<=20; i++)
    {
      was[i]=false;
      for(int j=0; j<=20; j++)
      {
        db[i][j]=0;
      }
    }
    cin>>n;
    cin>>s;
    cin>>z;
    int ans=0;
    for(int i=0; i<n; i++)
    {
      int c1=s[i]-'a';
      int c2=z[i]-'a';
      if(c1==c2) continue;
      db[c1][c2]=1;
    }
    for(int i=0; i<20; i++)
    {
      if(was[i]) continue;
      S.clear();
      dfs(i);
      if(S.size()==1) continue;
      ans+=calc();
    }
    cout<<ans<<'\n';
  }
	return 0;
}