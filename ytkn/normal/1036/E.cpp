#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

template<typename T>
struct line {
    line(T a, T b, T c): a(a), b(b), c(c){};
    T a, b, c;
};

template<typename T>
ostream& operator<<(ostream& os, const line<T>& l){
    os << l.a << "*x + " << l.b << "*y+ " << l.c;
    return os;
}

template<typename T>
inline T add(T a, T b){
    return a+b;
}

const double eps = 1e-10;

inline double add(double a, double b){
    if(abs(a+b) < eps*(abs(a)+abs(b))) return 0.0;
    return a+b;
}

template<typename T>
class point {
    public:
    point<T>(T x, T y): x(x), y(y){};
    point<T>(): x(0), y(0){};
    T x, y;
    point<T> operator + (point<T> p){
        return point<T>(add(x, p.x), add(y, p.y));
    };
    point<T> operator - (point<T> p){
        return point<T>(add(x, -p.x), add(y, -p.y));
    };
    point<T> operator * (T d){
        return point<T>(x*d, y*d);
    };
    T dot(point<T> p){
        return add(x*p.x, y*p.y);
    };
    T det(point<T> p){
        return add(x*p.y, -y*p.x);
    };
};

/**
 * lp1, p2
 */ 
template<typename T>
line<T> from_points(point<T> p1, point<T> p2){
    return line(p2.y-p1.y, p1.x-p2.x, p1.y*p2.x-p1.x*p2.y);
}

/**
 * l: ax+by+c = 0ax+by+c
 */ 
template<typename T>
T substitute(line<T> l, point<T> p){
    return p.x*l.a+p.y*l.b+l.c;
}

/**
 * lp1, p2
 */ 
template<typename T>
bool intersect(line<T> l, point<T> p1, point<T> p2){
    return (substitute(l, p1) > 0) ^ (substitute(l, p2) > 0);
}

/**
 * p1, p2q1, q2
 */ 
template<typename T>
bool intersect(point<T> p1, point<T> p2, point<T> q1, point<T> q2){
    auto lp = from_points(p1, p2);
    auto lq = from_points(q1, q2);
    bool fq = (substitute(lq, p1) > 0) ^ (substitute(lq, p2) >=0);
    fq |= substitute(lq, p1) == 0;
    fq |= substitute(lq, p2) == 0;
    bool fp = (substitute(lp, q1) > 0) ^ (substitute(lp, q2) > 0);
    fp |= substitute(lp, q1) == 0;
    fp |= substitute(lp, q2) == 0;
    return fp&&fq;
}

template<typename T>
double dist(point<T> p1, point<T> p2){
    T dx = p1.x-p2.x;
    T dy = p1.y-p2.y;
    return sqrt(dx*dx+dy*dy);
}

template<typename T>
T dist_sq(point<T> p1, point<T> p2){
    T dx = p1.x-p2.x;
    T dy = p1.y-p2.y;
    return dx*dx+dy*dy;
}

/**
 * l1l2
 * optional
 */ 
point<double> intersection(line<double> l1, line<double> l2){
    double x = l1.b*l2.c-l2.b*l1.c;
    double y = l2.a*l1.c-l1.a*l2.c;
    double d = l1.a*l2.b-l2.a*l1.b;
    return point<double>(x/d, y/d);
}

using Pii = pair<ll, ll>;
using P = point<ll>;
using L = line<ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    ll ans = 0;
    vector<L> lines;
    vector<P> pa, pb;
    for(int i = 0; i < n; i++){
        ll ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
        ll dx = abs(bx-ax);
        ll dy = abs(by-ay);
        ll g = gcd(dx, dy);
        ans += g+1;
        pa.push_back(P(ax, ay));
        pb.push_back(P(bx, by));
        lines.push_back(from_points(P(ax, ay), P(bx, by)));
    }
    map<Pii, set<int>> st;
    for(int i = 0; i < n; i++){
        auto l1 = lines[i];
        for(int j = i+1; j < n; j++){
            if(!intersect(pa[i], pb[i], pa[j], pb[j])) continue;
            auto l2 = lines[j];
            ll x = l1.b*l2.c-l2.b*l1.c;
            ll y = l2.a*l1.c-l1.a*l2.c;
            ll d = l1.a*l2.b-l2.a*l1.b;
            if(d == 0) continue;
            if(x%d != 0) continue;
            if(y%d != 0) continue;
            st[Pii(x/d, y/d)].insert(i);
            st[Pii(x/d, y/d)].insert(j);
        }
    }
    for(auto [p, s]: st){
        ans -= s.size()-1;
    }
    cout << ans << endl;
}