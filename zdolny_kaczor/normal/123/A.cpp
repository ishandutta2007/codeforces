# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;
const int MN = 1e3 + 44;
const int A = 1 << 8 + 4;
bool prime[MN];
char in[MN];
int cou[A];
char ans[MN];
vector <int> singletons;
int main()
{
	for (int i = 2; i < MN; ++i)
		prime[i] = true;
	for (int i = 2; i < MN; ++i)
		if (prime[i])
			for (int k = i * 2; k < MN; k += i)
				prime[k] = false;
	scanf("%s", in + 1);
	int n = strlen(in + 1);
	for (int i = 1; i <= n; ++i)
		cou[in[i]]++;
	singletons.push_back(1);
	for (int i = n / 2 + 1; i <= n; ++i)
		if (prime[i])
			singletons.push_back(i);
	int rest = n - singletons.size();
	int mass = -1;
	for (int i = 0; i < A; ++i)
		if (cou[i] >= rest)
		{
			mass = i;
			break;
		}
	if (mass == -1)
	{
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		ans[i] = mass;
	cou[mass] -= rest;
	int pos = 0;
	for (auto i : singletons)
	{
		while (cou[pos] == 0)
			pos++;
		ans[i] = pos;
		cou[pos]--;
	}
	ans[n + 1] = 0;
	printf("YES\n%s\n", ans + 1);
}