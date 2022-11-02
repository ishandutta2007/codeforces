#include<bits/stdc++.h>
using namespace std;
const int N=103,M=1003;
int n,m,x[N]={},s=0;
double p[N*M]={},tmp[N*M]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",x+i);
	s=accumulate(x+1,x+n+1,0);
}
void work()
{
	if(m==1)
	{
		puts("1.0000000000000000");
		return;
	}
	p[0]=1;
	for(int i=1;i<=n;++i)
	{
		double now=0;
		for(int j=1;j<s;++j)
		{
			now+=p[j-1];
			if(x[i]<=j)
				now-=p[j-x[i]];
			if(x[i]<j)
				now+=p[j-x[i]-1];
			if(m<j)
				now-=p[j-m-1];
			tmp[j]=now/(m-1);
		}
		copy(tmp,tmp+s,p);
	}
	double ans=accumulate(p,p+s,0.0)*(m-1)+1;
	printf("%.16f\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}