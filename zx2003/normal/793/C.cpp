#include<bits/stdc++.h>
const int N=1e5+5;
struct P{
	int x,y;
	inline void in(){
		scanf("%d%d",&x,&y);
	}
}p1,p2,r[N],v[N];
int n,i;
double lb,rb=1ll<<60,tt[4];
inline double calc1(int a,int b,int c,P p,P q){
	if(q.x==0)return -1;
	double t=(a-p.x)*1.0/q.x,yy=p.y+t*q.y;
	if(t<0 || yy<b || yy>c)return -1;
	return t;
}
inline double calc2(int a,int b,int c,P p,P q){
	if(q.y==0)return -1;
	double t=(a-p.y)*1.0/q.y,yy=p.x+t*q.x;
	if(t<0 || yy<b || yy>c)return -1;
	return t;
}
int main(){
	scanf("%d",&n);
	p1.in();p2.in();
	for(i=1;i<=n;++i){
		r[i].in(),v[i].in();
		double t1=-1,t2=-1;
		tt[0]=calc1(p1.x,p1.y,p2.y,r[i],v[i]);
		tt[1]=calc2(p2.y,p1.x,p2.x,r[i],v[i]);
		tt[2]=calc1(p2.x,p1.y,p2.y,r[i],v[i]);
		tt[3]=calc2(p1.y,p1.x,p2.x,r[i],v[i]);
		if(p1.x<r[i].x && r[i].x<p2.x && p1.y<r[i].y && r[i].y<p2.y)t1=0;else
			for(int i=0;i<4;++i)if(tt[i]!=-1 && (t1==-1 || tt[i]<t1))t1=tt[i];
		for(int i=0;i<4;++i)if(tt[i]!=-1 && (t2==-1 || tt[i]>t2))t2=tt[i];
		if(!v[i].x && !v[i].y){
			if(t1!=0)return puts("-1"),0;
			continue;
		}
		if(t2==-1 || (!v[i].x && (r[i].x==p1.x || r[i].x==p2.x)) || 
			(!v[i].y && (r[i].y==p1.y || r[i].y==p2.y)))return puts("-1"),0;
		lb=std::max(lb,t1);rb=std::min(rb,t2);
	}
	if(lb>=rb)puts("-1");else printf("%.8f\n",lb);
}