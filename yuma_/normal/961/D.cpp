#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

using ld= long double;;

ld eps=1e-9;
/*  */

#include <complex>

typedef complex<ld> Point;


const ld pi = acos(-1.0);
const ld dtop = pi / 180.;
const ld ptod = 1. / dtop;

namespace std {
	bool operator<(const Point &lhs, const Point &rhs) {
		if (lhs.real() < rhs.real() - eps) return true;
		if (lhs.real() > rhs.real() + eps) return false;
		return lhs.imag() < rhs.imag();
	}
}

// 
Point input_Point() {
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

// 
ld cross(const Point& a, const Point& b) {
	return imag(conj(a) * b);
}

// 
class Line {
public:
	Point a, b;
	Line() : a(Point(0, 0)), b(Point(0, 0)) {}
	Line(Point a, Point b) : a(a), b(b) {}
	Point operator[](const int _num)const {
		if (_num == 0)return a;
		else if (_num == 1)return b;
		else {
			assert(false);
			return Point();
		}
	}
};

// 
class Circle {
public:
	Point p;
	ld r;
	Circle() : p(Point(0, 0)), r(0) {}
	Circle(Point p, ld r) : p(p), r(r) {}
};

// ccw
// 1: a,b,c
//-1: a,b,c
// 2: c,a,b
//-2: a,b,c
// 0: a,c,b
int ccw(const Point& a, const Point &b, const Point &c) {
	const Point nb(b - a);
	const Point nc(c - a);
	if (cross(nb, nc) > eps) return 1;   // a,b,c
	if (cross(nb, nc) < -eps) return -1; // a,b,c
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

// 
bool isis_lp(const Line& l, const Point& p) {
	return (abs(cross(l.b - p, l.a - p)) < eps);
}

// 
bool isis_sp(const Line& s, const Point& p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}

// 
Point proj(const Line &l, const Point& p) {
	ld t = dot(p - l.a, l.b - l.a) / norm(l.a - l.b);
	return l.a + t * (l.b - l.a);
}

//
Point reflect(const Line &l, const Point &p) {
	Point pr = proj(l, p);
	return pr * 2.l - p;
}

// 
Point is_ll(const Line &s, const Line& t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
// 
vector<Point> is_ll2(const Line &s, const Line& t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	if (cross(sv, tv) != 0)return vector<Point>(1, is_ll(s, t));
	else {
		vector<Point>ans;
		for (int k = 0; k < 2; ++k) {
			if (isis_sp(s, t[k]) && find(ans.begin(), ans.end(), t[k]) == ans.end())ans.push_back(t[k]);
			if (isis_sp(t, s[k]) && find(ans.begin(), ans.end(), s[k]) == ans.end())ans.push_back(s[k]);
		}
		return ans;
	}
}
// 
//assert(false)
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
		//isis_ss
		assert(false);
		return Point(0, 0);
	}
}
// 
vector<Point> is_ss2(const Line &s, const Line& t) {
	vector<Point> kouho(is_ll2(s, t));
	vector<Point>ans;
	for (auto p : kouho) {
		if (isis_sp(s, p) && isis_sp(t, p))ans.emplace_back(p);
	}
	return ans;
}
// 
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

// 
ld dist_sp(const Line& s, const Point& p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

// 
ld dist_ss(const Line& s, const Line& t) {
	if (isis_ss(s, t)) return 0;
	return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}


//
Line line_bisection(const Line &s, const Line &t) {
	const Point laglanju(is_ll(s, t));
	const Point avec = !(abs(laglanju - s[0])<eps) ? s[0] - laglanju : s[1] - laglanju;
	const Point bvec = !(abs(laglanju - t[0])<eps) ? t[0] - laglanju : t[1] - laglanju;

	return Line(laglanju, laglanju + (abs(bvec)*avec + abs(avec)*bvec) / (abs(avec) + abs(bvec)));
}
//a
Line point_bisection(const Point&a, const Point&b) {
	const Point cen((a + b) / 2.l);
	const Point vec = (b - a)*Point(0, 1);
	return Line(cen, cen + vec);
}

//
Point outer_center(const vector<Point>&ps) {
	assert(ps.size() == 3);
	Line l1 = point_bisection(ps[0], ps[1]);
	Line l2 = point_bisection(ps[1], ps[2]);
	return is_ll(l1, l2);
}


//
//
Point  inner_center(const vector<Line>&ls) {
	vector<Point>vertics;
	for (int i = 0; i <static_cast<int>(ls.size()); ++i) {
		vertics.push_back(is_ll(ls[i], ls[(i + 1) % 3]));
	}
	if (vertics[0] == vertics[1] || vertics[1] == vertics[2] || vertics[2] == vertics[0])return vertics[0];
	Line bi1(line_bisection(Line(vertics[0], vertics[1]), Line(vertics[0], vertics[2])));
	Line bi2(line_bisection(Line(vertics[1], vertics[2]), Line(vertics[1], vertics[0])));
	if (bi1[0] == bi2[0])return bi1[0];
	else {
		return is_ll(bi1, bi2);
	}
}

//
//
vector<Point>  ex_center(const vector<Line>&ls) {
	vector<Point>vertics;
	for (int i = 0; i < static_cast<int>(ls.size()); ++i) {
		vertics.push_back(is_ll(ls[i], ls[(i + 1) % 3]));
	}
	if (abs(vertics[0] - vertics[1])<eps || abs(vertics[1] - vertics[2])<eps || (abs(vertics[2] - vertics[0])<eps))return vector<Point>();
	vector<Point>ecs;
	for (int i = 0; i < 3; ++i) {
		Line bi1(line_bisection(Line(vertics[i], vertics[i] * 2.0l - vertics[(i + 2) % 3]), Line(vertics[i], vertics[(i + 1) % 3])));
		Line bi2(line_bisection(Line(vertics[(i + 1) % 3], vertics[(i + 1) % 3] * 2.0l - vertics[(i + 2) % 3]), Line(vertics[(i + 1) % 3], vertics[i])));
		ecs.push_back(is_ll(bi1, bi2));
	}
	return ecs;
}


//a,b:
//c:
//
vector<Point>  same_dis(const vector<Line>&ls) {
	vector<Point>vertics;
	vertics.push_back(is_ll(ls[0], ls[2]));
	vertics.push_back(is_ll(ls[1], ls[2]));

	if (abs(vertics[0] - vertics[1]) < eps)return vector<Point>{vertics[0]};
	Line bis(line_bisection(ls[0], ls[1]));
	vector<Point>ecs;

	Line abi(line_bisection(Line(vertics[0], vertics[1]), ls[0]));
	ecs.push_back(is_ll(bis, abi));


	Line bbi(line_bisection(Line(vertics[0], 2.l*vertics[0] - vertics[1]), ls[0]));
	ecs.push_back(is_ll(bis, bbi));

	return ecs;
}
/*  */

// 
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

/*

0 => out
1 => on
2 => in*/
int is_in_Circle(const  Point& p, const Circle &cir) {
	ld dis = abs(cir.p - p);
	if (dis > cir.r + eps)return 0;
	else if (dis < cir.r - eps)return 2;
	else return 1;
}
int is_in_Circle(const Circle &cir, const  Point& p) {
	ld dis = abs(cir.p - p);
	if (dis > cir.r + eps)return 0;
	else if (dis < cir.r - eps)return 2;
	else return 1;
}
/*
lcrc
0 => out
1 => on
2 => in*/
int Circle_in_Circle(const Circle &lc, const  Circle&rc) {
	ld dis = abs(lc.p - rc.p);
	if (dis < rc.r - lc.r - eps)return 2;
	else if (dis>rc.r - lc.r + eps)return 0;
	else return 1;
}

// 
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

// 
vector<Point> is_sc(const Circle& c, const Line& l) {
	vector<Point> v = is_lc(c, l), res;
	for (Point p : v)
		if (isis_sp(l, p)) res.push_back(p);
	return res;
}

// 
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

// 
vector<Line> tangent_cc(const Circle& c1, const Circle& c2) {
	vector<Line> ret;
	if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
		Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
		ret = tangent_cp(c1, center);
	}
	if (abs(c1.r - c2.r) > eps) {
		Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
		vector<Line> nret = tangent_cp(c1, out);
		ret.insert(ret.end(), nret.begin(), nret.end());
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
//
ld two_Circle_area(const Circle&l, const Circle&r) {
	ld dis = abs(l.p - r.p);
	if (dis > l.r + r.r)return 0;
	else if (dis + r.r < l.r) {
		return r.r*r.r*pi;
	}
	else if (dis + l.r < r.r) {
		return l.r*l.r*pi;
	}
	else {
		ld ans = (l.r)*(l.r)*acos((dis*dis + l.r*l.r - r.r*r.r) / (2 * dis*l.r)) +
			(r.r)*(r.r)*acos((dis*dis + r.r*r.r - l.r*l.r) / (2 * dis*r.r)) -
			sqrt(4 * dis*dis*l.r*l.r - (dis*dis + l.r*l.r - r.r*r.r)*(dis*dis + l.r*l.r - r.r*r.r)) / 2;
		return ans;
	}

}

/*  */

typedef vector<Point> Polygon;



//()O(N=)
//
#include<random>
Circle welzl(vector<Point>ps) {
	struct solver {
		Circle solve(vector<Point>&ps, vector<Point>&rs) {
			if (ps.empty() || rs.size() == 3) {
				if (rs.size() == 1) {
					return Circle(Point(rs[0]), 0);
				}
				else if (rs.size() == 2) {
					return Circle((rs[0] + rs[1]) / 2.0l, abs(rs[1] - rs[0]) / 2);
				}
				else if (rs.size() == 3) {
					vector<Line> ls(3);
					for (int i = 0; i < 3; ++i) {
						ls[i] = Line(rs[i], rs[(i + 1) % 3]);
					}
					Point center = outer_center(rs);
					return Circle(center, abs(center - rs[0]));
				}
				else {
					return Circle(Point(), 0);
				}
			}
			else {

				Point p_ba = ps.back();
				ps.pop_back();
				Circle d = solve(ps, rs);
				ps.push_back(p_ba);
				if (is_in_Circle(d, p_ba)) {
					return d;
				}
				else {
					rs.push_back(p_ba);
					ps.pop_back();
					auto ans = solve(ps, rs);
					ps.push_back(p_ba);
					rs.pop_back();
					return ans;
				}
			}
		}
	}so;
	std::random_device rd;
	std::mt19937 mt(rd());
	shuffle(ps.begin(), ps.end(), mt);
	vector<Point>rs;
	Circle ans = so.solve(ps, rs);
	return ans;
}
// 
ld get_area(const Polygon &p) {
	ld res = 0;
	int n = p.size();
	for (int j = 0; j<n; ++j) res += cross(p[j], p[(j + 1) % n]);
	return res / 2;
}

//
bool is_counter_clockwise(const Polygon &poly) {
	ld angle = 0;
	int n = poly.size();
	for(int i=0;i<n;++i) {
		Point a = poly[i], b = poly[(i + 1) % n], c = poly[(i + 2) % n];
		angle += arg((c - b) / (b - a));
	}
	return angle > eps;
}

// 
/*0 => out
1 => on
2 => in*/
int is_in_Polygon(const Polygon &poly, const  Point& p) {
	ld angle = 0;
	int n = poly.size();
	for(int i=0;i<n;++i) {
		Point a = poly[i], b = poly[(i + 1) % n];
		if (isis_sp(Line(a, b), p)) return 1;
		angle += arg((b - p) / (a - p));
	}
	return eq(angle, 0) ? 0 : 2;
}
//2
enum { out, on, in };
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
//
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



//
vector<Polygon> convex_cut(const Polygon &ps, const Line& l) {
	int n = ps.size();
	Polygon q;
	Polygon r;
	for(int i=0;i<n;++i) {
		Point a = ps[i], b = ps[(i + 1) % n];
		Line m = Line(a, b);
		if (ccw(l.a, l.b, a) != -1) q.push_back(a);
		if (ccw(l.a, l.b, a) != 1) r.push_back(a);
		if (ccw(l.a, l.b, a) * ccw(l.a, l.b, b) < 0 && isis_ll(l, m)) {
			q.push_back(is_ll(l, m));
			r.push_back(is_ll(l, m));
		}
	}
	const vector<Polygon>polys{ q,r };
	return polys;
}


/*  */
void add_Point(vector<Point> &ps, const Point p) {
	for (Point q : ps) if (abs(q - p) < eps) return;
	ps.push_back(p);
}



vector<Line> solve(vector<Point>&ps, int num) {
	assert(num==1);
	if (num == 1) {
		Point p0(ps[0]);
		for (int i = 1; i < 2; ++i) {
			Point px(ps[i]);
			Line li(p0, px);

			vector<int>oks(ps.size());
			for (int j = 0; j < ps.size(); ++j) {
				if (isis_lp(li, ps[j])) {
					oks[j] = true;
				}
			}
			if (all_of(oks.begin(), oks.end(), [](int n) {return n == 1; })) {
				return vector<Line>{li};
			}
		}
	}
	else {
		for (int i = 0; i < ps.size(); ++i) {
			for (int j = i+1; j < ps.size(); ++j) {
				for (int k = i; k < ps.size(); ++k) {
					for (int l = k+1; l < ps.size(); ++l) {
						Line li0(ps[i],ps[j]);
						Line li1(ps[k],ps[l]);

						vector<int>oks(ps.size());
						for (int x = 0; x < ps.size(); ++x) {
							if (isis_lp(li0, ps[x])) {
								oks[x] = true;
							}
							if (isis_lp(li1, ps[x])) {
								oks[x] = true;
							}
						}
						if (all_of(oks.begin(), oks.end(), [](int n) {return n == 1; })) {
							return vector<Line>{li1,li0};
						}
					}
				}
			}
		}
	}
	return vector<Line>(0);
}


int main() {
	int N; cin >> N;

	/*cout<<102<<endl;
	for (int i = 0; i < 102; ++i) {
		cout<<i<<" "<<i*i+1<<endl;
	}*/

	vector<Point>ps;
	for (int i = 0; i < N; ++i) {
		int x,y;cin>>x>>y;
		ps.push_back(Point(x,y));
	}

	bool ok=false;
	if (N <=2) {
		ok=true;
	}
	else {
		
		Line l01=Line(ps[0],ps[1]);
		Line l12=Line(ps[1],ps[2]);
		Line l20=Line(ps[0],ps[2]);

		if (isis_lp(l01, ps[2])) {
			vector<int>oks(N);
			vector<Point>not_okps;
			for (int i = 0; i < N; ++i) {
				if (isis_lp(l01, ps[i])) {

				}
				else {
					not_okps.push_back(ps[i]);
				}
			}

			if (not_okps.size() <= 2) {
				ok=true;
			}
			else {
				auto l = solve(not_okps, 1);
				if (l.empty()) {
					ok = false;
				}
				else {
					ok = true;
				}
			}
			
		}
		else {
			{
				vector<int>oks(N);

				vector<Point>not_okps;
				for (int i = 0; i < N; ++i) {

					if (isis_lp(l12, ps[i])) {
					}
					else {
						not_okps.push_back(ps[i]);
					}

				}
				if (not_okps.size() <= 2) {
					ok = true;
				}
				else {
					auto l = solve(not_okps, 1);
					if (l.empty()) {
					}
					else {
						ok = true;
					}
				}
			}

			{
				vector<int>oks(N);

				vector<Point>not_okps;
				for (int i = 0; i < N; ++i) {

					if (isis_lp(l20, ps[i])) {
					}
					else {
						not_okps.push_back(ps[i]);
					}

				}
				if (not_okps.size() <= 2) {
					ok = true;
				}
				else {
					auto l = solve(not_okps, 1);
					if (l.empty()) {
					}
					else {
						ok = true;
					}
				}
			}

			{
				vector<int>oks(N);

				vector<Point>not_okps;
				for (int i = 0; i < N; ++i) {

					if (isis_lp(l01, ps[i])) {
					}
					else {
						not_okps.push_back(ps[i]);
					}

				}
				if (not_okps.size() <= 2) {
					ok = true;
				}
				else {
					auto l = solve(not_okps, 1);
					if (l.empty()) {
					}
					else {
						ok = true;
					}
				}
			}
		}
	}
	if (ok) {
		cout<<"YES"<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
	return 0;
}