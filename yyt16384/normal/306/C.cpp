#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXM=4005;
const int MOD=1000000009;
int n,w,b;
int fac[MAXM];
int facr[MAXM];
int powermod(int x,int y,int z)
{
	int s=1;
	while (y)
	{
		if (y&1) s=(long long)s*x%z;
		x=(long long)x*x%z;
		y>>=1;
	}
	return s;
}
void init()
{
	int m;
	scanf("%d%d%d",&n,&w,&b);
	m=(w>b?w:b);
	fac[0]=1;
	for (int i=1;i<=m;++i)
		fac[i]=(long long)fac[i-1]*i%MOD;
	facr[m]=powermod(fac[m],MOD-2,MOD);
	for (int i=m-1;i>=0;--i)
		facr[i]=(long long)facr[i+1]*(i+1)%MOD;
}
int f(int n,int k)
{
	if (n<k) return 0;
	return (long long)fac[n]*fac[n-1]%MOD*facr[k-1]%MOD*facr[n-k]%MOD;
}
void solve()
{
	int s=0;
	for (int i=2;i<n;++i)
		s=(s+(long long)f(b,n-i)*f(w,i)%MOD*(i-1))%MOD;
	printf("%d\n",s);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8784.in","r",stdin);
	freopen("8784.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}