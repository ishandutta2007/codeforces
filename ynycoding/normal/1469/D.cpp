#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200010
int T, n, ok[N], stk[N][2], top;
inline void op(int x, int y) { stk[++top][0]=x, stk[top][1]=y; }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		top=0;
		std::fill(ok+1, ok+n+1, 0);
		for(long long i=2; i<=n; i*=i) ok[i]=1;
		for(int i=2; i<n; ++i) if(!ok[i]) op(i, i+1);
		for(int i=n-1, pr=n; i>=2; --i)
			if(ok[i]) op(pr, i), op(pr, i), pr=i;
		printf("%d\n", top);
		for(int i=1; i<=top; ++i) printf("%d %d\n", stk[i][0], stk[i][1]);
	}
	return 0;
}