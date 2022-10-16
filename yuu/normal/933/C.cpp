#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const double eps=1e-6;
class point{
public:
	double x, y;
	point(double x=0, double y=0): x(x), y(y){}
	void input(){
		cin>>x>>y;
	}
	bool same(point P){
		return (fabs(x-P.x)<eps)&&(fabs(y-P.y)<eps);
	}
	
	point operator + (const point& p) const {return point(x + p.x, y + p.y);}
	point operator - (const point& p) const {return point(x - p.x, y - p.y);}
	point operator * (double c) const {return point(x * c, y * c);}
	point operator / (double c) const {return point(x / c, y / c);}
};
double dot(point p, point q) {return p.x * q.x + p.y * q.y;}
double dist(point p, point q) {return sqrtl(dot(p - q, p - q));}
double dist2(point p, point q) {return dot(p - q, p - q);}
point RotateCCW90(point p) {return point(-p.y, p.x);}
vector<point> CircleCircleIntersection(point a, point b, double r, double R) {
	vector<point> res;
	double d = sqrtl(dist2(a, b));
	if (d > r + R || d + min(r, R) < max(r, R)) return res;
	double x = (d * d - R * R + r * r) / (2 * d);
	double y = sqrtl(r * r - x * x);
	point v = (b - a) / d;
	res.push_back(a + v * x + RotateCCW90(v) * y);
	if (y > 0) res.push_back(a + v * x - RotateCCW90(v) * y);
	return res;
}
class circle{
public:
	point O;
	double r;
	circle(){}
	void input(){
		O.input();
		cin>>r;
	}
	//since edge and vertices on each circle are all equals, v-e=number of vertices
	vector <point> get_intersections(circle A){
		return CircleCircleIntersection(O, A.O, r, A.r);
	}
} c[100];

int r[100];
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
void unite(int u, int v){
	u=root(u);
	v=root(v);
	if(u==v) return;
	r[u]+=r[v];
	r[v]=u;
}
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++) r[i]=-1;
	for(int i=0; i<n; i++) c[i].input();
	for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(!c[i].get_intersections(c[j]).empty()) unite(i, j);
	int ans=1;
	for(int i=0; i<n; i++) if(i==root(i)){
		// cerr<<i<<'\n';
		vector <pair <point, bool>> p;
		int edge=0, vert=0;
		for(int j=0; j<n; j++) if(root(j)==i){
			vector <pair <point, bool>> q;
			for(int k=0; k<n; k++) if(j!=k) if(root(k)==i){
				auto res=c[j].get_intersections(c[k]);
				for(auto &x: res) p.push_back({x, 1});
				for(auto &x: res) q.push_back({x, 1});
			}
			for(int i=0; i<q.size(); i++) if(q[i].second){
				edge++;
				for(int j=0; j<q.size(); j++) if(q[i].first.same(q[j].first)) q[j].second=0;
			}
		}
		for(int i=0; i<p.size(); i++) if(p[i].second){
			vert++;
			for(int j=0; j<p.size(); j++) if(p[i].first.same(p[j].first)) p[j].second=0;
		}
		// cerr<<diff<<'\n';
		ans+=edge-vert+1;
	}
	cout<<ans<<'\n';
}