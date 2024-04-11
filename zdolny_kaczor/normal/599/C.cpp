# include <cstdio>
# include <stack>
using namespace std;
bool sep(pair <int, int> a, pair <int, int> b)
{
	return a.second<=b.first;
}
pair<int, int> unite (pair <int, int> a, pair <int, int> b)
{
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}
stack <pair<int, int> > all;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int x;
		scanf("%d", &x);
		pair <int, int> put=make_pair(x, x);
		while (!all.empty() && !sep(all.top(), put))
		{
			put = unite (put, all.top());
			all.pop();
		}
		all.push(put);
	}
	printf("%d\n", (int)all.size());
}