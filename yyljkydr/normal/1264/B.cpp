#include<bits/stdc++.h>
using namespace std;

const int N=4e5+1e3+7;

int n,a,b,c,d;

int ans[N];

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a+b+c+d==1)
	{
		puts("YES");
		if(a)
			puts("0");
		else if(b)
			puts("1");
		else if(c)
			puts("2");
		else if(d)
			puts("3");
		return 0;
	}
	if(a-b==1&&c==0&&d==0)
	{
		puts("YES");
		for(int i=1;i<=b;i++)
			printf("%d %d ",0,1);
		printf("%d ",0);
		return 0;
	}
	if(d-c==1&&a==0&&b==0)
	{
		puts("YES");
		for(int i=1;i<=c;i++)
			printf("%d %d ",3,2);
		printf("%d ",3);
		return 0;
	}
	int oa=a,ob=b,oc=c,od=d;
	n=a+b+c+d;
	if(a>b||d>c)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=a*2;i+=2)
		ans[i]=0,ans[i+1]=1;
	b-=a,a=0;
	for(int i=n;i>n-d*2;i-=2)
		ans[i]=3,ans[i-1]=2;
	c-=d,d=0;
	if(c-b>1||b-c>1)
	{
		puts("NO");
		return 0;
	}
	for(int i=oa*2+1;i<=oa*2+min(c,b)*2;i+=2)
		ans[i]=2,ans[i+1]=1;
	int mn=min(b,c);
	b-=mn,c-=mn;
	if(c||b)
	{
		if(b)
		{
			for(int i=oa*2+mn*2+1;i>1;i--)
				ans[i]=ans[i-1];
			ans[1]=1;
		}
		else if(c)
		{
			for(int i=oa*2+mn*2+1;i<n;i++)
				ans[i]=ans[i+1];
			ans[n]=2;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}