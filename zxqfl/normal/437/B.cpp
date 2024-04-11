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
#define iter(it, C) for (__typeof(C.begin()) it = C.begin(); it != C.end(); ++it)

typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	while (true)
	{
		int N = -1;
		rint(N);
		if (N < 0) break;
		nrint(L);
		vector<pi> V;
		jjs(i, 1, L+1)
		{
			V.push_back(pp(i & -i, i));
		}
		sort(V.begin(), V.end());
		reverse(V.begin(), V.end());
		vector<int> ans;
		iter(it, V)
		{
			pi x = *it;
			if (x.first <= N)
			{
				ans.push_back(x.second);
				N -= x.first;
			}
		}
		if (N != 0)
			printf("-1\n");
		else
		{
			printf("%d\n", (int) ans.size());
			iter(it, ans) printf("%d ", *it);
			printf("\n");
		}
	}
}