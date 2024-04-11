#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

inline int signum(double x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
//XYW
#define X real()
#define Y imag()
// _
typedef complex<double> P;

namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
double cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

int n;
main(){
	P a,b,c;
	cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;
	int ret = ccw(a, b, c);
	cout << ((abs(ret) < 2) ? (ret==1?"LEFT" : "RIGHT") : "TOWARDS") << endl;
	return 0;
}