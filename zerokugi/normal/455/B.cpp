#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

struct Tree{
	Tree* p[27];
	Tree(){
		memset(p, 0, sizeof(p));
	}
} tr;

void add(string &s, int t, Tree *p){
	if(t == s.size()) return;
	if(p->p[s[t] - 'a'] == 0){
		p->p[s[t] - 'a'] = new Tree();
	}
	add(s, t+1, p->p[s[t] - 'a']);
}

bool win(Tree *p){
	bool res = false;
	REP(i, 27)if(p->p[i]){
		if(!win(p->p[i])) return true;
	}
	return res;
}

bool lose(Tree *p){
	bool res = true;
	REP(i, 27)if(p->p[i]){
		if(lose(p->p[i])) res = false;
		else return true;
	}
	return res;
}

int n, m;
main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int ans;
	REP(i, n){
		string s;
		cin >> s;
		add(s, 0, &tr);
	}
	bool w = win(&tr);
	bool l = lose(&tr);
	if(l && w) cout << "First" << endl;
	else if(!w) cout << "Second" << endl;
	else if(m & 1) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}