#include<bits/stdc++.h>
#define eps 0.0000001
using namespace std;
int n,s;
struct P{
	double x,v;
	int dir;
}p[520517];
int g1=0,g2=0;
double now,dis,tem;

double suan(double v1,double v2,double d,double t){
	return (v1*v2*t-v1*d)/(v2-v1);
}

int a[1001000],b[1001000],st,en;
bool ok(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++){
		if (p[i].dir){//right
			dis=1000000-p[i].x;
			if (dis/p[i].v<=now){
				a[0]=1000001;
				continue;
			}
			if (dis/(p[i].v+s)>now) continue;
			tem=suan(p[i].v,p[i].v+s,dis,now);
			st=(int)max(ceil(p[i].x+tem-tem/p[i].v*s),(double)0.0);
			en=(int)min((p[i].x+0.000000001),(double)1000000.0);
			a[st]=max(a[st],en-st+1);
		}else{
			dis=p[i].x;
			if (dis/p[i].v<=now) {
				b[0]=1000001;
				continue;
			}
			if (dis/(p[i].v+s)>=now) continue;
			tem=suan(p[i].v,p[i].v+s,dis,now);
			en=(int)min((p[i].x-tem+tem/p[i].v*s),(double)1000000.0);
			st=(int)max((p[i].x+0.000000001),(double)0.0);
			b[st]=max(b[st],en-st+1);
		}
	}
	for (int i=0;i<=1000000;i++){
		a[i+1]=max(a[i+1],a[i]-1);
		b[i+1]=max(b[i+1],b[i]-1);
		if (a[i]&&b[i]) return 1;
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&s);
	int a,b,c;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		p[i].x=a;p[i].v=b;p[i].dir=c-1;
	}
	
	double l=0,r=1000233,mid;
	for (int nnd=0;nnd<50;nnd++){
		mid=(l+r)/2.0;
		now=mid;
		if (ok()){
			r=mid;
		}else{
			l=mid;
		}
	}
	
	printf("%.10lf",l);
	return 0;
}