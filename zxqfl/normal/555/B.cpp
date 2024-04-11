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
typedef pair<ll, ll> pi;
typedef pair<pi, ll> ppii;

const int MX = 2.1e5;
ll L[MX], R[MX];
ll lens[MX];
int ans[MX];

void fail()
{
	printf("No\n");
	exit(0);
}

int main()
{
	nrint(N); nrint(M);
	ji(N)
	{
		rint(L[i]);
		rint(R[i]);
	}
	ji(M) rint(lens[i]);
	vector<ppii> A;
	vector<pi> B;
	ji(N-1)
	{
		ll lo = L[i+1] - R[i];
		ll hi = R[i+1] - L[i];
		A.pb({{lo, hi}, i});
	}
	ji(M) B.pb({lens[i], i});
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	set<pi> S;
	int idx = 0;
	foreach(q, B)
	{
		while (idx < A.size() && A[idx].first.first <= q.first)
		{
			S.insert({A[idx].first.second, A[idx].second});
			++idx;
		}
		auto it = S.lower_bound({q.first, -1});
		if (it != S.end())
		{
			ans[it->second] = q.second + 1;
			S.erase(it);
		}
	}
	ji(N-1) if (ans[i] == 0) fail();
	printf("Yes\n");
	ji(N-1) printf("%d ", ans[i]);
}