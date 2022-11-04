#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1e18
#define sqr(x) ((x)*(x))
#define eps 1e-13
using namespace std;
struct P{
	db x,y;
	P operator +(const P &a)const{
		return (P){x+a.x,y+a.y};
	}
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	P operator *(const db &a)const{
		return (P){x*a,y*a};
	}
	bool operator <(const P &a)const{
		return x<a.x;
	}
	void init(){
		double _x,_y;
		scanf("%lf%lf",&_x,&_y);
		x=_x; y=_y;
	}
};
db dis(P x,P y){
	return sqrt(sqr(x.x-y.x)+sqr(x.y-y.y));
}
struct func{
	db a,b,c;
	P calc(db z){
		if (fabs(a)>=eps){
			db C=c-z;
			db delta=b*b-4*a*C;
			if (delta+eps<0) return (P){-1e18,-1e18};
			delta=sqrt(delta+eps);
			return (P){(-b-delta)/2/a,(-b+delta)/2/a};
		}
		return c>=z?(P){1e18,-1e18}:(P){-1e18,1e18};
	}
	//ax*2+bx+c=v
};
struct Func{
	func f;
	db l,r;
};
const int N=100005;
P p[N];
int n,m;
vector<P> spe[N];
db C;
void getspecial(){
	int at=2; P now=p[1];
	For(i,1,m){
		spe[i].PB(now);
		db rest=C/m;
		for (;fabs(rest)>=eps;){
			db D=dis(now,p[at]);
			if (fabs(D)<=eps)
				at=at%n+1;
			else if (D<=rest){
				spe[i].PB(p[at]);
				rest-=D;
				now=p[at];
				at=at%n+1;
			}
			else{
				now=now+(p[at]-now)*(rest/D);
				spe[i].PB(now);
				break;
			}
		}
	}
}
vector<Func> vec;
void getfunc(vector<P> a,vector<P> b){
	int sza=a.size(),szb=b.size();
	int nxa=1,nxb=1;
	P A=a[0],B=b[0];
	db T=0;
	for (;nxa<sza||nxb<szb;){
		db Da=dis(A,a[nxa]);
		db Db=dis(B,b[nxb]);
		P dela=(a[nxa]-A)*(1/Da);
		P delb=(b[nxb]-B)*(1/Db);
		P Sa=A-dela*T;
		P Sb=B-delb*T;
		P Sab=Sa-Sb;
		P delab=dela-delb;
		func f;
		f.a=sqr(delab.x)+sqr(delab.y);
		f.b=2*delab.x*Sab.x+2*delab.y*Sab.y;
		f.c=sqr(Sab.x)+sqr(Sab.y);
		db val=min(Da,Db);
		A=A+dela*val;
		B=B+delb*val;
		vec.PB((Func){f,T,T+val});
		T+=val;
		if (fabs(Da-val)<eps) nxa++;
		if (fabs(Db-val)<eps) nxb++;
	}
}
P q[N*10];
bool check(db mid){
	int top=0;
	For(i,0,vec.size()-1){
		P range=vec[i].f.calc(mid);
		if (range.x<-1e17){
			if (range.y<-1e17)
				q[++top]=(P){vec[i].l,vec[i].r};
		}
		else{
			if (vec[i].l<=range.x)
				q[++top]=(P){vec[i].l,min(range.x,vec[i].r)};
			if (vec[i].r>=range.y)
				q[++top]=(P){max(range.y,vec[i].l),vec[i].r};
		}
	}
	sort(q+1,q+top+1);
	db r=0;
	For(i,1,top)
		if (r<q[i].x-eps) return 0;
		else r=max(r,q[i].y);
	return r>=C/m-eps;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) p[i].init();
	For(i,1,n) C+=dis(p[i],p[i%n+1]);
	getspecial();
	For(i,1,m) getfunc(spe[i],spe[i%m+1]);
	db l=0,r=3000;
	while ((r-l)/(l>1?l:1)>=1e-8){
		db mid=(l+r)/2;
		if (check(mid*mid)) l=mid;
		else r=mid;
	}
	printf("%.10lf\n",(double)(l+r)/2);
}
/*
3 2
-1000 -1000
-1000 1000
1000 0
*/