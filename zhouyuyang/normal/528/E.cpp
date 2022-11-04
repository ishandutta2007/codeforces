#include<bits/stdc++.h>
using namespace std;
struct P{
	double x,y;
	P operator +(const P &a)const{
		return (P){x+a.x,y+a.y};
	}
};
double cross(P a,P b){
	return a.x*b.y-a.y*b.x;
}
struct L{
	double a,b,c;
	bool operator <(const L &x)const{
		return atan2(b,a)<atan2(x.b,x.a);
	} 
}l[3005];
P crossp(L l1,L l2){
	double tmp=l1.a*l2.b-l2.a*l1.b;
	return (P){(l1.c*l2.b-l2.c*l1.b)/tmp,
			   (l1.a*l2.c-l2.a*l1.c)/tmp};
}
int n;
double ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&l[i].a,&l[i].b,&l[i].c);
		if (l[i].a<0) l[i].a*=-1,l[i].b*=-1,l[i].c*=-1;
	}
	sort(l+1,l+n+1);
	for (int i=1;i<=n;i++){
		P s=(P){0,0};
		for (int j=i%n+1;j!=i;j=j%n+1){
			P p=crossp(l[i],l[j]);
			ans+=cross(s,p);
			s=s+p;
		}
	}
	printf("%.12lf\n",ans/2/(1.0*n*(n-1)*(n-2)/6));
}