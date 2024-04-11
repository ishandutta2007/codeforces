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
	nrint(ax);
	nrint(ay);
	nrint(bx);
	nrint(by);
	if (ax + ay <= max(bx, by)) return true;
	if (bx >= ax && by >= ay) return true;
	while (true)
	{
		if (ax + ay == 1)
			return true;
		if (ax == 0)
			ay--;
		else if (ay == 0)
			ax--;
		else
		{
			if (ax - ay > bx - by)
				ax--;
			else
				ay--;
		}
		if (bx - 1 == ax && by - 1 == ay)
			return true;
		else if (max(bx, by) <= 1)
			return false;
		else
		{
			if (bx) bx--;
			if (by) by--;
		}
	}
}

int main()
{
	printf("%s\n", solve() ? "Polycarp" : "Vasiliy");
}