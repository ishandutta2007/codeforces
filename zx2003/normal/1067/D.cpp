#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const long double eps=0;//1e-15;
int n,a[N],b[N],j,tp,pp;
ll T,i;
long double p[N],w;
struct P{long double x,y;long double getv(long double v){return y-x*v;}}c[N],st[N];
P operator-(P a,P b){return (P){a.x-b.x,a.y-b.y};}
long double cross(P a,P b){return a.x*b.y-b.x*a.y;}
void mv(long double x){for(;pp<tp && st[pp].getv(x)<st[pp+1].getv(x)+eps;++pp);}
long double v1[3],v2[3];
struct mat{
	long double a[3][3];
	void trs(){memset(v2,0,sizeof v2);for(int i=0;i<3;++i)for(int j=0;j<3;++j)v2[j]+=v1[i]*a[i][j];}
}mi[35];
mat operator*(mat a,mat b){
	static mat ret;memset(ret.a,0,sizeof ret.a);
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)for(int k=0;k<3;++k)ret.a[i][k]+=a.a[i][j]*b.a[j][k];
	return ret;
}
int main(){
	scanf("%d%lld",&n,&T);
	for(i=1;i<=n;++i){
		double pp;scanf("%d%d%lf",a+i,b+i,&pp);p[i]=pp;
		w=max(w,b[i]*p[i]);
	}
	for(i=1;i<=n;++i)c[i]=(P){p[i],p[i]*(a[i]+T*w)};
	sort(c+1,c+n+1,[&](P a,P b){return a.x<b.x;});
	for(i=1;i<=n;++i){
		for(;tp>1 && cross(c[i]-st[tp-1],st[tp]-st[tp-1])<=eps;--tp);
		st[++tp]=c[i];
	}
	pp=1;
	long double f=0;
	for(i=T;;){
		mv(f+i*w);
		memset(mi[0].a,0,sizeof mi[0].a);
		mi[0].a[2][0]=st[pp].y;mi[0].a[2][1]=-1;mi[0].a[2][2]=1;
		mi[0].a[1][1]=1;mi[0].a[1][0]=-st[pp].x*w;
		mi[0].a[0][0]=1-st[pp].x;
		v1[0]=f;v1[1]=i;v1[2]=1;
		for(j=1;j<35;++j)mi[j]=mi[j-1]*mi[j-1];
		for(j=34;j>=0;--j){
			mi[j].trs();
			if(v2[1]>0 && (pp==tp || st[pp].getv(v2[0]+v2[1]*w)>st[pp+1].getv(v2[0]+v2[1]*w)+eps))memcpy(v1,v2,sizeof v1);
		}
		mi[0].trs();memcpy(v1,v2,sizeof v1);
		f=v2[0];i=v2[1];if(i==0)break;++pp;
	}
	printf("%.8f\n",double(f));
	return 0;
}