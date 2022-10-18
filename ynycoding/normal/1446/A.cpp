#include <cstdio>
#include <algorithm>
#define ll long long
#define N 200005
int T, n, id[N], w[N];
ll c, W;
bool cmp(int a, int b) { return w[a]<w[b]; }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%lld", &n, &W);
		for(int i=1; i<=n; ++i) scanf("%d", w+i), id[i]=i;
		c=0;
		std::sort(id+1, id+n+1, cmp);
		bool ok=0;
		for(int l=1, r=0; l<=n; c-=w[id[l]], ++l)
		{
			while(r<n&&c+w[id[r+1]]<=W) ++r, c+=w[id[r]];
			if(c*2>=W)
			{
				ok=1;
				printf("%d\n", r-l+1);
				for(int i=l; i<=r; ++i) printf("%d ", id[i]);
				puts("");
				break;
			}
		}
		if(!ok) puts("-1");
	}
	return 0;
}