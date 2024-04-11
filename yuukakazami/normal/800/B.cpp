#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head


typedef double db;
 
const db EPS = 1e-8;
 
inline int sign(db a) {
    return a < -EPS ? -1 : a > EPS;
}
 
inline int cmp(db a, db b){
    return sign(a-b);
}
 
struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator+(P p) { return P(x + p.x, y + p.y); }
    P operator-(P p) { return P(x - p.x, y - p.y); }
    P operator*(db d) { return P(x * d, y * d); }
    P operator/(db d) { return P(x / d, y / d); }
    bool operator<(P p) const { 
        int c = cmp(x, p.x);
        if (c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    db dot(P p) { return x * p.x + y * p.y; }
    db det(P p) { return x * p.y - y * p.x; }
    db distTo(P p) { return (*this-p).abs(); }
    db alpha() { return atan2(y, x); }
    void read() { cin>>x>>y; }
    db abs() { return sqrt(abs2());}
    db abs2() { return x * x + y * y; }
    P rot90() { return P(-y,x);}
    P unit() { return *this/abs(); }
};
 
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))
 
P isLL(P p1, P p2, P q1, P q2) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return (p1 * a2 + p2 * a1) / (a1 + a2);
}
 
bool intersect(db l1,db r1,db l2,db r2){
    if(l1>r1) swap(l1,r1); if(l2>r2) swap(l2,r2); 
    return !( cmp(r1,l2) == -1 || cmp(r2,l1) == -1 );
}
 
bool isSS(P p1, P p2, P q1, P q2){
    return intersect(p1.x,p2.x,q1.x,q2.x) && intersect(p1.y,p2.y,q1.y,q2.y) && 
    crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0 && crossOp(q1,q2,p1)
            * crossOp(q1,q2,p2) <= 0;
}
 
bool isMiddle(db a, db m, db b) {
    return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}
  
bool isMiddle(P a, P m, P b) {
    return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}
 
bool onSeg(P p1, P p2, P q){
    return crossOp(p1,p2,q) == 0 && isMiddle(p1, q, p2);
}
 
P proj(P p1, P p2, P q) {
    P dir = p2 - p1;
    return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}
 
P reflect(P p1, P p2, P q){
    return proj(p1,p2,q) * 2 - q;
}
 
db nearest(P p1,P p2,P q){
    P h = proj(p1,p2,q);
    if(isMiddle(p1,h,p2))
        return q.distTo(h);
    return min(p1.distTo(q),p2.distTo(q));
}
 
db disSS(P p1, P p2, P q1, P q2){
    if(isSS(p1,p2,q1,q2)) return 0;
    return min(min(nearest(p1,p2,q1),nearest(p1,p2,q2)), min(nearest(q1,q2,p1),nearest(q1,q2,p2)) );
}
 
db rad(P p1,P p2){
    return atan2l(p1.det(p2),p1.dot(p2));
}
 
db incircle(P p1, P p2, P p3){
    db A = p1.distTo(p2);
    db B = p2.distTo(p3);
    db C = p3.distTo(p1);
    return sqrtl(A*B*C/(A+B+C));
}

vector<P> ps;
int n;

int main(){
	cin>>n; ps.resize(n); rep(i,0,n) ps[i].read();

	reverse(ps.begin(), ps.end());

	db ans = 1e100;

	rep(i,0,n){
		P p1 = ps[i], p2 = ps[(i+1)%n], p3 = ps[(i+2)%n];
		P q1 = (p1 + p2) / 2;
		P q2 = (p3 + p2) / 2;
		P h = proj(q1,q2,p2);
		
		ans = min(ans,p2.distTo(h));
	}

	printf("%0.10f\n",ans);
	return 0;
}