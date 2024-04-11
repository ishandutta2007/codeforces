#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,m;
LL a[maxn],b[maxn];

int main()	{
	scanf("%d%d",&n,&m);
	LL ans=0;
	for (int i=1;i<=n;++i)
		scanf("%lld",a+i),ans+=a[i]*m;
	for (int i=1;i<=m;++i)
		scanf("%lld",b+i);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if (b[1]<a[n])
		return puts("-1");
	for (int i=2;i<=m;++i)
		ans+=b[i]-a[n];
	if (b[1]>a[n])
		ans+=b[1]-a[n-1];
	cout<<ans<<endl;
	return 0;
}