#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 200000
#define N 200100
#define M 
using namespace std;
 
ll T,n,m,ans,tt,num[N],gg[N],qz[N],cc[N];
char str[N];
 
inline ll work(ll u,ll v,ll w){return cc[u]+cc[v]+cc[w];}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j,k,t,l,r,mid;
	for(j=0,i=1;j<=MN;j++)
	{
		if(j>i) i<<=1;
		cc[j]=i-j;
	}
//	for(i=1;i<=15;i++) cout<<cc[i]<<" ";return 0;
	cin>>T;
	while(T--)
	{
		for(i=1;i<=tt;i++) gg[i]=0;
		tt=0,ans=INF;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]);
		sort(num+1,num+n+1);
		for(i=1;i<=n;i++)
		{
			if(num[i]!=num[i-1]) tt++;
			gg[tt]++;
		}
//		for(i=1;i<=tt;i++) cout<<gg[i]<<" ";puts("");
		for(i=1;i<=tt;i++) qz[i]=qz[i-1]+gg[i];
		for(i=1;i<=tt;i++)
		{
			for(j=1;j<=(n<<1);j<<=1)
			{
				for(l=i,r=tt+1;l<r;)
				{
					mid=((l+r)>>1);
					if(qz[mid]-qz[i-1]<=j) l=mid+1;
					else r=mid;
				}
//				cout<<i<<" "<<j<<" "<<l<<" "<<work(qz[i-1],qz[l-1]-qz[i-1],n-qz[l-1])<<endl;
				Min(ans,work(qz[i-1],qz[l-1]-qz[i-1],n-qz[l-1]));
			}
		}
		printf("%lld\n",ans);
	}
}