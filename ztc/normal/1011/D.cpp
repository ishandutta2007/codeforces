#include<bits/stdc++.h>
using namespace std;
int n,m,k[31],i,h,l,r;
int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)
	{
		printf("%d\n",i);
		fflush(stdout);
		scanf("%d",&h);
		if(h==0)return 0;
		else k[i]=h;
	}
	l=n+1;
	r=m;
	i=1;
	while(h!=0)
	{
		printf("%d\n",(l+r)/2);
		fflush(stdout);
		scanf("%d",&h);
		if(h*k[i]==1)l=(l+r)/2+1;
		else r=(l+r)/2;
		if(h==0)return 0;
		i=i%n+1;
	}
}