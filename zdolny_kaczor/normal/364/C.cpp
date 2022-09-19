# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
void gen(vector <int> primes, int limit, int mul, vector <int> & acc)
{
	if (limit < mul)
		return;
	if (primes.size() == 0)
	{
		acc.push_back(mul);
		return;
	}
	int p = primes.back();
// 	printf("take %d\n", p);
	primes.pop_back();
	while (mul <= limit)
	{
// 		printf("call %d\n", mul);
		gen(primes, limit, mul, acc);
		mul *= p;
	}
}
bool isprime(int x)
{
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0)
			return false;
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	vector <int> prime;
	for (int l = 2; ; ++l)
		if (isprime(l))
		{
			prime.push_back(l);
			vector <int> can;
			gen(prime, 2 * n * n, 1, can);
			if (can.size() >= n)
			{
				sort(can.begin(), can.end());
				for (int i = 0; i < n; ++i)
				{
					printf("%d ", can.back());
					can.pop_back();
				}
				printf("\n");
				return 0;
			}
		}
}