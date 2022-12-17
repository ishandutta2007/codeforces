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

using namespace std;
typedef long long ll;

int main()
{
	int N, M;
	rint(N), rint(M);

	queue<int> Q;
	rep(N)
	{
		int x;
		rint(x);
		Q.push(x);
	}

	int t = 0;
	while (!Q.empty())
	{
		int rem = M;
		while (!Q.empty() && Q.front() <= rem)
		{
			rem -= Q.front();
			Q.pop();
		}
		t++;
	}

	printf("%d\n", t);
}