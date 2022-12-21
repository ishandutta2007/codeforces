#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1005;
inline int getint()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
int T,n,a[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int last=a[1],cnt=0,ansa=0,ansb=0,posl=1,posr=n+1,sum=0;
		cnt++,ansa=a[1];
		int turn=0;
		while(posl+1<posr)
		{
			sum=0;
			turn^=1;
			if(turn==1)
			{
				while(posr>posl+1)
				{
					sum+=a[--posr];
					if(sum>last)break;
				}
				ansb+=sum;
				cnt++;
				if(sum<=last)break;
				last=sum;
			}
			else
			{
				while(posr>posl+1)
				{
					sum+=a[++posl];
					if(sum>last)break;
				}
				ansa+=sum;
				cnt++;
				if(sum<=last)break;
				last=sum;
			}
		}
		printf("%d %d %d\n",cnt,ansa,ansb);
	}
	return 0;
}