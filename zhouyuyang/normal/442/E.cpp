#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) ((x)*(x))
using namespace std;
const double pi=acos(-1);
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
struct P{
	double x,y;
}a[1005];
int n;
double val;
double calc(double x,double y){
	double mn1=1<<30,mn2=1<<30;
	For(i,1,n){
		double v=sqrt(sqr(a[i].x-x)+sqr(a[i].y-y));
		if (v<mn1) mn2=mn1,mn1=v;
		else mn2=min(mn2,v);
	}
	return mn2;
}
double w,h,ans;
int main(){
	srand(time(NULL));
	double ans=0;
	scanf("%lf%lf%d",&w,&h,&n);
	For(i,1,n) scanf("%lf%lf",&a[i].x,&a[i].y);
	For(T,1,60){
		double x=rand()*rand()%(int)w;
		double y=rand()*rand()%(int)h;
		double stp=h; val=0; val=calc(x,y);
		for (;stp>1e-10;){
			bool chg=0; double X,Y;
			For(j,0,3){
				double XX=x+stp*dx[j];
				double YY=y+stp*dy[j];
				if (XX<0||XX>w||YY<0||YY>h) continue;
				double nval=calc(XX,YY);
				if (nval>val) val=nval,X=XX,Y=YY,chg=1; 
			}
			if (chg) x=X,y=Y;
			stp*=0.9;
		}
		ans=max(ans,val);
	}
	printf("%.15lf\n",ans);
}