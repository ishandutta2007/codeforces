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

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int N, M, T;
pi times[20010];
int ids[20010];
int pids[20010];
int online = 0;
int ocount[20010];

void add(int p)
{
	if (ocount[p] == 0)
		online++;
	ocount[p]++;
}
void remove(int p)
{
	if (ocount[p] == 1)
		online--;
	ocount[p]--;
	assert(ocount[p] >= 0);
}

int main()
{
	rint(N); rint(M); rint(T);
	ji(N)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		m += h * 60;
		s += m * 60;
		times[i] = {s, i};
	}
	sort(times, times + N);
	int pos = 0;
	int R = 0;
	bool ok = false;
	ji(N)
	{
		while (pos < i && times[i].first - times[pos].first >= T)
			remove(ids[pos++]);
		if (online == M)
			ids[i] = ids[i-1];
		else
			ids[i] = ++R;
		add(ids[i]);
		if (online == M)
			ok = true;
	}
	if (!ok)
	{
		printf("No solution\n");
	}
	else
	{
		ji(N) pids[times[i].second] = ids[i];
		printf("%d\n", R);
		ji(N) printf("%d\n", pids[i]);
	}
}