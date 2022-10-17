#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MAXM (ll)1e13
#define BJ 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

ll n,m,a,b=1,c,can[BJ*10],cc,M,tmp[BJ*10],ans=INF,XH;
inline ll cheng(ll u,ll v)
{
	ll res=0;
	for(;v;v>>=1)
	{
		if(v&1) res=(res+u)%M;
		u=u*2%M;
	}
	return res;
}
struct Jz
{
	ll num[2][2];
	Jz()
	{
		memset(num,0,sizeof(num));
	}
	Jz operator * (const Jz &u) const
	{
		Jz res;
		ll i,j,k;
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				for(k=0;k<2;k++)
				{
//					cout<<num[i][k]<<" "<<u.num[k][j]<<endl;
					res.num[i][j]=(res.num[i][j]+cheng(num[i][k],u.num[k][j]))%M;
				}
			}
		}
		return res;
	}
}dw;

inline Jz po(Jz u,ll v)
{
	Jz res;
	res.num[0][0]=res.num[1][1]=1;
	for(;v;)
	{
		if(v&1) res=res*u;
		u=u*u;
		v>>=1;
	}
	return res;
}

inline ll ask(ll u)
{
	Jz res=po(dw,u);
	return res.num[0][0];
}

int main()
{
	dw.num[0][1]=dw.num[1][0]=dw.num[1][1]=1;
	ll i,j,k,t;
//	M=1000;cout<<ask(2);
	cin>>n;
	t=n%BJ;
	for(i=1;;i++)
	{
		if(t==a) can[++cc]=i;
		c=(a+b)%BJ;
		a=b,b=c;
		if(!a&&b==1) break;
	}
	for(M=BJ*10,XH=150000;M<=MAXM;M*=10,XH*=10)
	{
//		cout<<M<<" "<<XH<<endl;
		t=n%M,k=0;
		for(i=1;i<=cc;i++)
		{
			for(j=0;j<=9;j++)
			{
				if(ask(can[i]+XH*j)%M==t)
				{
					tmp[++k]=can[i]+XH*j;
				}
			}
		}
		for(i=1;i<=k;i++) can[i]=tmp[i];
		cc=k;
//		for(i=1;i<=cc;i++) cout<<can[i]<<" ";puts("");
	}
	if(!cc)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=cc;i++) ans=min(ans,can[i]);
	cout<<ans-1;
}