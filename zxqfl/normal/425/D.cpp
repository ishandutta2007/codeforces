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

const int MX = 100010;
const int SZ = 350;

ll ans;
vector<int> pts[MX];
int N;

bool is(int x, int y)
{
	if (y < 0 || y >= MX) return false;
	auto it = lower_bound(pts[y].begin(), pts[y].end(), x);
	return it != pts[y].end() && *it == x;
}

int main()
{
	rint(N);
	jk(N)
	{
		nrint(x);
		nrint(y);
		pts[y].pb(x);
	}
	ji(MX) sort(pts[i].begin(), pts[i].end());
	vector<int> large;
	jjl(ypos, MX)
	{
		if (pts[ypos].size() > SZ)
			large.pb(ypos);
		else
		{
			auto& V = pts[ypos];
			ji(V.size()) jjs(j, i+1, V.size())
			{
				int d = V[j] - V[i];
				if (ypos - d >= 0 && pts[ypos - d].size() > SZ)
					ans += is(V[i], ypos - d) && is(V[j], ypos - d);
				ans += is(V[i], ypos + d) && is(V[j], ypos + d);
			}
		}
	}
	ji(large.size()) jjs(j, i+1, large.size())
	{
		int a = large[i];
		int b = large[j];
		auto& A = pts[a];
		auto& B = pts[b];
		int d = b - a;
		int l1 = 0;
		int r1 = 0;
		int r2 = 0;
		for (int l2 = 0; l2 < A.size(); l2++)
		{
			int p = A[l2];
			while (p - A[l1] > d)
				l1++;
			while (r2 < B.size() && p > B[r2])
				r2++;
			if (r2 == B.size())
				break;
			while (p - B[r1] > d)
				r1++;
			ans += A[l2] == B[r2] && B[r1] == p - d && A[l1] == p - d;
		}
	}
	printf("%lld\n", ans);
}