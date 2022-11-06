#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


/* { */

#include <complex>

typedef long double ld;
typedef complex<ld> Point;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

const ld eps = 1e-9, pi = acos(-1.0);
const ld dtop = pi / 180.;
const ld ptod = 1. / dtop;

namespace std {
	bool operator<(const Point &lhs, const Point &rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() > rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}

// _
Point input_point() {
	ld x, y;
	cin >> x >> y;
	return Point(x, y);
}

// 
bool eq(const ld a, const ld b) {
	return (abs(a - b) < eps);
}

// 
ld dot(const Point& a, const Point& b) {
	return real(conj(a) * b);
}

// O
ld cross(const Point& a, const Point& b) {
	return imag(conj(a) * b);
}

// `
class Line {
public:
	Point a, b;
	Line() : a(Point(0, 0)), b(Point(0, 0)) {}
	Line(Point a, Point b) : a(a), b(b) {}
	Point operator[](const int _num)const {
		if (_num == 0)return a;
		else if (_num == 1)return b;
		else assert(false);
	}
};

// ~`
class Circle {
public:
	Point p;
	ld r;
	Circle() : p(Point(0, 0)), r(0) {}
	Circle(Point p, ld r) : p(p), r(r) {}
};

// CCW
int ccw(const Point& a, const Point &b, const Point &c) {
	const Point nb(b - a);
	const Point nc(c - a);
	if (cross(nb, nc) > eps) return 1;   // a,b,cv
	if (cross(nb, nc) < -eps) return -1; // a,b,cv
	if (dot(nb, nc) < 0) return 2;       // c,a,b
	if (norm(nb) < norm(nc)) return -2;  // a,b,c
	return 0;                          // a,c,b
}


/*  */

// 
bool isis_ll(const Line& l, const Line& m) {
	return !eq(cross(l.b - l.a, m.b - m.a), 0);
}

// 
bool isis_ls(const Line& l, const Line& s) {
	return isis_ll(l, s) &&
		(cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}

// 
bool isis_ss(const Line& s, const Line& t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
		ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

// _
bool isis_lp(const Line& l, const Point& p) {
	return (abs(cross(l.b - p, l.a - p)) < eps);
}

// _
bool isis_sp(const Line& s, const Point& p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

// 
Point proj(const Line &l, const Point& p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

// _
Point is_ll(const Line &s, const Line& t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
// _
//@dassert(false)
Point is_ss(const Line &s, const Line& t) {
	if (isis_ss(s, t)) {
		for (int k = 0; k < 2; ++k) {
			for (int l = 0; l < 2; ++l) {
				if (s[k] == t[l])return s[k];
			}
		}
		return is_ll(s, t);
	}
	else {
		return Point(0, 0);
	}
}
// _
ld dist_lp(const Line& l, const Point& p) {
	return abs(p - proj(l, p));
}

// 
ld dist_ll(const Line& l, const Line& m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

// 
ld dist_ls(const Line& l, const Line& s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

// _
ld dist_sp(const Line& s, const Point& p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

// 
ld dist_ss(const Line& s, const Line& t) {
	if (isis_ss(s, t)) return 0;
	return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}


//xNg
Line bisection(const Line &s, const Line &t) {
	const Point laglanju(is_ll(s, t));
	const Point avec = !(abs(laglanju - s[0]))<eps ? s[0] - laglanju : s[1] - laglanju;
	const Point bvec = !(abs(laglanju - t[0]))<eps ? t[0] - laglanju : t[1] - laglanju;

	return Line(laglanju, laglanju + (abs(bvec)*avec + abs(avec)*bvec) / (abs(avec) + abs(bvec)));
}


/* ~ */

// ~~_
vector<Point> is_cc(const Circle& c1, const Circle& c2) {
	vector<Point> res;
	ld d = abs(c1.p - c2.p);
	ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
	ld dfr = c1.r * c1.r - rc * rc;
	if (abs(dfr) < eps) dfr = 0.0;
	else if (dfr < 0.0) return res; // no intersection
	ld rs = sqrt(dfr);
	Point diff = (c2.p - c1.p) / d;
	res.push_back(c1.p + diff * Point(rc, rs));
	if (dfr != 0.0) res.push_back(c1.p + diff * Point(rc, -rs));
	return res;
}

// ~_
vector<Point> is_lc(const Circle& c, const Line& l) {
	vector<Point> res;
	ld d = dist_lp(l, c.p);
	if (d < c.r + eps) {
		ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;
		Point nor = (l.a - l.b) / abs(l.a - l.b);
		res.push_back(proj(l, c.p) + len * nor);
		res.push_back(proj(l, c.p) - len * nor);
	}
	return res;
}

// ~
vector<Point> is_sc(const Circle& c, const Line& l) {
	vector<Point> v = is_lc(c, l), res;
	for (Point p : v)
		if (isis_sp(l, p)) res.push_back(p);
	return res;
}

// ~_
vector<Line> tangent_cp(const Circle& c, const Point& p) {
	vector<Line> ret;
	Point v = c.p - p;
	ld d = abs(v);
	ld l = sqrt(norm(v) - c.r * c.r);
	if (isnan(l)) { return ret; }
	Point v1 = v * Point(l / d, c.r / d);
	Point v2 = v * Point(l / d, -c.r / d);
	ret.push_back(Line(p, p + v1));
	if (l < eps) return ret;
	ret.push_back(Line(p, p + v2));
	return ret;
}

// ~~
vector<Line> tangent_cc(const Circle& c1, const Circle& c2) {
	vector<Line> ret;
	if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
		Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
		ret = tangent_cp(c1, center);
	}
	if (abs(c1.r - c2.r) > eps) {
		Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
		vector<Line> nret = tangent_cp(c1, out);
		ret.insert(ret.end(), ALL(nret));
	}
	else {
		Point v = c2.p - c1.p;
		v /= abs(v);
		Point q1 = c1.p + v * Point(0, 1) * c1.r;
		Point q2 = c1.p + v * Point(0, -1) * c1.r;
		ret.push_back(Line(q1, q1 + v));
		ret.push_back(Line(q2, q2 + v));
	}
	return ret;
}


/* p` */

typedef vector<Point> Polygon;

// 
ld area(const Polygon &p) {
	ld res = 0;
	int n = p.size();
	REP(j, n) res += cross(p[j], p[(j + 1) % n]);
	return res / 2;
}

// p`]
bool is_counter_clockwise(const Polygon &poly) {
	ld angle = 0;
	int n = poly.size();
	REP(i, n) {
		Point a = poly[i], b = poly[(i + 1) % n], c = poly[(i + 2) % n];
		angle += arg((c - b) / (b - a));
	}
	return angle > eps;
}

// ~O
//  0 => out
//  1 => on
//  2 => in
int is_in_polygon(const Polygon &poly, const  Point& p) {
	ld angle = 0;
	int n = poly.size();
	REP(i, n) {
		Point a = poly[i], b = poly[(i + 1) % n];
		if (isis_sp(Line(a, b), p)) return 1;
		angle += arg((b - p) / (a - p));
	}
	return eq(angle, 0) ? 0 : 2;
}
//~O2@
enum { OUT, ON, IN };
int convex_contains(const Polygon &P, const Point &p) {
	const int n = P.size();
	Point g = (P[0] + P[n / 3] + P[2 * n / 3]) / 3.0l; // inner-point
	int a = 0, b = n;
	while (a + 1 < b) { // invariant: c is in fan g-P[a]-P[b]
		int c = (a + b) / 2;
		if (cross(P[a] - g, P[c] - g) > 0) { // angle < 180 deg
			if (cross(P[a] - g, p - g) > 0 && cross(P[c] - g, p - g) < 0) b = c;
			else                                                  a = c;
		}
		else {
			if (cross(P[a] - g, p - g) < 0 && cross(P[c] - g, p - g) > 0) a = c;
			else                                                  b = c;
		}
	}
	b %= n;
	if (cross(P[a] - p, P[b] - p) < 0) return 0;
	if (cross(P[a] - p, P[b] - p) > 0) return 2;
	return 1;
}

// 
// _L
Polygon convex_hull(vector<Point> ps) {
	int n = ps.size();
	int k = 0;
	sort(ps.begin(), ps.end());
	Polygon ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}



// Jbg
vector<Polygon> convex_cut(const Polygon &ps, const Line& l) {
	int n = ps.size();
	Polygon Q;
	Polygon R;
	REP(i, n) {
		Point A = ps[i], B = ps[(i + 1) % n];
		Line m = Line(A, B);
		if (ccw(l.a, l.b, A) != -1) Q.push_back(A);
		if (ccw(l.a, l.b, A) != 1) R.push_back(A);
		if (ccw(l.a, l.b, A) * ccw(l.a, l.b, B) < 0 && isis_ll(l, m)) {
			Q.push_back(is_ll(l, m));
			R.push_back(is_ll(l, m));
		}
	}
	const vector<Polygon>polys{ Q,R };
	return polys;
}


/* AWg */
void add_point(vector<Point> &ps, const Point p) {
	for (Point q : ps) if (abs(q - p) < eps) return;
	ps.push_back(p);
}

typedef int Weight;

struct Edge { int from, to; Weight weight; };

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph &g, const int from, const int to, const Weight weight) {
	g[from].push_back(Edge{ from, to, weight });
}

Graph segment_arrangement(const vector<Line> &s, const vector<Point> &p) {
	int n = p.size(), m = s.size();
	Graph g(n);
	REP(i, m) {
		vector<pair<ld, int>> vec;
		REP(j, n) if (isis_sp(s[i], p[j]))
			vec.emplace_back(abs(s[i].a - p[j]), j);
		sort(ALL(vec));
		REP(j, vec.size() - 1) {
			int from = vec[j].second, to = vec[j + 1].second;
			add_edge(g, from, to, abs(p[from] - p[to]));
		}
	}
	return g;
}
Graph sennbunn_arrangement(const vector<Line>&s) {
	vector<Point>crss;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i + 1; j < s.size(); ++j) {
			if (isis_ss( s[i],  s[j])) {
				crss.push_back(is_ll( s[i],  s[j]));
			}
		}
	}
	for (int i = 0; i <s.size(); ++i) {
		crss.push_back( s[i][0]);
		crss.push_back( s[i][1]);
	}
	return segment_arrangement(s, crss);
}

Graph circle_arrangement(const vector<Circle> &c, const vector<Point> &p) {
	int n = p.size(), m = c.size();
	Graph g(n);
	REP(i, m) {
		vector<pair<ld, int>> vec;
		REP(j, n) if (abs(abs(c[i].p - p[j]) - c[i].r) < eps)
			vec.emplace_back(arg(c[i].p - p[j]), j);
		sort(ALL(vec));
		REP(j, vec.size() - 1) {
			int from = vec[j].second, to = vec[j + 1].second;
			ld angle = vec[j + 1].first - vec[j].first;
			add_edge(g, from, to, angle * c[i].r);
		}
		if (vec.size() >= 2) {
			int from = vec.back().second, to = vec.front().first;
			ld angle = vec.front().first - vec.back().first;
			add_edge(g, from, to, angle * c[i].r);
		}
	}
	return g;
}


/* oOt */

// WAWgD
// ~vCO~vD
//  polygon Cvector<int> \p`WC
// vector<int> \ p`iC__WpD
vector<vector<int>> polygon;
vector<int> seg2p[1024][1024];

//Graph dual_graph(const vector<Line> &s, const vector<Point> &p) {
//	int N = p.size();
//	polygon.clear();
//	REP(i, 1024) REP(j, 1024) seg2p[i][j].clear();
//	vector<vector<tuple<ld, int, bool>>> tup(N);
//	REP(i, s.size()) {
//		int a = -1, b = -1;
//		REP(j, N) if (abs(s[i].a - p[j]) < eps) a = j;
//		REP(j, N) if (abs(s[i].b - p[j]) < eps) b = j;
//		assert(a >= 0 && b >= 0);
//		tup[a].emplace_back(arg(s[i].b - s[i].a), b, false);
//		tup[b].emplace_back(arg(s[i].a - s[i].b), a, false);
//	}
//	REP(i, N) sort(ALL(tup[i]));
//	REP(i, N) {
//		REP(j, tup[i].size()) {
//			ld angle; int pos = j, from = i, to; bool flag;
//			tie(angle, to, flag) = tup[i][j];
//			if (flag) continue;
//			vector<int> ps;
//			while (!flag) {
//				ps.push_back(from);
//				get<2>(tup[from][pos]) = true;
//				seg2p[from][to].push_back(polygon.size());
//				seg2p[to][from].push_back(polygon.size());
//				angle += pi + eps;
//				if (angle > pi) angle -= 2 * pi;
//				auto it = lower_bound(ALL(tup[to]), make_tuple(angle, 0, false));
//				if (it == tup[to].end()) it = tup[to].begin();
//				from = to; tie(angle, to, flag) = *it;
//				pos = it - tup[from].begin();
//			}
//			polygon.push_back(ps);
//		}
//	}
//	Graph g(polygon.size());
//	REP(i, N) REP(j, i) {
//		if (seg2p[i][j].size() == 2) {
//			int from = seg2p[i][j][0], to = seg2p[i][j][1];
//			g[from].push_back(Edge{ from, to });
//			g[to].push_back(Edge{ to, from });
//		}
//	}
//	return g;
//}


/* rWACU */
const ld zoom = 25;
const ld centerX = 6;
const ld centerY = 5;

void change_color(const int r, const int g, const int b) {
	fprintf(stderr, "c.strokeStyle = 'rgb(%d, %d, %d)';\n", r, g, b);
}


int cordx(Point p) { return 400 + static_cast<int>(zoom * (p.real() - centerX)); }
int cordy(Point p) { return 400 - static_cast<int>(zoom * (p.imag() - centerY)); }

#define cord(p) cordx(p),cordy(p)

void draw_point(const Point& p) {
	fprintf(stderr, "circle(%d, %d, %d)\n", cord(p), 2);
}

void draw_segment(const Line& l) {
	fprintf(stderr, "line(%d, %d, %d, %d)\n", cord(l.a), cord(l.b));
}

void draw_line(const Line& l) {
	Point v = l.b - l.a;
	Line m(l.a - v * Point(1e4, 0), l.b + v * Point(1e4, 0));
	fprintf(stderr, "line(%d, %d, %d, %d)\n", cord(m.a), cord(m.b));
}

void draw_polygon(const Polygon &p) {
	int n = p.size();
	REP(i, n) draw_segment(Line(p[i], p[(i + 1) % n]));
}

void draw_circle(const Circle c) {
	fprintf(stderr, "circle(%d, %d, %d)\n", cord(c.p), (int)(zoom * c.r));
}

Point goal;
Point wind1;
Point wind2;
long double v, t;

bool  getans(long double atime) {
	Point windp;
	if (atime < t) {
		windp = wind1*Point(atime,0);
	}
	else {
		windp = wind1*Point(t,0) + wind2*Point(atime-t, 0);
	}
	const Point needvec = goal-windp;
	return abs(needvec)/v<atime;
}

int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	goal=Point(x2-x1, y2-y1);
	cin >> v >> t;
	long double vx, vy, wx, wy; cin >> vx >> vy >> wx >> wy;
	wind1=Point(vx, vy);
	wind2=Point(wx, wy);

	
	{
		long double amin = 0;
		long double amax = 1e14;
		for (int i = 0; i < 10000;++i){
			long double amid = (amin  + amax) / 2;
			if (getans(amid)) {
				amax = amid;
			}
			else {
				amin = amid;
			}
		}
		cout <<fixed<<setprecision(22)<< amin << endl;
	}
	return 0;

}