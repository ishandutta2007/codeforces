#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int f[N],a[N],T,n,b,t,i,j,k;
int main()
{
	scanf("%d%d%d%d",&T,&n,&b,&t);
	t=min(t,min(n,b));
	while(T--)
	{
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		for(i=1;i<=t;++i)
			for(j=1;j<=n;++j)
			{
				f[a[j]]=f[a[j]-1]+1;
				for(k=a[j]+1;k<=b && f[k]<f[a[j]]; ++k)
					f[k]=f[a[j]];
			}
		printf("%d\n",f[b]);
	}
	return 0;
}