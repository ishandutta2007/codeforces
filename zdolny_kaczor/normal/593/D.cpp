# include <cstdio>
# include <vector>
using namespace std;
const int MN=200*1000+42;
vector <pair <int, long long> > graf[MN];
int up[MN];
long long valup[MN];
int in[MN], out[MN];
int timer=0;
int lownr[MN];
int jumptab[MN];
int jump(int x)
{
// 	printf("jump %d\n", x);
	if (jumptab[x]==x)
		return x;
	else
		return jumptab[x]=jump(jumptab[x]);
}
void dfs(int x, int y=0)
{
	in[x]=timer++;
	up[x]=y;
	for (auto v:graf[x])
	{
		if (v.first!=y)
		{
			dfs(v.first, x);
			valup[v.first]=v.second;
		}
	}
	out[x]=timer++;
}
bool under(int x, int y) /*czy x jest pod y*/
{
	if (y==0)
		return true;
	return in[x]>=in[y] && out[x]<=out[y];
}
void jumpinit()
{
	for (int i=0; i<MN; ++i)
		jumptab[i]=i;
}
void remove(int x)
{
	if (jumptab[x]==x)
		jumptab[x]=up[x];
}
pair <int, int> edges[MN];
int low[MN];
void moveup(int a, int b, long long &val)
{
// 	printf("moveup %d %d\n", a, b);
	a=jump(a);
	while (val && !under(b, a))
	{
// 		printf("jump to %d\n", a);
		val/=valup[a];
		a=up[a];
		a=jump(a);
	}
}
int main()
{
	jumpinit();
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i=1; i<n; ++i)
	{
		int a, b;
		long long c;
		scanf("%d%d%I64d", &a, &b, &c);
		edges[i]=make_pair(a, b);
		graf[a].push_back(make_pair(b, c));
		graf[b].push_back(make_pair(a, c));
	}
	dfs(1);
// 	for (int i=1; i<=n; ++i)
// 	{
// 		printf("%d:up=%d upval=%lld\n", i, up[i], valup[i]);
// 	}
	for (int i=1; i<n; ++i)
	{
		if (up[edges[i].first]==edges[i].second)
			low[i]=edges[i].first;
		else
			low[i]=edges[i].second;
	}
	for (int i=1; i<n; ++i)
		if (valup[i]==1)
			remove(i);
// 	for (int i=0; i<=n; ++i)
// 		printf("%d. jumptab=%d\n",i, jumptab[i]);
// 	for (int i=1; i<n; ++i)
// 		printf("%d.%d\n", i, low[i]);
	while (q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int a, b;
			long long y;
			scanf("%d%d%I64d", &a, &b, &y);
			moveup(a, b, y);
			moveup(b, a, y);
			printf("%I64d\n", y);
		}
		else
		{
			int nr;
			long long val;
			scanf("%d%I64d", &nr, &val);
			valup[low[nr]]=val;
			if (val==1)
				remove(low[nr]);
		}
	}
}