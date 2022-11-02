#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

typedef long double db;

struct P {
	db x, y;
	P() {
	}
	P(db _x, db _y) :
		x(_x), y(_y) {
	}
	P operator+(const P&p) const {
		return P(x + p.x, y + p.y);
	}
	P operator-(const P&p) const {
		return P(x - p.x, y - p.y);
	}
	P operator*(db d) const {
		return P(x * d, y * d);
	}
	P operator/(db d) const {
		return P(x / d, y / d);
	}
	db det(const P&p) const {
		return x * p.y - y * p.x;
	}
	db dot(const P&p) const {
		return x * p.x + y * p.y;
	}
	P rot90() const {
		return P(-y, x);
	}
	void read() {
		double _x,_y;
		scanf("%lf%lf", &_x, &_y); x=_x; y=_y;
	}
	void write() const {
		printf("%lf %lf", (double)x, (double)y);
	}

	db dist(const P&p) const {
		db dx = x - p.x;
		db dy = y - p.y;
		return sqrtl(dx*dx+dy*dy);
	}
};

const int MAX_N_CIRCLES = 2000 + 10;

int n;
P ps[MAX_N_CIRCLES];
int cr[MAX_N_CIRCLES];

typedef pair<db, int> Event;
Event events[MAX_N_CIRCLES * 10];
int nEvents;

void addCover(db l, db r, int tp) {
	int val = 1; if(tp==0) val = 2;
	events[nEvents++] = make_pair(l, val);
	events[nEvents++] = make_pair(r, -val);
}

const db PI = acosl(-1.0);

void normalize(db&alpha) {
	while (alpha >= 2 * PI)
		alpha -= 2 * PI;
	while (alpha < 0)
		alpha += 2 * PI;
}

bool check(int id, db R) {

	P c1 = ps[id];

	nEvents = 0;

	for (int oid = 0; oid < n; ++oid) {
		if (oid == id)
			continue;

		P c2 = ps[oid];

		db d = c1.dist(c2);

		if (d > R + R)
			continue;

		db alpha = acosl(d / (2 * R));
		db am = atan2l(c2.y - c1.y, c2.x - c1.x);
		db left = am - alpha, right = am + alpha;

		normalize(left);
		normalize(right);

		if (left < right) {
			addCover(left, right, cr[oid]);
		} else {
			addCover(left, 2 * PI, cr[oid]);
			addCover(0, right, cr[oid]);
		}
	}

	int rcnt = 0, bcnt = 0;

	if(cr[id] == 0)
		addCover(0,2*PI,0);

	sort(events, events + nEvents);

	for (int i = 0; i < nEvents; ++i) {
		if (i > 0) {
			if((rcnt > 0) && bcnt == 0)
				return 1;
		}

		if(abs(events[i].second)==1)
			bcnt += events[i].second;
		else
			rcnt += events[i].second/2;
	}

	return 0;
}

int main() {
	int nr,nb;

	cin>>nr>>nb;

	n=0;

	rep(i,nr) {cr[n]=0;ps[n++].read();}
	rep(i,nb) {cr[n]=1;ps[n++].read();}

	rep(i,n) if(check(i,(db)1e15)){
		puts("-1");
		return 0;
	}

	int perm[MAX_N_CIRCLES];
	rep(i,n) perm[i] = i;

	random_shuffle(perm,perm+n);

	db ans = 0;

	// edge with red point
	rep(i,n){
		int id = perm[i];
		if(cr[id] != 0) continue;

		if(!check(id,ans))
			continue;

		db r = ans+1;
		while(check(id,r))
			r=r*2;
		db l = ans;

		rep(it,70){ db m = (l+r)/2; if(check(id,m)) l = m; else r = m;}
		ans = l;
	}

	//edge with blue point
	rep(i,n){
		int id = perm[i];
		if(cr[id] != 1) continue;

		if(!check(id,ans))
			continue;

		db r = ans+1;
		while(check(id,r))
			r=r*2;
		db l = ans;

		rep(it,70){ db m = (l+r)/2; if(check(id,m)) l = m; else r = m;}
		ans = l;
	}
	printf("%0.10lf\n",(double)ans);
}