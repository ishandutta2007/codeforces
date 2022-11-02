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
#include <assert.h>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a,b) make_pair(a, b)
#define pb push_back
#define eb emplace_back
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;
}
template<class T> ostream& operator<<(ostream &os, const set<T> &t) {
os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;
}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}
template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;
struct SuffixArray{
	template <bool End, class T>
	vi compute_buckets(const T *s, int n, int k) const {
		vi buckets(k);
		REP(i, n) ++buckets[s[i]];
		int sum = 0;
		REP(i, k){
			sum += buckets[i];
			buckets[i] = (End ? sum : (sum - buckets[i]));
		}
		return buckets;
	}
	template <class T>
	void induce_sa_l(int *sa, const T *s, int n, int k, const vi &ls) const{
		vi buckets(compute_buckets<false>(s, n, k));
		REP(i, n){
			const int j = sa[i] - 1;
			if(j >= 0 && !ls[j]){ sa[buckets[s[j]]++] = j; }
		}
	}
	template <class T>
	void induce_sa_s(int *sa, const T *s, int n, int k, const vi &ls) const{
		vi buckets(compute_buckets<true>(s, n, k));
		RREP(i, n){
			const int j = sa[i] - 1;
			if(j >= 0 && ls[j]){ sa[--buckets[s[j]]] = j; }
		}
	}
	bool is_lms(const vi& ls, int i)const {
		return i>0 && !ls[i-1] && ls[i];
	}
	
	template <class T>
	void sa_is(int *sa, const T *s, int n) const{
		vi ls(n); // 0:L 1:S
		ls[n-1] = 1;
		RREP(i, n-1) ls[i] = (s[i] != s[i+1]) ? s[i] < s[i+1] : ls[i+1];
		const int k = (int)*std::max_element(s, s + n) + 1;
		vi buckets = compute_buckets<true>(s, n, k);
		REP(i, n) sa[i] = -1;
		REPS(i, n-1) if(is_lms(ls, i)) sa[--buckets[s[i]]] = i;
		induce_sa_l(sa, s, n, k, ls);
		induce_sa_s(sa, s, n, k, ls);
		int m = 0;
		REP(i, n) if(is_lms(ls, sa[i])) sa[m++] = sa[i];
		for(int i=m;i<n;i++) sa[i] = -1;
		int num = 0, prev = -1;
		REP(i, m){
			int p = sa[i], diff = 0;
			REP(d, n){
				const int l = p+d, r = prev + d;
				if(prev < 0 || s[l] != s[r] || ls[l] != ls[r]){
					diff = 1;
					break;
				}else if(d > 0 && (is_lms(ls, l) || is_lms(ls, r))){
					break;
				}
			}
			if(diff){
				num ++;
				prev = p;
			}
			p = (p-(p&1))/2;
			sa[m+p] = num-1;
		}
		for(int i=n-1, j=n-1;i>=m;i--) if(sa[i] >= 0) sa[j--]=sa[i];
		int *reduced_s = sa+n-m;
		if(num < m) sa_is(sa, reduced_s, m);
		else REP(i, m) sa[reduced_s[i]] = i;
		buckets = compute_buckets<true>(s, n, k);
		int j=0;
		REPS(i, n-1)if(is_lms(ls, i)) reduced_s[j++] = i;
		REP(i, m) sa[i] = reduced_s[sa[i]];
		for(int i=m;i<n;i++) sa[i] = -1;
		RREP(i, m){
			const int j = sa[i];
			sa[i] = -1;
			sa[--buckets[s[j]]] = j;
		}
		induce_sa_l(sa, s, n, k, ls);
		induce_sa_s(sa, s, n, k, ls);
	}
	
	vi sa;

	template <class T>
	vi sa_is(const T &s) const {
		if(s.size() == 0){ return vi(1); }
		const int n = s.size() + 1;
		vi vs(n), sa(n);;
		REP(i, n-1){ vs[i] = s[i]; }
		sa_is(&sa[0], &vs[0], n);
		return sa;
	}
	template <class T>
	explicit SuffixArray(const T &s):sa(sa_is(s)){}
	size_t size() const { return sa.size(); }
	int operator[](int i) const { return sa[i]; }
};


struct LCP{
	int n;
	vi vs, isa, lcp;
	template <class T>
	LCP(const T &s, const vi &sa):n(sa.size()),vs(n),isa(n),lcp(n - 1){
		REP(i, n-1) vs[i] = s[i];
		REP(i, n) isa[sa[i]] = i;
		int h = 0, j;
		REP(i, n)if((j = isa[i]) > 0){
			while(vs[sa[j] + h] == vs[sa[j-1] + h]) h++;
			lcp[j-1] = h;
			if(h > 0) --h;
		}
	}
	int operator[](int i) const{
		return lcp[i];
	}
};

int n, m;
string s;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	SuffixArray sa(s);
	LCP lcp(s, sa.sa);
	
	vi &isa = lcp.isa;
	vi minsum(s.size()+1);
	minsum[0] = s.size();
	for(int i=isa[0]-1;i>=0;i--) minsum[sa[i]] = min(lcp[i], minsum[sa[i+1]]);
	for(int i=isa[0]+1;i<s.size();i++)  minsum[sa[i]] = min(lcp[i-1], minsum[sa[i-1]]);
	vi y(m);
	REP(i, m){
		cin >> y[i];
		y[i]--;
	}
	sort(ALL(y));
	y.pb(INF);
	int c = -1, j = 0, k = 0, node = 0;
	ll ans = 1;
	REP(i, n){
		if(y[j] == i){
			if(max(0, c)+minsum[max(0, c)] < s.size()){
				cout << 0 << endl;
				return 0;
			}
			c = 0;
			j ++;
		}
		if(c == -1) ans = ans*26%MOD;
		else{
			if(++c == s.size()) c = -1;
		}
	}
	cout << (c == -1 ? ans : 0ll) << endl;
	return 0;
}