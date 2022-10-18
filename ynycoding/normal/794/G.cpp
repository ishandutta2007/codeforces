#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=2000005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, len, mx, cnt[3], cnt1[3], f[N], is[N], inv[N<<1], fac[N<<1], ans, ad;
int len1, mul;
char s[N], t[N];
int rc[N<<1], off;
inline int C(int n, int m) { return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int pr[N], isp[N], phi[N], top;
void init(int n)
{
	phi[1]=1;
	for(int i=2; i<=n; ++i)
	{
		if(!isp[i]) pr[++top]=i, phi[i]=i-1;
		for(int j=1; j<=top&&i*pr[j]<=n; ++j)
		{
			int x=i*pr[j];
			isp[x]=1;
			if(i%pr[j]==0) { phi[x]=phi[i]*pr[j]; break; }
			phi[x]=phi[i]*(pr[j]-1);
		}
	}
}
int main()
{
	scanf("%s", s+1);
	len=strlen(s+1);
	for(int i=1; i<=len; ++i)
	{
		++cnt[s[i]=='B'?0:s[i]=='A'?1:2];
	}
	std::copy(s+1, s+len+1, t+1);
	len1=len;
	mx=len;
	scanf("%s", s+1);
	len=strlen(s+1);
	for(int i=1; i<=len; ++i)
	{
		++cnt1[s[i]=='B'?0:s[i]=='A'?1:2];
	}
	mx=std::max(mx, len);
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=2*mx; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1; i<=2*mx; ++i) fac[i]=1ll*i*fac[i-1]%MOD, inv[i]=1ll*inv[i-1]*inv[i]%MOD;
	scanf("%d", &n);
	f[0]=1;
	for(int i=1; i<=n; ++i) f[i]=2ll*f[i-1]%MOD;
	for(int i=1; i<=n; ++i) for(int j=2*i; j<=n; j+=i) dec(f[j], f[i]);
	f[0]=0;
	for(int i=1; i<=n; ++i) inc(f[i], f[i-1]);
	if(len==len1)
	{
		mul=1;
		for(int i=1; i<=len; ++i)
		{
			if(s[i]!='?'&&t[i]!='?'&&s[i]!=t[i]) { mul=0; break; }
			if(s[i]=='?'&&t[i]=='?') mul=2ll*mul%MOD;
		}
		dec(ad, mul);
		inc(ans, 1ll*fix(qpow(2, n+1)-2)*fix(qpow(2, n+1)-2)%MOD*mul%MOD);
	}
	off=mx;
	int a=cnt[2], b=cnt1[2];
	for(int t=-mx; t<=mx; ++t) if(b-t>=0&&b-t<=a+b) rc[t+off]=C(a+b, b-t);
	for(int i=-mx; i<=mx; ++i) if(rc[i+off])
	{
		int v=rc[i+off];
		int a=cnt[0]-cnt1[0]-i;
		int b=cnt[1]+cnt[2]-cnt1[1]-cnt1[2]+i;
		if(a<0) a=-a, b=-b;
		b=-b;
		if(!a&&!b)
		{
			inc(ad, v);
			continue;
		}
		if(b<0) continue;
		if(!a||!b) continue;
		int d=std::__gcd(a, b);
		a/=d, b/=d;
		inc(is[std::max(a, b)], v);
	}
	init(n);
	for(int i=1; i<=n; ++i)
	{
		inc(is[i], (i==1?ad:2ll*phi[i]*ad%MOD));
	}
	for(int i=n; i; --i) for(int j=2*i; j<=n; j+=i) inc(is[j], is[i]);
	int rans=0;
	for(int i=1; i<=n; ++i) inc(rans, qpow(2, i));
	for(int i=1; i<=n; ++i) if(is[i])
	{
		inc(ans, 1ll*is[i]*f[n/i]%MOD);
	}
	printf("%d\n", ans);
	return 0;
}