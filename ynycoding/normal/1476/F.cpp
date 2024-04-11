#include <cstdio>
#include <algorithm>
const int N=300005;
int T, n, p[N], f[N], pr[N][2], ans[N], lg[N], mx[N][20];
inline int gmx(int a, int b) { return a+p[a]>b+p[b]?a:b; }
void init(int n)
{
	std::fill(lg, lg+n+1, 0);
	for(int i=2; i<=n; i<<=1) ++lg[i];
	for(int i=1; i<=n; ++i) lg[i]+=lg[i-1];
	for(int i=1; i<=n; ++i) mx[i][0]=i;
	for(int l=1; (1<<l)<=n; ++l) for(int i=1; i+(1<<l)-1<=n; ++i)
		mx[i][l]=gmx(mx[i][l-1], mx[i+(1<<(l-1))][l-1]);
}
inline int ask(int l, int r)
{
	int len=lg[r-l+1];
	return gmx(mx[l][len], mx[r-(1<<len)+1][len]);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", p+i);
		init(n);
		for(int i=1; i<=n; ++i)
		{
			pr[i][0]=pr[i][1]=0;
			f[i]=(f[i-1]>=i?std::max(i+p[i], f[i-1]):f[i-1]);
			int l=std::lower_bound(f, f+i, i-p[i]-1)-f;
			if(l<i)
			{
				int t=(l<i-1?ask(l+1, i-1):0);
				if(std::max(t+p[t], i-1)>f[i])
				{
					f[i]=std::max(p[t]+t, i-1);
					pr[i][0]=l+1, pr[i][1]=t;
				}
			}
		}
		if(f[n]<n) { puts("NO"); continue; }
		puts("YES");
		for(int i=n; i; i=pr[i][0]?pr[i][0]-1:i-1)
		{
			if(pr[i][0]) ans[i]=0, ans[pr[i][1]]=1;
			else ans[i]=1;
		}
		for(int i=1; i<=n; ++i) putchar(ans[i]?'R':'L');
		puts("");
	}
	return 0;
}