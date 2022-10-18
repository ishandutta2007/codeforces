#include <cstdio>
#include <random>
#include <map>
#include <vector>
#include <ctime>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <unordered_map>
#define ull unsigned long long
#define pb push_back
using namespace __gnu_pbds;
using __gnu_pbds::gp_hash_table;
using std::vector;
using std::unordered_map;
using std::map;
std::mt19937_64 rnd(114);
const int N=100005, M=5;

namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[20];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;

int n, m, a[N][M], val[N], id[N], rid[N], ans=0x7f7f7f7f, tp;
int cx, rsz[1<<M];
ull qr[1<<M];
map<int, ull> mp;
void dfs(int u, ull cur, int sz)
{
	if(u==m)
	{
		rsz[tp]=sz;
		qr[tp++]=cur;
//		printf("cur %d %llu %d\n", cx, cur, sz);
		return;
	}
	dfs(u+1, cur, sz);
	dfs(u+1, cur^a[cx][u], sz^1);
}
gp_hash_table<ull, int> cnt;
inline void ins(int x, int v)
{
	tp=0;
	cx=x;
	dfs(0, 0, 0);
	for(int i=0; i<tp; ++i) cnt[qr[i]]+=(rsz[i]?-v:v);
}
bool chk(int u)
{
	tp=0, cx=u;
	dfs(0, 0, 0);
	int ret=0;
	for(int i=0; i<tp; ++i) ret+=cnt[qr[i]];//, printf("fuck %d\n", cnt[u][qr[i]]);
//	printf("ret %d %d\n", u, ret);
	return ret>0;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<m; ++j) scan(a[i][j]), mp[a[i][j]]=rnd();
		scan(val[i]);
		std::sort(a[i], a[i]+m);
		for(int j=1; j<m; ++j) if(a[i][j]==a[i][j-1])
		{
			--i, --n;
			break;
		}
		id[i]=i;
	}
	for(int i=1; i<=n; ++i) for(int j=0; j<m; ++j) a[i][j]=mp[a[i][j]];
	std::sort(id+1, id+n+1, [] (int x, int y) { return val[x]<val[y]; } );
	for(int i=1; i<=n; ++i) ins(i, 1);
	for(int i=1, r=n; i<=n; ++i)
	{
		int u=id[i];
		int is=0;
		while(chk(u)) is=1, ins(id[r], -1), --r;
		if(is&&r<n) ans=std::min(ans, val[u]+val[id[r+1]]);
	}
	printf("%d\n", ans==0x7f7f7f7f?-1:ans);
	return 0;
}