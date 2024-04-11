#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
int n[3];
vector<ll> t[3];
ll infi=4LL*1e18;
ll calc(int a, int b, int c)
{
  if(a>=n[0] || b>=n[1] || c>=n[2]) return infi;
  return (t[0][a]-t[1][b])*(t[0][a]-t[1][b])+(t[0][a]-t[2][c])*(t[0][a]-t[2][c])+(t[2][c]-t[1][b])*(t[2][c]-t[1][b]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll test;
	cin>>test;
	while(test--)
	{
		cin>>n[0]>>n[1]>>n[2];
    for(int i=0; i<3; i++)
    {
      t[i].resize(n[i]);
      for(int j=0; j<n[i]; j++)
      {
        cin>>t[i][j];
      }
      sort(t[i].begin(), t[i].end());
    }
    ll ans=calc(0, 0, 0);
    for(int j=0; j<3; j++)
    {
      int cnt[3];
      cnt[0]=0;
      cnt[1]=0;
      cnt[2]=0;
      for(int i=0; i<n[j]; i++)
      {
        if(j!=0) while(cnt[0]+1<n[0] && t[0][cnt[0]+1]<=t[j][i]) cnt[0]++;
        if(j!=1) while(cnt[1]+1<n[1] && t[1][cnt[1]+1]<=t[j][i]) cnt[1]++;
        if(j!=2) while(cnt[2]+1<n[2] && t[2][cnt[2]+1]<=t[j][i]) cnt[2]++;
        if(j==0)
        {
          ans=min(ans, calc(i, cnt[1]+1, cnt[2]+1));
          ans=min(ans, calc(i, cnt[1]+1, cnt[2]));
          ans=min(ans, calc(i, cnt[1], cnt[2]+1));
          ans=min(ans, calc(i, cnt[1], cnt[2]));
        }
        else if(j==1)
        {
          ans=min(ans, calc(cnt[0]+1, i, cnt[2]+1));
          ans=min(ans, calc(cnt[0]+1, i, cnt[2]));
          ans=min(ans, calc(cnt[0], i, cnt[2]+1));
          ans=min(ans, calc(cnt[0], i, cnt[2]));
        }
        else
        {
          ans=min(ans, calc(cnt[0]+1, cnt[1]+1, i));
          ans=min(ans, calc(cnt[0]+1, cnt[1], i));
          ans=min(ans, calc(cnt[0], cnt[1]+1, i));
          ans=min(ans, calc(cnt[0], cnt[1], i));
        }
      }
    }
    
    cout<<ans<<'\n';
	}
	return 0;
}