# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
vector <long long> matrix;
bool insert(long long a)
{
	for (auto x : matrix)
		a = min(a, x ^ a);
	if (a != 0)
	{
		matrix.push_back(a);
		sort(matrix.begin(), matrix.end());
		reverse(matrix.begin(), matrix.end());
		return true;
	}
	else
		return false;
}
int main()
{
	int n;
	scanf("%d", &n);
	long long aim = 0;
	for (int i = 0; i < n; ++i)
	{
		long long a, b;
		scanf("%I64d%I64d", &a, &b);
		insert(a ^ b);
		aim ^= a;
	}
	if (insert(aim))
		printf("1/1\n");
	else
		printf("%I64d/%I64d\n", (1LL << matrix.size()) - 1, (1LL << matrix.size()));
}