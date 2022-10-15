#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

__int128 one = 1;

__int128 sqr(long long x){
	return x * one * x;
}

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
	Point() : x(0), y(0) {}
	friend istream& operator>>(istream& in, Point& p) {
		in >> p.x >> p.y;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Point& p) {
		out << p.x << " " << p.y;
		return out;
	}

	long long dot(const Point& p) const {
		return x * 1ll * p.x + y * 1ll * p.y;
	}

	Point normal() const {
		// (p.x, p.y) dot (p.y, -p.x) = 0
		// 90 degrees counter-clockwise
		return Point(-y, x);
	}

	// axis sizes might not stay the same
	Point rename(const Point& p) const {
		return Point(dot(p), dot(p.normal()));
	}

	Point operator-(const Point& p) const {
		return Point(x - p.x, y - p.y);
	}

	Point operator-() const {
		return Point(-x, -y);
	}

	long long cross(const Point& p) const {
		return x * 1ll * p.y - y * 1ll * p.x;
	}

	bool operator<(const Point& p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

struct LineSegment {
	Point a, b;

	LineSegment(){}
	LineSegment(const Point& a, const Point& b) : a(a), b(b) {}

	friend istream &operator>>(istream &in, LineSegment &ls) {
		in >> ls.a >> ls.b;
		return in;
	}
	friend ostream& operator<<(ostream& out, const LineSegment& l) {
		out << l.a << " " << l.b;
		return out;
	}

	LineSegment reverse() const {
		return LineSegment(b, a);
	}
	bool below45(const Point& beam) const {
		// if it will be <45 degrees if we start a beam from b

		// a dot b = |a| * |b| * cos(deg)
		// deg < 45, therefore |a| * |b| < sqrt(2) * (a dot b)
		//            |a|^2 * |b|^2 < 2 * (a dot b)^2
		return (sqr(beam.dot(b-a)) * 2 > beam.dot(beam) * one * (b-a).dot(b-a))
		       && (b-a).dot(beam) > 0;
	}
	LineSegment rename(const Point& p) const {
		return LineSegment(a.rename(p), b.rename(p));
	}

};

bool intersect(const Point& a1, const Point& a2, const Point& b1, const Point& b2){
	if (((a2-a1).cross(b1-a1) * one * (a2-a1).cross(b2-a1) == 0) &&
		   ((b2-b1).cross(a1-b1) * one * (b2-b1).cross(a2-b1) == 0)) return false;

	return ((a2-a1).cross(b1-a1) * one * (a2-a1).cross(b2-a1) <= 0) &&
		   ((b2-b1).cross(a1-b1) * one * (b2-b1).cross(a2-b1) <= 0);
}

vector<vector<int> > nxt;
vector<vector<int> > nxtq;

int x;
struct Line: public LineSegment{
	int i;
	Line(){}
	Line (const LineSegment& ls, int i) : LineSegment(ls), i(i) {}
	bool operator< (const Line& other) const {
		long long tyn, tyd, oyn, oyd;
		if (b.x == a.x) {
			tyn = a.y;
			tyd = 1;
		} else {
			tyn = abs(x - a.x) * 1ll * b.y + a.y * 1ll * abs(x - b.x);
			tyd = abs(b.x - a.x);
		}

		if (other.b.x == other.a.x) {
			oyn = other.a.y;
			oyd = 1;
		} else {
			oyn = abs(x - other.a.x) * 1ll * other.b.y + other.a.y * 1ll * abs(x - other.b.x);
			oyd = abs(other.b.x - other.a.x);
		}
		return tyn * one * oyd < oyn * one * tyd;
	}
};
struct Vertex {
	int i;
	bool _45;
	bool query;
	bool lst;
	Point p;
	Vertex(){}
	Vertex(int i, const Point& p, bool _4, bool query, bool lst) : i(i), p(p), _45(_4), query(query), lst(lst) {}
	bool operator<(const Vertex& v) const {
		return p.x < v.p.x || p.x == v.p.x && lst < v.lst || p.x == v.p.x && lst == v.lst && ((lst && p.y > v.p.y) || (lst==0 && p.y < v.p.y));
	}
};

void sviplayn(vector<LineSegment>& lines, vector<Point>& qs, int ind) {
	// downwards by y
	vector<bool> visited(lines.size(), false);
	vector<Vertex> vertices(2*lines.size() + qs.size());
	for (int i=0;i<lines.size();++i) {
		vertices[2*i] = Vertex(i, lines[i].a, lines[i].below45(Point(0, 1)), false, !(lines[i].a < lines[i].b));
		vertices[2*i+1] = Vertex(i, lines[i].b, lines[i].below45(Point(0, -1)), false, (lines[i].a < lines[i].b));
	}
	for (int i=0;i<qs.size();++i){
		vertices[2*lines.size() + i] = Vertex(i, qs[i], true, true, false);
	}
	sort(vertices.begin(), vertices.end());
	set<Line> active;
	for (int i=0;i<vertices.size();++i) {
		x = vertices[i].p.x;
		Line l(lines[0], i);
		if (vertices[i].query){
			Point s = qs[vertices[i].i];
			l = Line(LineSegment(s, s), i);
		} else {
			l = Line(lines[vertices[i].i], vertices[i].i);
		}
		if (!vertices[i].query && visited[vertices[i].i]) {
			active.erase(l);
			// remove
		}
		if (!active.empty()) {
			if (vertices[i].query || vertices[i]._45 && nxt[ind][vertices[i].i] == -1) {
				auto it = active.lower_bound(l);
				if (it != active.begin()){
					--it;
					if (vertices[i].query){
						nxtq[ind][vertices[i].i] = it->i;
					} else {
						nxt[ind][vertices[i].i] = it->i;
					}
				}
			}
		}
		if (!vertices[i].query && !visited[vertices[i].i]) {
			// insert
			active.insert(l);
			visited[vertices[i].i] = true;
		}
	}
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<LineSegment> ls(n);
	vector<Point> beams;

	for (int i=0;i<n;++i) {
		cin >> ls[i];
	}

	int q;
	cin >> q;
	vector<Point> qs(q);
	for (int i=0;i<q;++i){
		Point s;
		cin >> s;
		qs[i] = s;
	}

	for (int i=0;i<n;++i) {
		if (!ls[i].below45(-ls[i].b)) {
			ls[i] = ls[i].reverse();
		}
		if (ls[i].below45(-ls[i].b)) {
			bool ok = true;
			for (int j=0;ok&&j<n;++j){
				if (j == i) continue;
				if (intersect(ls[i].b, Point(), ls[j].a, ls[j].b)){
					// cout << "hey" << endl;
					ok = false;
				}
			}
			if (ok){
				beams.push_back(ls[i].b);
				nxt.emplace_back(n, -1);
				nxt.back()[i] = n;
				nxtq.emplace_back(q, -1);
			}
		}
	}

	for (int ind=0;ind<beams.size();++ind) {
		Point beam = beams[ind];
		Point x = -beam.normal();
		// bring to y axis downwards
		// find next point if there is one
		vector<LineSegment> lines(n);
		for (int i=0;i<n;++i) {
			lines[i] = ls[i].rename(x);
		}
		vector<Point> nqs(q);
		for (int i=0;i<q;++i){
			nqs[i] = qs[i].rename(x);
		}
		sviplayn(lines, nqs, ind);
	}

	// find out if beam from this point leads to target
	function<void(int, int)> find_nxt = [&](int v, int ind){
		int u = nxt[ind][v];
		if (u == -1 || u == n) return;
		find_nxt(u, ind);
		nxt[ind][v] = nxt[ind][u];
	};

	for (int i=0;i<beams.size();++i){
		for (int j=0;j<n;++j){
			find_nxt(j, i);
		}
	}

	for (int i=0;i<q;++i) {
		Point s = qs[i];
		bool ok = true;
		for (LineSegment& l: ls){
			if (intersect(Point(), s, l.a, l.b)){
				ok = false;
				break;
			}
		}
		if (!ok){
			for (int j=0;j<beams.size();++j){
				if (nxtq[j][i] != -1){
					ok |= nxt[j][nxtq[j][i]] == n;
				}
			}
		}
		if (ok){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}