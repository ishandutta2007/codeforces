#include <bits/stdc++.h>
using namespace std;

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


const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> pi;
int N;
int a[200000];
map<int, int> idxmap;

struct stree
{
	int a, b;
	stree *left, *right;
	int cnt;

	stree(int l, int r)
	{
		a = l;
		b = r;
		cnt = 0;
		if (a == b)
			left = right = 0;
		else
		{
			int mid = (a + b) / 2;
			left = new stree(a, mid);
			right = new stree(mid+1, b);
		}
	}
	stree(stree* x, stree* y)
	{
		a = x->a;
		b = y->b;
		left = x;
		right = y;
		cnt = x->cnt + y->cnt;
	}
	stree(stree* x)
	{
		*this = *x;
		cnt++;
	}

	int query(int l, int r)
	{
		if (l > b || r < a)
			return 0;
		if (l <= a && r >= b)
			return cnt;
		return left->query(l, r) + right->query(l, r);
	}
	stree* update(int pos)
	{
		if (pos < a || pos > b)
			return this;
		if (a == b)
			return new stree(this);
		return new stree(left->update(pos), right->update(pos));
	}
};

stree* trees[200001];

int solve(int x, ll k)
{
	int ans = 0;
	for (int o = x*k+1; o <= x*k+k; o++)
	{
		if (o*k+1 < N)
		{
			ans += solve(o, k);
			if (a[o] < a[x])
				ans++;
		}
		else
		{
			int s = o;
			int e = int(min(N-1ll, x * k + k));
			ans += trees[e+1]->query(-1, a[x]-1);
			ans -= trees[s]->query(-1, a[x]-1);
			break;
		}
	}
	return ans;
}

int main()
{
	rint(N);
	ji(N) rint(a[i]);
	set<int> S;
	ji(N) S.insert(a[i]);
	int idx = 0;
	foreach(v, S) idxmap[v] = idx++;
	ji(N) a[i] = idxmap[a[i]];
	trees[0] = new stree(0, N-1);
	ji(N)
	{
		trees[i+1] = trees[i]->update(a[i]);
	}
	jk(N-1) printf("%d ", solve(0, k+1));
}