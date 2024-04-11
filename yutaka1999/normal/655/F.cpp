#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define MX 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll inv[SIZE],fac[SIZE],finv[SIZE];
int cnt[MX],nm[MX];
ll kt[MX];
int k;
ll ans;

void init()
{
	inv[1]=1;
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
	for(int i=1;i<MX;i++)
	{
		kt[i]+=i;
		if(kt[i]>=MOD) kt[i]-=MOD;
		for(int j=2*i;j<MX;j+=i)
		{
			kt[j]-=kt[i];
			if(kt[j]<0) kt[j]+=MOD;
		}
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
ll get(int v)
{
	return C(cnt[v],k)*(ll) kt[v]%MOD;
}
void add(int n)
{
	int sz=0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans-=get(i);
			if(ans<0) ans+=MOD;
			cnt[i]++;
			ans+=get(i);
			if(ans>=MOD) ans-=MOD;
			if(i!=n/i)
			{
				ans-=get(n/i);
				if(ans<0) ans+=MOD;
				cnt[n/i]++;
				ans+=get(n/i);
				if(ans>=MOD) ans-=MOD;
			}
		}
	}
	//printf("%lld\n",ans);
	//for(int i=1;i<=6;i++) printf("%lld ",get(i));puts("");
}
int main()
{
	init();
	int n,q;
	scanf("%d %d %d",&n,&k,&q);
	for(int i=0;i<n+q;i++)
	{
		int x;
		scanf("%d",&x);
		add(x);
		if(i>=n) printf("%lld\n",ans);
	}
	return 0;
}