#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int cnt[30];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		memset(cnt,0,sizeof cnt);
		int n,l,i,j,r=0;
		cin>>n>>l;
		for (i=1;i<=n;i++)
		{
			int x;cin>>x;
			for (j=0;j<l;j++) cnt[j]+=x>>j&1;
		}
		for (i=0;i<l;i++) if (cnt[i]*2>=n) r|=1<<i;
		cout<<r<<'\n';
	}
}