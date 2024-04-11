#include<bits/stdc++.h>
#define db long double
using namespace std;
db rnd(){
	db x=0;
	for (int i=1;i<=12;i++)
		x=x*10+rand()%10;
	return (rand()&1?-x:x);
}
db sqr(db x){
	return x*x;
}
db x[5],y[5],r[5];
int n,tot,ans;
struct P{
	db x,y;
}sec[20];
int main(){
	srand(19260817);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>r[i];
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (fabs(sqr(x[i]-x[j])+sqr(y[i]-y[j])-sqr(r[i]+r[j]))<1e-5)
				sec[++tot]=(P){x[i]+1.0*(x[j]-x[i])*r[i]/(r[i]+r[j]),
							   y[i]+1.0*(y[j]-y[i])*r[i]/(r[i]+r[j])};
			else if (fabs(sqr(x[i]-x[j])+sqr(y[i]-y[j])-sqr(r[i]-r[j]))<1e-5){
				int p=i,q=j;
				if (r[p]<r[q]) swap(p,q);
				sec[++tot]=(P){x[p]+1.0*(x[q]-x[p])/(r[p]-r[q])*r[p],
							   y[p]+1.0*(y[q]-y[p])/(r[p]-r[q])*r[p]};
			}
			else if (sqr(x[i]-x[j])+sqr(y[i]-y[j])-sqr(r[i]+r[j])<-1e-5&&
				sqr(x[i]-x[j])+sqr(y[i]-y[j])-sqr(r[i]-r[j])>1e-5){
					db dis=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
					P tmp=(P){1.0*(x[j]-x[i])*r[i]/dis,
						      1.0*(y[j]-y[i])*r[i]/dis};
					db deg=acos((sqr(r[i])+sqr(dis)-sqr(r[j]))/(2*r[i]*dis));
					sec[++tot]=(P){x[i]+tmp.x*cos(deg)-tmp.y*sin(deg),y[i]+tmp.x*sin(deg)+tmp.y*cos(deg)};
					sec[++tot]=(P){x[i]+tmp.x*cos(-deg)-tmp.y*sin(-deg),y[i]+tmp.x*sin(-deg)+tmp.y*cos(-deg)};
				}
	int Tot=min(1,tot);
	for (int i=2;i<=tot;i++){
		bool flag=0;
		for (int j=1;j<=Tot;j++)
			if (fabs(sec[i].x-sec[j].x)<1e-5&&fabs(sec[i].y-sec[j].y)<1e-5)
				flag=1;
		if (!flag) sec[++Tot]=sec[i];
	}
	tot=Tot;
	int edge=0;
	for (int i=1;i<=n;i++){
		int times=0;
		for (int j=1;j<=tot;j++)
			if (fabs(sqrt(sqr(x[i]-sec[j].x)+sqr(y[i]-sec[j].y))-r[i])<1e-5)
				times++;
		if (!times) ans++;
		else edge+=times; 
	}
	printf("%d\n",ans+(!edge?1:(edge+2-tot)));
}