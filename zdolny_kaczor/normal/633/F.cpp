# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
int cou[MN];
vector <int> graph[MN];
long long a[MN], b[MN], c[MN], d[MN];
const int L = 3;
# define rep for (auto v : graph[x])\
	if (y != v)
void getmax2(int x, int y, long long t[], pair <long long, int> res[])
{
	for (int i = 0; i < L; ++i)
		res[i] = make_pair(0, -1);
	rep
	{
		auto add = make_pair(t[v], v);
		for (int i = 0; i < L; ++i)
			if (add > res[i])
				swap(add, res[i]);
	}
}
long long compose(pair <long long, int> A[], pair <long long, int> B[])
{
	long long ret = 0;
	for (int i = 0; i < L; ++i)
		for (int k = 0; k < L; ++k)
			if (A[i].second != B[k].second)
				ret = max(ret, A[i].first + B[k].first);
	return ret;
}
long long compose3(pair <long long, int> A[], pair <long long, int> B[], pair <long long, int> C[])
{
	long long ret = 0;
	for (int i = 0; i < L; ++i)
		for (int k = 0; k < L; ++k)
			for (int l = 0; l < L; ++l)
				if (A[i].second != B[k].second && A[i].second != C[l].second && B[k].second != C[l].second)
					ret = max(ret, A[i].first + B[k].first + C[l].first);
	return ret;
}
void dfs(int x, int y = -1)
{
	rep
		dfs(v, x);
	pair <long long, int> A[L], B[L], C[L], D[L];
	getmax2(x, y, a, A);
	getmax2(x, y, b, B);
	getmax2(x, y, c, C);
	getmax2(x, y, d, D);
	a[x] = cou[x] + A[0].first;
	b[x] = max(B[0].first, A[0].first + A[1].first + cou[x]);
	c[x] = max(C[0].first + cou[x], compose(A, B) + cou[x]);
	d[x] = max(max(D[0].first, B[0].first + B[1].first), max(compose(A, C) + cou[x], compose3(A, A, B) + cou[x]));
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", cou + i);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	printf("%I64d\n", d[1]);
}