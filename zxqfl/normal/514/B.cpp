#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define rint(x) scanf("%d", &(x))
#define nrint(x) int x; rint(x);
#define pp make_pair

typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	while (true)
	{
		int N = -1;
		rint(N);
		if (N < 0) break;
		nrint(x0); nrint(y0);
		set<pi> S;
		jk(N)
		{
			nrint(x); nrint(y);
			x -= x0;
			y -= y0;
			int d = __gcd(abs(x), abs(y));
			x /= d;
			y /= d;
			if (x < 0 || (x == 0 && y < 0))
			{
				x = -x;
				y = -y;
			}
			S.insert(pp(x, y));
		}
		printf("%d\n", (int) S.size());
	}
}