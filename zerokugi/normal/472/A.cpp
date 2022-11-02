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


int n, m;

vi eratosthenes_sieve(int n){
	vi res(n+1);
	if(n<2) return res;
	res[2]=1;
	for(int i=3;i<=n;i+=2){
		if(i*i<=n && !res[i]) for(int j=i+i+i;j<=n;j+=i+i) res[j]=1;
		res[i]=!res[i];
	}
	return res;
}
vi prime_list(const vi& isprime){
	vi res;if(isprime.size()<=2)return res;
	res.push_back(2);
	for(unsigned int i=3;i<isprime.size();i+=2)
		if(isprime[i])res.push_back(i);
	return res;
}
vi prime_list(int n){
	return prime_list(eratosthenes_sieve(n));
}

main(){
	vi pl = eratosthenes_sieve(1000001);
	scanf("%d", &n);
	REP(i, n){
		if(i>2 && !pl[i] && !pl[n-i]){
			printf("%d %d\n", i, n-i);
			return 0;
		}
	}
	return 0;
}