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

#ifndef ONLINE_JUDGE
const bool DEBUG = true;
#define Db(x...)   ({ if (DEBUG) { cout << "Debug["; DB, #x, ":", x, "]\n"; } })
template<class T> void Dbrng(T lo, T hi, string note = "", int w = 0) {
  if (DEBUG) {  
    cout << "Debug[ ";
    if (!note.empty()) cout << setw(3) << note << " : ";
    for (; lo != hi; ++lo) cout << setw(w) << *lo << " ";
    cout << "]" << endl;
  }
}
struct Debugger { template<class T> Debugger& operator ,
  (const T & v) { cout << " " << v << flush; return *this; } } DB;
#else
const bool DEBUG = false;
#define Db(x...)
#endif

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

int N, Q;

const int MX = 2.1e5;
const int TMX = MX * 8;

#define _L (idx*2+1)
#define _R (idx*2+2)
#define _M ((l+r)/2)

int tLeft[TMX];
int tRight[TMX];
int tMin[TMX];

vector<pi> queries;
int answers[MX];
int qX[MX];
int qY[MX];
char qDir[MX];

void build(int idx, int l, int r)
{
	if (l == r)
	{
		tLeft[idx] = tRight[idx] = queries[l].first;
		tMin[idx] = queries[l].second;
	}
	else
	{
		build(_L, l, _M);
		build(_R, _M+1, r);
		tLeft[idx] = tLeft[_L];
		tRight[idx] = tRight[_R];
		tMin[idx] = min(tMin[_L], tMin[_R]);
	}
}

int query(int idx, int a, int b)
{
	if (a <= tLeft[idx] && b >= tRight[idx])
		return tMin[idx];
	if (a > tRight[idx] || b < tLeft[idx])
		return INF;
	return min(query(_L, a, b), query(_R, a, b));
}

void upd(int idx, int a)
{
	if (a < tLeft[idx] || a > tRight[idx])
		return;
	if (tLeft[idx] == tRight[idx])
		tMin[idx] = INF;
	else
	{
		upd(_L, a);
		upd(_R, a);
	}
}

void solve(int l, int r, int cei, int lef)
{
	if (l > r) return;
	int q = query(0, l, r);
	if (q >= INF) return;
	int x = qX[q];
	int y = qY[q];
	char dir = qDir[q];
	upd(0, x);
	if (dir == 'U')
	{
		answers[q] = y - cei;
		solve(l, x-1, cei, lef);
		solve(x+1, r, cei, x);
	}
	else
	{
		answers[q] = x - lef;
		solve(l, x-1, y, lef);
		solve(x+1, r, cei, lef);
	}
}

int main()
{
	rint(N); rint(Q);
	set<int> S;
	ji(Q)
	{
		rint(qX[i]);
		rint(qY[i]);
		char st[10];
		scanf("%s", st);
		qDir[i] = st[0];
		if (S.count(qX[i]))
			continue;
		S.insert(qX[i]);
		queries.pb({qX[i], i});
	}
	sort(queries.begin(), queries.end());
	build(0, 0, queries.size()-1);
	solve(1, N, 0, 0);
	ji(Q) printf("%d\n", answers[i]);
}