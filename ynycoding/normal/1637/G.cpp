#include <cstdio>
#include <algorithm>
const int N=50005;
int T, n, mx, stk[N*20][2], top;
inline void proc(int x, int y)
{
	stk[++top][0]=x, stk[top][1]=y;
}
inline void mul2(int x, int n)
{
	while(n>3)
	{
		proc(x, x), proc(2*x, 0);
		n-=2;
	}
	if(n==2) proc(x, x), proc(2*x, 0);
	else proc(x, x), proc(x, 0), proc(x, x), proc(2*x, 0);
}
int cur;
inline void fix(int x)
{
	if(cur&x)
	{
		cur^=x;
		while(x<mx) mul2(x, 2), x*=2;
		return;
	}
	else cur|=x;
}
void solve(int l, int r, int d)
{
	int n=(r-l)/d+1;
	if(n==1)
	{
		if(l<mx) fix(l);
		return;
	}
	int x=r;
	while(x>=l)
	{
		int t=1<<(32-__builtin_clz(x));
		int tl=t-x, tr=x;
		int v=t, cnt=(tr-tl)/d+1;
		while(tl<tr)
		{
			proc(tl, tr);
			tl+=d, tr-=d;
		}
		if(cnt>3) while(v<mx) mul2(v, cnt/2), v*=2;
		else if(cnt==3&&v<mx) fix(v);
		if(cnt>1) solve(2*d, 2*x-t, 2*d);
		fix(t>>1);
		x=t-x-d;
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		cur=top=0;
		scanf("%d", &n);
		if(n==2) { puts("-1"); continue; }
		mx=1<<(32-__builtin_clz(n-1));
		solve(1, n, 1);
		for(int i=1; i<=n; i<<=1) if(cur&i)
		{
			--top;
			int v=i;
			proc(v, 0);
			while(v<mx) mul2(v, 2), v*=2;
		}
		printf("%d\n", top);
		for(int i=1; i<=top; ++i) printf("%d %d\n", stk[i][0], stk[i][1]);
	}
	return 0;
}