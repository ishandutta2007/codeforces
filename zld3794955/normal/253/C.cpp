#include<bits/stdc++.h>
using namespace std;
const int N=110,Inf=1<<30;
int n,c[N]={},r1,c1,r2,c2;
int calc1()
{
	int p=c1;
	for(int i=r1;i<=r2;++i)
		p=min(p,c[i]);
	return abs(r2-r1)+abs(p-c2);
}
int calc2()
{
	int ans=Inf;
	for(int s=1;s<r1;++s)
	{
		int p=c1;
		for(int i=s;i<=r2;++i)
			p=min(p,c[i]);
		ans=min(ans,abs(r2-s)+abs(r1-s)+abs(p-c2));
	}
	return ans;
}
int calc3()
{
	int ans=Inf;
	for(int e=r2+1;e<=n;++e)
	{
		int p=c1;
		for(int i=r1;i<=e;++i)
			p=min(p,c[i]);
		ans=min(ans,abs(e-r2)+abs(e-r1)+abs(p-c2));
	}
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	--c1,--c2;
	if(r1>r2)
	{
		r1=n-r1+1,r2=n-r2+1;
		reverse(c+1,c+n+1);
	}
	int ans=Inf;
	ans=min(ans,calc1());
	ans=min(ans,calc2());
	ans=min(ans,calc3());
	printf("%d\n",ans);
	return 0;
}