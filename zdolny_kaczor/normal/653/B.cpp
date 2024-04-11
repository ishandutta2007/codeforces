# include <cstdio>
# include <vector>
using namespace std;
bool poss[6][6][6];
int res = 0;
vector <pair <int, int> > graph[36];
int cou[36];
inline int make_state(int len, int let)
{
	return (len - 1) * 6 + let;
}
char a[5], b[5];
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%s%s", a, b);
		poss[a[0] - 'a'][a[1] - 'a'][b[0] - 'a'] = true;
	}
	for (int i = 0; i < 6; ++i)
		for (int k = 0; k < 6; ++k)
		{
			int cou = 0;
			for (int l = 0; l < 6; ++l)
				if (poss[k][l][i])
					cou ++;
			for (int len = 1; len < n; ++len)
				graph[make_state(len, i)].push_back(make_pair(make_state(len + 1, k), cou));
		}
	cou[make_state(1, 0)] = 1;
	for (int state = 0; state < 6 * n; ++state)
		for (auto x : graph[state])
			cou[x.first] += cou[state] * x.second;
	int res = 0;
	for (int l = 0; l < 6; ++l)
		res += cou[make_state(n, l)];
	printf("%d\n", res);
}