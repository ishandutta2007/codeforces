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
	return (f==1)?x:-x;
}
int n,k,T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n%2==1&&k%2==0){printf("NO\n");continue;}
		else if(n<k){printf("NO\n");continue;}
		else if(n%2==0&&k%2==1&&n<k*2){printf("NO\n");continue;}
		else
		{
			printf("YES\n");
			if(n%2==0&&k%2==1)
			{
				for(int i=1;i<=k-1;++i)printf("2 ");
				printf("%d\n",n-2*k+2);
			}
			else
			{
				for(int i=1;i<=k-1;++i)printf("1 ");
				printf("%d\n",n-k+1);
			}
		}
	}
	return 0;
}