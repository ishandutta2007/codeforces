#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;

typedef complex<double> P;
const double EPS = 1e-8;
struct L {
    P x, y;
    L();
    L(P a, P b) {x=a, y=b;};
};

inline double cross(const P &a, const P &b) { return a.real()*b.imag()-a.imag()*b.real(); }
inline double dot(const P &a, const P &b) { return a.real()*b.real()+a.imag()*b.imag(); }

inline int ccw(const P &a, const P &b, const P &c) {
    double cr = cross(b-a, c-a);
    if (cr > EPS) return 1;
    if (cr < -EPS) return -1;
    if (dot(b-a, c-a) <= EPS) return 2;
    if (dot(a-b, c-b) <= EPS) return -2;
    return 0;
}


bool insSS(const L &s, const L &t) {
    int a = ccw(s.x,s.y,t.x), b = ccw(s.x,s.y,t.y);
    int c = ccw(t.x,t.y,s.x), d = ccw(t.x,t.y,s.y);
    if (!a || !b || !c || !d) return true;
    if (a*b < 0 && c*d < 0) return true;
    return false;
}

typedef vector<P> Pol;

int contains(const Pol &pol, P p) {
    bool in = false;
    for (int i = 0; i < pol.size(); i++) {
        P a=pol[i]-p, b=pol[(i+1)%pol.size()]-p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b)) {
            if (cross(a, b) < 0) in = !in;
        }
    }
    return in;
}

const int MN = 220;
const int MD = 1e9+7;
int n;
P p[MN];

Pol pol;
ll dp[MN][MN][MN];
bool used[MN][MN][MN] = {};
vector<L> pl;
bool isok(int a, int b) {
    if (a == b) return false;
    if ((b+1)%n==a || (a+1)%n==b) return true;
    L l = L(p[a], p[b]);
    for (int i = 0; i < n; i++) {
        if (insSS(l, pl[i])) {
            return false;
        }
    }
    return contains(pol, (p[a]+p[b])/2.0);
}

bool iss[MN][MN] = {};
ll solve(int a, int b, int c) {
    if (c>=n || b>=c || a>=b) return 1;
    if (c-b == 1) return 1;
    if (dp[a][b][c] != -1) return dp[a][b][c];
    ll r = 0;
    for (int i = b+1; i <= c; i++) {
        if (iss[a][i] && iss[b][i]) {
            r += (solve(b,b+1,i)*solve(a,i,c))%MD;
            r %= MD;
        }
    }
    dp[a][b][c] = r;
    return r;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p[i] = P(x*2, y*2);
    }
    for (int i = 0; i < n; i++) {
        pl.push_back(L(p[i], p[(i+1)%n]));
    }
    pol = Pol(p, p+n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            iss[i][j] = iss[j][i] = isok(i, j);
        }
    }
    fill_n(dp[0][0], MN*MN*MN, -1);
    cout << solve(0, 1, n-1) << endl;
    return 0;
}