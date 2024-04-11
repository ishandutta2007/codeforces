# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
const int MN = 1e6 + 44;
int inv[MN], p[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		inv[x] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		p[i] = inv[x];
	}
	vector <int> sequence;
	for (int i = n; i > 0; --i)
	{
		int x = p[i];
		auto pos = lower_bound(sequence.begin(), sequence.end(), x);
		if (pos == sequence.end())
			sequence.push_back(x);
		else
			*pos = x;
	}
	printf("%d\n", (int) sequence.size());
}