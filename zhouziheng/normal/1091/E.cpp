#include<cstdio>
#include<algorithm>

using namespace std;

int d[1000000];long long sum[1000000];int cnt[1000000];
int n=0;

long long calc(int p,int x)// \sum_{i=p}^n \min (d_i,x)
{
	if(p>n)return 0;
	int l=p-1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;if(d[mid]>=x)l=mid;else r=mid-1;
	}
	return (long long)(l-p+1)*x+sum[n]-sum[l];
}

long long ans[1000000];int c=0;
void add(long long l,long long r)
{
	if(r>=n)c++;
	if(l>r||r<0||l>n)return;
	if(l<0)l=0;if(r>n)r=n;
	ans[l]++,ans[r+1]--;
}



int main()
{
	//freopen("dat.in","r",stdin);
	//freopen("dat.out","w",stdout);
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&d[i]),cnt[d[i]]++;
	sort(d+1,d+n+1);reverse(d+1,d+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+d[i];
	for(int i=1;i<=n;i++)
	{
		//printf("%d:\n",i);
		long long x=calc(i,i);
		add(d[i],x+(long long)i*(i-1)-sum[i-1]);
		//printf("A: %lld %lld\n",d[i],x+(long long)i*(i-1)-sum[i-1]);
		x=calc(i+1,i);
		if(i<d[i])
		{
			if(sum[i]<=(long long)i*(i-1)+x+i)add(i,d[i]-1);//printf("B: %lld %lld\n",i,d[i]-1);
			add(sum[i]-(long long)i*(i-1)-x,i-1);//printf("C: %lld %lld\n",(long long)i*(i-1)+x-sum[i],i-1);
		}
		else
		{
			add(sum[i]-(long long)i*(i-1)-x,d[i]-1);//printf("D: %lld %lld\n",(long long)i*(i-1)+x-sum[i],d[i]-1);
		}
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
	bool fl=0;
	
	for(int i=0;i<=n;i++)
	{
		if(ans[i]==n&&(i+sum[n])%2==0)printf("%d ",i),fl=1;
	}
	if(fl==0)puts("-1");
}