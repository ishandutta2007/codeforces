#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 300100
#define M
using namespace std;

ll n,m,k,t,a,b,num[N],qz[N],pos[N],cnt,ans,ji[N],ou[N];

inline ll ct(ll u)
{
	ll res=0;
	for(; u; u>>=1)
	{
		res+=u&1;
	}
	return res;
}

int main()
{
	ll i,j,p,q,l,r;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		scanf("%lld",&p);
		num[i]=ct(p);
		qz[i]=qz[i-1]+num[i];
	}
	
	//*
	for(i=2; i<=200; i+=2)
	{
		cnt=0;
		for(l=r=1; r<=n; r++)
		{
			cnt+=(num[r]>i/2);
			for(;l<r && qz[r]-qz[l-1]>i; l++) cnt-=(num[l]>i/2);
			if(!cnt&&qz[r]-qz[l-1]==i) ans++;
		}
	}
	//*/
	
	ou[0]=1;
	for(l=r=1; r<=n; r++)
	{
		if(qz[r]&1) ji[r]=ji[r-1]+1,ou[r]=ou[r-1];
		else ji[r]=ji[r-1],ou[r]=ou[r-1]+1;
		for(;l<r && qz[r]-qz[l-1]>200; l++);
		if(l>1)
		{
			if(qz[r]&1) ans+=ji[l-2];
			else ans+=ou[l-2];
		}
	}
	cout<<ans;
}