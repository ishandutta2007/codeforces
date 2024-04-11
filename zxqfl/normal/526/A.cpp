#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

bool solve()
{
	int N;
	char str[200];
	rint(N);
	scanf("%s", str);
	auto ok = [&](int x) {
		return x < N && str[x] == '*';
	};
	ji(N)
	{
		for (int len = 1; len < N; len++)
		{
			bool tok = true;
			jk(5)
				tok &= ok(i + len * k);
			if (tok) return true;
		}
	}
	return false;
}

int main()
{
	printf("%s\n", solve() ? "yes" : "no");
}