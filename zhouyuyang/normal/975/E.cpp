#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 100001
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct P{double x,y,dis;}p[N],G,g;
int n,q,f,t,v,_,a,b;
double get_distance(P A,P B)
{
	return pow(pow(A.x-B.x,2.0)+pow(A.y-B.y,2.0),0.5);
}
double get_cos(P A,P B)
{
	return ((A.x-G.x)*(B.x-G.x)+(A.y-G.y)*(B.y-G.y))/(A.dis*B.dis);
}
double get_sin(P A,P B)
{
	return ((A.x-G.x)*(B.y-G.y)-(B.x-G.x)*(A.y-G.y))/(A.dis*B.dis);
}
P get(int k)
{
	P res;
	res.dis=p[k].dis;
	res.x=g.x+res.dis*get_sin(p[k],p[a]);
	res.y=g.y+res.dis*get_cos(p[k],p[a]);
	return res;
}
void change(int k)
{
	P res=get(k);
	g.x=res.x,g.y=res.y-res.dis;
}
void rchange(int k)
{
	g.x=p[k].x,g.y=p[k].y-p[k].dis;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	  scanf("%lf%lf",&p[i].x,&p[i].y);
	for(int i=2;i<n;i++)
	  {
	  double px=(p[1].x+p[i].x+p[i+1].x)/3.0;
	  double py=(p[1].y+p[i].y+p[i+1].y)/3.0;
	  double A=abs((p[i].x-p[1].x)*(p[i+1].y-p[1].y)-(p[i+1].x-p[1].x)*(p[i].y-p[1].y));
	  G.x+=A*px,G.y+=A*py,G.dis+=A;
	  }
	G.x/=G.dis,G.y/=G.dis,g=G;
	for(int i=1;i<=n;i++)
	  p[i].dis=get_distance(p[i],G);
	while(q && _!=1)
	  {
	  q--,scanf("%d",&_);
	  if(_==2)scanf("%d",&v),printf("%.10lf %.10lf\n",p[v].x,p[v].y);
	  else scanf("%d%d",&f,&t),rchange(3-f),a=3-f,b=t;
	  }
	while(q--)
	  {
	  scanf("%d",&_);
	  if(_==2){scanf("%d",&v);P res=get(v);printf("%.10lf %.10lf\n",res.x,res.y);}
	  else{scanf("%d%d",&f,&t);if(f==a)change(b),a=b;swap(b,t);}
	  }
	return 0;
}