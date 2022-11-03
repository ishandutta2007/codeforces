//
//  main.cpp
//  C
//
//  Created by  on 8/1/16.
//  Copyright  2016 . All rights reserved.
//

#include<cstdio>
#include<cmath>
#define D double
#define S(x)	((x)*(x))
#define G(t)	a[t]=x[t]-x[2];b[t]=y[t]-y[2];c[t]=(S(x[t])+S(y[t])-S(x[2])-S(y[2]))/2;
#define M(p,q)	(p[0]*q[1]-p[1]*q[0])
D g(D a,D b){return fabs(b)<1e-4?a:g(b,fmod(a,b));}
D x[3],y[3],a[3],b[2],c[2],A,X,Y;
int main()
{
    for(int i=0;i<3;++i)scanf("%lf%lf",x+i,y+i);
    G(0);G(1);
    X=M(c,b)/M(a,b);
    Y=M(a,c)/M(a,b);
    for(int i=0;i<3;++i)a[i]=atan2(x[i]-=X,y[i]-=Y);
    A=g(M_PI*2,g(fabs(a[1]-a[0]),fabs(a[2]-a[0])));
    printf("%lf\n",(S(x[0])+S(y[0]))*sin(A)*M_PI/A);
    return 0;
}