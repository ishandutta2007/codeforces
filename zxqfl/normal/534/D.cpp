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

vector<int> VV[200010];
vector<int> ans;

void get(int x)
{
	auto& V = VV[x];
	if (V.size() == 0)
	{
		printf("Impossible\n");
		exit(0);
	}
	ans.pb(V.back());
	V.pop_back();
}

int main()
{
	nrint(N);
	jk(N)
	{
		nrint(x);
		VV[x].pb(k+1);
	}
	int v = -1;
	jk(N)
	{
		v++;
		while (v >= 3 && VV[v].size() == 0)
			v -= 3;
		get(v);
	}
	if (ans.size() < N)
	{
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	ji(N) printf("%d ", ans[i]);
}