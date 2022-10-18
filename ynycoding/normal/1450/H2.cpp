#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=200005, MOD=998244353, g=3, iv2=MOD/2+1;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, m, inv[N], fac[N], cur, ct, ipw[N], pw[2][N], w[2], wn;
char rs[N], t[3];
inline int C(int n, int m) { return (n<m||m<0)?0:1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD; }
int s[4], s1[4], x, y=-1;
inline void incx(void)
{
	for(int t:{0, 1})
	{
		int a=fix(s[t]-(y<0?0:1ll*C(x, y)*pw[t][y]%MOD)), b=fix(s[t]-1);
		int a1=fix(s1[t]-(y<0?0:1ll*C(x, y)*pw[t][y]%MOD*y%MOD)), b1=s1[t];
		s1[t]=(1ll*a1*w[t]+b1+1ll*a*w[t])%MOD;
		s[t]=(1ll*a*w[t]+b)%MOD;
		inc(s[t], 1);
	}
	++x;
	if(x<=0) memset(s, 0, sizeof(s)), memset(s1, 0, sizeof(s1));
	if(!x&&y>=0) s[0]=s[1]=1;
//	printf("inc %d %d %d %d\n", x, y, s[0], s1[0]);
}
inline void decx(void)
{
	--x;
	for(int t:{0, 1})
	{
		inc(s[t], 1ll*C(x, y)*pw[t][y+1]%MOD);
		s[t]=1ll*s[t]*(t?0:iv2)%MOD;
		int a=fix(s[t]-(y<0?0:1ll*C(x, y)*pw[t][y]%MOD)), b=fix(s[t]-1);
		dec(s1[t], 1ll*a*w[t]%MOD);
		inc(s1[t], (y<0?0:1ll*C(x, y)*pw[t][y+1]%MOD*y%MOD));
		s1[t]=1ll*s1[t]*(t?0:iv2)%MOD;
	}
	if(x<=0) memset(s, 0, sizeof(s)), memset(s1, 0, sizeof(s1));
	if(!x&&y>=0) s[0]=s[1]=1;
//	printf("dec %d %d %d %d %d %d\n", x, y, s[0], s1[0], s[1], s1[1]);
}
inline void incy(void)
{
	++y;
	for(int t:{0, 1})
	{
		inc(s[t], (y<0?0:1ll*C(x, y)*pw[t][y]%MOD));
		inc(s1[t], (y<0?0:1ll*C(x, y)*pw[t][y]%MOD*y%MOD));
	}
}
inline void decy(void)
{
	for(int t:{0, 1})
	{
		dec(s[t], (y<0?0:1ll*C(x, y)*pw[t][y]%MOD));
		dec(s1[t], (y<0?0:1ll*C(x, y)*pw[t][y]%MOD*y%MOD));
	}
	--y;
}
inline void move(int cx, int cy)
{
	cy=std::min(cx, cy);
	while(x<cx) incx();
	while(y<cy) incy();
	while(x>cx) decx(), decx(), decx(), incx(), incx();
	while(y>cy) decy();
}
inline void solve(int res, int dt)
{
	if(!res)
	{
		printf("%d\n", dt%4?0:std::abs(dt)/4);
		return;
	}
	int ans=0;
	int off=((dt-res)/2%2+2)%2;
	move(res, (-dt+res)/2);
//	printf("move %d\n", (-dt+res)/2);
	for(int t:{0, 1})
	{
		int sum=2ll*qpow(mval(1+w[t]), res-1)*w[t]%MOD*res%MOD, cnt=qpow(mval(1+w[t]), res);
		inc(ans, (sum+1ll*fix(-res+dt)*cnt)%MOD*pw[t][off]%MOD);
//		printf("in %d %d %d %d\n", t, sum, cnt, (sum+1ll*fix(-res+dt)*cnt)%MOD);
		sum=2ll*s1[t]%MOD, cnt=s[t];
//		printf("in %d %d %d %d\n", t, sum, cnt, (sum+1ll*fix(-res+dt)*cnt)%MOD);
		dec(ans, 2ll*(sum+1ll*fix(-res+dt)*cnt)%MOD*pw[t][off]%MOD);
	}
//	printf("ans %d\n", ans);
	printf("%d\n", 1ll*ans*qpow(iv2, res+2)%MOD);
}
int res, dt;
int main()
{
	scanf("%d%d", &n, &m);
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD;
	inv[n]=qpow(fac[n], MOD-2);
	for(int i=n-1; ~i; --i) inv[i]=1ll*(i+1)*inv[i+1]%MOD;
	scanf("%s", rs+1);
	wn=qpow(g, (MOD-1)/2);
	w[0]=1;
	for(int i=1; i<2; ++i) w[i]=1ll*wn*w[i-1]%MOD;
	for(int i=0; i<2; ++i)
	{
		pw[i][0]=1;
		for(int j=1; j<=n+1; ++j) pw[i][j]=1ll*pw[i][j-1]*w[i]%MOD;
	}
	for(int i=1; i<=n; ++i)
	{
		if(rs[i]=='?') ++res;
		else
		{
			if((rs[i]=='b')^(i&1)) ++dt;
			else --dt;
		}
	}
	solve(res, dt);
	for(int i=1, p; i<=m; ++i)
	{
		scanf("%d%s", &p, t+1);
		if(rs[p]=='?') --res;
		else
		{
			if((rs[p]=='b')^(p&1)) --dt;
			else ++dt;
		}
		rs[p]=t[1];
		if(rs[p]=='?') ++res;
		else
		{
			if((rs[p]=='b')^(p&1)) ++dt;
			else --dt;
		}
		solve(res, dt);
	}
	return 0;
}