#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,P=998244353;

int T,n,f[N],g[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			g[j]++;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=(sum+g[i])%P;
		sum=(sum+f[i])%P;
	}
	printf("%d\n",f[n]);
}