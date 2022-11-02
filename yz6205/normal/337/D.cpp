#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

void init();
void solve();
int main(){
try { 

#ifndef CUSTOM_MAIN
#ifdef MULTIPLE_TEST_CASES_WITH_T

int T; scanf("%d",&T); while(T--) {init(); solve();}

#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T

while(1) {try{init(); } catch(bool t){return 0;} solve(); }

#else

init(); solve();

#endif
#endif
#endif

} catch (const char* s) { return 0; }
    return 0;
}

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"
#else
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define IIII "%d%d%d%d"
#define IN "%d\n"
#define IIN "%d%d\n"
#define IIIN "%d%d%d\n"
#define IIIIN "%d%d%d%d\n"
#endif

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define repe(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr; typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }
class Scanner{ private: istream& ist;public: Scanner(istream& in):ist(in){} string next(){ string r; ist >> r; return r; } string nextLine(){ string r; getline(ist,r); return r; } int nextInt(){ int r; ist >> r; return r; } double nextDouble(){ double r; ist >> r; return r; } char nextChar(){ char r; ist>>r; return r;} }; Scanner sc(cin);
void ALERT(bool judgememt, const char* phrase) { if (judgememt) { puts(phrase); throw "ALERT"; } }
bool alert(bool judgememt, const char* phrase) { if (judgememt) puts(phrase); return judgememt; }

const int N = 100005;
vector < int > e[N];
int n, m, p;
int dis[N][3];
int is[N];

void init() {
    scanf(III,&n,&m,&p);
    rep (i,m) is[sc.nextInt()] = 1;
    rep (i,n-1) {
    	int u, v; scanf(II,&u,&v);
    	e[u].push_back(v);
    	e[v].push_back(u);
	}
	memset(dis, 0xcf, sizeof(dis));
}

inline void update(int& a, int& b, int u) {
	if (u >= a) {
		b = a; a = u;
	} else {
		checkMax(b, u);	
	}
}

void dfs0(int u, int f) {
	if (is[u]) update(dis[u][0], dis[u][1], 0);
	for (int v: e[u]) {
		if (v == f) continue;
		dfs0(v, u);
		update(dis[u][0], dis[u][1], dis[v][0]+1);
		//update(dis[u][0], dis[u][1], dis[v][1]+1);
	}
}

void dfs1(int u, int f, int current) {
	dis[u][2] = current;
	for (int v: e[u]) {
		if (v == f) continue;
		int next = dis[u][0];
		if (dis[v][0]+1 == dis[u][0]) next = dis[u][1];
		checkMax(next, current);
		dfs1(v, u, next+1);
	}
}

void solve() {
	dfs0(1,0);
	dfs1(1,0,0xcfcfcfcf);
	int ans = 0;
	repa (i,n) {
		ses(dis[i][0]);ses(dis[i][1]);see(dis[i][2]);
		int m = max(dis[i][0], dis[i][2]);
		if (m <= p) ans++;
	}
	printf(IN,ans);
}