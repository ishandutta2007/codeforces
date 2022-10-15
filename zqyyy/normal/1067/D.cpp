#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
const double eps=1e-11;
bool eq(double x, double y) {return abs(x-y)<eps;}
struct Line {
	double x, y;
}c[N], stk[N];
inline double slope(Line a, Line b) {
	return (b.y-a.y)/(b.x-a.x);
}
struct Mat {
	int n, m;
	double a[3][3];
	Mat(int _n=0, int _m=0):n(_n), m(_m) {
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) a[i][j]=0;
	}
	double* operator [](int i) {return a[i];}
	Mat operator *(Mat q) {
		Mat r(n, q.m); assert(m==q.n);
		for (int i=0; i<n; i++)
			for (int k=0; k<m; k++)
				for (int j=0; j<q.m; j++)
					r[i][j]+=a[i][k]*q[k][j];
		return r;
	}
}A[35];
int n, m, tp;
ll t; double v;
int main() {
	n=read(), t=read();
	for (int i=1; i<=n; i++) {
		int a=read(), b=read(); double p; scanf("%lf", &p);
		c[i]={p, p*a}, v=max(v, p*b);
	}
	sort (c+1, c+n+1, [](auto x, auto y) {return eq(x.x, y.x)?x.y>y.y:x.x<y.x;});
	for (int i=1; i<=n; i++) {
		if (eq(c[i-1].x, c[i].x)) continue;
		while (tp>1 && slope(stk[tp-1], stk[tp])<=slope(stk[tp], c[i])) tp--;
		stk[++tp]=c[i];
	}
	Mat f(1, 3); f[0][2]=1; int p=1;
	while (p<=tp && f[0][1]<t) {
		while (p<tp && f[0][0]-f[0][1]*v<=slope(stk[p], stk[p+1])) p++;
		A[0]=Mat(3, 3);
		A[0][0][0]=1-stk[p].x, A[0][1][0]=stk[p].x*v, A[0][2][0]=stk[p].y;
		A[0][1][1]=A[0][2][1]=A[0][2][2]=1;
		for (int i=1; i<=33; i++) A[i]=A[i-1]*A[i-1];
		for (int i=33; ~i; i--)
			if (f[0][1]+(1ll<<i)<t) {
				Mat tmp=f*A[i];
				if (p==tp || tmp[0][0]-tmp[0][1]*v>slope(stk[p], stk[p+1]))
					f=tmp;
			}
		f=f*A[0], p++;
	}
	printf("%.9lf\n", f[0][0]);
    return 0;
}