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

const int MX = 2.1e5;

struct Edge
{
	int a, b;
	int oth(int x) const
	{
		return x == a ? b : a;
	}
} edgeList[MX];
vector<int> edges[MX];
int N, M, Q;
int src[MX], dst[MX];

vector<int> S, P;
int pre[MX];
int mainComponent[MX];
int treeVertex[MX];
int nxtTree = 1;
int nxtPre = 1;

void dfs(int x, Edge* from, int cid)
{
	assert(pre[x] == 0);
	pre[x] = nxtPre++;
	mainComponent[x] = cid;
	S.pb(x);
	P.pb(pre[x]);
	foreach(eidx, edges[x])
	{
		Edge* e = edgeList + eidx;
		if (e != from)
		{
			int o = e->oth(x);
			if (pre[o] == 0)
				dfs(o, e, cid);
			else if (treeVertex[o] == 0)
				while (P.back() > pre[o])
					P.pop_back();
		}
	}
	if (P.back() == pre[x])
	{
		P.pop_back();
		while (true)
		{
			treeVertex[S.back()] = nxtTree;
			if (S.back() == x)
			{
				S.pop_back();
				break;
			}
			else
				S.pop_back();
		}
		++nxtTree;
	}
}

void fail()
{
	printf("No\n");
	exit(0);
}

const int LOG = 20;

vector<int> tEdge[MX];
int parent[MX];
int dep[MX];
int jmp[MX][LOG];
int prefix[MX][2];

void initTree(int x)
{
	if (parent[x] < 0) dep[x] = 0;
	else dep[x] = 1 + dep[parent[x]];
	jmp[x][0] = parent[x];
	jjs(i, 1, LOG)
		jmp[x][i] = (jmp[x][i-1] < 0 ? -1 : jmp[jmp[x][i-1]][i-1]);
	foreach(o, tEdge[x]) if (o != parent[x])
	{
		parent[o] = x;
		initTree(o);
	}
}

int LCA(int a, int b)
{
	if (a == b) return a;
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = LOG-1; i >= 0; i--)
		if (jmp[a][i] >= 0 && dep[jmp[a][i]] >= dep[b])
			a = jmp[a][i];
	assert(dep[a] == dep[b]);
	if (a == b) return a;
	for (int i = LOG-1; i >= 0; i--)
		if (jmp[a][i] != jmp[b][i])
			a = jmp[a][i],
			b = jmp[b][i];
	assert(parent[a] == parent[b]);
	return parent[b];
}

void sweep(int x)
{
	foreach(o, tEdge[x]) if (o != parent[x])
	{
		sweep(o);
		ji(2) prefix[x][i] += prefix[o][i];
	}
	if (prefix[x][0] && prefix[x][1])
		fail();
}

int main()
{
	rint(N); rint(M); rint(Q);
	ji(M)
	{
		nrint(a); nrint(b);
		--a; --b;
		edgeList[i].a = a;
		edgeList[i].b = b;
		edges[a].pb(i);
		edges[b].pb(i);
	}
	ji(Q)
	{
		nrint(a); nrint(b);
		--a; --b;
		src[i] = a;
		dst[i] = b;
	}
	int nxt = 1;
	ji(N) if (pre[i] == 0)
	{
		dfs(i, nullptr, nxt++);
	}
	ji(M)
	{
		int a = edgeList[i].a;
		int b = edgeList[i].b;
		if (treeVertex[a] != treeVertex[b])
		{
			tEdge[treeVertex[a]].pb(treeVertex[b]);
			tEdge[treeVertex[b]].pb(treeVertex[a]);
		}
	}
	ji(Q)
	{
		if (mainComponent[src[i]] != mainComponent[dst[i]])
			fail();
	}
	ji(Q) src[i] = treeVertex[src[i]];
	ji(Q) dst[i] = treeVertex[dst[i]];
	N = nxtTree + 1;
	memset(parent, -1, sizeof parent);
	ji(N) if (parent[i] < 0)
		initTree(i);
	ji(Q)
	{
		int a = src[i];
		int b = dst[i];
		int c = LCA(a, b);
		++prefix[a][0];
		--prefix[c][0];
		++prefix[b][1];
		--prefix[c][1];
	}
	ji(N) if (parent[i] < 0)
		sweep(i);
	printf("Yes\n");
}