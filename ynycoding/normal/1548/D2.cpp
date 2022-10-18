#include <cstdio>
#include <algorithm>
#define ll long long
const int N=6005;
int n, x[N], y[N], cnt[N][4][4][4], rcnt[4][4], f[4], g[4];
ll ans, ans1;
inline int gcd(int a, int b) { while(b) a%=b, std::swap(a, b); return a; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i);
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
	{
		int t=gcd(abs(x[i]-x[j]), abs(y[i]-y[j]))&3;
		int a=(10000000+x[i]-x[j])&3, b=(10000000+y[i]-y[j])&3;
		++cnt[i][a][b][t], ++cnt[j][(4-a)&3][(4-b)&3][t];
	}
	for(int i=1; i<=n; ++i)
	{
		for(int a=0; a<4; ++a) for(int b=0; b<4; ++b) for(int c=0; c<4; ++c) for(int d=0; d<4; ++d)
			if((a*d-b*c)%2==0)
			{
				int s=(a*d-b*c)&2;
				int *f=cnt[i][a][b], *g=cnt[i][c][d];
				for(int x=0; x<4; ++x) if(f[x]) for(int y=0; y<4; ++y) if(g[y])
				{
					int t=!((a==c)&&(b==d)&&(x==y));
					if(!(x&1)&&!(y&1))
					{
						if(((s^x^y)>>1)==!((a==c)&&(b==d)))
							ans+=t?f[x]*g[y]:f[x]*(g[y]-1);
					}
					if((x&1)&&(y&1))
					{
						if(((s^x^y)>>1)==((a==c)&&(b==d)))
							ans1+=t?f[x]*g[y]:f[x]*(g[y]-1);
					}
				}
			}
	}
	printf("%lld\n", (ans/3+ans1)/2);
	return 0;
}