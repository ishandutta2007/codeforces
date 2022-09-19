# include <cstdio>
# include <vector>
using namespace std;
const int MOD = 1e9 + 7;
const int MN = 1e5 + 44;
vector <int> graf[MN];
int col[MN];
long long with[MN], without[MN];
long long temp[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		graf[x].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", col + i);
	for (int i = n - 1; i >= 0; --i)
		if (col[i])
		{
			without[i] = 0;
			with[i] = 1;
			for (auto x : graf[i])
				with[i] = with[i] * (without[x] + with[x]) % MOD;
		}
		else
		{
			without[i] = 1;
			for (auto x : graf[i])
				without[i] = without[i] * (without[x] + with[x]) % MOD;
			with[i] = 0;
			temp[0] = 1;
			for (int k = 0; k < graf[i].size(); ++k)
				temp[k + 1] = temp[k] * (without[graf[i][k]] + with[graf[i][k]]) % MOD;
			long long pro = 1;
			for (int k = graf[i].size() - 1; k >= 0; --k)
			{
				with[i] += with[graf[i][k]] * pro % MOD * temp[k] % MOD;
				with[i] %= MOD;
				pro = pro * (without[graf[i][k]] + with[graf[i][k]]) % MOD;
			}
		}
// 	for (int i = 0; i < n; ++i)
// 		printf("%d.w=%d wo = %d\n", i, (int) with[i], (int) without[i]);
	printf("%d\n", (int) (with[0]));
}