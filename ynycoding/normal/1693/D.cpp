#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
const int N=200005;

int n, m, p[N], mx[N];
int f[N][2][2], f1[N][2][2];
ll ans;
void work(int (*f)[2][2])
{
	f[n][0][0]=f[n][1][0]=n;
	for(int i=n-1; i; --i)
	{
		// printf("in %d %d\n", i, p[i]);
		if(p[i+1]>p[i])
		{
			// puts("fa");
			if(!f[i+1][1][1]||p[f[i+1][1][1]]<p[i])
			{
				f[i][1][0]=f[i+1][1][0];
				f[i][1][1]=f[i+1][1][1];
			}
			else f[i][1][0]=f[i+1][1][1]-1;
			
			if(!f[i+1][1][1]||p[f[i+1][1][1]]<p[i])
			{
				f[i][0][0]=f[i+1][1][0];
				f[i][0][1]=i+1;
			}
			else f[i][0][0]=f[i+1][1][1]-1, f[i][0][1]=i+1;
		}
		else
		{
			if(!f[i+1][0][1]||p[f[i+1][0][1]]>p[i])
			{
				f[i][0][0]=f[i+1][0][0];
				f[i][0][1]=f[i+1][0][1];
			}
			else f[i][0][0]=f[i+1][0][1]-1;

			if(!f[i+1][0][1]||p[f[i+1][0][1]]>p[i])
			{
				f[i][1][0]=f[i+1][0][0];
				f[i][1][1]=i+1;
			}
			else f[i][1][0]=f[i+1][0][1]-1, f[i][1][1]=i+1;
		}
	}
	// for(int i=1; i<=n; ++i) printf("%d ", p[i]);
	// puts("");
}
inline void add(int l, int r)
{
	// printf("add %d %d\n", l, r);
	mx[l]=std::max(mx[l], r);
}
int main()
{
	scanf("%d", &n);
	if(n==1) return puts("1"), 0;
	for(int i=1; i<=n; ++i) scanf("%d", p+i);
	work(f);
	std::reverse(p+1, p+n+1);
	work(f1);
	std::reverse(p+1, p+n+1);
	std::reverse(f1+1, f1+n+1);
	// printf("fa %d %d\n", f1[4][0][0], f1[4][0][1]);
	for(int i=1; i<=n; ++i)
	{
		for(int x:{0, 1}) for(int y:{0, 1}) if(f1[i][x][y])
			f1[i][x][y]=n-f1[i][x][y]+1;
	}
	for(int i=1; i<n; ++i)
	{
		for(int x:{0, 1}) for(int y:{0, 1})
		{
			// printf("in %d %d %d\n", i, x, y);
			int l=f1[i][x][0], cl=f1[i][x][1], r=f[i+1][y][0], cr=f[i+1][y][1];
			int l0=i, l1=cl, r0=i+1, r1=cr;
			if(x) std::swap(l0, l1);
			if(y) std::swap(r0, r1);
			// printf("fa %d %d %d %d\n", l0, l1, r0, r1);
			if((!p[l0]||!p[r1]||p[l0]<p[r1])&&(!p[l1]||!p[r0]||p[l1]>p[r0]))
			{
				add(l, r);
			}
			else
			{
				if(!p[l0]||!p[r1]||p[l0]<p[r1])
				{
					add(l, r0-1);
					add(l1+1, r);
				}
				if(!p[l1]||!p[r0]||p[l1]>p[r0])
				{
					add(l, r1-1);
					add(l0+1, r);
				}
			}
		}
	}
	// for(int i=1; i<=n; ++i) printf("mx %d %d\n", i, mx[i]);
	for(int i=1, r=0; i<=n; ++i)
	{
		r=std::max({r, mx[i], i});
		ans+=r-i+1;
	}
	printf("%lld\n", ans);
	return 0;
}