#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 300100
using namespace std;

ll n,a,b,lea,mx[N],pos[N];
P num[N];

int main()
{
	ll i,j,k;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i].fi);
		num[i].se=i;
	}
	sort(num+1,num+n+1);
	for(i=n;i>=1;i--)
	{
		if((n-i+1)*num[i].fi>=b) break;
	}
	lea=i;
	for(i=1;i<=n;i++)
	{
		k=(n-i+1)-(b+num[i].fi-1)/num[i].fi;
		if(k>mx[i-1])
		{
			mx[i]=k;
			pos[i]=i;
		}
		else mx[i]=mx[i-1],pos[i]=pos[i-1];
	}
	for(i=n;i>=1;i--)
	{
		if((a+num[i].fi-1)/num[i].fi>(n-i+1)) continue;
		k=(a+num[i].fi-1)/num[i].fi+i-1;
		if(k<lea)
		{
			puts("Yes");
			printf("%lld %lld\n",k-i+1,n-lea+1);
			for(j=i;j<=k;j++) printf("%lld ",num[j].se);puts("");
			for(j=lea;j<=n;j++) printf("%lld ",num[j].se);
			return 0;
		}
		if(mx[i-1]>=k-i+1)
		{
			puts("Yes");
			printf("%lld %lld\n",k-i+1,n-pos[i]+1-(k-i+1));
			for(j=i;j<=k;j++) printf("%lld ",num[j].se);puts("");
			for(j=pos[i-1];j<=n;j++) if(j<i||j>k) printf("%lld ",num[j].se);
			return 0;
		}
	}
	puts("No");
}