#include<bits/stdc++.h>
using namespace std;
const int N=200200;
int n,s[N]={},d[N]={},top=0;
long long sum=0;
int main()
{	
	scanf("%d",&n);
	s[++top]=0;
	for(int i=1,t,x,y;i<=n;++i)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&x,&y);
			sum+=x*y;
			d[x]+=y;
		}
		if(t==2)
		{
			scanf("%d",&x);
			s[++top]=x;
			sum+=x;
		}
		if(t==3)
		{
			d[top-1]+=d[top];
			sum-=s[top]+d[top];
			d[top]=0;
			--top;
		}
		printf("%.12f\n",sum*1.0/top);
	}
	return 0;
}