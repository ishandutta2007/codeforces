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
	return f?x:-x;
}
int main()
{
	int T,n;
	T=getint();
	while(T--)
	{
		n=getint();
		if((n/2)%2)printf("NO\n");
		else
		{
			printf("YES\n");
			int sum=0;
			for(int i=1;i<=n/2;++i)printf("%d ",i*2),sum+=i*2;
			for(int i=1;i<=n/2-1;++i)printf("%d ",i*2-1),sum-=i*2-1;
			printf("%d\n",sum);
		}
	}
	return 0;
}