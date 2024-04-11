#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#define x first
#define y second
#define pb push_back
#define ll long long
using std::pair;
using std::vector;
typedef pair<int, int> vec;
const int N=1005;

inline ll cross(const vec &a, const vec &b) { return 1ll*a.x*b.y-1ll*b.x*a.y; }
vec operator +(const vec &a, const vec &b) { return {a.x+b.x, a.y+b.y}; }
vec operator -(const vec &a, const vec &b) { return {a.x-b.x, a.y-b.y}; }
ll operator *(const vec &a, const vec &b) { return cross(a, b); }

int n, col[N], ct[2], tp, tot, mn=0x3f3f3f3f, s;
vec p[N];
int stk[N], top, id[N];
inline void add(int x, int y)
{
	printf("%d %d\n", x-1, y-1);
}
void add(int a, int b, int c, vector<int> rw)
{
	vector<int> v;
	ll s=std::abs(p[a]*p[b]+p[b]*p[c]+p[c]*p[a]);
	for(int x:rw) if(std::abs((p[b]-p[a])*(p[x]-p[a]))+std::abs((p[c]-p[b])*(p[x]-p[b]))+
	std::abs((p[a]-p[c])*(p[x]-p[c])) ==s) v.pb(x);
//	printf("in %d %d %d\n", a, b, c);
//	for(int x:v) printf("%d ", x);
//	puts("");
	int co=col[a]^col[b]^col[c], id=(co^col[a]^1)*a+(co^col[b]^1)*b+(co^col[c]^1)*c;
	for(int x:v) if(col[x]==co)
	{
		add(x, id);
		v.erase(std::find(v.begin(), v.end(), x));
		add(a, b, x, v);
		add(b, c, x, v);
		add(c, a, x, v);
		return;
	}
	for(int x:v) add(x, col[x]==co?id:(col[a]==co?b:a));
}
inline int gnx(int x) { return x==top?1:x+1; }
vector<int> v;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d%d", &p[i].x, &p[i].y, col+i), ++ct[col[i]];
	if(!ct[0]||!ct[1])
	{
		printf("%d\n", n-1);
		for(int i=2; i<=n; ++i) add(1, i);
		return 0;
	}
	for(int i=1; i<=n; ++i)
	{
		id[i]=i;
		if(p[i].x<mn) mn=p[i].x, s=i;
	}
	std::swap(id[s], id[n]);
	std::sort(id+1, id+n, [] (int x, int y) { return (p[x]-p[s])*(p[y]-p[s])>0; } );
	stk[top=1]=s;
	for(int i=1; i<n; ++i)
	{
		int x=id[i];
		while(top>1&&(p[x]-p[stk[top-1]])*(p[stk[top]]-p[stk[top-1]])>0) v.pb(stk[top]), --top;
		stk[++top]=x;
	}
	for(int i=1; i<=top; ++i) tot+=col[stk[i]]!=col[stk[i==top?1:i+1]];
	if(tot>2) return puts("Impossible"), 0;
	printf("%d\n", n-2);
	stk[top+1]=stk[1];
	if(!tot)
	{
		for(int i=1; i<top; ++i) add(stk[i], stk[i+1]);
		for(int x:v) if(col[x]!=col[s])
		{
			v.erase(std::find(v.begin(), v.end(), x));
			for(int i=1; i<=top; ++i) add(stk[i], stk[i+1], x, v);
			break;
		}
	}
	else
	{
		for(int i=1; i<=top; ++i)
		{
			int u=stk[i], v=stk[i+1];
			if(col[u]==col[v]) add(u, v);
		}
//		for(int i=1; i<=top; ++i) printf("%d ", stk[i]);
//		puts("");
		int t=1;
		while(col[stk[t]]==col[stk[t+1]]) t=gnx(t);
		int t1=gnx(t);
		while(col[stk[t1]]==col[stk[t1+1]]) t1=gnx(t1);
		int x=gnx(t);
		while(x!=t1) add(stk[t], stk[x], stk[x+1], v), x=gnx(x);
		x=gnx(t1);
//		puts("ga");
		while(x!=t) add(stk[t1], stk[x], stk[x+1], v), x=gnx(x);
	}
	return 0;
}