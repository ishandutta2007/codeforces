#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2e5+2;
int b[N];
int n;
bool ck(int m)
{
	static ll a[N],lz[N];
	int i,x;
	for (i=1;i<=n;i++) a[i]=b[i],lz[i]=0;
	for (i=n;i>=3;i--)
	{
		if (lz[i]>=m)
		{
			x=a[i]/3;
			lz[i-1]+=x;
			lz[i-2]+=x*2;
			continue;
		}
		a[i]+=lz[i];
		if (a[i]<m) return 0;
		x=(a[i]-m)/3;
		lz[i-1]+=x;
		lz[i-2]+=x*2;
	}
	return a[1]+lz[1]>=m&&a[2]+lz[2]>=m;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int i;
		cin>>n;
		for (i=1;i<=n;i++) cin>>b[i];
		int l=0,r=1.001e9,mid;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (ck(mid)) l=mid; else r=mid-1;
		}
		cout<<l<<'\n';
	}
}