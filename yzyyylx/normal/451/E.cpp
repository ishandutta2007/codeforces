#include<iostream>
#include<cstdio>
#define ll long long
#define N 30
#define M 1000000007
using namespace std;

ll n,m,sum,cnt,ans,num[N],inv[N];

inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		u=u*u%M;
		v>>=1;
	}
	return res;
}

inline ll C(ll u,ll v)
{
	if(u<=0) return 0;
	ll i,res=1;
	for(i=u;i>u-v;i--) res=res*(i%M)%M;
	for(i=1;i<=v;i++) res=res*inv[i]%M;
	return res;
}

int main()
{
	ll i,j,t;
	cin>>n>>m;
	if(!m)
	{
		puts("1");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
		inv[i]=po(i,M-2);
	}
	if(sum<m)
	{
		puts("0");
		return 0;
	}
	for(i=0;i<(1 << n);i++)
	{
		sum=cnt=0;
		for(j=1;j<=n;j++)
		{
			if((1 << (j-1))&i)
				sum+=num[j]+1,cnt++;
		}
		t=C(n+m-1-sum,n-1);
		if(cnt&1) ans-=t;
		else ans+=t;
		ans%=M;
	}
	cout<<(ans+M)%M;
}