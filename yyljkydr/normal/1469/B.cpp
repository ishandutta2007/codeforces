#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m;

int a[N],b[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		int s1=0,s2=0,m1=0,m2=0;
		for(int i=1;i<=n;i++)
			s1+=a[i],m1=max(m1,s1);
		for(int i=1;i<=m;i++)
			s2+=b[i],m2=max(m2,s2);
		printf("%d\n",m1+m2);
	}	
}