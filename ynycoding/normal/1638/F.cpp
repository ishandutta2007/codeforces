#include <cstdio>
#include <algorithm>
#define ll long long
const int N=10005;
int n, lf[N], rt[N], stk[N], a[N], top;
ll h[N], f[N], g[N], ans;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%lld", h+i);
	for(int i=1; i<=n; ++i)
	{
		while(top&&h[i]<=h[stk[top]]) --top;
		lf[i]=stk[top];
		stk[++top]=i;
	}
	top=0;
	stk[0]=n+1;
	for(int i=n; i; --i)
	{
		while(top&&h[i]<=h[stk[top]]) --top;
		rt[i]=stk[top];
		stk[++top]=i;
	}
	for(int i=1; i<=n; ++i)
	{
		int x=lf[i], pr=i;
		while(1)
		{
			f[i]=std::max(f[i], h[pr]*(i-x));
//			printf("x %d\n", x);
			if(!x) break;
			pr=x;
			x=lf[x];
		}
		x=rt[i], pr=i;
		while(1)
		{
			g[i]=std::max(g[i], h[pr]*(x-i));
			if(x>n) break;
			pr=x;
			x=rt[x];
		}
		f[i]=std::max(f[i], f[i-1]);
		ans=std::max(ans, f[i-1]+g[i]);
	}
//	printf("rt %d\n", rt[4]);
//	printf("ans %lld\n", ans);
	for(int i=1; i<=n; ++i)
	{
		ll s=(rt[i]-lf[i]-1)*h[i];
		int len=rt[i]-lf[i]-1;
		int l=lf[i], r=rt[i], pr=i;
		ll ret=0;
		while(1)
		{
			ret=std::max(ret, s+h[pr]*(r-l-1-len));
//			printf("%d %d %d\n", l, r, h[pr]);
			if(!l&&r>n) break;
			if(h[l]>h[r]) pr=l, l=lf[l];
			else pr=r, r=rt[r];
		}
		l=lf[i], r=rt[i];
		int cl=lf[i]+1, cr=rt[i]-1;
		int tp=0;
		l=i;
		while(l) a[++tp]=l, l=lf[l];
		a[tp+1]=0;
		l=tp+1;
		pr=i;
//		printf("ret %d %d %d %d\n", ret, s, cl, cr);
		while(1)
		{
			while(h[pr]+h[a[l-1]]<=h[i]) --l;
//			printf("now %d %d %d %d %d\n", pr, a[l], h[pr]+h[a[l]], r-cl, cr-a[l+1]);
//			if(h[pr]+a[l]>n) exit(114);
			ret=std::max(ret, h[pr]*(r-cl)+(cr-a[l+1])*h[a[l]]);
			ret=std::max(ret, h[pr]*(r-cl)+(cr-a[l])*(h[i]-h[pr]));
			ret=std::max(ret, (h[i]-h[a[l-1]])*(pr-cl)+(cr-a[l])*h[a[l-1]]);
//			printf("%d %d %d %d %d\n", a[l+1], h[a[l]], r, h[pr], ret);
			if(r>n) break;
			pr=r;
			r=rt[r];
		}
//		printf("ret %d %d\n", i ,ret);
		ans=std::max(ans, ret);
//		puts("");
	}
	printf("%lld\n", ans);
	return 0;
}