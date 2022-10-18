#include <cstdio>
#include <algorithm>
#define ll long long
const int N=200005;
int T, n, a[N];
ll sum;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		--a[1];
		int t=n;
		while(t>1&&!a[t]) --t;
		++a[t];
		sum=0;
		for(int i=1; i<=n; ++i)
		{
			sum+=a[i];
			if(sum<0) { puts("No"); goto out; }
		}
		if(sum) puts("No");
		else puts("Yes");
		out:;
	}
	return 0;
}