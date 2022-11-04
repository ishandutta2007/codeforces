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
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,yb
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
using namespace std;

struct prob{
	int ssc,lsc,st,lt;
	db pos;
};
bool cmp(const prob &a,const prob &b){
	return a.pos*a.lt*(1-b.pos)<b.pos*b.lt*(1-a.pos);
}
prob a[2005];

struct State{
	db pts,times;
	State small(prob a){
		return (State){pts+a.ssc,times+a.st};
	}
	State large(prob a,int T){
		return (State){pts+a.ssc+(1-a.pos)*a.lsc,a.st+a.pos*times+(1-a.pos)*(a.lt+T)};
	}
	bool operator <(const State &a)const{
		if (fabs(pts-a.pts)>1e-8)
			return pts<a.pts;
		return times>a.times;
	}
};
State f[2000];

int n,t;

int main(){
	scanf("%d%d",&n,&t);
	For(i,1,n){
		double tmp;
		scanf("%d%d",&a[i].ssc,&a[i].lsc),
		scanf("%d%d%lf",&a[i].st,&a[i].lt,&tmp);
		a[i].pos=tmp;
	}
	sort(a+1,a+n+1,cmp);
	For(i,1,n) for (int j=t;j>=0;j--){
		if (j>=a[i].st) f[j]=max(f[j],f[j-a[i].st].small(a[i]));
		if (j>=a[i].st+a[i].lt) f[j]=max(f[j],f[j-a[i].st-a[i].lt].large(a[i],j-a[i].st-a[i].lt));
	}
	State ans=(State){0,0};
	For(j,0,t) ans=max(ans,f[j]);
	printf("%.15lf %.15lf",(double)ans.pts,(double)ans.times);
}