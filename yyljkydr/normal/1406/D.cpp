#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int n,a[N],d[N],nows;

int q;

int solve()
{
	if(a[1]+nows<0)
		return (a[1]+nows)/2;
	else
		return (a[1]+nows+1)/2;
}

void del(int x)
{
	if(x<1||x>n-1)
		return;
	if(d[x]>0)
		nows-=d[x];
}

void ins(int x)
{
	if(x<1||x>n-1)
		return;
	if(d[x]>0)
		nows+=d[x];
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
		d[i]=a[i+1]-a[i],nows+=(d[i]>0)*d[i];
	printf("%lld\n",solve());
	scanf("%lld",&q);
	while(q--)
	{
		int l,r,x;
		scanf("%lld%lld%lld",&l,&r,&x);
		if(l==1)
			a[1]+=x;
		del(l-1);
		del(r);
		d[l-1]+=x;
		d[r]-=x;
		ins(l-1);
		ins(r);
		printf("%lld\n",solve());
	}
}