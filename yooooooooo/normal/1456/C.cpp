#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,m,c,al,sum0=0,sum[500005],a[500005],dpk[500005],dpk2[500005],ans;
ll b[500005],sum3[500005];
const ll inf=1e18;
ll ask(ll x,ll y){return sum[y]-sum[x-1];}
ll ask2(ll x,ll y){return sum3[x]+y*sum[x];}
ll asksim(ll x,ll y,ll z){return ask(x-y+1,x)*(z+1);}
ll askk(ll x,ll y,ll z)
{
	ll ans=dpk[x]-dpk[x-y*k]-y*sum[x-y*k];
	return ans+z*ask(x-y*k+1,x);
}
ll askk2(ll x,ll y,ll z)
{
	ll ans=dpk2[x]-dpk2[x-y*(k+1)]-y*sum[x-y*(k+1)];
	return ans+z*ask(x-y*(k+1)+1,x);
}
bool cmp(ll a,ll b){return a>b;}
int main()
{
	ans=-inf;
	scanf("%lld%lld",&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]),sum0+=a[i];
	sort(a+1,a+m+1,cmp);
	if(k==0)
	{
		ans=0;
		for(int i=1;i<=m;i++)ans+=1ll*i*a[m+1-i];
		printf("%lld\n",ans-sum0);
		return 0;
	}
	c=al=0;
	int i;
	for(i=1;a[i]>=0&&i<=m;i++)
	{
		c=c+al+a[i];
		al+=a[i];
	}
	n=m-i+1;
	if(n==0)
	{
		printf("%lld\n",c-sum0);
		return 0;
	}
	for(int i=1;i<=n;i++)b[i]=a[m-n+i],sum[i]=sum[i-1]+b[i];
	//0?
	for(int i=1;i<=min(n,k);i++)dpk[i]=sum[i];
	for(int i=min(n,k)+1;i<=n;i++)dpk[i]=dpk[i-k]+sum[i];
	for(int i=1;i<=min(n,k+1);i++)dpk2[i]=sum[i];
	for(int i=min(n,k+1)+1;i<=n;i++)dpk2[i]=dpk2[i-k-1]+sum[i];
	for(int i=1;i<=n;i++)sum3[i]=sum3[i-1]+sum[i];
	for(int i=0;i<=n;i++)
	{
		ll res=n-i;
		ll x=res/k,y=res%k;
		if(i<=x)
		{
			ll tmp=askk2(n,i,0)+askk(n-i*(k+1),x-i,i)+asksim(n-i-x*k,y,x);
			ans=max(ans,tmp+c+al*i);	
		}
		else
		{
			ll tmp=askk2(n,x,0)+asksim(n-x*(k+1),y+1,x)+ask2(n-x*(k+1)-y-1,x+1);
			ans=max(ans,tmp+c+al*i);
		}
	}
	printf("%lld\n",ans-sum0);
	return 0;
}