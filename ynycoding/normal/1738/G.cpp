#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=1005;
int T, n, k;
char s[N];
bool rans[N][N];
vector<int> e[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		--k;
		for(int i=n; i; --i)
		{
			scanf("%s", s+1);
			e[i].clear();
			for(int j=1; j<=n; ++j)
			{
				rans[i][j]=0;
				if(i+j<=k+1||i+j>=2*n-k+1||s[j]=='0') e[i].pb(j);
			}
		}
		while(k--)
		{
			int cur=1;
			for(int i=1; i<=n; ++i)
			{
				int to=cur;
				if(!e[i].empty()&&e[i].back()>=cur) to=e[i].back(), e[i].pop_back();
				while(e[i].size()&&e[i].back()>=cur) e[i].pop_back();
				std::fill(rans[i]+cur, rans[i]+to+1, 1);
				// for(int j=cur; j<=to; ++j) rans[i][j]=1;
				cur=to;
			}
		}
		for(int i=1; i<=n; ++i) if(e[i].size()) { puts("NO"); goto out; }
		puts("YES");
		for(int i=n; i; --i, puts("")) for(int j=1; j<=n; ++j) putchar(rans[i][j]+'0');
		out:;
	}
	return 0;
}