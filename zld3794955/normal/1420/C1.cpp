#include<bits/stdc++.h>
using namespace std;
const int N=300030;
int T,n,q,a[N]={};
long long f[N][2]={};
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		for(int i=1;i<=n;++i)
		{
			f[i][0]=max(f[i-1][0],f[i-1][1]+a[i]);
			f[i][1]=max(f[i-1][1],f[i-1][0]-a[i]);
		}
		cout<<f[n][0]<<endl;
	}
}