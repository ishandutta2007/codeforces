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

const int MX = 100009;
int N;
char s[MX], t[MX];

int main()
{
	rint(N);
	scanf("%s%s", s, t);
	int ans = 0;
	ji(N) if (s[i] != t[i])
	{
		bool seen = false;
		bool ok = true;
		for (int j = i; j < N; j++)
		{
			if (seen)
			{
				if (s[j] != t[j])
					ok = false;
			}
			else
			{
				if (s[j+1] != t[j])
					seen = true;
			}
		}
		if (ok) ans++;
		break;
	}
	ji(N) swap(s[i], t[i]);
	ji(N) if (s[i] != t[i])
	{
		bool seen = false;
		bool ok = true;
		for (int j = i; j < N; j++)
		{
			if (seen)
			{
				if (s[j] != t[j])
					ok = false;
			}
			else
			{
				if (s[j+1] != t[j])
					seen = true;
			}
		}
		if (ok) ans++;
		break;
	}
	printf("%d\n", ans);
}