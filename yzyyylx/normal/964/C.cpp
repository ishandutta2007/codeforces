#include<iostream>
#include<cstdio>
#define ll long long
#define db double
#define N 100100
#define M 1000000009
using namespace std;

ll n,m,a,b,k,kk,t,len,num[N];
char str[N];

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

ll ask(ll u)
{
	if(u<=1) return u;
	if(u&1)
		return (ask(u-1)+po(k,u-1))%M;
	return ask(u/2)*(1+po(k,u/2))%M;
}

int main()
{
	ll i,j,tmp;
	cin>>n>>a>>b>>len;
	scanf("%s",str+1);
	for(i=1;i<=len;i++)
	{
		num[i]=(str[i]=='+'?1:-1);
	}
	k=b*po(a,M-2)%M;
//	cout<<k<<' ';
	for(i=0;i<len;i++)
	{
		t=(t+po(k,i)*num[i+1]+M)%M;
	}
	k=po(k,len);
	cout<<ask((n+1)/len)*t%M*po(a,n)%M;
}