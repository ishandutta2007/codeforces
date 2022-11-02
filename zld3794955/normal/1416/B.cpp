#include<bits/stdc++.h>
using namespace std;
const int N=10010,D=30;
int n,a[N]={},target=0;
int m=0,p[N<<2]={},q[N<<2]={},x[N<<2]={};
void write(int i,int j,int v)
{
	++m;
	p[m]=i, q[m]=j, x[m]=v;
	a[i]=a[i]-v*i;
	a[j]=a[j]+v*i;
}
int main()
{
	srand(time(0));
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		m=0;
		long long sum=accumulate(a+1,a+n+1,0ll);
		if(sum%n)
		{
			puts("-1");
			continue;
		}
		target=sum/n;
		for(int i=2;i<=n;++i)
		{
			int d=(i-a[i]%i)%i;
			write(1,i,d);
			write(i,1,a[i]/i);
		}
		for(int i=2;i<=n;++i)
			write(1,i,target);
		printf("%d\n",m);
		for(int i=1;i<=m;++i)
			printf("%d %d %d\n",p[i],q[i],x[i]);
	}
}