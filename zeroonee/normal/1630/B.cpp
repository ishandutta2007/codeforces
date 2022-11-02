#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+2;
int a[N],cnt[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,q,i,j,l,x=1,y=1e9,now=0;
		cin>>n>>m;q=n+m+1>>1;
		fill_n(cnt+1,n,0);
		for (i=1;i<=n;i++) cin>>a[i],++cnt[a[i]];
		for (i=j=1;i<=n;i++)
		{
			while (j<=n&&now<q) now+=cnt[j++];
			if (now<q) break;
			if (j-i<y-x) x=i,y=j;
			now-=cnt[i];
		}
		now=0;
		cout<<x<<' '<<y-1<<'\n';
		for (i=l=1;i<=n&&m>1;i++)
		{
			now+=(a[i]>=x&&a[i]<y?1:-1);
			if (now==1)
			{
				cout<<l<<' '<<i<<'\n';
				--m;now=0;l=i+1;
			}
		}
		cout<<i<<' '<<n<<'\n';
	}
}