#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

ll c[6],tmp[6]; 

int dx[6]={1,0,-1,-1,0,1};

int dy[6]={1,1,0,-1,-1,0};

int T;

ll x,y;

void cmin(ll &a,ll b)
{
	a=min(a,b);
}

ll solve(int a,int b,ll x,ll y)
{
	//m dx[a] + n dx[b] = x
	//m dy[a] + n dy[b] = y
	ll a1=dx[a],a2=dy[a];
	ll b1=dx[b],b2=dy[b];
	ll c1=x,c2=y;
	if(b1*a2-b2*a1==0)
	{
		if(c1*a2-c2*a1==0)
			return 0;
		return 2e18;
	}
	if((c1*a2-c2*a1)%(b1*a2-b2*a1)!=0)
		return 2e18;
	if((b1*c2-b2*c1)%(b1*a2-b2*a1)!=0)
		return 2e18;
	if((c1*a2-c2*a1)/(b1*a2-b2*a1)<0)
		return 2e18;
	if((b1*c2-b2*c1)/(b1*a2-b2*a1)<0)
		return 2e18;
	return c[b]*((c1*a2-c2*a1)/(b1*a2-b2*a1))+c[a]*((b1*c2-b2*c1)/(b1*a2-b2*a1));
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<6;i++)
			scanf("%lld",&c[i]);
		for(int i=0;i<6;i++)
			tmp[i]=c[(i+5)%6]+c[(i+1)%6];
		for(int i=0;i<6;i++)
			c[i]=min(c[i],tmp[i]);
		ll ans=2e18;
		for(int i=0;i<6;i++)
			cmin(ans,solve(i,(i+1)%6,x,y));
		printf("%lld\n",ans);
	}
}