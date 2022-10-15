#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=15;
int n,a[maxn];
int f[maxn+1][maxn+1][1<<maxn],sum[1<<maxn];
tuple<int,int,int>pre[maxn+1][maxn+1][1<<maxn];
int dif[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a,n=read(),read);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				memset(f[i][j],0x3f,sizeof(int)*(1<<n));
		f[0][0][0]=0;
		for(int i=0;i<(1<<n);i++)
		{
			sum[i]=0;
			for(int j=0;j<n;j++)
				if((i>>j)&1)sum[i]+=a[j];
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<(1<<n);k++)
				{
					if(f[i][j][k]==0x3f3f3f3f)continue;
					int all=((1<<n)-1)^k;
					for(int s=all;s;s=(s-1)&all)
						if((s>>j)&&sum[s]>f[i][j][k]&&f[i+1][__builtin_ctz(s>>j)+j][k|s]>sum[s])
						{
							f[i+1][__builtin_ctz(s>>j)+j][k|s]=sum[s];
							pre[i+1][__builtin_ctz(s>>j)+j][k|s]=make_tuple(i,j,k);
						}
				}
		tuple<int,int,int>ans=make_tuple(0,0,0);
		for(int i=n;i>=1;i--)
		{
			for(int j=0;j<=n;j++)
				if(f[i][j][(1<<n)-1]!=0x3f3f3f3f){ans=make_tuple(i,j,(1<<n)-1);break;}
			if(get<2>(ans))break;
		}
		for(int i=1;i<=n;i++)dif[i]=0;
		printf("%d\n",n-get<0>(ans));
		while(get<0>(ans))
		{
			int S=get<2>(ans)^get<2>(pre[get<0>(ans)][get<1>(ans)][get<2>(ans)]);
			for(int i=0;i<n;i++)
				if(((S>>i)&1)&&i!=get<1>(ans))
				{
					printf("%d %d\n",i+1-dif[i+1],get<1>(ans)+1-dif[get<1>(ans)+1]);
					for(int j=i+1;j<=n;j++)dif[j]++;
				}
			ans=pre[get<0>(ans)][get<1>(ans)][get<2>(ans)];
		}
	}
	return 0;
}