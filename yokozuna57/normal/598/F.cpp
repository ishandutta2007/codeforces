#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef long double ld;

struct po{
	ld x;
	ld y;
	po(ld a){ x = a; y = 0; }
	po(ld a,ld b){ x = a; y = b; }
	po(){}
	inline ld operator()(const po& rhs) const {
		return x*rhs.x+y*rhs.y;
	}
	inline ld norm() {
		return sqrt((*this)(*this));
	}
	inline po& operator+=(const po& rhs){
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	inline po& operator-=(const po& rhs){
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
	inline po& operator*=(const po& rhs){
		ld x_ = x*rhs.x-y*rhs.y;
		y = x*rhs.y+y*rhs.x;
		x = x_;
		return *this;
	}
	inline po& operator/=(const po& rhs){
		ld x_ = x*rhs.x+y*rhs.y;
		y = -x*rhs.y+y*rhs.x;
		x = x_;
		ld nor = rhs(rhs);
		x /= nor;
		y /= nor;
		return *this;
	}
	inline void in(){
		scanf("%Lf%Lf",&x,&y);
	}
};
inline po operator+(const po& a, const po& b){ return po(a) += b; }
inline po operator-(const po& a, const po& b){ return po(a) -= b; }
inline po operator*(const po& a, const po& b){ return po(a) *= b; }
inline po operator/(const po& a, const po& b){ return po(a) /= b; }

inline po similar(const po& a,const po& b,const po& c,const po& p,const po& q){
	return p+(q-p)*(c-a)/(b-a);
}

inline ld ext(const po& p,const po& q){
  return p.x*q.y-p.y*q.x;
}

inline ld area_t(const po &p,const po &q,const po &r){
  return ext(q-p,r-q)/2.0;
}

typedef pair<po,po> se;
#define fr first
#define sc second

struct li{
	ld a;
	ld b;
	ld c;
	li(po p,po q){
		a = q.y-p.y;
		b = p.x-q.x;
		c = p.y*q.x-p.x*q.y;
	}
	li(){}
	inline ld operator()(const po& p) const {
		return a*p.x+b*p.y+c;
	}
};

void intersect(const li &l,const li &m,po* &ret){
	if(abs(l.a*m.b-m.a*l.b) <= 1e-18){
		ret = nullptr;
		return;
	}
	ret = new po;
	ret->x = -(l.c*m.b-m.c*l.b)/(l.a*m.b-m.a*l.b);
	ret->y = -(l.a*m.c-m.a*l.c)/(l.a*m.b-m.a*l.b);
}
inline ld dist(const po &p,const po &q){
	return sqrt((p-q)(p-q));
}
inline bool on(const po &p,const se &s){
	//cerr.precision(20);
	//cerr<<p.x<<" "<<p.y<<" "<<s.fr.x<<" "<<s.fr.y<<" "<<s.sc.x<<" "<<s.sc.y<<endl;
	if(dist(p,s.fr)<=1e-7||dist(p,s.sc)<=1e-7)return true;
	return (s.fr-p)(s.sc-p) <= 1e-9;
}
void intersect(const li &l,const se &t,po* &ret){
	li m = li(t.fr,t.sc);
	po *p;
	intersect(l,m,p);
	//cerr<<t.fr.x<<" "<<t.fr.y<<" "<<t.sc.x<<" "<<t.sc.y<<endl;
	//if(p==nullptr)puts("nullptr");
	if(p == nullptr || on(*p,t))ret = p;
	else{
		//puts("hoge");
		delete p;
		ret = nullptr;
	}
}
void intersect(const se &s,const se &t,po* &ret){
	li l = li(s.fr,s.sc);
	li m = li(t.fr,t.sc);
	po *p;
	intersect(l,m,p);
	if(p == nullptr || (on(*p,s)&&on(*p,t)))ret = p;
	else{
		delete p;
		ret = nullptr;
	}
}
inline li perpen(const po &p,const li &l){
	li ret;
	ret.a = l.b;
	ret.b = -l.a;
	ret.c = l.a*p.y-l.b*p.x;
	return ret;
}
inline po perpen_leg(const po &p,const li &l){
	po ret;
	li m = perpen(p,l);
	ret.x = -(l.c*m.b-m.c*l.b)/(l.a*m.b-m.a*l.b);
	ret.y = -(l.a*m.c-m.a*l.c)/(l.a*m.b-m.a*l.b);
	return ret;
}
inline ld dist(const po &p,const se &s){
	po h = perpen_leg(p,li(s.fr,s.sc));
	if(on(h,s))return dist(p,h);
	else return min( dist(p,s.fr) , dist(p,s.sc) );
}
inline ld dist(const se &s,const se &t){
	po *p;
	intersect(s,t,p);
	if(p != nullptr){
		delete p;
		return 0.0;
	}
	ld ret = min( dist(s.fr,t) , dist(s.sc,t) );
	ret = min( ret , min( dist(t.fr,s) , dist(t.sc,s) ) );
	return ret;
}
inline ld dist(const po &p, const li &l){
	return abs(l(p))/sqrt(l.a*l.a+l.b*l.b);
}

struct ci{
	po c;
	ld r;
	inline bool internal(const po &p){
		return dist(p,c) <= r+1e-9;
	}
};

ci circum(const po &p,const po &q,const po &r){
	ci ret;
	li l = perpen((p+q)/2.0,li(p,q));
	li m = perpen((q+r)/2.0,li(q,r));
	po* _c;
	intersect(l,m,_c);
	if(_c == nullptr){
		ret.c = po(0.0,0.0);
		ret.r = -1.0;
		return ret;
	}
	else {
		ret.c = *_c;
		ret.r = dist(ret.c,p);
		delete _c;
		return ret;
	}
}


void intersect(const li &l, const ci &c, po* &ret1, po* &ret2){
	ld d = dist(c.c,l);
	if(d > c.r+1e-9){
		ret1 = nullptr;
		ret2 = nullptr;
		return;
	}
	po h = perpen_leg(c.c,l);
	if(abs(d-c.r) <= 1e-9){
		ret1 = new po;
		*ret1 = h;
		ret2 = nullptr;
		return;
	}
	po v = po(l.b,-l.a);
	v /= sqrt(v(v));
	v *= sqrt(c.r*c.r-d*d);
	ret1 = new po;
	*ret1 = h+v;
	ret2 = new po;
	*ret2 = h-v;
	return;
}
void intersect(const ci &c, const ci &d, po* &ret1, po* &ret2){
	li l;
	l.a = 2*(c.c.x-d.c.x);
	l.b = 2*(c.c.y-d.c.y);
	l.c = d.c(d.c)-d.r*d.r-(c.c(c.c)-c.r*c.r);
	intersect(l,c,ret1,ret2);
}
void tangent(const po &p, const ci &c,li* &ret1,li* &ret2){
	ci d;
	d.c = (p+c.c)/2.0;
	d.r = dist(p,c.c)/2.0;
	po *q,*r;
	intersect(c,d,q,r);
	ret1 = ret2 = nullptr;
	if(q == nullptr)return;
	ret1 = new li;
	*ret1 = li(p,*q);
	delete q;
	if(r == nullptr)return;
	ret2 = new li;
	*ret2 = li(p,*r);
	delete r;
}
void cotan_in(const ci &c, const ci &d, li* &ret1, li* &ret2){
	po p = similar(-c.r,d.r,0.0,c.c,d.c);
	tangent(p,c,ret1,ret2);
}
void cotan_out(const ci &c, const ci &d, li* &ret1, li* &ret2){
	if(abs(c.r-d.r) < 1e-9){
		ret1 = new li;
		ret2 = new li;
		*ret1 = *ret2 = li(c.c,d.c);
		ret1->c += c.r*sqrt(ret1->a*ret1->a+ret1->b*ret1->b);
		ret2->c -= c.r*sqrt(ret1->a*ret1->a+ret1->b*ret1->b);
		return;
	}
	po p = similar(c.r,d.r,0.0,c.c,d.c);
	tangent(p,c,ret1,ret2);
}

#define mp make_pair
#define fr first
#define sc second

int n,m;
ld x[1002],y[1002];
po p[1002];

int sgn(ld x,ld eps=1e-12){
	return (x>eps)-(x<-eps);
}

ld f(se s,se t){
	return ext(t.sc-t.fr,t.fr-s.fr)/ext(t.sc-t.fr,s.sc-s.fr);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		p[i]=po(x[i],y[i]);
	}
	x[n]=x[0]; y[n]=y[0];
	p[n]=p[0];
	for(;m>0;m--){
		ld a,b,c,d;
		cin>>a>>b>>c>>d;
		po q(a,b),r(c,d);
		vector<pair<ld,ld>> vec;
		for(int i=0;i<n;i++){
			ld rate=sgn(ext(r-q,p[i+1]-p[i]));
			if(abs(rate)<.5)continue;
			ld tmp=f(se(p[i],p[i+1]),se(q,r));
			if(sgn(tmp)>=0&&sgn(1.-tmp)>=0){
				if(sgn(tmp)==0||sgn(1.-tmp)==0)rate*=.5;
				tmp=f(se(q,r),se(p[i],p[i+1]));
				vec.push_back(mp(tmp,rate));
			}
		}
		sort(vec.begin(),vec.end());
		ld cnt=.0;
		ld ret=.0;
		/*for(auto xx: vec){
			cerr<<xx.fr<<" "<<xx.sc<<endl;
		}*/
		for(int i=0;i+1<vec.size();i++){
			cnt+=vec[i].sc;
			if(sgn(cnt)!=0)ret+=vec[i+1].fr-vec[i].fr;
		}
		cout.precision(20);
		cout<<ret*dist(q,r)<<endl;
	}
}

/*int main2(){
	scanf("%d%d",&n,&M);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		//scanf("%d%d",&x[i],&y[i]);
	}
	x[n]=x[0]; y[n]=y[0];
	se l[1002];
	for(int i=0;i<n;i++){
		l[i]=make_pair(po(x[i],y[i]),po(x[i+1],y[i+1]));
	}
	for(;M>0;M--){
		ld a,b,c,d;
		cin>>a>>b>>c>>d;
		li m=li(po(a,b),po(c,d)); //m.c+=1e-12;
		li mm=m; swap(mm.a,mm.b); mm.a*=-1.0;
		ld ret=0.0;
		vector<pair<pair<ld,po>,ld>> vec;
		for(int i=0;i<n;i++){
			po *p;
			intersect(m,l[i],p);
			if(p!=nullptr){
				ld rate=ext(po(c-a,d-b),po(x[i+1]-x[i],y[i+1]-y[i]));
				if(rate>1e-12)rate=1.0;
				else if(rate<-1e-12)rate=-1.0;
				else rate=0.0;
				if(dist(*p,po(x[i],y[i]))<1e-9||dist(*p,po(x[i+1],y[i+1]))<1e-9)rate*=0.5;
				vec.push_back(make_pair(make_pair(mm(*p),*p),rate));
				delete p;
			}
		}
		sort(vec.begin(),vec.end(),[](pair<pair<ld,po>,ld> x,pair<pair<ld,po>,ld> y){
			return x.first.first<y.first.first;
		});
		//cerr<<vec.size()<<endl;
		ld cnt=0.0;
		for(int i=0;i+1<vec.size();i++){
			//cerr<<i<<" ";
			//cerr<<vec[i].second.x<<" "<<vec[i].second.y<<" "<<vec[i+1].second.x<<" "<<vec[i+1].second.y<<endl;
			//ld d=dist(vec[i].second,vec[i+1].second);
			//if(d<=1e-12)i--;
			//else ret+=d;
			cnt+=vec[i].second;
			if(abs(cnt)>1e-9){
				ret+=dist(vec[i].first.second,vec[i+1].first.second);
			}
		}
		cout.precision(20);
		cout<<ret<<endl;
	}
}*/