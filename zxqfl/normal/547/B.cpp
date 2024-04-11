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

struct picomp
{
	bool operator () (const pi& a, const pi& b)
	{
		return a.second - a.first < b.second - b.first;
	}
};

priority_queue<pi, vector<pi>, picomp> PQ;
set<pi, greater<pi> > S;
const int MX = 1e6;
int arr[MX];
pi srt[MX];
int N;
int finalAnswer[MX];
int nxt;

void put(int a, int b)
{
	if (b < a) return;
	S.insert({a, b});
	PQ.push({a, b});
}

pi Qtop()
{
	while (!S.count(PQ.top()))
	{
		PQ.pop();
		if (PQ.empty()) return {0, -1};
	}
	return PQ.top();
}

void processQueue(int v)
{
	if (nxt == 0) return;
	pi x = Qtop();
	while (x.second - x.first + 1 < nxt)
	{
		finalAnswer[nxt--] = v;
	}
}

int main()
{
	rint(N);
	nxt = N;
	ji(N) rint(arr[i]);
	ji(N) srt[i] = {arr[i], i};
	sort(srt, srt + N);
	S.insert({0, N-1});
	PQ.push({0, N-1});
	ji(N)
	{
		int p = srt[i].second;
		auto v = S.lower_bound({p, INF});
		int a = v->first;
		int b = v->second;
		S.erase(v);
		put(a, p-1);
		put(p+1, b);
		processQueue(srt[i].first);
	}
	ji(N) printf("%d%c", finalAnswer[i+1], i == N-1 ? '\n' : ' ');
}