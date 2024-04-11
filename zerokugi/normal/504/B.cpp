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


struct handler{
	typedef int val_t;
	handler(){}
	inline static val_t def_val(){ return INF; }
	inline static val_t update(const val_t &l, const val_t &r){
		return r;
	}
	inline static val_t merge(const val_t &l, const val_t &r){
		return min(l, r);
	}
};

template<class H>
struct RBST{
	unsigned long xor128(){
		static unsigned long x=123456789,y=362436069,z=521288629,w=88675123;
		unsigned long t=(x^(x<<11));x=y;y=z;z=w; return w=(w^(w>>19))^(t^(t>>8));
	}
	typedef typename H::val_t val_t;
	struct Node{
		val_t v, sum;
		Node* ch[2];
		int c;
		Node(const val_t &v):v(v), sum(v), c(1){ch[0]=ch[1]=0;}
	};
	typedef pair<Node*, Node*> PNode;
	int count(Node* v){return v ? v->c : 0;}
	val_t val(Node* v){return v ? v->v : H::def_val();}
	val_t sum(Node* v){return v ? v->sum : H::def_val();}
	Node* update(Node *v){
		v->c = count(v->ch[0]) + count(v->ch[1]) + 1;
		v->sum = H::merge(H::merge(sum(v->ch[0]), v->v), sum(v->ch[1]));
		return v;
	}
	Node* merge(Node* l, Node* r){
		if(!l || !r) return !l ? r : l;
		if(xor128() % (count(l) + count(r)) < count(l)){
			l->ch[1] = merge(l->ch[1], r);
			return update(l);
		}else{
			r->ch[0] = merge(l, r->ch[0]);
			return update(r);
		}
	}
	PNode split(Node *v, int k){	// [0, k), [k, n)
		if(!v) return PNode(0, 0);
		if(k <= count(v->ch[0])){
			PNode s = split(v->ch[0], k);
			v->ch[0] = s.second;
			return PNode(s.first, update(v));
		}else{
			PNode s = split(v->ch[1], k - count(v->ch[0]) - 1);
			v->ch[1] = s.first;
			return PNode(update(v), s.second);
		}
	}
	Node* insert(Node *v, int k, Node *t){
		if(!v || !t) return !t ? v : t;
		PNode s = split(v, k);
		return merge(merge(s.first, t), s.second);
	}
	Node* insert(Node *v, int k, const val_t &val){
		return insert(v, k, new Node(val));
	}
	Node* erase(Node* v, int k){
		PNode s = split(v, k);
		PNode p = split(s.second, 1);
//		delete p.first;
		return merge(s.first, p.second);
	}
	val_t kth(Node* v, int k){
		if(!v) return H::def_val();
		if(k == count(v->ch[0])) return val(v);
		if(k < count(v->ch[0])) return kth(v->ch[0], k);
		else return kth(v->ch[1], k - count(v->ch[0]) - 1);
	}
	val_t query(Node *v, int l, int r, int k=0){
		if(!v || r <= 0 || count(v) <= l) return H::def_val();
		if(l<=0 && count(v) <= r) return v->sum;
		if(r <= count(v->ch[0])) return query(v->ch[0], l, r, k);
		if(count(v->ch[0]) < l) return query(v->ch[1], l-count(v->ch[0])-1, r-count(v->ch[0])-1, k+count(v->ch[0])+1);
		return H::merge(query(v->ch[0], l, r, k), H::merge(v->v, 
						query(v->ch[1], l-count(v->ch[0])-1, r-count(v->ch[0])-1, k+count(v->ch[0])+1)));
	}
	Node* update(Node* v, int k, const val_t &val){
		if(!v || k < 0 || count(v) <= k) return v;
		if(k == count(v->ch[0])) v->v = H::update(v->v, val);
		else if(k < count(v->ch[0])) update(v->ch[0], k, val);
		else update(v->ch[1], k-count(v->ch[0])-1, val);
		return update(v);
	}
	Node* build(const vector<val_t> &val, int l=0, int r=-1){
		if(r==-1) r = val.size();
		if(r<=l) return 0;
		Node *v = new Node(val[(l+r)/2]);
		v->ch[0] = build(val, l, (l+r)/2);
		v->ch[1] = build(val, (l+r)/2+1, r);
		return update(v);
	}
	friend ostream& operator<<(ostream &os, Node* v){
		if(!v) return os;
		if(v->ch[0]) os << v->ch[0] << ", ";
		os << v->v;
		if(v->ch[1]) os << ", " << v->ch[1];
		return os;
	}
};
class BIT {
	int n;
	vector<int> vs;
public:
	BIT(int size) {
		n = size;
		vs = vector<int>(n);
	}
	//O(log n)
	void add(int k, int a) {
		for(int i = k; i < n; i |= i + 1) vs[i] += a;
	}
	//[s,t)	O(log n)
	int sum(int s, int t) {
		if(s > 0) return sum(0, t) - sum(0, s);
		int res = 0;
		for(int i = t - 1; i >= 0; i = (i & (i + 1)) - 1) res += vs[i];
		return res;
	}
};

int n, m;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	vi d(n), e(n);
	BIT bit1(n), bit2(n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		d[i] = x - bit1.sum(0, x);
		bit1.add(x, 1);
	}
	REP(i, n){
		int x;
		scanf("%d", &x);
		e[i] = x - bit2.sum(0, x);
		bit2.add(x, 1);
	}
	vi a(n);
	RREP(i, n){
		if(i && a[i]+d[i]+e[i] >= n-i) a[i-1] ++;
		a[i] = (a[i]+d[i]+e[i])%(n-i);
	}
	vi unused;
	REP(i, n) unused.pb(i);
	RBST<handler> rbst;
	auto root = rbst.build(unused);
	vector<int> ans(n);
	REP(i, n){
		printf("%d ", rbst.kth(root, a[i]));
		root = rbst.erase(root, a[i]);
	}
	REP(i, n) 
	return 0;
}