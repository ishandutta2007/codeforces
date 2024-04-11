#include<bits/stdc++.h>
#define db double
#define eps 1e-8
#define N 3010
using namespace std;

int n;
db x,y,sx,sy,ans;
struct Xn
{
    db a,b,c;
    bool operator < (const Xn &u) const
    {
	if(fabs(b)<eps) return 1;
	if(fabs(u.b)<eps) return 0;
	return a/b<u.a/u.b;
    }
}xn[N];

int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%lf%lf%lf",&xn[i].a,&xn[i].b,&xn[i].c);
    sort(xn+1,xn+n+1);
    for(i=1;i<=n;i++)
    {
	sx=sy=0;
	for(j=i%n+1;j!=i;j=j%n+1)
	{
	    x=(xn[j].c*xn[i].b-xn[i].c*xn[j].b)/(xn[i].a*xn[j].b-xn[j].a*xn[i].b);
	    y=(xn[j].c*xn[i].a-xn[i].c*xn[j].a)/(xn[j].a*xn[i].b-xn[i].a*xn[j].b);
	    ans+=x*sy-y*sx;
	    sx+=x,sy+=y;
	}
    }
    printf("%.12f",ans*3/n/(n-1)/(n-2));
}