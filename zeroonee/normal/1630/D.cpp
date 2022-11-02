#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+2;
int a[N],mn[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,d=0,x;
		cin>>n>>m;
		for (i=0;i<n;i++) cin>>a[i];
		while (m--) {cin>>x;d=gcd(d,x);}
		for (i=0;i<d;i++) mn[i]=2e9;
		for (i=d;i<n;i++) if (a[i]<0) a[i]=-a[i],a[i%d]=-a[i%d];
		for (i=0;i<n;i++) mn[i%d]=min(mn[i%d],abs(a[i]));
		ll ans,anss;
		ans=accumulate(a,a+n,0ll);
		for (i=0;i<d;i++) if (a[i]<0) ans-=2ll*(mn[i]+a[i]);
		for (i=0;i<d;i++) a[i]=-a[i];
		anss=accumulate(a,a+n,0ll);
		for (i=0;i<d;i++) if (a[i]<0) anss-=2ll*(mn[i]+a[i]);
		cout<<max(ans,anss)<<'\n';
	}
}