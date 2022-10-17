#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7;

int T,n,tag[N],s[N];

long long f[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			f[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&tag[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int i=1;i<=n;i++)
			for(int j=i-1;j>=1;j--)
			{
				if(tag[i]==tag[j])
					continue;
				long long fi=f[i],fj=f[j];
				f[i]=max(f[i],fj+abs(s[i]-s[j]));
				f[j]=max(f[j],fi+abs(s[i]-s[j]));
			}
		printf("%lld\n",*max_element(f+1,f+n+1));
	}
}