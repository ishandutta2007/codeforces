#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> istream& operator>>(istream& is,vector<T>& v) { for(T& t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { for(T t:v){os<<t<<" ";} os<<"\n"; return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

const double eps = 1e-9;
const double PI = acos(-1);
int sgn(double a) { return a < -eps ? -1 : (a > eps ? 1 : 0); }
double torad(double deg) { return deg*PI/180; }
double todeg(double rad) { return rad*180/PI; }

struct point {
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    point operator+(const point &p) const{ return {x+p.x,y+p.y}; }
    point operator-(const point &p) const{ return {x-p.x,y-p.y}; }
    point operator*(double a) const{ return {x*a,y*a}; }
    point operator*(const point &p) const{ return point(x*p.x-y*p.y,x*p.y+y*p.x); }
    point operator/(double a) const{ return {x/a,y/a}; }
    point operator-() const{ return *this*(-1); }
    bool operator==(const point &p) const{ return !sgn(x-p.x) && !sgn(y-p.y); }
    bool operator!=(const point &p) const{ return !(*this == p); }
    bool operator<(const point &p) const{ return sgn(x-p.x) ? x < p.x : y < p.y;}
    bool operator>(const point &p) const{ return sgn(x-p.x) ? x > p.x : y > p.y;}
    double norm() const{ return x*x+y*y; }
    double abs() const{ return sqrt(norm()); }
    point rot(double rad) const{ return point(cos(rad)*x-sin(rad)*y,sin(rad)*x+cos(rad)*y); }
    point rot90() const{ return point(-y,x); }
    double arg() const{ double res = atan2(y,x); if(sgn(res) < 0) res += 2*PI; return res;}
};
istream& operator>>(istream &is,point &p){ return is >> p.x >> p.y; }
ostream& operator<<(ostream &os,const point &p){ return os << '(' << p.x << "," << p.y << ')'; }
double dist(const point &a,const point &b) { return (a-b).abs(); }
double dot(const point &a,const point &b) { return a.x*b.x+a.y*b.y; }
double cross(const point &a,const point &b) { return a.x*b.y-a.y*b.x; }
point mid(const point &a,const point &b) { return (a+b)/2; }
int ccw(const point &a,const point &b,const point &c) {
    // 1 -> c is upper than line(a,b)
    // -1 -> c is lower than line(a,b)
    // 2 -> in order [a,b,c]
    // -2 -> in order [c,a,b]
    // 0 -> in order [a,c,b]
    point nb = b-a,nc = c-a;
    if(sgn(cross(nb,nc))) return sgn(cross(nb,nc));
    if(sgn(dot(nb,nc)) < 0) return -2;
    if(sgn(nc.abs()-nb.abs()) > 0) return 2;
    return 0;
}
struct line {
    point a,b;
    line(point a=point(),point b=point()):a(a),b(b) {}
    bool online(const point &p) const{ return abs(ccw(a,b,p)) != 1; }
};
ostream& operator<<(ostream &os,const line &l){ return os << '{' << l.a << ',' << l.b << '}'; }
struct segline {
    point a,b;
    segline(point a=point(),point b=point()):a(a),b(b) {}
    bool online(const point& p) const{ return !ccw(a,b,p); }
    line vertical_bisector() const{ return line(mid(a,b),mid(a,b)+(b-a).rot90()); }
};
ostream& operator<<(ostream &os,const segline &l){ return os << '{' << l.a << ',' << l.b << '}'; }
bool vertical(const line &l,const line &m) { return !sgn(dot(l.a-l.b,m.a-m.b)); }
bool vertical(const segline &l,const segline &m) { return !sgn(dot(l.a-l.b,m.a-m.b)); }
bool parallel(const line &l,const line &m) { return !sgn(cross(l.a-l.b,m.a-m.b)); }
bool parallel(const segline &l,const segline &m) { return !sgn(cross(l.a-l.b,m.a-m.b)); }
bool operator==(const line &l,const line &m) { return parallel(l,m) && l.online(m.a); }
bool operator!=(const line &l,const line &m) { return !(l == m); }
bool operator==(const segline &l,const segline &m) { return l.a == m.a && l.b == m.b || l.a == m.b && l.b == m.a; }
bool operator!=(const segline &l,const segline &m) { return !(l == m); }
// intersect at one point
bool intersect(const line &l,const line &m) { return !parallel(l,m); }
bool intersect(const line &l,const segline &m) { return sgn(cross(l.b-l.a,m.a-l.a)*cross(l.b-l.a,m.b-l.a)) <= 0; }
bool intersect(const segline &l,const segline &m) {
    return ccw(l.a,l.b,m.a)*ccw(l.a,l.b,m.b) <= 0 &&
        ccw(m.a,m.b,l.a)*ccw(m.a,m.b,l.b) <= 0;
}
point intersection(const line &l,const line &m) {
    assert(intersect(l,m));
    return l.a+(l.b-l.a)*cross(m.b-m.a,m.a-l.a)/cross(m.b-m.a,l.b-l.a);
}
point intersection(const line &l,const segline &m) {
    assert(intersect(l,m));
    return l.a+(l.b-l.a)*cross(m.b-m.a,m.a-l.a)/cross(m.b-m.a,l.b-l.a);
}
point intersection(const segline &l,const segline &m) {
    assert(intersect(l,m));
    return l.a+(l.b-l.a)*cross(m.b-m.a,m.a-l.a)/cross(m.b-m.a,l.b-l.a);
}
double dist(const line &l,const point &p) { return abs(cross(l.b-l.a,p-l.a))/(l.b-l.a).abs(); }
double dist(const segline &l,const point &p) {
    if(sgn(dot(l.b-l.a,p-l.a)) < 0) return dist(p,l.a);
    if(sgn(dot(l.a-l.b,p-l.b)) < 0) return dist(p,l.b);
    return dist(line(l.a,l.b),p);
}
double dist(const line &l,const line &m) {
    if(parallel(l,m)) return dist(l,m.a);
    return 0;
}
double dist(const line &l,const segline &m) {
    if(intersect(l,m)) return 0;
    return min(dist(l,m.a),dist(l,m.b));
}
double dist(const segline &l,const segline &m) {
    if(intersect(l,m)) return 0;
    return min({dist(l,m.a),dist(l,m.b),dist(m,l.a),dist(m,l.b)});
}
point projection(const line &l,const point &p) {
    double d = dot(p-l.a,l.b-l.a)/(l.b-l.a).norm();
    return l.a+(l.b-l.a)*d;
}
point gaisin(const point &a,const point &b,const point &c) {
    return intersection(segline(a,b).vertical_bisector(),segline(b,c).vertical_bisector());
}
struct circle {
    point o;
    double r;
    circle(point o=point(),double r=0):o(o),r(r) {}
    bool inside(const point &p) const{ return sgn(r-dist(o,p)) >= 0; }
    double area() const{ return r*r*PI; }
};
ostream& operator<<(ostream &os,const circle &c) { return os << '{' << c.o << ',' << c.r << '}'; }
bool intersect(const circle &c,const line &l) { return sgn(dist(l,c.o)-c.r) <= 0; }
bool intersect(const circle &c,const segline &l) {
    if(sgn(dist(l,c.o)-c.r) > 0) return false;
    return sgn(max((c.o - l.a).abs(), (c.o - l.b).abs()) - c.r) >= 0;
}
vector<point> intersection(const circle &c,const line &l) {
    point p = projection(l,c.o);
    if(!intersect(c,l)) return {};
    if(sgn(dist(l,c.o)-c.r) == 0) return {p};
    point e = (l.b-l.a)/(l.b-l.a).abs();
    double d = sqrt(c.r*c.r-(p-c.o).norm());
    return {p-e*d,p+e*d};
}
vector<point> intersection(const circle &c,const segline &l) {
    auto v = intersection(c,line(l.a,l.b));
    vector<point> ret;
    for(point p : v) if(l.online(p)) ret.pb(p);
    return ret;
}
vector<point> intersection(const circle &a,const circle &b) {
    double d = dist(a.o,b.o);
    if(!sgn(a.r+b.r-d)) return {a.o+(b.o-a.o)*a.r/d};
    if(!sgn(a.r-b.r-d)) return {a.o+(b.o-a.o)*a.r/d};
    if(!sgn(b.r-a.r-d)) return {b.o+(a.o-b.o)*b.r/d};
    if(sgn(abs(a.r-b.r)-d) > 0 || sgn(a.r+b.r-d) < 0) return {};
    double x = (a.r*a.r+d*d-b.r*b.r)/(2*d);
    double y = sqrt(a.r*a.r-x*x);
    point p = (b.o-a.o).rot90()*y/d;
    point tomid = a.o+(b.o-a.o)*x/d;
    return {tomid+p,tomid-p};
}
vector<circle> circle_with_two_points_and_radius(const point &a,const point &b,const double &r) {
    if(sgn(dist(a,b)-2*r) > 0) return {};
    circle A(a,r),B(b,r);
    auto v = intersection(A,B);
    vector<circle> ret;
    for(point p : v) ret.eb(p,r);
    return ret;
};
vector<point> tanline(const circle &c,const point& p) {
    int s = sgn(dist(c.o,p)-c.r);
    if(s < 0) return {};
    if(s == 0) return {p};
    double d = (p-c.o).norm()-c.r*c.r;
    return intersection(c,circle(p,sqrt(d)));
}

void solve() {
    int n;
    cin >> n;
    n *= 2;
    double d = 2*PI/n;
    vector<point> v;
    point now(0.5/sin(d/2),0);
    rep(i,n) {
        v.pb(now);
        now = now.rot(d);
    }
    for(auto &p : v) p = p.rot(d/4);
    double mxy = 0,mny = 0,mxx = 0,mnx = 0;
    for(auto &p : v) {
        chmax(mxy,p.y);
        chmin(mny,p.y);
        chmax(mxx,p.x);
        chmin(mnx,p.x);
    }
    cout << max(mxy-mny,mxx-mny) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    rep(i,t) solve();
}