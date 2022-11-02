#include<iostream>
#include<cstdio>
using namespace std;
const int P=1010;
struct point
{
	long long x,y;
}c[2]={},p[2][P]={};
inline long long sqr(long long x)
{
	return x*x;
}
inline long long dis_sqr(const point &p1,const point &p2)
{
	return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}
inline long long dis_sqr(const point &p,long long A,long long B,long long C)
{
	return (sqr(A*p.x+B*p.y+C)+A*A+B*B-1)/(A*A+B*B);
}
int n[2];
void init()
{
	cin>>c[0].x>>c[0].y>>n[0];
	for(int i=1;i<=n[0];++i)
		cin>>p[0][i].x>>p[0][i].y;
	p[0][n[0]+1]=p[0][1];
	cin>>c[1].x>>c[1].y>>n[1];
	for(int i=1;i<=n[1];++i)
		cin>>p[1][i].x>>p[1][i].y;
	p[1][n[1]+1]=p[1][1];
}
//ab
//a=0,b=1a=1,b=0 
bool check(int a,int b)
{
	long long A[P]={},B[P]={},C[P]={},D[P]={},rsqr=dis_sqr(c[a],c[b]);
	for(int j=1;j<=n[b];++j)
	{
		A[j]=p[b][j].y-p[b][j+1].y;
		B[j]=p[b][j+1].x-p[b][j].x;
		C[j]=p[b][j].x*p[b][j+1].y-p[b][j+1].x*p[b][j].y;
		D[j]=dis_sqr(p[b][j],p[b][j+1]);
	}
	for(int i=1;i<=n[a];++i)
	{
		point p0{c[b].x+p[a][i].x-c[a].x,c[b].y+p[a][i].y-c[a].y};
		for(int j=1;j<=n[b];++j)
		{
			long long t1=dis_sqr(p0,p[b][j]),t2=dis_sqr(p0,p[b][j+1]);
			if(t1+D[j]<=t2 || t2+D[j]<=t1)
			{
				if((t1<=rsqr && t2>=rsqr) || (t1>=rsqr && t2<=rsqr))
					return true;
			}
			else
				if(dis_sqr(p0,A[j],B[j],C[j])<=rsqr && rsqr<=max(t1,t2))
					return true;
		}
	}
	return false;
}
int main()
{
	init();
	puts((check(1,0) || check(0,1)) ? "YES" : "NO");
	return 0;
}