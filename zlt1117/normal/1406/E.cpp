#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define int long long
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define int long long
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int n,k;
bool prime[maxn];
vector<int>v;
bool d[maxn];
inline int A(int x)
{
	int ret=0;
//	if(x>n){printf("WA [1]\n");exit(0);}
	printf("A %lld\n",x);
	fflush(stdout);
	ret=gi();
//	for(int i=x;i<=n;i+=x)
//	{
//		if(d[i]==1)ret++;
//	}
	return ret;
}
inline int B(int x)
{
	int ret=0;
//	if(x>n){printf("WA [2]\n");exit(0);}
	printf("B %lld\n",x);
	fflush(stdout);
	ret=gi();
//	for(int i=x;i<=n;i+=x)
//	{
//		if(d[i]==1)ret++;
//		if(i!=k)d[i]=0;
//	}
	return ret;
}
inline void C(int x)
{
//	if(x==k)printf("AC %d\n",x);
//	else printf("WA %d\n",x);
	printf("C %lld\n",x);
	fflush(stdout);
}
signed main()
{
	n=gi();
	//cin>>n>>k;
	FOR(i,1,n)d[i]=1;
	FOR(i,2,n)
	{
		if(!prime[i])
		{
			v.push_back(i);
			for(ll j=i;i*j<=1LL*n;++j)prime[i*j]=true;
		}
	}
	int ans=1;
	if(n<=100)
	{
		FOR(i,0,(int)(v.size())-1)
		{
			ll x=v[i];
			int cnt1=B(x);
			cnt1=A(x);
			if(cnt1==1)
			{
				int cnt=1;
				while(x<=1LL*n)x*=v[i],cnt++;
				cnt--;
				int l=1,r=cnt,nowans=0;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					ll ret=1;
					FOR(j,1,mid)ret*=v[i];
					int now=A(ret);
					if(now==1)nowans=mid,l=mid+1;
					else r=mid-1;
				}
				FOR(j,1,nowans)ans*=v[i];
			}
		}
		C(ans);
		return 0;
	}
	int tot=(int)v.size()-1;
	FOR(i,0,tot)
	{
		if(v[i]<=(int)sqrt(n))B(v[i]);
		else break;
		if(A(v[i])==1)
		{
			int now=v[i];
			while(now<=n)
			{
				if(now*v[i]<=n)
				{
					if(A(now*v[i])==1)now*=v[i];
					else break;
				}
				else break;
			}
			ans*=now;
		}
	}
	if(ans!=1)
	{
		FOR(i,0,tot)
		{
			if(v[i]>(int)sqrt(n))
			{
				int x=A(v[i]);
				if(x==2)
				{
					C(ans*v[i]);
					return 0;
				}
			}
		}
	}
	else
	{
		int block=sqrt(tot)+1;
		int now=A(1);
		int st=0;
		while(v[st]<=(int)(sqrt(n)))st++;
		for(int i=st;i<=tot;i+=block)
		{
			int cnt=min(block,tot-i+1);
			for(int j=i;j<=i+block-1&&j<=tot;++j)B(v[j]);
			int x=A(1);
			if(now-x!=cnt)
			{
				for(int j=i;j<=i+block-1&&j<=tot;++j)
				{
					if(A(v[j])==1)
					{
						C(v[j]);
						break;
					}
				}
				return 0;
			}
			now=x;
		}
	}
	C(ans);
	return 0;
}