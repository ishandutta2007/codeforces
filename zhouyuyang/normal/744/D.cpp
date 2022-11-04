#include<bits/stdc++.h>
#define db long double
#define pi acos(-1)
#define eps 1e-13
using namespace std;
int n,m,lx,ly,rx,ry;
db l,ans,r,ma,mid;
struct P{int c,x,y;}a[2005];
struct range{
	int c;
	db l,r;
	bool operator <(const range &b)const{
		return l+eps<b.l;
	}
}b[4005];
db max(db x,db y){
	return (x<y?y:x);
}
db sqr(db x){
	return x*x;
}
bool check(int i,db x){
	int tot=0;
	for (int j=1;j<=n;j++)
		if (a[i].x==a[j].x&&a[i].y==a[j].y){
			if (a[j].c==2) continue;
			b[++tot]=(range){1,-pi,pi};
		}
		else{
			db t=atan2((double)a[j].y-a[i].y,a[j].x-a[i].x);
			db tt=sqr(a[j].x-a[i].x)+sqr(a[j].y-a[i].y);
			if (a[j].c==1){
				if (4.0*x*x-eps<=tt){
					if (4.0*x*x+eps>=tt)
						b[++tot]=(range){1,t,t};
					continue;
				}
				tt=acos(sqrt(tt)/2.0/x);
				db ll=t-tt,rr=t+tt;
				if (ll-eps<-pi) ll+=2*pi,rr+=2*pi;
				if (rr+eps<pi) b[++tot]=(range){1,ll,rr};
				else{
					b[++tot]=(range){1,ll,pi};
					b[++tot]=(range){1,-pi,rr-2*pi};
				}
			}
			else{
				if (4.0*x*x-eps<=tt) continue;
				tt=acos(sqrt(tt)/2.0/x);
				db ll=t-tt,rr=t+tt;
				if (ll-eps<-pi) ll+=2*pi,rr+=2*pi;
				if (rr+eps<pi) b[++tot]=(range){2,ll+eps,rr-eps};
				else{
					b[++tot]=(range){2,ll+eps,pi};
					b[++tot]=(range){2,-pi,rr-2*pi-eps};
				}
			}
		}
	sort(b+1,b+tot+1);
	db r1=-pi,r2=-pi;
	for (int j=1;j<=tot;j++)
		if (b[j].c==1){
			if (r2+eps<b[j].l) return 1;
			r1=max(r1,b[j].r); 
		}
		else{
			if (r2+eps<b[j].l&&r2+eps<r1) return 1;
			r2=max(r2,b[j].r);
		}
	return r2+eps<r1;
}
int main(){
	scanf("%d%d",&n,&m);
	lx=ly=10000,rx=ry=0;
	for (int i=1;i<=n+m;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		lx=min(lx,a[i].x);
		ly=min(ly,a[i].y);
		rx=max(rx,a[i].x);
		ry=max(ry,a[i].y);
	}
	for (int i=1;i<=n+m;i++)
		a[i].c=(i<=n?1:2);
	n+=m;
	l=0.0;
	ma=sqr(rx-lx)+sqr(ry-ly);
	for (int i=1;i<=n;i++)
		if (check(i,ma))
			return puts("-1"),0;
	for (int i=1;i<=n;i++){
		l=ans,r=ma;
		if (!check(i,l)) continue;
		for (int j=1;j<=50;j++){
			mid=(l+r)/2;
			if (check(i,mid)) l=mid;
			else r=mid;
			if (abs(r-l)/max(l,1.0)<=1e-8) break;
		}
		ans=max(ans,l);
	}
	printf("%.15lf",(double)ans);
}