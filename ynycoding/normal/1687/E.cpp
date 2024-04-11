#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=1000005;
int n, a[N], p[N], mn[N], mn1[N], id[N], id1[N], rid[N];
int is[N], pr[N], top, fac[N], in[N];
vector<int> res, v;
void init(int n)
{
	for(int i=2; i<=n; ++i)
	{
		if(!is[i]) pr[++top]=i, fac[i]=i;
		for(int j=1; j<=top&&i*pr[j]<=n; ++j)
		{
			is[i*pr[j]]=1;
			fac[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
int main()
{
	init(1000000);
	for(int i=1; i<=top; ++i)
	{
		int x=pr[i];
		res.pb(x);
		mn[x]=0x3f3f3f3f, mn1[x]=0x3f3f3f3f;
	}
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), rid[i]=i;
	std::sort(rid+1, rid+n+1, [] (int x, int y) { return a[x]<a[y]; } );
	std::sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i)
	{
		// printf("in %d\n", a[i]);
		int x=a[i];
		vector<int> rfac;
		while(x>1)
		{
			int v=fac[x];
			rfac.pb(v);
			while(x%v==0) x/=v, ++p[v];
			// printf("p %d %d\n", v, p[v]);
		}
		// puts("");
		vector<int> nrs;
		for(int x:res)
		{
			if(mn[x]>p[x])
			{
				mn1[x]=mn[x], id1[x]=id[x];
				mn[x]=p[x], id[x]=i;
			}
			else if(mn1[x]>p[x])
			{
				mn1[x]=p[x], id1[x]=i;
			}
			if(!mn1[x]&&id1[x]==i&&!in[i])
			{
				v.pb(i);
				in[i]=1;
				if(!in[id[x]]) v.pb(id[x]), in[id[x]]=1;
			}
			if(mn1[x]) nrs.pb(x);
		}
		for(int x:rfac) p[x]=0;
		res=nrs;
	}
	for(int x:res)
	{
		// printf("ha %d %d %d %d %d\n", x, mn[x], mn1[x], id[x], id1[x]);
		if(!in[id[x]]) v.pb(id[x]), in[id[x]]=1;
		if(!in[id1[x]]) v.pb(id1[x]), in[id1[x]]=1;
	}
	n=v.size();
	std::sort(v.begin(), v.end(), [] (int x, int y) { return rid[x]<rid[y]; } );
	// puts("v");
	// for(int x:v) printf("%d ", x);
	// puts("");
	int tot=0;
	for(int s=1; s<(1<<n); ++s)
		tot+=std::abs((__builtin_parity(s)?1:-1)*(1-(__builtin_popcount(s)-1)));
	printf("%d\n", tot);
	for(int s=1; s<(1<<n); ++s)
	{
		int v=(__builtin_parity(s)?1:-1)*(1-(__builtin_popcount(s)-1));
		int t=v<0;
		if(t) v=-v;
		while(v--)
		{
			printf("%d %d ", t, __builtin_popcount(s));
			for(int i=0; i<n; ++i) if(s&(1<<i)) printf("%d ", rid[::v[i]]);
			puts("");
		}
	}
	return 0;
}