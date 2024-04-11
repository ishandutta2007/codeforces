#include<bits/stdc++.h>
#define maxn 2100
using namespace std;
typedef double ldb;
struct point{
	ldb x,y;
	void scan(){scanf("%lf%lf",&x,&y);}
	point(){}
	point(ldb x,ldb y):x(x),y(y){}
	point operator+(const point& p)const{return point(x+p.x,y+p.y);}
	point operator-(const point& p)const{return point(x-p.x,y-p.y);}
	point operator*(const ldb d)const{return point(x*d,y*d);}
	int operator==(const point& p)const{return fabs(p.x-x)<1e-9&&fabs(p.y-y)<1e-9;}
}p[maxn],S,anses[maxn];
ldb cross(point A,point B){return A.x*B.y-B.x*A.y;}
ldb dot(point A,point B){return A.x*B.x+A.y*B.y;}
int n,tp,tg[maxn];
ldb ls[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		p[i].scan(),S=S+p[i];
	for(int i=1;i<=n;++i)if(!tg[i])
		for(int j=i;j<=n;++j)if(!tg[j]&&S*2==(p[i]+p[j])*n)
			tg[i]=tg[j]=1;
	S=S*(1/(double)n);
	for(int i=1;i<=n;++i)if(!tg[i])
		p[++tp]=p[i];
	n=tp,tp=0;
	if(!n)return puts("-1"),0;
	for(int i=1;i<=n;++i)
		p[i]=p[i]-S;
	for(int i=1;i<=n;++i){
		point x=p[1]+p[i],y(-x.y,x.x);
		for(int j=1;j<=n;++j)
			ls[j]=dot(p[j],y);
		sort(ls+1,ls+n+1);
		for(int j=1;j<=n+1-j;j++)
			if(fabs((ls[j]+ls[n+1-j])/2)>1e-9)goto nxt;
		anses[++tp]=y;
		nxt:;
	}
	int sum=0;
	for(int i=1;i<=tp;++i){
		for(int j=1;j<i;++j)
			if(fabs(cross(anses[i],anses[j]))<1e-9)goto nxt2;
		sum++;
		nxt2:;
	}
	printf("%d",sum);
}