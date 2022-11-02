#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=100010,D=1500;
int n,m,p,d[D]={},tot,a[N]={},t[N]={},b[M]={};
long long ans=0;
inline int power(int x,int y)
{
	int t=1;
	for(; y; y>>=1,x=x*1ll*x%p)
		if(y&1) t=t*1ll*x%p;
	return t;
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int j=1;j<=m;++j)
		scanf("%d",&b[j]);
	for(int i=1;i*i<p;++i)
		if((p-1)%i==0)
			d[++tot]=i,d[++tot]=(p-1)/i;
	sort(d+1,d+tot+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=tot;++j)
			if(power(a[i],d[j])==1)
			{
				a[i]=(p-1)/d[j];
				break;
			}
	int x=p-1;
	for(int i=1;i<=m;++i)
		x=__gcd(x,b[i]);
	for(int i=1;i<=n;++i)
		a[i]=__gcd<int>(p-1,a[i]*1ll*x%(p-1));
	
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;++i)
	{
		++t[i];
		for(int j=1;j<i;++j)
			if(a[i]%a[j]==0)
				t[i]-=t[j];
		ans+=t[i]*1ll*(p-1)/a[i];
	}
	cout<<ans<<endl;
	return 0;
}