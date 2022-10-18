#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
#define N 200005
using std::vector;
using std::queue;
int T, n, m, ok[N], deg[N], top;
int e[N][2];
int q[N], *hd=q, *tl=q;
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
		static char s[15];
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
void bfs(void)
{
	for(int i=1; i<=n; ++i) if(!deg[i]) *(++tl)=i, ok[i]=1;
	while(hd<tl)
	{
		int u=*(++hd);
		for(int i=0; i<2&&e[u][i]; ++i)
		{
			int v=e[u][i];
			--deg[v];
			deg[v]?0:(*++tl)=v;
			(ok[u]!=-1&&ok[v]!=-1)?ok[v]=ok[u]==2?-1:2:0;
		}
	}
}
int main()
{
	scan(T);
	while(T--)
	{
		hd=q, tl=q;
		scan(n), scan(m);
		for(int i=1; i<=n; ++i) e[i][0]=e[i][1]=deg[i]=ok[i]=0;
		for(int i=1, x, y; i<=m; ++i) scan(x), scan(y), (e[x][0]?e[x][1]=y:e[x][0]=y), ++deg[y];
		bfs();
		int cnt=0;
		for(int i=1; i<=n; ++i) cnt+=ok[i]==-1;
		putint(cnt, '\n');
		for(int i=1; i<=n; ++i) if(ok[i]==-1) putint(i, ' ');
		pc('\n');
	}
	flush();
	return 0;
}