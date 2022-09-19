# include <cstdio>
# include <set>
using namespace std;
# define MN 100001
bool pri[MN];
int low[MN];
int wh[MN];
int tab[MN];
pair <int, int> res[5*MN];
int rs=0;
void swapin(int x, int y)
{
	if (x>y)
		swap(x, y);
	swap(tab[x], tab[y]);
	swap(wh[tab[x]], wh[tab[y]]);
	res[rs]=make_pair(x, y);
	rs++;
}
int spl_reg[MN];
int split(int x)
{
	if (spl_reg[x])
		return spl_reg[x];
	for (int i=2; i<=x/2; ++i)
		if (pri[i] && pri[x-i])
			return spl_reg[x]=i;
}
void swap_pri(int x, int y)
{
	int left=3;
	if ((x+y)%2)
	{
		swapin(y, y-1);
		y--;
		left--;
	}
	while (left-- && y-x+1>=3)
	{
		int p=low[y-x+1];
		swapin(y-p+1, y);
		y=y-p+1;
	}
	if (x!=y)
	{
		int p=split(y-x+2);
		swapin(y, y-p+1);
		swapin(x, y-p+1);
	}
}
int main()
{
	for (int i=2; i<MN; ++i)
		pri[i]=true;
	for (int i=2; i<MN; ++i)
		if (pri[i])
			for (int k=2*i; k<MN; k+=i)
				pri[k]=false;
	for (int i=2; i<MN; ++i)
		if (pri[i])
			low[i]=i;
		else
			low[i]=low[i-1];
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", tab+i);
		wh[tab[i]]=i;
	}
	for (int i=1; i<=n; ++i)
		swap_pri(i, wh[i]);
	printf("%d\n", rs);
	for (int i=0; i<rs; ++i)
		printf("%d %d\n", res[i].first, res[i].second);
}