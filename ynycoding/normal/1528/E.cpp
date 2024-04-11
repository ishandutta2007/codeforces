#include <cstdio>
#include <algorithm>
const int N=1000005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int n, f[N], s[N], ans, ans1, iv2=MOD/2+1, iv6=qpow(6, MOD-2);
int main()
{
	scanf("%d", &n);
	s[0]=f[0]=1;
	for(int i=1; i<=n; ++i)
	{
		f[i]=(1ll*s[i-1]*s[i-1]+s[i-1])%MOD;
		if(i>1)
		{
			dec(f[i], (1ll*s[i-2]*s[i-2]+s[i-2])%MOD);
		}
		f[i]=1ll*f[i]*iv2%MOD;
		s[i]=mval(f[i]+s[i-1]);
	} 
	ans=(1ll*s[n]*s[n]%MOD*s[n]+3ll*s[n]*s[n]+2*s[n])%MOD;
	dec(ans, (1ll*s[n-1]*s[n-1]%MOD*s[n-1]+3ll*s[n-1]*s[n-1]+2*s[n-1])%MOD);
	ans=1ll*ans*iv6%MOD;
	ans=2ll*ans%MOD;
	for(int i=1; i<n; ++i)
	{
		inc(ans1, (1ll*(s[n-i]-1)*(s[n-i]-1)+(s[n-i]-1))%MOD*(f[i]-1)%MOD);
		dec(ans1, (1ll*(s[n-i-1]-1)*(s[n-i-1]-1)+(s[n-i-1]-1))%MOD*(f[i]-1)%MOD);
	}
	ans1=1ll*iv2*ans1%MOD;
	dec(ans, 1);
	printf("%d\n", mval(ans+ans1));
	return 0;
}