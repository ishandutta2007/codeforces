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

 class NazoTable{
	int N, K;
	vector< vector<int> > d;
	
	int combine(int i, int j){
		return __gcd(i, j);
	}
	
public:
	NazoTable(){}
	NazoTable(vector<int> v){
		N=v.size();
		K = 1;
		while((1<<K)<v.size()) K++;
		v.resize(1<<K);
		d = vector< vector<int> >(K, vector<int>(1<<K));
		for(int k=0;k<K;k++){
			for(int i=0;i<1<<(K-k-1);i++){
				int center = (i<<(k+1)) | (1<<k);
				d[k][center-1] = v[center-1];
				d[k][center  ] = v[center  ];
				for(int j=2;j<=(1<<k);j++) if(center  <N) d[k][center-j] = combine(v[center-j], d[k][center-j+1]);
				for(int j=1;j<(1<<k);j++)  if(center+j<N) d[k][center+j] = combine(d[k][center+j-1], v[center+j]);
			}
		}
	}
	
	int query(int l, int r){ // [l, r]
		r--;
		if(r<l) return 0;
		// index list O(logn)  O(1)
		for(int k=K-1;k>=0;k--) if((l^r)&(1<<k)) return combine(d[k][l], d[k][r]);
		return d[0][l];
	}
};

int n, m;
main(){
	map<int, vi> dic;
	scanf("%d", &n);
	vi d(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		d[i] = x;
		dic[x].push_back(i);
	}
	FOR(it, dic) sort(ALL(it->second));
	NazoTable tbl(d);
	scanf("%d", &m);
	REP(i, m){
		int l, r;
		scanf("%d%d", &l, &r);l--;
		int g=tbl.query(l, r);
		auto &it=dic[g];
		int c = upper_bound(ALL(it), r-1) - lower_bound(ALL(it), l);
		printf("%d\n", r-l-c);
	}
	return 0;
}