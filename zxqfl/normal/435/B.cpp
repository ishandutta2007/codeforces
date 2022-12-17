#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

#define MAXK 100

using namespace std;
typedef long long ll;

int main()
{
	ll A;
	int K;
	scanf("%I64d", &A);
	rint(K);

	vector<int> digits;
	while (A > 0)
	{
		digits.push_back(A % 10);
		A /= 10;
	}

	reverse(digits.begin(), digits.end());

	loop(i, digits.size())
	{
		for (int t = 9; t >= 0; t--)
		{
			int pos = -1;
			sloop(j, i, digits.size())
				if (digits[j] == t)
				{
					pos = j;
					break;
				}

			//printf("  i=%d t=%d pos=%d\n", i, t, pos);

			if (pos - i <= K && pos >= 0)
			{
				K -= pos - i;
				for (int j = pos; j > i; j--)
					swap(digits[j], digits[j-1]);
				assert(digits[i] == t);
				break;
			}
		}
		printf("%d", digits[i]);
	}
	printf("\n");
}