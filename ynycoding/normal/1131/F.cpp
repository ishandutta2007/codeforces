#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 150005
using std::vector;
int n, fa[MAXN];
int pa(int x) { return x==fa[x]?x:pa(fa[x]); }
vector<int> seq[MAXN];
void uni(int x, int y)
{
	x=pa(x), y=pa(y);
	if(seq[x].size()<seq[y].size()) std::swap(x, y);
	for(int i=seq[y].size()-1; ~i; --i) seq[x].push_back(seq[y][i]), seq[y].pop_back();
	fa[y]=fa[x];
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) fa[i]=i, seq[i].push_back(i);
	for(int i=1, a, b; i<n; ++i)
	{
		scanf("%d%d", &a, &b);
		uni(a, b);
	}
	int idx=pa(1);
	for(int i=0; i<n; ++i) printf("%d ", seq[idx][i]);
	return 0;
}