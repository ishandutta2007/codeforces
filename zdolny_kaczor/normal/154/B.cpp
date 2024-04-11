# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
int div[MN];
void sito()
{
	for (int p = 2; p < MN; ++p)
		if (div[p] == 0)
			for (int q = p; q < MN; q += p)
				div[q] = p;
}
vector <int> factors(int x)
{
	vector <int> res;
	while (x > 1)
	{
		int p = div[x];
		res.push_back(p);
		while (x % p == 0)
			x /= p;
	}
	return res;
}
int by[MN];
bool on[MN];
int main()
{
	sito();
	int m, n;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		char sign[2];
		int x;
		scanf("%s%d", sign, &x);
		vector <int> divs = factors(x);
		if (sign[0] == '-')
		{
			if (on [x])
			{
				for (int a : divs)
					by[a] = 0;
				printf("Success\n");
				on[x] = false;
			}
			else
				printf("Already off\n");
		}
		else
		{
			if (on[x])
			{
				printf("Already on\n");
			}
			else
			{
				bool ok = true;
				for (int a : divs)
					if (by[a])
					{
						printf("Conflict with %d\n", by[a]);
						ok = false;
						break;
					}
				if (ok)
				{
					printf("Success\n");
					for (int a : divs)
						by[a] = x;
					on[x] = true;
				}
			}
		}
	}
}