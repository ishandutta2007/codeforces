#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const double pi=acos(-1);
double sqr(double x){
	return x*x;
}
double Abs(double x){
	return x<0?-x:x;
}
struct P{
	double x,y,r;
}a[N];
struct range{
	double l,r;
	bool operator <(const range &b)const{
		if (l==b.l) return r<b.r;
		return l<b.l;
	} 
}b[N*2];
set<double> S;
int n;
double k;
bool check(double mid){
	int i,tot=0;
	for (int i=1;i<=n;i++){
		double dis=sqrt(sqr(a[i].x-k)+sqr(a[i].y));
		if (dis>a[i].r+mid||a[i].r>dis+mid||mid>dis+a[i].r) continue;
		double u=atan2(a[i].y,a[i].x-k);
		double t=acos((sqr(dis)+sqr(mid)-sqr(a[i].r))/(2.0*dis*mid));
		double L=u-t,R=u+t;
		if (L<-pi) L+=2*pi;
		if (L>pi) L-=2*pi;
		if (R<-pi) R+=2*pi;
		if (R>pi) R-=2*pi;
		if (L>R) swap(L,R);
		b[++tot]=(range){L,R};
	}
	sort(b+1,b+tot+1);
	S.clear();
	for (int i=1;i<=tot;i++){
		set<double>::iterator it;
		it=S.lower_bound(b[i].l);
		if (it!=S.end()&&*it<b[i].r) return 1;
		S.insert(b[i].r);
	}
	return 0;
}
int main(){
	scanf("%d%lf",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		a[i].r=sqrt(sqr(a[i].x+k)+sqr(a[i].y));
	}
	double l=0.0,r=2.0*k;
	for (int i=1;i<=50;i++){
		double mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%.15lf\n",l);
}