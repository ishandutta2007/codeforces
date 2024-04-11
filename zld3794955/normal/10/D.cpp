#include<iostream>
#include<cstdio>
using namespace std;
int m1,a[501]={},m2,b[501]={},f[501][501]={},l[501][501]={},ans[501]={},len(0),end=0;
inline void init()
{	
	scanf("%d",&m1);
	for(int i=1;i<=m1;++i)
		scanf("%d",&a[i]);
	scanf("%d",&m2);
	for(int i=1;i<=m2;++i)
		scanf("%d",&b[i]);
}
inline void dp()
{	
	int m=0,p=0;
	for(int i=1;i<=m1;++i)
	{	
		m=0;
		for(int j=1;j<=m2;++j)
		{	
			f[i][j]=f[i-1][j];
			if(a[i]>b[j] && f[i-1][j]>m)
			{	
				m=f[i-1][j];
				p=j;
			}
			if(a[i]==b[j])
			{	
				f[i][j]=m+1;
				l[i][j]=p;
			}
		}
	}
	m=0,p=0;
	for(int j=1;j<=m2;++j)
		if(f[m1][j]>m)
		{	
			m=f[m1][j];
			p=j;
		}
	printf("%d\n",m);
	len=m;
	end=p;
}
void get_seq()
{	
	int t=len;
	ans[t]=b[end];
	for(int i=m1;i>=1;--i)
	{	
		if(l[i][end])
		{	
			end=l[i][end];
			ans[--t]=b[end];
		}
	}
	for(int i=1;i<len;++i)
		printf("%d ",ans[i]);
	printf("%d\n",ans[len]);
}
int main()
{	
	init();
	dp();
	if(len)
		get_seq();
	return 0;
}