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
const int maxn=2e5+5;
int n;
int ans;
int cnt[maxn];
int calc(int l,int r)
{
	int sum=cnt[r]-cnt[l-1];
	if(!sum)return 1;
	if(__builtin_popcount(sum)==1)return 0;
	return (1<<((int)ceil(log2(sum))))-sum;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();ans=1e9;
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[read()]++;
		for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		for(int i=0;i<=30;i++)
		{
			int pos0=upper_bound(cnt+1,cnt+n+1,1<<i)-cnt-1;
			for(int j=0;j<=30;j++)
			{
				int pos1=upper_bound(cnt+1,cnt+n+1,cnt[pos0]+(1<<j))-cnt-1;
				ans=min(ans,calc(1,pos0)+calc(pos0+1,pos1)+calc(pos1+1,n));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}