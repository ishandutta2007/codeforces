# include <cstdio>
# include <vector>
# include <map>
using namespace std;
struct record
{
	map <int, int> dirs;
	long long sum_v;
	int maxi;
	int size_v;
	record()
	{
		sum_v = maxi = size_v = 0;
	}
	void insert(int x, int cou) //cou > 1
	{
		dirs[x]+=cou;
		if (dirs[x]>maxi)
		{
			sum_v = x;
			maxi=dirs[x];
		}
		else if (dirs[x]==maxi)
			sum_v += x;
		size_v+=cou;
	}
	long long sum()
	{
		return sum_v;
	}
	int size()
	{
		return size_v;
	}
	void merge(record b)
	{
		for (auto x : b.dirs)
			insert(x . first, x . second);
	}
};
const int MN = 1e5+17;
vector <int> graf[MN];
int key[MN];
long long res[MN];
record rpos[MN];
int dfs(int x, int up)
{
	vector <int> under;
	for (int v : graf[x])
		if (v != up)
			under.push_back(dfs(v, x));
	if (under.size() == 0)
	{
		rpos[x].insert(key[x], 1);
		res[x]=key[x];
		return x;
	}
	int nr, maxi = -1;
	for (int y : under)
	{
		if (rpos[y].size()>maxi)
		{
			nr = y;
			maxi = rpos[y].size();
		}
	}
	for (int y: under)
	{
		if (y != nr)
			rpos[nr].merge(rpos[y]);
	}
	rpos[nr].insert(key[x], 1);
	res[x]=rpos[nr].sum();
	return nr;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", key + i);
	int a, b;
	for (int i=0; i<n-1; ++i)
	{
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1, 0);
	for (int i=1; i<=n; ++i)
		printf("%I64d ", res[i]);
}