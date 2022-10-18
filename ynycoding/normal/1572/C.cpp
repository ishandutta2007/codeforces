#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define INF 0x3f3f3f3f

using std::vector;
const int N=3005;
int T, n, a[N], f[N][N], pos[N], pr[N], nxt[N];
inline void gmn(int &x, int a) { x=std::min(x, a); }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		std::fill(pos+1, pos+n+1, 0);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; ++i)
		{
			pr[i]=pos[a[i]];
			pos[a[i]]=i;
		}
		std::fill(pos+1, pos+n+1, 0);
		for(int i=n; i; --i)
		{
			nxt[i]=pos[a[i]];
			pos[a[i]]=i;
		}
		for(int len=2; len<=n; ++len)
		{
			for(int l=1, r=len; r<=n; ++l, ++r)
			{
				f[l][r]=INF;
				int x=l;
				while(x&&x<=r)
					gmn(f[l][r], std::min(f[l][x-1], f[l+1][x-1]+1)+std::min(f[x][r], f[x+1][r]+1)), x=nxt[x];
			}
		}
		printf("%d\n", f[1][n]);
	}
	return 0;
}