#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,a,b,c,d,l,r,mid,k,m,ct;
ll calc2(ll x,ll y,ll lim)
{
	return lim*x+lim*(lim-1)/2*y;
}
ll calc(ll x,ll y,ll lim)
{
	ll cnt=x/y+1;
	return calc2(x,-y,min(lim,cnt));
}
ll solve(ll x,ll num)
{
	ll ans=(num+1)*a;
	ll cnt=1+(c-1)/d;
	//printf("%lld %lld\n",ans,cnt);
	ans-=max(0ll,num+1-cnt)*b*c;
	ans-=b*calc2(0,d,min(num,(c-1)/d)+1);
	//printf("%lld %lld %lld\n",d,min(num,(c-1)/d),calc2(0,d,min(num,(c-1)/d)));
	return ans;
}
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(b*c<a)
		{
			printf("-1\n");
			continue;
		}
		if(d>c||b*d>=a)
		{
			printf("%lld\n",a);
			continue;
		}
		l=1;r=2000000000;
		while(l<r)
		{
			mid=(l+r)/2;
			k=d;
			ll cnt0=(c-d)/d+1;
			ll sum=min(mid,cnt0)*d;
			ll u=c-d*((c-d)/d+1);
			if(u>0)sum+=calc(u,d,mid-min(mid,cnt0));
			if(sum*b>=a)r=mid;
			else l=mid+1;
		}
		//printf("%lld\n",l);
		if(l>=2000000000)
		{
			printf("-1\n");
			continue;
		}
		l--;
		ct=l*d+1;
		printf("%lld\n",solve(ct,l));
	}
	return 0;
}