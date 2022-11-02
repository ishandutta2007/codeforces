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
#include <unordered_map>
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


unordered_map<int, vi> table;

void addRollingHash(char *S, int d){
	int hash = 0;
	int Bd = 1;
	REP(i, d) Bd *= 27;
	for(int i=0;S[i];i++){
		hash = hash*27 + S[i]-'a'+1;
		if(i-d>=0) hash -= Bd*(S[i-d]-'a'+1);
		if(i+1>=d){
			table[hash].push_back(i-d+1);
//			printf("%d, %d -> %d\n", i-d+1, d, hash);
		}
	}
}

int RollingHash(char *S){
	int hash = 0;
	for(int i=0;S[i];i++){
		hash = hash*27 + S[i]-'a'+1;
	}
	return hash;
}

int n;
char str[100011], s[10], t[10];

main(){
	scanf(" %s", str);
	REP(i, 4) addRollingHash(str, i+1);
//	FOR(it, table){
//		cout << it->first << ": " << it->second << endl;
//	}
	scanf("%d", &n);
	unordered_map<ll, int> memo;
	REP(i, n){
		scanf(" %s %s", s, t);
		int a =  RollingHash(s);
		int b =  RollingHash(t);
		ll qtar = (ll)a*531441+b;
		auto mm = memo.find(qtar);
		if(mm != memo.end()){
			printf("%d\n", mm->second);
			continue;
		}
		int al = strlen(s);
		int bl = strlen(t);
//		cout << a << ": " << table[a] << ", " << b << ": " << table[b] << endl;
		vector<int> *A = &table[a];
		vector<int> *B = &table[b];
		if(A->size() > B->size()){
			swap(A, B);
			swap(al, bl);
		}
		if(A->empty()) puts("-1");
		else{
			int ans = 100000;
			REP(i, A->size()){
				int t = (*A)[i];
				auto u = lower_bound(B->begin(), B->end(), t);
				if(u != B->end()) ans = min(ans, max(*u + bl, t+al) - min(*u, t));
				if(u != B->begin()){
					--u;
					ans = min(ans, max(*u + bl, t+al) - min(*u, t));
				}
			}
			printf("%d\n", memo[qtar] = ans);
		}
	}
	return 0;
}