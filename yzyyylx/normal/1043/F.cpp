#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 300100
#define MN 300000
#define M 998244353
using namespace std;

ll n,zs[N],miu[N],cnt[N],qc[N],jc[N],zz,g;
bool P[N];

inline void get()
{
	ll i,j,t;
	miu[1]=jc[0]=jc[1]=1;
	for(i=2;i<=MN;i++)
	{
		jc[i]=jc[i-1]*i%M;
		if(!P[i])
		{
			zs[++zz]=i;
			miu[i]=-1;
		}
		for(j=1;j<=zz;j++)
		{
			t=zs[j]*i;
			if(t>MN) break;
			P[t]=1;
			if(i%zs[j]) miu[t]=-miu[i];
			else
			{
				miu[t]=0;
				break;
			}
		}
	}
	for(i=1;i<=MN;i++) for(j=i;j<=MN;j+=i) qc[i]+=cnt[j];
}

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
	if(u<v) return 0;
	return jc[u]*po(jc[v],M-2)%M*po(jc[u-v],M-2)%M;
}

inline ll calc(ll u)
{
	ll i,res=0;
	for(i=1;i<=MN;i++)
	{
		res+=miu[i]*C(qc[i],u);
		res%=M;
	}
	return res;
}

int main()
{
	ll i,j,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		cnt[p]++;
	}
	get();
//	for(i=1;i<=10;i++) cout<<cnt[i]<<" ";
//	cout<<C(5,3)<<endl;
	for(i=1;i<=min(n,7ll);i++)
	{
		if(calc(i))
		{
			cout<<i;
			return 0;
		}
	}
	puts("-1");
}