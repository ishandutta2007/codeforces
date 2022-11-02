#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <queue>
#include <deque>
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
template<class T> ostream& operator<<(ostream &os, const deque<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int BLOCK = 500;
int n, q;
main(){
	scanf("%d", &n);
	vector<deque<int> > deq(n/BLOCK + 1);
	vector<vi> freq(n/BLOCK + 1, vi(n+1));
	int ans;
	REP(i, n){
		int x;
		scanf("%d", &x);
		deq[i/BLOCK].push_back(x);
		freq[i/BLOCK][x] ++;
	}
	scanf("%d", &q);
	int last = 0;
	REP(i, q){
		int t, l, r, k;
		scanf("%d%d%d", &t, &l, &r);
		l = (l+last-1) % n;
		r = (r+last-1) % n;
		if(r < l) swap(l, r);
		if(t == 1){
			int t = deq[r/BLOCK][r%BLOCK];
			if(l/BLOCK < r/BLOCK){
				auto &d = deq[r/BLOCK];
				freq[r/BLOCK][t] --;
				for(;r%BLOCK;r--) d[r%BLOCK] = d[r%BLOCK-1];
				d[0] = deq[r/BLOCK-1][BLOCK-1];
				freq[r/BLOCK][d[0]] ++;
				r --;
				for(;l/BLOCK < r/BLOCK;r -= BLOCK){
					freq[r/BLOCK][deq[r/BLOCK][BLOCK-1]] --;
					deq[r/BLOCK].pop_back();
					deq[r/BLOCK].push_front(deq[r/BLOCK-1][BLOCK-1]);
					freq[r/BLOCK][deq[r/BLOCK][0]] ++;
				}
				freq[l/BLOCK][deq[l/BLOCK][BLOCK-1]] --;
				freq[l/BLOCK][t] ++;
			}
			auto &d = deq[l/BLOCK];
			l %= BLOCK;
			r %= BLOCK;
			for(;l<r;r--) d[r] = d[r-1];
			d[l] = t;
		}else{
			scanf("%d", &k);
			k = (k+last-1) % n + 1;
//			cout << l << ", " << r << "," << k << endl;
			int ans = 0;
			if(l/BLOCK < r/BLOCK){
				for(;l%BLOCK;l++) ans += deq[l/BLOCK][l%BLOCK] == k;
				for(;l/BLOCK < r/BLOCK;l+=BLOCK) ans += freq[l/BLOCK][k];
			}
			for(;l<=r;l++) ans += deq[l/BLOCK][l%BLOCK] == k;
			printf("%d\n", ans);
			last = ans;
		}
//		cout << deq << endl;
	}
	return 0;
}