#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
int t[200009];
vector<int> hol[209];
int db[200009][209];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin>>test;
	while(test--)
	{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
      cin>>t[i];
      for(int j=1; j<=200; j++)
      {
        db[i][j]=db[i-1][j];
      }
      db[i][t[i]]++;
    }
    for(int j=1; j<=200; j++)
    {
      hol[j].clear();
    }
    for(int i=n; i>=1; i--)
    {
      hol[t[i]].push_back(i);
    }
    int ans=0;
    for(int j=1; j<=200; j++) ans=max(ans, db[n][j]);
    for(int i=1; i<=n; i++)
    {
      if(hol[t[i]].size()<db[i][t[i]]) continue;
      int last=hol[t[i]][db[i][t[i]]-1];
      if(last==0 || last<=i) continue;
      int cans=0;
      for(int j=1; j<=200; j++)
      {
        cans=max(cans, db[last-1][j]-db[i][j]);
      }
      cans+=(2*db[i][t[i]]);
      ans=max(ans, cans);
    }
    cout<<ans<<'\n';
	}
	return 0;
}