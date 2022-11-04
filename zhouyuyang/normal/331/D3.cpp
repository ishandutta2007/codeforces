#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
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
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=200005,T=51;
int sgn(int x){
	return x>0?1:(x==0?0:-1);
}
int n,b,q;
ll tim[N];
struct arrow *null;
struct arrow{
	int x0,x1,y0,y1,dx,dy;
	arrow *to[T];
	ll dis[T];
	void read(){
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		dx=sgn(x1-x0); dy=sgn(y1-y0);
	}
	void read2(){
		char c;
		scanf("%d%d %c",&x0,&y0,&c);
		x1=x0; y1=y0;
		if (c=='L') dx--;
		if (c=='R') dx++;
		if (c=='D') dy--;
		if (c=='U') dy++;
	}
}a[N],*ord[N];
bool cmpx0(arrow *a,arrow *b){
	return max(a->x0,a->x1)<max(b->x0,b->x1);
}
bool cmpx1(arrow *a,arrow *b){
	return min(a->x0,a->x1)>min(b->x0,b->x1);
}
bool cmpy0(arrow *a,arrow *b){
	return max(a->y0,a->y1)<max(b->y0,b->y1);
}
bool cmpy1(arrow *a,arrow *b){
	return min(a->y0,a->y1)>min(b->y0,b->y1);
}
void work(int dx,int dy,int arrow::*y0,int arrow::*y1,bool (*cmp)(arrow*,arrow*)){
	For(i,1,n+q) ord[i]=a+(n+q+1-i);
	stable_sort(ord+1,ord+n+q+1,cmp);
	typedef multimap<int,arrow*> AXS; AXS s;
	For(i,1,n+q){
		if (ord[i]<=a+n){
			AXS::iterator
				lo=s.lower_bound(min(ord[i]->*y0,ord[i]->*y1)),
				hi=s.upper_bound(max(ord[i]->*y0,ord[i]->*y1)),
				it;
			for (it=lo;it!=hi;s.erase(it++)){
				arrow *tmp=it->se;
				tmp->to[0]=ord[i];
				tmp->dis[0]=abs(ord[i]->x1-tmp->x1)
						   +abs(ord[i]->y1-tmp->y1);
			}
		}
		if (ord[i]->dx==dx&&ord[i]->dy==dy)
			s.insert(make_pair(ord[i]->*y1,ord[i]));
	}
	for (AXS::iterator it=s.begin();it!=s.end();it++){
		arrow *tmp=it->second;
		tmp->to[0]=null;
		tmp->dis[0]=1ll<<60;
	}
}
int main(){
	null=a;
	scanf("%d%d",&n,&b);
	For(i,1,n) a[i].read();
	scanf("%d",&q);
	For(i,1,q) a[n+i].read2(),scanf("%lld",&tim[i]);
	work( 1, 0,&arrow::y0,&arrow::y1,cmpx0);
	work(-1, 0,&arrow::y0,&arrow::y1,cmpx1);
	work( 0, 1,&arrow::x0,&arrow::x1,cmpy0);
	work( 0,-1,&arrow::x0,&arrow::x1,cmpy1);
	null->to[0]=null;
	For(j,1,T-1) For(i,0,n+q){
		a[i].to[j]=a[i].to[j-1]->to[j-1];
		a[i].dis[j]=min(a[i].dis[j-1]+a[i].to[j-1]->dis[j-1],1ll<<60);
	}
	For(i,1,q){
		arrow *u=a+n+i;
		Rep(j,T-1,0) if (u->dis[j]<=tim[i]) 
			tim[i]-=u->dis[j],u=u->to[j];
		if (u->to[0]!=null&&tim[i]>(u->to[0]->x1-u->x1)*u->dx+
			                       (u->to[0]->y1-u->y1)*u->dy)
			tim[i]-=u->dis[0],u=u->to[0];
		printf("%lld %lld\n",min(max(u->x1+tim[i]*u->dx,0ll),(ll)b),
							 min(max(u->y1+tim[i]*u->dy,0ll),(ll)b));
	}
}