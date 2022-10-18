#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=300005, MOD=1000000007, MOD1=998244353;
int n, sum[N], mn[N], rmn[N], to[N], tom[N], stk[N], cl[N], stk1[N], top1, mn1[N], rtp1[N], len, top, tp;
char s[N], t[N];
int pw[N], pw1[N], hs[N], hs1[N], rtp[N];
inline bool chk(int x, int y, int len)
{
	if((hs[x]+1ll*(MOD-pw[len])*hs[x-len])%MOD!=(hs[y]+1ll*(MOD-pw[len])*hs[y-len])%MOD)
		return 0;
	if((hs1[x]+1ll*(MOD1-pw1[len])*hs1[x-len])%MOD1!=(hs1[y]+1ll*(MOD1-pw1[len])*hs1[y-len])%MOD1)
		return 0;
	return 1;
}
inline int lcp(int x, int y)
{
	int l=0, r=std::min(x, y);
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(chk(x, y, mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	scanf("%s", s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+(s[i]=='('?1:-1);
	mn[0]=n+1;
	for(int i=n; i; --i)
	{
		while(top&&sum[stk[top]]<=sum[i])
		{
			mn[top-1]=std::min(mn[top-1], mn[top]);
			--top;
		}
		to[i]=stk[std::max(0, top-1)];
		tom[i]=std::min({sum[i], mn[top], mn[std::max(top-1, 0)]});
		stk[++top]=i, mn[top]=sum[i];
	}
	rmn[n+1]=n+1;
	for(int i=n; i; --i) rmn[i]=std::min(sum[i], rmn[i+1]);
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='('||(to[i]&&tom[i]-sum[i-1]+len>=0))
		{
			t[++tp]='(';
			i=(s[i]=='('?i:to[i]);
			++len;
		}
		else t[++tp]=')', len=0;
		cl[tp]=len;
		if(sum[i]==sum[n]&&len+(rmn[i+1]-sum[i])>=0) break;
	}
	top=0;
	n=tp;
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+(t[i]=='('?1:-1);
	pw[0]=pw1[0]=1;
	for(int i=1; i<=n; ++i) pw[i]=2ll*pw[i-1]%MOD, pw1[i]=2ll*pw1[i-1]%MOD1;
	tp=0;
	for(int i=n; i; --i)
	{
		while(top&&sum[i-1]<sum[stk[top]-1])
		{
			mn[top-1]=std::min(mn[top-1], mn[top]);
			--top;
		}
		int ok=1;
		s[++tp]=t[i];
		hs[tp]=(2ll*hs[tp-1]+(t[i]=='('))%MOD;
		hs1[tp]=(2ll*hs1[tp-1]+(t[i]=='('))%MOD1;
		if(t[i]=='('&&top&&cl[i-1]+std::min(sum[i], mn[top])>=sum[i-1])
		{
			int l=lcp(tp, rtp[top]);
			ok=s[tp-l]<s[rtp[top]-l];
		}
		if(ok)
		{
			stk[++top]=i;
			mn[top]=sum[i];
			rtp[top]=tp;
		}
		else
		{
			tp=rtp[top];
			mn[top]=std::min(mn[top], sum[i]);
		}
	}
	s[tp+1]=0;
	std::reverse(s+1, s+tp+1);
	puts(s+1);
	return 0;
}