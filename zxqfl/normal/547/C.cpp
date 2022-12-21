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

const int MX = 5.2e5;
int cnt[MX];
int arr[MX];
bool in[MX];
ll ans = 0;
int N, Q;

vector<int> factors(int x)
{
	int base = x;
	vector<int> ans;
	for (int i = 2; i * i <= base && x != 1; i++) if (x % i == 0)
	{
		ans.pb(i);
		do {
			x /= i;
		} while (x % i == 0);
	}
	if (x != 1) ans.pb(x);
	return ans;
}

unordered_map<ll, int> mapping;

void modify(int base, int dir)
{
	vector<int> F = factors(base);
	int S = F.size();
	ji(1 << S)
	{
		ll v = 1;
		jj(S) if (i & (1 << j))
			v *= F[j];
		if (dir == -1)
			mapping[v] += dir;
		ll change = mapping[v] * (__builtin_popcount(i) % 2 ? -1 : 1) * dir;
		if (dir == 1)
			mapping[v] += dir;
		ans += change;
	}
}

int main()
{
	rint(N); rint(Q);
	ji(N) rint(arr[i]);
	jk(Q)
	{
		nrint(idx);
		--idx;
		modify(arr[idx], in[idx] ? -1 : 1);
		in[idx] = !in[idx];
		printf("%lld\n", ans);
	}
}