#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<ld, ld> pdd;
#define F first
#define S second

pdd operator+(const pdd &p1, const pdd &p2) {
    return {p1.F + p2.F, p1.S + p2.S};
}

pdd operator-(const pdd &p1, const pdd &p2) {
    return {p1.F - p2.F, p1.S - p2.S};
}

pdd operator*(const ld &d, const pdd &p) {
    return {d * p.F, d * p.S};
}

ld operator*(const pdd &p1, const pdd &p2) {
    return p1.F * p2.F + p1.S * p2.S;
}

ld operator^(const pdd &p1, const pdd &p2) {
    return p1.F * p2.S - p1.S * p2.F;
}

const ld eps = 1e-8;

bool is_0(ld x) {
    return fabs(x) <= eps;
}

int sgn(ld x) {
    return (x > eps) - (x < -eps);
}   

const int N = 100006;

pdd intersect(pdd p1, pdd p2, pdd q1, pdd q2) {
    return p1 + ((q1 - p1) ^ (q2 - q1)) / ((p2 - p1) ^ (q2 - q1)) * (p2 - p1);
}

bool on_seg(pdd p1, pdd p2, pdd q) {
    //todo: check p1p2 parallel to p1q before calling this function
    if ( sgn( (p1 - p2) ^ (p1 - q) ) != 0) return false;
    return sgn( (p1 - q) * (p2 - q) ) == -1;
}

bool banana(pdd p1, pdd p2, pdd q1, pdd q2) {
    if ( sgn( (p1 - p2) ^ (q1 - q2) ) == 0 ) {        
        return false;
    }
    return sgn( (p1 - q1) ^ (p2 - q1) ) * sgn( (p1 - q2) ^ (p2 - q2) ) == -1 && 
           sgn( (q1 - p1) ^ (q2 - p1) ) * sgn( (q1 - p2) ^ (q2 - p2) ) == -1;
}

ld dis(pdd p) {
    return sqrt(p * p);
}

typedef pair<pdd, pdd> Line;
vector<pdd> pts[N];
Line line[N];
int n;

bool in_polygon(pdd p) {
    for (int i = 0; i < n; ++i) {
        pdd a = line[3 * i].F;
        pdd b = line[3 * i + 1].F;
        pdd c = line[3 * i + 2].F;
        pdd d = {889301, 890501};
        if (on_seg(a, b, p)) continue;
        if (on_seg(b, c, p)) continue;
        if (on_seg(a, c, p)) continue;
        int cnt = 0;
        if (banana(p, d, a, b)) ++cnt;//return true;
        if (banana(p, d, b, c)) ++cnt;//return true;
        if (banana(p, d, a, c)) ++cnt;//return true;
        if (cnt & 1) return true;
    }
    return false;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int id = 0;
    for (int i = 1; i <= n; ++i) {
        pdd a, b, c;
        cin >> a.F >> a.S >> b.F >> b.S >> c.F >> c.S;
        pts[id].push_back(a); pts[id].push_back(b); 
        line[id] = {a, b}; ++id;
        pts[id].push_back(b); pts[id].push_back(c); 
        line[id] = {b, c}; ++id;
        pts[id].push_back(a); pts[id].push_back(c); 
        line[id] = {c, a}; ++id;
    }
    for (int i = 0; i < id; ++i) {
        for (int j = i + 1; j < id; ++j) {
            pdd a = line[i].F, b = line[i].S, c = line[j].F, d = line[j].S;
            if (a == c || a == d || b == c || b == d) continue;
            if (banana(a, b, c, d)) {
                pdd ret = intersect(a, b, c, d);
                //cout << "a = " << a.F << " , " << a.S << " , b = " << b.F << " , " << b.S << " c = " << c.F << " , " << c.S << " , d = " << d.F << " , " << d.S << " , ret = " << ret.F << " , " << ret.S << endl;
                pts[i].push_back(ret);
                pts[j].push_back(ret);
            }
        }
    }
    ld ans = 0;
    for (int i = 0; i < id; ++i) {
        sort(pts[i].begin(), pts[i].end());
        pts[i].resize(unique(pts[i].begin(), pts[i].end()) - pts[i].begin());
        for (int j = 0; j < (int)pts[i].size() - 1; ++j) {
            if (!in_polygon( 0.5*(pts[i][j] + pts[i][j+1]) )) {
                //cout << "pts = " << pts[i][j].F << " , " << pts[i][j].S << " and " << pts[i][j + 1].F << " , " << pts[i][j + 1].S << endl;
                ans += dis(pts[i][j + 1] - pts[i][j]);
            }
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
}