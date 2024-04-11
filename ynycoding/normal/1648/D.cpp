#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f
using std::pair;
using std::vector;
const int N=500005;
int n, q, ql[N], qr[N], w[N];
ll a[3][N], valx[N], valy[N], ans=-INF;
int pos[N], top;
ll val[N], f[N];
vector<int> eid[N];
void solve(int l, int r, vector<int> vq)
{
	ll mn=INF;
	for(int x:vq) if(ql[x]<=l&&qr[x]>=r) mn=std::min(mn, 1ll*w[x]);
	ll mx=-INF;
	for(int i=l; i<=r; ++i)
	{
		mx=std::max(mx, valx[i]);
//		printf("fa %d %lld\n", i, valx[i]+valy[i]+mx-mn);
		ans=std::max(ans, valy[i]+mx-mn);
	}
	if(l==r) return;
	for(int i=l-1; i<=r+1; ++i) eid[i].clear();
	int mid=(l+r)>>1;
	for(int v:vq) if(ql[v]>l||qr[v]<r)
	{
//		if(qr[v]<=mid) 
		if(ql[v]<=mid) eid[std::min(mid, qr[v])].pb(v);
//		if(ql[v]>mid) 
		if(qr[v]>mid) eid[std::max(ql[v], mid+1)].pb(v);
	}
	top=0;
	for(int i=l-1; i<=mid; ++i)
	{
		ll rv=(i==mid?-INF:valx[i+1]);
		if(top)
		{
			for(int v:eid[i])
			{
				int t=std::lower_bound(pos+1, pos+top+1, ql[v]-1)-pos;
				rv=std::max(rv, val[t]-w[v]);
			}
		}
		while(top&&val[top]<=rv) --top;
		val[++top]=rv;
		pos[top]=i;
		f[i]=rv;
	}
	for(int i=mid-1; i>=l-1; --i) f[i]=std::max(f[i], f[i+1]);
	top=0;
	for(int i=r+1; i>mid; --i)
	{
		ll rv=(i==mid+1?-INF:valy[i-1]);
		if(top)
		{
			for(int v:eid[i])
			{
				int t=std::lower_bound(pos+1, pos+top+1, qr[v]+1, std::greater<int>())-pos;
				rv=std::max(rv, val[t]-w[v]);
			}
		}
		while(top&&val[top]<=rv) --top;
		val[++top]=rv;
		pos[top]=i;
		f[i]=rv;
	}
	for(int i=mid+2; i<=r+1; ++i) f[i]=std::max(f[i], f[i-1]);
	ans=std::max(ans, f[mid]+f[mid+1]);
	vector<int> vl, vr;
	for(int x:vq)
	{
		if(ql[x]<=mid&&qr[x]>mid) ans=std::max(ans, f[std::max(l, ql[x])-1]+f[std::min(r, qr[x])+1]-w[x]);
		if(ql[x]<=l&&qr[x]>=r) continue;
//		printf("ins %d\n", x);
		if(ql[x]<=mid) vl.pb(x);
		if(qr[x]>mid) vr.pb(x);
	}
	solve(l, mid, vl);
	solve(mid+1, r, vr);
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int t:{0, 1, 2}) for(int i=1; i<=n; ++i) scanf("%lld", a[t]+i), a[t][i]+=a[t][i-1];
	for(int i=1; i<=n; ++i)
	{
		valx[i]=a[0][i]-a[1][i-1];
		valy[i]=a[2][n]-a[2][i-1]+a[1][i];
	}
	vector<int> qid;
	for(int i=1; i<=q; ++i) scanf("%d%d%d", ql+i, qr+i, w+i), qid.pb(i);
	solve(1, n, qid);
	printf("%lld\n", ans);
	return 0;
}