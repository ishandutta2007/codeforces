#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=998244353,inv2=(P+1)/2;

int n,f[N];

int main()
{
	scanf("%d",&n);
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%P;
	int ans=f[n];
	for(int i=1;i<=n;i++)
		ans=1ll*ans*inv2%P;
	printf("%d\n",ans);
}