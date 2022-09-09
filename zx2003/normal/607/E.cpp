#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
const double eps=1e-15;
inline int dcmp(const double&x){return fabs(x)<eps?0:(x>0?1:-1);}
struct P{
	double x,y;
	inline P(double _x=0,double _y=0):x(_x),y(_y){}
	inline P operator+(const P&rhs){return P(x+rhs.x,y+rhs.y);}
	inline P operator-(const P&rhs){return P(x-rhs.x,y-rhs.y);}
	inline P operator*(const double&k){return P(x*k,y*k);}
	inline double len()const{return sqrt(x*x+y*y);}
	inline double geta(){return atan2(y,x);}
}O,a[N],p[N];
inline double cross(const P&a,const P&b){return a.x*b.y-b.x*a.y;}
inline double dot(const P&a,const P&b){return a.x*b.x+a.y*b.y;}
inline P interr(int x,int y){
	double z=-cross(a[x]-a[y],p[y])/cross(p[x],p[y]);
	return a[x]+p[x]*z;
}
inline double inter(int x,int y){
	return (interr(x,y)-O).len();
}
int n,x,y,m,i,bd[N][2];
double l=0,r=1e10,mid,dis[N],lee[N],le[N],ans;
pair<double,int>ev[N*2];int xb;
int bi[N*2];
inline void add(int x){for(;x<=xb;x+=x&-x)++bi[x];}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
long long su;
inline void getev(double mid){
	xb=0;memset(bd+1,0,n<<3);
	for(i=1;i<=n;++i)if(dcmp(dis[i]-mid)==-1){
		double d=sqrt(mid*mid-dis[i]*dis[i]),x1=lee[i]-d,x2=lee[i]+d,a1,a2;
		P p1=a[i]+p[i]*(x1/le[i]),p2=a[i]+p[i]*(x2/le[i]);
		ev[++xb]=make_pair((p1-O).geta(),i);ev[++xb]=make_pair((p2-O).geta(),i);
	}
	sort(ev+1,ev+xb+1);
	for(i=1;i<=xb;++i)x=ev[i].second,bd[x][bd[x][0]?1:0]=i;
}
inline long long calc(){
	su=0;memset(bi+1,0,xb<<2);
	for(i=1;i<=xb;++i){
		x=ev[i].second;
		if(i==bd[x][0])su+=ask(bd[x][1])-ask(bd[x][0]),add(bd[x][1]);
	}
	return su;
}
set<int>S;
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&m);
	O=P(x*1e-3,y*1e-3);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x,&y),a[i]=P(0,y*1e-3),p[i]=P(1,x*1e-3);
		le[i]=p[i].len();
		dis[i]=abs(cross(O-a[i],p[i])/le[i]);
		lee[i]=dot(O-a[i],p[i])/le[i];
	}
	double lst=-1;
	for(;r-l!=lst;){
		lst=r-l;
		mid=(l+r)/2;
		getev(mid);
		if(calc()<m)l=mid;else r=mid;
	}
	getev(l);
	ans=(m-calc())*l;
	for(i=1;i<=xb;++i){
		x=ev[i].second;
		if(i==bd[x][0]){
			S.insert(bd[x][1]);
			for(auto it=S.upper_bound(i);*it<bd[x][1];++it)ans+=inter(x,ev[*it].second);
		}
	}
	printf("%.8f\n",ans);
	return 0;
}