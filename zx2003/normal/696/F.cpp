#include<bits/stdc++.h>
using namespace std;
const int N=305;
const long double eps=1e-10;
inline int dcmp(long double x){return fabsl(x)<eps?0:(x>0?1:-1);}
struct P{
	long double x,y;
	P(long double X=0,long double Y=0){x=X,y=Y;}
	inline void in(){int xx,yy;scanf("%d%d",&xx,&yy);x=xx;y=yy;}
	bool operator==(const P &b)const{return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;}
	long double len2(){return x*x+y*y;}
	long double len(){return sqrtl(len2());}
	inline void out(){printf("%.16f %.16f\n",double(x),double(y));}
};
P operator+(P a,P b){return P(a.x+b.x,a.y+b.y);}
P operator-(P a,P b){return P(a.x-b.x,a.y-b.y);}
P operator*(P a,long double b){return P(a.x*b,a.y*b);}
P operator/(P a,long double b){return P(a.x/b,a.y/b);}
P norm(P a){long double l=a.len();return P(a.x/l,a.y/l);}
long double dot(P a,P b){return a.x*b.x+a.y*b.y;}
long double cross(P a,P b){return a.x*b.y-a.y*b.x;}
struct Line{
	P s,t;
	Line(P X=P(),P Y=P()){s=X,t=Y;}
	inline bool onseg(P p){return dcmp(cross(p-s,t-s))==0 && dcmp((p.x-s.x)*(p.x-t.x))<=0 && dcmp((p.y-s.y)*(p.y-t.y))<=0;}
	inline long double dis(P p){return fabsl(cross(p-s,t-s)/(t-s).len());}
}aa[N*2];
P I(Line a,Line b){return a.s+(a.t-a.s)*(cross(b.t-b.s,a.s-b.s)/cross(a.t-a.s,b.t-b.s));}
P a[N*2],oo[N][N],o1,o2;long double rr[N][N],ans=1ll<<60,w;
int n,i,j,k,l,lm[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)a[i].in(),a[i+n]=a[i];
	if(n<5){puts("0");a[1].out();a[3].out();return 0;}
	for(i=1;i<n*2;++i)aa[i]=Line(a[i],a[i+1]);
	//printf("%d %d %d\n",dcmp(1),dcmp(0),dcmp(-1));
	for(i=1;i<=n;++i){
		for(j=k=1;j<n && dcmp(cross(a[i+j+1]-a[i+j],a[i+1]-a[i]))<0;++j){
			P p=I(aa[i],aa[i+j]),q=norm(a[i]-a[i+1])+norm(a[i+j+1]-a[i+j]),pp;
			for(;;++k){
				pp=I(aa[i+k],Line(p,p+q));
				if(aa[i+k].onseg(pp))break;
			}
			oo[i][j]=pp;rr[i][j]=aa[i].dis(pp);
		}
	//	(a[i+j+1]-a[i+j]).out();
	//	(a[i+1]-a[i]).out();
	//  printf("%.16Lg\n",cross(a[i+j+1]-a[i+j],a[i+1]-a[i]));
	//	printf("%d %d\n",i,j);
		lm[i]=j;
		for(j=k=n-1;j && dcmp(cross(a[i+j+1]-a[i+j],a[i+1]-a[i]))>=0;--j){
			P p,q,pp;
			if(dcmp(cross(a[i+j+1]-a[i+j],a[i+1]-a[i]))==0)p=(a[i]+a[i+j])/2,q=a[i+1]-a[i];
				else p=I(aa[i],aa[i+j]),q=norm(a[i]-a[i+1])+norm(a[i+j+1]-a[i+j]);
			for(;;--k){
				pp=I(aa[i+k],Line(p,p+q));
				if(aa[i+k].onseg(pp))break;
			}
			oo[i][j]=pp;rr[i][j]=aa[i].dis(pp);
		}
	}
	//printf("%d\n",n);
	for(i=1;i<=n;++i)for(j=1;j<lm[i];++j){
		k=i+j+1;k>n?k-=n:0;l=n-j-2;
	//	printf("%d %d %d\n",i,j,k);
		if(l>=lm[k])continue;
		w=std::max(rr[i][j],rr[k][l]);
	//	printf("%.8Lf\n",w);
		if(w<ans)ans=w,o1=oo[i][j],o2=oo[k][l];
	}
	printf("%.8f\n",double(ans));o1.out();o2.out();
	return 0;
}