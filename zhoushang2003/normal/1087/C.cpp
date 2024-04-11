#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=3,M=1e4;
struct S
{
	int x,y;
};
int x[N],y[N],p[N],X,Y,t,A=1;
S w[M];
int D(int x,int y,int z,int k)
{
	p[0]=x,p[1]=y,p[2]=z;
	sort(p,p+N);
	return p[k];
}
void P(int a,int b,int c,int d)
{
	if(a>c)
		swap(a,c),swap(b,d);
	while(a<c)
		w[t].x=a,w[t++].y=b,a++;
	if(b>d)
		swap(b,d);
	for(int i=b;i<=d;i++)
		w[t].x=a,w[t++].y=i;
}
bool C(S x,S y)
{
	if(x.x!=y.x)
		return x.x<y.x;
	return x.y<y.y;
}
int main()
{
	for(int i=0;i<N;i++)
		cin>>x[i]>>y[i];
	X=D(x[0],x[1],x[2],1),Y=D(y[0],y[1],y[2],1);
	for(int i=0;i<N;i++)
		P(x[i],y[i],X,Y);
	sort(w,w+t,C);
	for(int i=1;i<t;i++)
		if(w[i].x!=w[i-1].x||w[i].y!=w[i-1].y)
			A++;
	cout<<A<<endl<<w[0].x<<" "<<w[0].y<<endl;
	for(int i=1;i<t;i++)
		if(w[i].x!=w[i-1].x||w[i].y!=w[i-1].y)
			cout<<w[i].x<<" "<<w[i].y<<endl;
	return 0;
}