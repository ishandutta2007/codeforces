#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[1010];
int cnt;
int n,x,y;
int ask()
{
	int i;
	printf("? %d ",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
	int s;
	scanf("%d",&s);
	return s;
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	int m=0;
	int s,p;
	int i,j;
	int num;
	int ans1=0,ans2=0;
	for(i=1;i<=15;i++)
		if(n&(1<<(i-1)))
			m=i;
	for(i=m;i>=1;i--)
	{
		cnt=0;
		num=0;
		for(j=1;j<=n;j++)
			if(j&(1<<(i-1)))
			{
				a[++cnt]=j;
				num^=x;
			}
		if(cnt)
		{
			s=ask();
			if(s!=num)
			{
				p=i;
				break;
			}
		}
	}
	ans2|=1<<(p-1);
	for(i=p-1;i>=1;i--)
	{
		cnt=0;
		num=0;
		for(j=1;j<=n;j++)
			if(j&(1<<(i-1))&&j&(1<<(p-1)))
			{
				a[++cnt]=j;
				num^=x;
			}
		if(cnt)
		{
			s=ask();
			if(s!=num)
				ans2|=1<<(i-1);
		}
	}
	for(i=p-1;i>=1;i--)
	{
		cnt=0;
		num=0;
		for(j=1;j<=n;j++)
			if(j&(1<<(i-1))&&!(j&(1<<(p-1))))
			{
				a[++cnt]=j;
				num^=x;
			}
		if(cnt)
		{
			s=ask();
			if(s!=num)
				ans1|=1<<(i-1);
		}
	}
	for(i=p+1;i<=m;i++)
	{
		cnt=0;
		num=0;
		for(j=1;j<=n;j++)
			if(j&(1<<(p-1))&&j&(1<<(i-1)))
			{
				a[++cnt]=j;
				num^=x;
			}
		if(cnt)
		{
			s=ask();
			if(s!=num)
			{
				ans1|=1<<(i-1);
				ans2|=1<<(i-1);
			}
		}
	}
	if(ans1>ans2)
		swap(ans1,ans2);
	printf("! %d %d\n",ans1,ans2); 
	return 0;
}