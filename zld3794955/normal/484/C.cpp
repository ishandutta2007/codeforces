#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000010;
int n,m,a[N]={},b[N]={},c[N]={};
char ch[N]={},ans[N]={};
int main()
{	
	scanf("%s\n",ch);
	n=strlen(ch);
	scanf("%d",&m);
	for(int i=1,k=0,d=0;i<=m;++i)
	{
		scanf("%d%d",&k,&d);
		for(int j=0,tot=0;j<d;++j)
			for(int now=j;now<k;now+=d)
				b[tot++]=now;
		for(int j=k;j<n;++j)
			b[j]=j%n;
		for(int j=0;j<n;++j)
			a[j]=b[(j+1)%n];
		for(int j=0;j<n;++j)
			c[j]=a[j];
		for(int y=n-k;y;y>>=1)
		{
			if(y&1)
				for(int j=0;j<n;++j)
					c[j]=a[c[j]];
			copy(a,a+n,b);
			for(int j=0;j<n;++j)
				a[j]=b[b[j]];
		}
		int tot=0;
		for(int j=k-1;j<n;++j)
			ans[tot++]=ch[c[j]];
		for(int j=0;j<k-1;++j)
			ans[tot++]=ch[c[j]];
		puts(ans);
		copy(ans,ans+n,ch);
	}
	return 0;
}