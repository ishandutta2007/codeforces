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
const int maxn=105;
int n;
int p[maxn],a[maxn];
int query()
{
	printf("? ");for(int i=1;i<=n;i++)printf("%d ",a[i]+1);printf("\n");fflush(stdout);
	int x;cin>>x;
	return x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i==n){p[n]=1;break;}
		a[n]=i;
		int k=query();
		if(!k){p[n]=n+1-i;break;}
	}
	a[n]=0;
	for(int i=1;i<p[n];i++)
	{
		for(int j=1;j<=n-1;j++)a[j]=p[n]-i;
		p[query()]=i;
	}
	for(int i=1;i<=n;i++)a[i]=0;
	for(int i=p[n]+1;i<=n;i++)
	{
		a[n]=i-p[n];
		p[query()]=i;
	}
	printf("! ");for(int i=1;i<=n;i++)printf("%d ",p[i]);printf("\n");fflush(stdout);
	return 0;
}