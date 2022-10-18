#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define x first
#define y second
using std::string;
const int N=18, MOD=998244353, BASE=233;
int n;
int f[N+1][1<<N], pw[N+1];
char s[(1<<N)+2];
bool cmp(int a, int b)
{
	if(f[n][a]==f[n][b]) return 0;
	for(int l=n-1; ~l; --l)
	{
		if(f[l][a]==f[l][b]) a^=(1<<l), b^=(1<<l);
	}
	return s[a]<s[b];
}
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	pw[0]=BASE;
	for(int i=1; i<=n; ++i) pw[i]=1ll*pw[i-1]*pw[i-1]%MOD;
	for(int i=0; i<(1<<n); ++i) f[0][i]=s[i]-'a'+1;
	for(int l=1; l<=n; ++l)
	{
		int mid=1<<(l-1);
		for(int i=0; i<(1<<n); i+=(1<<l)) for(int j=i; j<i+mid; ++j)
		{
			int x=f[l-1][j], y=f[l-1][j+mid];
			f[l][j]=(x+1ll*y*pw[l-1])%MOD;
			f[l][j+mid]=(y+1ll*x*pw[l-1])%MOD;
		}
	}
	int id=0;
	for(int i=1; i<(1<<n); ++i) if(cmp(i, id)) id=i;
	for(int i=0; i<(1<<n); ++i) putchar(s[i^id]);
	return 0;
}