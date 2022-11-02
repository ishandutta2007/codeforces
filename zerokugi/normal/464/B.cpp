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

int n;

ll inp(vi &r, vi &p, vi &q){
	return (ll)(p[0]-r[0])*(q[0]-r[0]) + (ll)(p[1]-r[1])*(q[1]-r[1]) + (ll)(p[2]-r[2])*(q[2]-r[2]);
}


ll norm(vi p, vi q){
	 return (ll)(p[0]-q[0])*(p[0]-q[0]) + (ll)(p[1]-q[1])*(p[1]-q[1]) + (ll)(p[2]-q[2])*(p[2]-q[2]);
}

bool check(vector<vi> &p){
	vi ang(8);
	REP(k, 8){
		REP(i, 8)REP(j, i){
			if(i == k || j == k) continue;
			if(inp(p[k], p[i], p[j]) == 0){
//				cout << p[k] << ", " << p[i] << ", " << p[j] << endl;
				ang[k] ++;
			}
		}
		if(ang[k] != 6) return false;
	}
	REP(k, 8){
		vector<ll> dist;
		REP(i, 8){
			if(i == k) continue;
			dist.push_back(norm(p[i], p[k]));
		}
		sort(ALL(dist));
		if(dist[0] != dist[1] || dist[1] != dist[2]) return false;
	}
	return true;
}

main(){
	vector<vi> p(8, vi(3));
	REP(i, 8){
		REP(j, 3) cin >> p[i][j];
		sort(ALL(p[i]));
	}
	do{do{do{do{do{do{do{do{
//		cout << "check: " << p << endl;
		if(check(p)){
			cout << "YES" << endl;
			REP(i, 8){
				REP(j, 3) cout << p[i][j] << " ";
				cout << endl;
			}
			return 0;
		}
	}while(next_permutation(ALL(p[0])));
	sort(ALL(p[0]));
	}while(next_permutation(ALL(p[1])));
	sort(ALL(p[1]));
	}while(next_permutation(ALL(p[2])));
	sort(ALL(p[2]));
	}while(next_permutation(ALL(p[3])));
	sort(ALL(p[3]));
	}while(next_permutation(ALL(p[4])));
	sort(ALL(p[4]));
	}while(next_permutation(ALL(p[5])));
	sort(ALL(p[5]));
	}while(next_permutation(ALL(p[6])));
	sort(ALL(p[6]));
	}while(next_permutation(ALL(p[7])));
	puts("NO");
	return 0;
}