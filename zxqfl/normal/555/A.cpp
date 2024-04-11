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

const int MX = 1.1e5;
int dolls[MX];
int contained[MX];
vector<int> chains[MX];
int N, K;
int ans;

void extract(int x)
{
	if (dolls[x] < 0) return;
	auto& V = chains[dolls[x]];
	while (V.back() != x)
	{
		dolls[V.back()] = -1;
		if (V.size() > 1)
			contained[V[V.size()-2]] = -1;
		++ans;
		if (V.back() == x)
		{
			V.pop_back();
			break;
		}
		else
			V.pop_back();
	}
}

void fullExtract(int x)
{
	if (dolls[x] < 0) return;
	else extract(chains[dolls[x]][0]);
}

int main()
{
	rint(N); rint(K);
	memset(contained, -1, sizeof contained);
	ji(K)
	{
		nrint(M);
		jk(M)
		{
			nrint(x);
			--x;
			dolls[x] = i;
			chains[i].pb(x);
		}
		jj(M-1)
			contained[chains[i][j]] = chains[i][j+1];
	}
	for (int i = 0; i < N-1; i++)
	{
		if (contained[i] == i+1)
			continue;
		extract(i);
		fullExtract(i+1);
		++ans;
	}
	printf("%d\n", ans);
}