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

#define INF (1<<29)
#define sqr(x) ((x)*(x))
#define eps (1e-7)
using namespace std;
const int N=1005;
struct Line{
	double x,y,vx,vy;
	void read(){
		double t1,t2;
		scanf("%lf%lf%lf%lf%lf%lf",&t1,&x,&y,&t2,&vx,&vy);
		vx=(vx-x)/(t2-t1);
		vy=(vy-y)/(t2-t1);
		x-=vx*t1; y-=vy*t1;
	}
}p[N],tmp;
struct P{
	double x,y;
}b[N];
double det(P a,P b){
	return a.x*b.y-a.y*b.x;
}
bool cmp(P a,P b){
	if (abs(det(a,b))<eps){
		if (abs(a.x-b.x)<eps) return a.y<b.y;
		return a.x<b.x;
	}
	return det(a,b)<0;
}
double a[N];
int n,ans,cnt;
int main(){
	scanf("%d",&n);
	For(i,1,n) p[i].read();
	For(i,1,n){
		int tot=0;
		For(j,1,n) if (j!=i){
			tmp.x=p[j].x-p[i].x;
			tmp.y=p[j].y-p[i].y;
			tmp.vx=p[j].vx-p[i].vx;
			tmp.vy=p[j].vy-p[i].vy;
			double t=0;
			if (tmp.vx) t=tmp.x/tmp.vx;
			else if (tmp.vy) t=tmp.y/tmp.vy;
			if (abs(tmp.x-tmp.vx*t)<eps)
				if (abs(tmp.y-tmp.vy*t)<eps){
					a[++tot]=t;
					b[tot].x=tmp.vx;
					b[tot].y=tmp.vy;
				}
		}
		sort(a+1,a+tot+1);
		cnt=0;
		for (int j=1;j<=tot;j++){
			if (abs(a[j]-a[j-1])<eps) cnt++;
			else cnt=1;
			ans=max(ans,cnt);
		}
		cnt=0;
		sort(b+1,b+tot+1,cmp);
		for (int j=1;j<=tot;j++){
			if (abs(det(b[j],b[j-1]))<eps){
				if (abs(b[j].x-b[j-1].x)>eps||abs(b[j].y-b[j-1].y)>eps) cnt++;
				else;
			}
			else cnt=1;
			ans=max(ans,cnt);
		}
	}
	printf("%d\n",ans+1);
}