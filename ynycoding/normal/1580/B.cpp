//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
//Problem Writer Your Mother Has Died. KaNiMaDeChang
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ull unsigned long long
const int N=105;
int MOD;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline void inc(int &x, int a) { x=mval(x+a); }

int n, m, k, C[N][N], fac[N], f[N][N], g[N][N], h[N][N], ans;
inline ull barret(ull x)
{
	static __int128 c=-1ull/MOD;
	int r=x-(ull)((x*c)>>64)*(ull)MOD;
	return mval(r);
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &MOD);
	C[0][0]=1;
	fac[0]=1;
	for(int i=1; i<=n; ++i)
	{
		fac[i]=1ll*i*fac[i-1]%MOD;
		C[i][0]=1;
		for(int j=1; j<=i; ++j) C[i][j]=mval(C[i-1][j-1]+C[i-1][j]);
	}
	f[0][0]=1;
	for(int i=1; i<=n; ++i) f[1][i]=fac[i];
	for(int i=1; i<m; ++i)
	{
		memset(g, 0, sizeof(g));
		for(int a=0; a<=k; ++a) for(int b=0; a+b<=k; ++b)
		{
			for(int j=0; j<n; ++j) if(f[a][j]) for(int k=0; k+j<n; ++k)
				inc(g[a+b][j+k+1], barret(barret(1ll*f[a][j]*f[b][k])*C[j+k][j]));
		}
		memcpy(f, g, sizeof(f));
		f[0][0]=1;
	}
	printf("%d\n", f[k][n]);
	return 0;
}