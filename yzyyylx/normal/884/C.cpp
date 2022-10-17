#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;

ll fa[N],n,pos[N],cnt[N],ans;

ll get(ll u)
{
	return u==fa[u]?u:fa[u]=get(fa[u]),fa[u];
}

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&pos[i]);
		fa[get(i)]=get(pos[i]);
	}
	for(i=1;i<=n;i++)
	{
		cnt[get(i)]++;
	}
	sort(cnt+1,cnt+n+1);
	ans=(cnt[n]+cnt[n-1])*(cnt[n]+cnt[n-1]);
	for(i=n-2;i>=1;i--)
	{
		ans+=cnt[i]*cnt[i];
	}
	printf("%lld",ans);
}