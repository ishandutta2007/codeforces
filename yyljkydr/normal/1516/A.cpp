#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T,n,k,a[N],s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int s=0;
		for(int i=1;i<=n;i++)
		{
			int w=min(k,a[i]);
			s+=w;
			k-=w;
			a[i]-=w;
		}
		a[n]+=s;
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i]," \n"[i==n]);
	}
}