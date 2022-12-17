#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

#define MAXN 100
#define NC 10

using namespace std;
typedef long long ll;

int N;
pair<int, int> cards[MAXN];

bool does[NC];
int best = INF;

void solve()
{
	int count = 0;
	loop(i, NC) if (does[i])
		count++;

	if (count < best)
	{
		loop(i, N)
		{
			loop(j, N)
			{
				auto& a = cards[i];
				auto& b = cards[j];

				if (a == b)
					continue;
				if (a.first != b.first && (does[a.first] || does[b.first]))
					continue;
				if (a.second != b.second && (does[a.second+5] || does[b.second+5]))
					continue;

				return;
			}
		}
		best = count;
	}
}

int test(int pos)
{
	if (pos == NC)
		solve();
	else
	{
		does[pos] = true;
		test(pos+1);
		does[pos] = false;
		test(pos+1);
	}
}

int main()
{
	rint(N);

	loop(i, N)
	{
		char buf[10];
		scanf("%s", buf);

		int a, b;
		if (buf[0] == 'R')
			a = 0;
		if (buf[0] == 'G')
			a = 1;
		if (buf[0] == 'B')
			a = 2;
		if (buf[0] == 'Y')
			a = 3;
		if (buf[0] == 'W')
			a = 4;
		b = buf[1] - '1';
		cards[i] = mp(a, b);
	}

	test(0);

	printf("%d\n", best);
}