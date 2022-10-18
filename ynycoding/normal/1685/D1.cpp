#include <cstdio>
#include <algorithm>
const int N=205;
int T, n, p[N], rp[N], is[N], vis[N];
inline bool ext(int x, int typ)
{
	std::fill(vis+1, vis+n+1, 0);
	int l=x;
	while(l&&!vis[is[l]]) vis[is[l]]=1, --l;
	++l;
	std::fill(vis+1, vis+n+1, 0);
	int r=x;
	while(r<=n&&!vis[is[r]]) vis[is[r]]=1, ++r;
	--r;
	int mn=0x3f3f3f3f;
	for(int i=l; i<=r; ++i) if(i!=x) mn=std::min(mn, rp[i]);
	if(mn<p[x]||(typ&&l<r))
	{
		int t=p[mn];
		if(t<x)
		{
			int pr=x;
			while(t<x) std::swap(p[pr], p[t]), rp[p[pr]]=pr, rp[p[t]]=t, pr=t, ++t;
		}
		else
		{
			int pr=x;
			while(t>x) std::swap(p[pr], p[t]), rp[p[pr]]=pr, rp[p[t]]=t, pr=t, --t;
		}
		// printf("ext %d %d\n", x, mn);
		return 1;
	}
	return 0;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1, x; i<=n; ++i) scanf("%d", &x), p[x]=i, rp[i]=x;
		while(1)
		{
			// puts("fa");
			std::fill(is+1, is+n+1, 0);
			int tot=0;
			for(int i=1; i<=n; ++i) if(!is[i])
			{
				int x=i;
				++tot;
				while(!is[x]) is[x]=tot, x=p[x];
			}
			int ok=0;
			for(int i=1; i<=n; ++i) ok|=is[i]>1;
			if(!ok) break;
			int x=1;
			ok=0;
			int mx=1;
			do{
				if(ext(x, 0)) { ok=1; break; }
				x=p[x];
			}while(x!=1);
			if(!ok)
			{
				x=rp[1];
				do{
					if(ext(x, 1)) break;
					x=rp[x];
				}while(x!=rp[1]);
			}
			// {
			// 	int x=1;
			// 	do{
			// 		printf("%d ", x);
			// 		x=p[x];
			// 	}while(x!=1);
			// }
			// puts("");
		}
		int x=1;
		do{
			printf("%d ", x);
			x=p[x];
		}while(x!=1);
		puts("");
	}
	return 0;
}