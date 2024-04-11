# include <cstdio>
# include <set>
using namespace std;
int primes[] = {500002991, (int)1e9 + 9, (int)1e9 + 7, (int)1e9 + 33, 250001503, 500002961, 83333827, 500002939, 500002927, 500002933};
const int MN = 100;
long long a[MN];
int main()
{
	int n;
	long long p, q;
	scanf("%I64d%I64d%d", &p, &q, &n);
	for (int i = 0; i < n; ++i)
		scanf("%I64d", a + i);
	bool equ = true;
	for (auto d : primes)
	{
		long long den = 1, nom = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			nom = (nom + den * (a[i] % d)) % d;
			swap(nom, den);
		}
		if ((p % d * nom - q % d * den) % d)
		{
			equ = false;
			break;
		}
	}
	if (equ)
		printf("YES\n");
	else
		printf("NO\n");
}