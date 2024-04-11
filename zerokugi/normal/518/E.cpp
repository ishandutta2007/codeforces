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


int n, k;
vi solve(vector<vi> &d){
	int invalid = 0;
	REP(i, k){
		REP(j, d[i].size()){
			if(d[i][j] == 1145141919){
				if(j && d[i][j-1] != 1145141919 && d[i][j-1] >= -1) d[i][j] = d[i][j-1]+1;
			}else{
				if(j && d[i][j-1] != 1145141919 && d[i][j-1] >= d[i][j]) return vi();
			}
		}
		RREP(j, d[i].size()){
			if(d[i][j] == 1145141919){
				if(j+1<d[i].size() && d[i][j+1] != 1145141919 && d[i][j+1] <= 1) d[i][j] = d[i][j+1]-1;
			}else{
				if(j+1<d[i].size() && d[i][j+1] != 1145141919 && d[i][j+1] <= d[i][j]) return vi();
			}
		}
		int tail = -1, tailp = 0;
		REP(j, d[i].size()+1){
			ll cur = j<d[i].size() ? d[i][j] : 1145141918;
			if(cur == 1145141919 && tail == -1){
				tail = j;
				tailp = j ? d[i][j-1]+1 : -1145141918;
			}
			if(cur != 1145141919 && tail != -1){
				int len = j-tail;
				if(len > cur - tailp) return vi();
				if((len-1)/2 >= cur-1){
					for(int p=j-1;p>=tail;p--) d[i][p] = cur - (j-p);
				}else if((len-1)/2 > - tailp){
					for(int p=tail;p<j;p++) d[i][p] = tailp + (p-tail);
				}else{
					int center = (tail+j-1)/2;
					for(int p=tail;p<j;p++) d[i][p] = p - center;
				}
				tail = -1;
			}
		}
	}
	vi res(n);
	REP(i, n) res[i] = d[i%k][i/k];
	return res;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	vector<vi> d(k);
	REP(i, n){
		string s;
		cin >> s;
		if(s == "?") d[i%k].pb(1145141919);
		else d[i%k].pb(atoi(s.c_str()));
	}
	auto res = solve(d);
	if(res.empty()) cout << "Incorrect sequence" << endl;
	else{
		REP(i, n) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}