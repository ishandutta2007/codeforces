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
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

const int MX = 2.1e5;
char s[MX];

int nxtTrie = -1;
struct trie
{
	trie* nxt[26];
	int idx;
	trie()
	{
		ji(26) nxt[i] = 0;
		idx = nxtTrie--;
	}

	int get(int x, int len)
	{
		if (len == 0)
		{
			return idx;
		}
		trie*& ch = nxt[s[x]-'a'];
		if (!ch)
			ch = new trie();
		return ch->get(x+1, len-1);
	}
};

map<pi, int> M;
trie tr;

int classify(int x, int len)
{
	if (len % 2 == 0)
	{
		int a = classify(x, len / 2);
		int b = classify(x + len / 2, len / 2);
		if (a > b) swap(a, b);
		pi pr{a, b};
		if (M.count(pr))
			return M[pr];
		else
		{
			int nv = M.size();
			return M[pr] = nv;
		}
	}
	else
	{
		return tr.get(x, len);
	}
}

int classify()
{
	return classify(0, strlen(s));
}

int main()
{
	scanf("%s", s);
	int a = classify();
	scanf("%s", s);
	int b = classify();
	printf("%s\n", a == b ? "YES" : "NO");
}