#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class point{
public:
  ll x, y;
  point(){x=y=0;}
  point(ll x, ll y): x(x), y(y) {}
	void input(){cin>>x>>y;}
  point operator + (point p){return point(x+p.x, y+p.y);}
  point operator - (point p){return point(x-p.x, y-p.y);}
  point operator * (ll k){return point(x*k, y*k);}
  ll sq(){return x*x+y*y;}
  double len(){return sqrt(sq());}//hypot(x, y) is slower but more accurate
};

inline ll cross(const point a, const point b){
  return a.x*b.y-a.y*b.x;
}
inline ll dot(const point a, const point b){
  return a.x*b.x+a.y*b.y;
}
inline point vect(const point a, const point b){
  return point(b.x-a.x, b.y-a.y);
}
inline bool ccw(const point a, const point b, const point c){
  return cross(vect(b, a), vect(c, b))>0;
}
inline bool cw(const point a, const point b, const point c){
  return cross(vect(b, a), vect(c, b))<0;
}
vector <point> v;
int n;
// ll x;
ll ans=0;
ll C2(int x){
	return x*(x-1)/2;
}
void make(int u){
	vector <point> now;
	auto root=v[u];
	for(int i=0; i<n; i++) if(i!=u) now.push_back(v[i]);
	auto it=partition(now.begin()+1, now.end(), [root, now](point A){
		return ccw(root, now[0], A);
	});
	sort(now.begin(), it, [root](point A, point B){
		return ccw(root, A, B);
	});
	sort(it, now.end(), [root](point A, point B){
		return ccw(root, A, B);
	});
	// cerr<<"root=("<<root.x<<", "<<root.y<<")\n";
	// for(auto &x: now){
		// cerr<<"("<<x.x<<", "<<x.y<<") ";
	// }
	// cerr<<'\n';
	int sz=now.size();
	for(int i=0, j=0; i<sz; i++){
		while(cw(root, now[i], now[j])) j=(j+1)%sz;
		while(ccw(root, now[i], now[(j+1)%sz])) j=(j+1)%sz;
		int x=j-i;
		if(x<0) x+=sz;
		int y=sz-x-1;
		ans+=C2(x)*C2(y);
	}
}
int main(){
	cin>>n;
	v.resize(n);
	for(auto &x: v) x.input();
	for(int i=0; i<n; i++) make(i);
	ans/=2;
	cout<<ans<<'\n';
}