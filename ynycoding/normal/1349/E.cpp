#include <cstdio>
#include <algorithm>
#define ll long long
const int N=200005;
int n, tp, c[N];
ll t[N];
int f[N][2], tr[N][2], rt[N];
int cl[N], cr[N], top;
namespace SUB1{
	ll f[N];
	int pr[N];
	void solve(void)
	{
		for(int i=1; i<=n; ++i) pr[i]=c[i]?i:pr[i-1];
		if(!pr[n]) std::fill(t+1, t+n+1, 1);
		else
		{
			for(int i=n; i; --i) f[i]=f[i+1]+(c[i]?i:0);
			for(int i=1; i<=n; ++i) t[i]=pr[i]?((pr[i]!=i)+f[pr[i]]):f[i]+1;
		}
		for(int i=1; i<=n; ++i) printf("%lld ", t[i]);
		puts("");
	}
}
inline ll calc(int x) { return 1ll*x*(x+1)/2; }
bool chk(int cl, int cr, ll v)
{
	int l=0, r=cr-cl+1;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(calc(cl+mid-1)-calc(cl-1)>v) r=mid-1;
		else l=mid;
	}
	return calc(cr)-calc(cr-l)>=v;
}
void find(int cl, int cr, ll v)
{
	if(!v) return;
//	printf("find %d %d %d\n", cl, cr, v);
	if(cl<cr&&chk(cl+1, cr, v)) find(cl+1, cr, v);
	else c[cl]=1, find(cl+1, cr, v-cl);
}
int main()
{
	scanf("%d*d", &n);
	if(tp==1)
	{
		for(int i=1; i<=n; ++i) scanf("%d", c+i);
		SUB1::solve();
		return 0;
	}
	for(int i=1; i<=n; ++i) scanf("%lld", t+i);
	std::reverse(t+1, t+n+1);
	int pr=0;
	for(int i=1; i<=n; ++i) if(t[i])
	{
		if(!pr||t[i]<t[pr])
		{
			cr[top]=pr;
			cl[++top]=i;
		}
		pr=i;
	}
	cr[0]=-1;
	cr[top]=pr;
	if(!pr) { for(int i=1; i<=n; ++i) printf("%d", 0); return 0; }
	cl[top+1]=n+1;
	f[top+1][1]=n+1, f[top+1][0]=-0x3f3f3f3f;
	for(int i=top; i; --i)
	{
		int l=cl[i], r=cr[i];
		f[i][0]=f[i][1]=-0x3f3f3f3f;
		for(int x:{0, 1})
		{
			if(x==1&&l<r&&t[l]==t[r]) continue;
			if(x==0&&t[l]!=t[r]) continue;
			for(int y:{0, 1}) if(f[i+1][y]>=r)
			{
				ll dt=t[l]-(x^1)+(y^1)-t[cl[i+1]];
				int v=x?l:(i==1?r:l), lim=x?l:cr[i-1]+1;
				v=std::min(1ll*v, dt);
				while(v>=lim&&(!chk(r+1, std::min(f[i+1][y], cl[i+1])-1, dt-v)||(!x&&t[v]))) --v;
				if(v>=lim&&v>=f[i][x])
				{
					tr[i][x]=y;
					f[i][x]=v;
				}
			}
		}
	}
	int x=f[1][0]>=0?0:1;
	for(int i=1; i<=top; ++i)
	{
		int l=cl[i], r=cr[i];
		int y=tr[i][x];
		ll dt=t[l]-(x^1)+(y^1)-t[cl[i+1]];
		c[f[i][x]]=1;
		find(r+1, std::min(f[i+1][y], cl[i+1])-1, dt-f[i][x]);
		x=y;
	}
	std::reverse(c+1, c+n+1);
	for(int i=1; i<=n; ++i) printf("%d", c[i]);
	return 0;
}