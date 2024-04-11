#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,p[N];

int n,a[N],b[N],c[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		p[1]=a[1];
		for(int i=2;i<n;i++)
		{
			if(a[i]!=p[i-1])
				p[i]=a[i];
			if(b[i]!=p[i-1])
				p[i]=b[i];
			if(c[i]!=p[i-1])
				p[i]=c[i];
		}
		if(a[n]!=p[n-1]&&a[n]!=p[1])
			p[n]=a[n];
		if(b[n]!=p[n-1]&&b[n]!=p[1])
			p[n]=b[n];
		if(c[n]!=p[n-1]&&c[n]!=p[1])
			p[n]=c[n];
		for(int i=1;i<=n;i++)
			printf("%d%c",p[i]," \n"[i==n]);
	}
}