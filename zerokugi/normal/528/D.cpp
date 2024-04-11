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
const double M_PI = 3.14159265358979323846264338;

int n, m, k, n2;
char s[300010], t[300010];

typedef complex<double> cd;
void fft(cd f[], int N, bool inv){
	int n;
	for(n=0;N!=(1<<n);n++);
	REP(m, N){
		int m2 = 0;
		REP(i,n) if(m&(1<<i)) m2 |= (1<<(n-1-i));
		if(m < m2) swap(f[m], f[m2]);
	}

	for(int t=1;t<N;t*=2){
		double theta = M_PI / t;
		cd w(cos(theta), sin(theta));
		if(inv) w = cd(cos(theta), -sin(theta));
		for(int i=0;i<N;i+=2*t){
			cd power(1.0, 0.0);
			REP(j,t){
				cd tmp1 = f[i+j] + f[i+t+j] * power;
				cd tmp2 = f[i+j] - f[i+t+j] * power;
				f[i+j] = tmp1;
				f[i+t+j] = tmp2;
				power = power * w;
			}
		}
	}
	if(inv) REP(i, N) f[i] /= N;
}

vi solve(char c){
	vi sum(n+1);
	REP(i, n)if(s[i] == c){
		sum[max(i-k, 0)]++;
		sum[min(i+k+1, n)]--;
	}
	vi a(n2), b(n2);
	vector<complex<double>> s1(n2), s2(n2), t1(n2), t2(n2);
	REP(i, n){
		sum[i+1] += sum[i];
		if(sum[i] > 0) s1[i] = 1;
	}
	int cnt = 0;
	REP(i, m){
		if(t[i] == c){
			s2[m-i-1] = 1;
			cnt ++;
		}
	}
	fft(s1.data(), n2, 0);
	fft(s2.data(), n2, 0);
	REP(i, n2) s1[i] = s1[i]*s2[i];
	fft(s1.data(), n2, 1);
	vi res(n2);
	REP(i, n2){
		if(s1[i].real() > cnt-0.5) res[i] = 1;
	}
	return res;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	n2=1;
	while(n2<n+1) n2<<=1;
	scanf(" %s %s", s, t);
	vector<vi> ret(4);
	ret[0] = solve('A');
	ret[1] = solve('T');
	ret[2] = solve('G');
	ret[3] = solve('C');
	int ans = 0;
	REP(i, n2){
		int x=0;
		REP(j, 4) x += ret[j][i];
		ans += x == 4;
	}
	printf("%d\n", ans);
	return 0;
}