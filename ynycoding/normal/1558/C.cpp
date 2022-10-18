#include <cstdio>
#include <algorithm>
const int N=20770;
int T, n, a[N], stk[N], top;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; ++i) if((i&1)!=(a[i]&1))
		{
			puts("-1");
			goto out;
		}
		top=0;
		for(int i=1; i<n; i+=2)
		{
			int p=std::find(a+1, a+n-i+2, i)-a;
			stk[++top]=p;
			std::reverse(a+1, a+p+1);
			p=std::find(a+1, a+n-i+2, i+1)-a;
			stk[++top]=p-1;
			std::reverse(a+1, a+p);
			stk[++top]=p+1;
			std::reverse(a+1, a+p+2);
			stk[++top]=3;
			std::reverse(a+1, a+4);
			stk[++top]=n-i+1;
			std::reverse(a+1, a+n-i+2);
		}
		stk[++top]=n;
		std::reverse(a+1, a+n+1);
		printf("%d\n", top);
		for(int i=1; i<=top; ++i) printf("%d ", stk[i]);
		puts("");
		out:;
	}
	return 0;
}