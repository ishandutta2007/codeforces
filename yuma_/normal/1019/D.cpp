#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;
ld eps=1e-9;


unsigned long long int N;
unsigned long long int A, B, C, D;

const signed long long int Mod=1ll<<32;



void rotate(complex<ld>&c,bool flag=false) {
	ld theta=0.000021;
	if(flag)theta=-0.000021;
	complex<ld>n(c.real()*cos(theta)+c.imag()*sin(theta),c.real()*sin(theta)-c.imag()*cos(theta));
	c=n;
}


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
long long int get_area(pair<int,int>a,pair<int,int>b,pair<int,int>c) {
	b.first-=a.first;
	b.second-=a.second;
	c.first-=a.first;
	c.second-=a.second;
	long long int answer=(abs(
		static_cast<long long int>(b.first)*c.second-
		static_cast<long long int>(b.second)*c.first));
	
	if (ccw(Point(0,0),Point(b.first,b.second),Point(c.first,c.second))== 1) {

	}
	else {
		answer=-answer;
	}
	return answer;
}

struct sa {
	ld slope;
	Point a;
	int ida,idb;
	Point b;
};

pair<int, int>to(const Point&p) {
	return make_pair(p.real(),p.imag());
}

bool check(const long long int S, const Line&l, const pair<int,int>& p) {
	auto sum = get_area(to(l.a),to(l.b),p);
	return sum>2*S;
}
vector<Point>anss;
int solve(const long long int S, const Line&l, 
	const vector<pair<int,int>>&ps) {
	int amin=0;
	int amax=int(ps.size());
	while (amin+1!=amax) {
		int amid((amin+amax)/2);
		if (check(S, l, ps[amid])) {
			amax=amid;
		}
		else {
			amin=amid;
		}
	}
	auto sum = get_area(to(l.a),to(l.b),ps[amin]);
	auto sum2=get_area(to(l.a),to(l.b),ps[amin!=ps.size()-1?amin+1:amin]);
	long long int  dis=sum-2*S;
	if (!dis) {
		return amin;
	}
	else {
		return -1;
	}
}
void out( const vector<complex<ld>>&ps) {
	if (anss.empty()) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
		for (int i = 0; i < 3; ++i) {
			auto p(anss[i]);
			//rotate(p,true);
			cout<<int(p.real())<<" "<<int(p.imag())<<endl;
		}
	}
}
int main() {
	int N;cin>>N;
	long long int S;cin>>S;
	vector<complex<ld>>ps;
	for (int i = 0; i < N; ++i) {
		int x,y;
		scanf("%d %d",&x,&y);
		complex<ld>c(x,y);
		//rotate(c);
		ps.emplace_back(c);
	}
	sort(ps.begin(),ps.end());
	vector<sa>sas;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			auto d = ps[j] - ps[i];
			if (ps[j].real() == ps[i].real()) {
				sas.push_back(sa{ 1e17,ps[i],i,j,ps[j] });
			}
			sas.push_back(sa{ d.imag() / d.real(),ps[i],i,j,ps[j]});

			
		}
	}

	vector<pair<int,int>>nps;
	sort(sas.begin(), sas.end(), [](const sa&l, const sa&r) {return l.slope < r.slope;});
{
		sa s(sas[0]);
		
		vector<pair<ld,int>>diss;
		for (int i = 0; i < N; ++i) {
			auto len = dist_lp(Line(s.a, s.b), ps[i]);
			if (abs(ps[i]-s.b)<eps) {
				diss.push_back(make_pair(eps, i));
			}
			else if (ccw(s.a, s.b, ps[i]) >= 1) {
				diss.push_back(make_pair(len,i));
			}
			else {
				diss.push_back(make_pair(-len,i));
			}
		}
		sort(diss.begin(),diss.end());
		vector<Point>nextps;
		for(auto dis:diss)nextps.push_back(ps[dis.second]);
		for (auto dis : diss) {
			nps.push_back(make_pair(ps[dis.second].real(),ps[dis.second].imag()));

		}
		ps=nextps;
	}
	vector<int>v(N);	
	iota(v.begin(),v.end(),0);
	for (auto s : sas) {

		auto k=solve(S,Line(s.a,s.b),nps);
		if (k != -1) {
			anss = vector<Point>{ s.a,s.b,ps[k] };
			break;
		}
		else {
			swap(ps[v[s.ida]],ps[v[s.idb]]);
			swap(nps[v[s.ida]], nps[v[s.idb]]);

			swap(v[s.ida],v[s.idb]);
		}
	}
	out(ps);
	return 0;
}