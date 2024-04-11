#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int T,n,a[200020];
long long sum[200020],sum1[200020];
long long qsum(int l,int r){return sum[r]-sum[l-1];}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],sum1[i]=(i-2>=0?sum1[i-2]:0)+a[i];
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		long long ans=0,lastans=0;
		//c...c
		for(int i=1;i<n;++i)
			if(qsum(i+1,n-1)>a[n]+sum[i])
			{
				int l=0,r=n,mid;
				while(l<r)
				{
					mid=(l+r+1)>>1;
					if(i+2*mid<n-1&&sum[i]+a[n]+sum1[i+2*mid]-sum1[i]<qsum(i+1,n-1)-sum1[i+2*mid]+sum1[i])l=mid;
					else r=mid-1;
				}
				ans+=l+1;
			}
			else break;
		// printf("cc %lld\n",ans-lastans);lastans=ans;
		//c..p
		for(int i=1;i<n;++i)
			if(sum[i]<qsum(i+1,n))
			{
				int l=0,r=n,mid;
				while(l<r)
				{
					mid=(l+r+1)>>1;
					if(i+2*mid<n&&sum[i]+sum1[i+2*mid]-sum1[i]<qsum(i+1,n)-sum1[i+2*mid]+sum1[i])l=mid;
					else r=mid-1;
				}
				ans+=l+1;
			}
			else break;
		// printf("cp %lld\n",ans-lastans);lastans=ans;
		//p..c
		for(int i=1;i<n;++i)if(sum[i]>qsum(i+1,n))++ans;
		for(int i=2;i<n-1;++i)
			if(sum[i]-a[1]+a[n]<qsum(i+1,n-1)+a[1])
			{
				int l=0,r=n,mid;
				while(l<r)
				{
					mid=(l+r+1)>>1;
					if(i+2*mid<n-1&&sum[i]-a[1]+a[n]+sum1[i+2*mid]-sum1[i]<qsum(i+1,n-1)+a[1]-sum1[i+2*mid]+sum1[i])l=mid;
					else r=mid-1;
				}
				ans+=l+1;
			}
			else break;
		// printf("pc %lld\n",ans-lastans);lastans=ans;
		//p..p
		for(int i=2;i<n;++i)
			if(qsum(i+1,n)+a[1]>qsum(2,i))
			{
				int l=0,r=n,mid;
				while(l<r)
				{
					mid=(l+r+1)>>1;
					if(i+2*mid<n&&qsum(2,i)+sum1[i+2*mid]-sum1[i]<qsum(i+1,n)+a[1]-sum1[i+2*mid]+sum1[i])l=mid;
					else r=mid-1;
				}
				ans+=l+1;
			}
			else break;
		// printf("pp %lld\n",ans-lastans);lastans=ans;
		++ans;
		printf("%lld\n",ans%mod);
	}
	return 0;
}