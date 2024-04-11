#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=2e5+5;
int n;
bool a[maxn],pre[maxn];
int main()
{
	int ot=T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
		if(pre[n]){printf("NO\n");continue;}
		if(n&1)
		{
			printf("YES\n%d\n",max(0,n-2));
			for(int i=1;i<=n-2;i+=2)printf("%d ",i);
			for(int i=n-4;i>=1;i-=2)printf("%d ",i);
			if(n!=1)printf("\n");
		}
		else
		{
			bool flag=0;
			for(int i=1;i<=n;i+=2)
			{
				if(!pre[i]&&(i&1))
				{
					printf("YES\n%d\n",max(0,i-2)+max(0,n-i-2));
					for(int j=1;j<=i-2;j+=2)printf("%d ",j);
					for(int j=i-4;j>=1;j-=2)printf("%d ",j);
					for(int j=i+1;j<=n-2;j+=2)printf("%d ",j);
					for(int j=n-4;j>=i+1;j-=2)printf("%d ",j);
					if(max(0,i-2)+max(0,n-i-2))printf("\n");
					flag=1;break;
				}
			}
			if(!flag)printf("NO\n");
		}
	}
	return 0;
}