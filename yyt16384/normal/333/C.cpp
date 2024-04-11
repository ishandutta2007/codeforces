#include <cstdio>
#include <cstdlib>
#include <vector>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int N = 10000;
const int M = 100000000;

int k, m;
std::vector<int> ans;
bool fl[M];

void init()
{
	scanf("%d%d", &k, &m);
}

void search(int val, int r, int p)
{
	if (r == 0)
	{
		int d = abs(abs(val) - k);
		if (d < N)
		{
			ans.push_back(p * N + d);
			ans.push_back(d * N + p);
		}
		return;
	}

	search(val + (r % 10), r / 10, p);
	search(val - (r % 10), r / 10, p);
	search(val * (r % 10), r / 10, p);
}

void solve()
{
	for (int i = 0; i < N; ++i)
		search(i % 10, i / 10, i);
	for (int i = 0; i < (int)ans.size(); ++i)
	{
		int x = ans[i];
		if (fl[x]) continue;
		else
		{
			fl[x] = true;
			printf("%08d\n", x);
			--m;
			if (m == 0) break;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9199.in", "r", stdin);
	freopen("9199.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}