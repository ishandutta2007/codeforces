#include <cstdio>
#include <cstring>
#include <algorithm>
#define ull unsigned
const int N=1505, BASE=233;




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

int n, m, vis[N], a[N][N], b[N][N], is[N], id[N], stk[N], top;
int rk[N];
ull hs[N], hs1[N];
bool chk(int x)
{
	for(int i=2; i<=n; ++i) if(rk[i]==rk[i-1]&&b[i-1][x]>b[i][x]) return 0;
	return 1;
}
void proc(int x)
{
	int v=0, pr=0;
	for(int i=1; i<=n; ++i)
	{
		if(rk[i]!=pr||b[i][x]!=b[i-1][x]) ++v;
		pr=rk[i];
		rk[i]=v;
	}
//	printf("proc %d\n", x);
//	for(int i=1; i<=n; ++i) printf("%d ", rk[i]);
//	puts("");
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scan(a[i][j]), hs[i]=hs[i]*BASE+a[i][j];
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scan(b[i][j]), hs1[i]=hs1[i]*BASE+b[i][j];
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) if(!vis[j]&&hs1[i]==hs[j])
		{
			id[i]=j;
			vis[j]=1;
			break;
		}
		if(!id[i]) return puts("-1"), 0;
		b[i][m+1]=id[i];
//		printf("%d %d\n", i, id[i]);
	}
	while(1)
	{
		bool ok=0;
		for(int i=1; i<=m; ++i) if(!is[i]&&chk(i))
		{
			ok=1;
			proc(i);
			stk[++top]=i;
			is[i]=1;
			break;
		}
		if(chk(m+1)) break;
		if(!ok) return puts("-1"), 0;
	}
	printf("%d\n", top);
	for(int i=top; i; --i) printf("%d ", stk[i]);
	return 0;
}