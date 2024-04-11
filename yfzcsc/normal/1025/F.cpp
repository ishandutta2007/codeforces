#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
typedef long long ll;
struct point{
	ll x,y;
	void scan(){
		scanf("%lld%lld",&x,&y);
	}
	point(){}
	point(ll x,ll y):x(x),y(y){}
	point operator-(const point& p)const{
		return point(x-p.x,y-p.y);
	}
	point operator+(const point& p)const{
		return point(x+p.x,y+p.y);
	}
}A[maxn],B[maxn];
int n;
ll ans=0;
ll cal(ll x){
	return x*(x-1)/2;
}
ll cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
int get(point a){
	if(a.x>=0&&a.y>=0)return 1;
	else if(a.x>=0&&a.y<=0)return 2;
	else if(a.x<=0&&a.y<=0)return 3;
	else if(a.x<=0&&a.y>=0)return 4;
}
int main(){
//	printf("[%lld]",cross(point(0,1),point(1,-1)));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)A[i].scan();
	for(int i=1;i<=n;++i){
		int sz=0;
		for(int j=1;j<=n;++j)if(i!=j)
			B[++sz]=A[j]-A[i];
		sort(B+1,B+sz+1,[](point a,point b){
			int g=get(a),g2=get(b);
			if(g!=g2)return g<g2;
			return cross(a,b)<0;
		});
		int k=1;
		#define pre(x) (x==1?sz:x-1)
		#define nxt(x) (x==sz?1:x+1)
		#define dis(x,y) (x<=y?y-x:y+sz-x)
		while(cross(B[1],B[pre(k)])>0)k=pre(k);
		for(int j=1;j<=sz;++j){
			while(cross(B[j],B[k])<0)k=nxt(k);
			int l=dis(k,j);
			int r=sz-l-1;
			ans+=cal(l)*cal(r);
//			printf("[%lld,%lld(%d,%d,%lld)]\n",B[j].x,B[j].y,j,k,ans);
		}
//		puts("");
	}
//	printf("[%lld]",ans);
	printf("%lld",ans/2);
}