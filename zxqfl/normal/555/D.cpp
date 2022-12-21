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

set<pi> Sgoleft;
set<pi, greater<pi> > Sgoright;

const int MX = 2.1e5;
int x[MX];

int simulate(int a, int l)
{
	static vector<int> V;
	V.clear();
	while (true)
	{
		if (V.size() >= 2 && a == V[V.size()-1] && a == V[V.size()-2])
			return a;
		if (V.size() >= 2 && a == V[V.size()-2])
			l %= abs(x[a] - x[V.back()]) * 2;
		V.pb(a);
		if (V.size() % 2 == 1)
		{
			int o = x[a] + l;
			auto it = Sgoright.lower_bound({o, INF});
			l -= abs(it->first - x[a]);
			a = it->second;
		}
		else
		{
			int o = x[a] - l;
			auto it = Sgoleft.lower_bound({o, -1});
			l -= abs(it->first - x[a]);
			a = it->second;
		}
	}
}

int main()
{
	nrint(N); nrint(M);
	ji(N)
	{
		rint(x[i]);
		Sgoleft.insert({x[i], i});
		Sgoright.insert({x[i], i});
	}
	jk(M)
	{
		nrint(a); a--;
		nrint(l);
		printf("%d\n", simulate(a, l) + 1);
	}
}