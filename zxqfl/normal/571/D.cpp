#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); i++)
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
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rint(x);
#define rfloat(x) scanf("%lf", &(x))

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
	char c,r=0,n=0;
	x=0;
	for (ever)
	{
		c=getchar();
		if ((c<0) && (!r))
			return(0);
		else if ((c=='-') && (!r))
			n=1;
		else if ((c>='0') && (c<='9'))
			x=x*10+c-'0',r=1;
		else if (r)
			break;
	}
	if (n)
		x=-x;
	return(1);
}

const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

struct tr
{
	int a, b;
	tr *left, *right;
	ll sum;

	tr(const VPI& base, int l, int r)
	{
		a = base[l].first;
		b = base[r].first;
		if (l == r)
		{
			sum = base[l].second;
			left = right = 0;
		}
		else
		{
			int mid = (l + r) / 2;
			left = new tr(base, l, mid);
			right = new tr(base, mid + 1, r);
			stat();
		}
	}

	void stat()
	{
		assert(left);
		sum = left->sum + right->sum;
	}

	ll query(int l, int r) const
	{
		// printf("[%d %d] -> q(%d %d)\n", a, b, l, r);
		if (l <= a && r >= b) return sum;
		if (r < a || l > b) return 0;
		return left->query(l, r) + right->query(l, r);
	}
};

tr* buildFrom(const VPI& V)
{
	if (V.empty()) return 0;
	return new tr(V, 0, V.size() - 1);
}

const int MX = 5.1e5;

int uniRep[MX];
tr* uniMoves[MX];
VPI uniMoveList[MX];
VI uniContents[MX];

int milRep[MX];
int milLastRaid[MX];
VI milContents[MX];

ll students[MX];
int lastUpdate[MX];

typedef pair<char, pi> query_t;
int N, M;
query_t queries[MX];
bool phase2 = false;
int QID;

int find(int x, int* repArr)
{
	return repArr[x];
}

void updateDorm(int d)
{
	int u = find(d, uniRep);
	int m = find(d, milRep);
	// printf("updating on %d, d=%d, u=%d, m=%d\n", QID, d, u, m);
	if (milLastRaid[m] > lastUpdate[d])
	{
		students[d] = 0;
		lastUpdate[d] = milLastRaid[m];
	}
	if (uniMoves[u])
		students[d] += uniMoves[u]->query(lastUpdate[d], QID);
	lastUpdate[d] = QID;
}

void mergeUnis(int a, int b)
{
	a = find(a, uniRep);
	b = find(b, uniRep);
	if (a == b) return;
	if (uniContents[a].size() > uniContents[b].size())
		swap(a, b);
	foreach(z, uniContents[a])
		if (phase2) updateDorm(z);
	foreach(z, uniContents[a])
	{
		uniRep[z] = b;
		uniContents[b].pb(z);
	}
}

void mergeMils(int a, int b)
{
	a = find(a, milRep);
	b = find(b, milRep);
	if (a == b) return;
	if (milContents[a].size() > milContents[b].size())
		swap(a, b);
	foreach(z, milContents[a])
		if (phase2) updateDorm(z);
	foreach(z, milContents[a])
	{
		milRep[z] = b;
		milContents[b].pb(z);
	}
}

void doRaid(int m)
{
	m = find(m, milRep);
	milLastRaid[m] = QID;
}

void moveIn(int u)
{
	assert(!phase2);
	u = find(u, uniRep);
	uniMoveList[u].pb({QID, (int) uniContents[u].size()});
	// printf("%d move in to %d on query %d\n", (int) uniContents[u].size(), u, QID);
}

ll countStudentsInDorm(int d)
{
	updateDorm(d);
	return students[d];
}

void initialize()
{
	ji(N)
	{
		uniRep[i] = i;
		uniContents[i] = {i};
		milRep[i] = i;
		milLastRaid[i] = -1;
		milContents[i] = {i};
		students[i] = 0;
		lastUpdate[i] = -1;
	}
	++students[N];
}

void solve()
{
	phase2 = false;
	initialize();
	ji(M)
	{
		char c = queries[i].first;
		QID = i;
		if (c == 'U')
			mergeUnis(queries[i].second.first, queries[i].second.second);
		if (c == 'A')
			moveIn(queries[i].second.first);
	}
	initialize();
	phase2 = true;
	ji(N) uniMoves[i] = buildFrom(uniMoveList[i]);
	ji(M)
	{
		char c = queries[i].first;
		QID = i;
		if (c == 'U')
			mergeUnis(queries[i].second.first, queries[i].second.second);
		if (c == 'M')
			mergeMils(queries[i].second.first, queries[i].second.second);
		if (c == 'Z')
			doRaid(queries[i].second.first);
		if (c == 'Q')
			printf("%lld\n", countStudentsInDorm(queries[i].second.first));
	}
}

int main()
{
	rint(N); rint(M);
	ji(M)
	{
		char buf[5];
		scanf("%s", buf);
		char c = *buf;
		queries[i].first = c;
		rint(queries[i].second.first);
		queries[i].second.second = 0;
		if (c == 'U' || c == 'M')
			rint(queries[i].second.second);
		--queries[i].second.first;
		--queries[i].second.second;
	}
	solve();
	// while (true)
	// {
	// 	N = rand() % 100 + 2;
	// 	M = rand() % 100 + 5;
	// 	ji(M)
	// 	{
	// 		queries[i].first = "UMAZQ"[rand() % 5];
	// 		queries[i].second.first = rand() % N;
	// 		queries[i].second.second = rand() % N;
	// 		// printf("%c %d %d\n", queries[i].first, queries[i].second.first, queries[i].second.second);
	// 	}
	// 	solve();
	// }

}