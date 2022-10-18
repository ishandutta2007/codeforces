#include <cstdio>
#include <assert.h>
#include <algorithm>
const int N=200005;
int T, n, a[N], stk[N], top;
inline void proc(int x) { stk[++top]=x; }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), a[i]^=a[i-1];
		if(a[n]) { puts("NO"); continue; }
		top=0;
		int x=1;
		while(x<=n&&a[x]) x+=2;
		if(x>n) { puts("NO"); continue; }
		for(int i=x+3; i<=n; i+=2) if(a[i-1]) proc(i-2), a[i-2]=a[i], a[i-1]=a[i-3];
		for(int i=x; i>=3; i-=2) if(a[i-2]) proc(i-2), a[i-2]=a[i], a[i-1]=a[i-3];
		for(int i=3; i<=n; ++i)
		{
			if(i&1) assert(!a[i]);
			if(a[i-1]) proc(i-2), a[i-2]=a[i], a[i-1]=a[i-3];
		}
		for(int i=1; i<=n; ++i) if(a[i]) { puts("NO"); goto out; }
		printf("YES\n%d\n", top);
		for(int i=1; i<=top; ++i) printf("%d ", stk[i]);
		puts("");
		out:;
	}
	return 0;
}