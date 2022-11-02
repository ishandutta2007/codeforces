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
map<ll, vector<ll> > memo;
vector<ll> ans;
vector<ll>& divisor(ll n){
	if(memo.find(n) != memo.end()) return memo[n];
	vector<ll> res;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			res.push_back(i);
			if(i*i!=n)res.push_back(n/i);
		}
	}
	sort(ALL(res));
	return memo[n] = res;
}

void dfs(ll X, ll k){
	stack<pair<ll, ll> > st;
	st.emplace(X, k);
	while(!st.empty()){
		X = st.top().first;
		k = st.top().second;
		st.pop();
		if(X == 1 || k == 0){
			ans.push_back(X);
			if(ans.size() == 100000) throw 0;
		}else{
			vector<ll> &div = divisor(X);
			RREP(i, div.size()) st.emplace(div[i], k-1);
		}
	}
}

ll X, k;
main(){
	cin >> X >> k;
	try{
		dfs(X, k);
	}catch(...){}
	REP(i, ans.size()) printf("%I64d ", ans[i]);
	return 0;
}