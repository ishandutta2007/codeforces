#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
typedef long long ll;
typedef long double ldb;
const ldb pi=acos(-1.0);
struct Point{
	ll x,y,id;
	void scan(int z){scanf("%lld%lld",&x,&y);id=z;}
	Point(){}
	Point(ll x,ll y):x(x),y(y){}
	Point operator-(const Point& p)const{return Point(x-p.x,y-p.y);}
	Point operator+(const Point& p)const{return Point(x+p.x,y+p.y);}
	ll operator*(const Point& p)const{return (ll)x*p.y-(ll)y*p.x;}
	bool operator<(const Point& p)const{return y<p.y;x<p.x||(x==p.x&&y<p.y);}
	void print(){printf("%lld %lld\n",x,y);}
}a[maxn];
struct Line{
	int x,y;
	ldb k;
	Line(){}
	Line(int x,int y,Point p):x(x),y(y){
		k=atan2l(p.y,p.x);
		if(k<0)k+=2*pi;
	}
	bool operator<(const Line& p)const{return k<p.k;}
}b[maxn*maxn];
int n,tp,rk[maxn];
ll S;
void chk(int l,int r,Point c,Point b,int flg){
	while(l<=r){
		int mid=l+r>>1;
		ll s=fabs((a[mid]-c)*(b-c));
		if(s==S){
			puts("Yes");
			a[mid].print();
			b.print();
			c.print();
			exit(0);
		}
		if(flg==0)s<=S?r=mid-1:l=mid+1;
		else s<=S?l=mid+1:r=mid-1;
	}
}
int main(){
	scanf("%d%lld",&n,&S),S*=2;
	for(int i=1;i<=n;++i)a[i].scan(i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)rk[a[i].id]=i;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			b[++tp]=Line(a[i].id,a[j].id,a[j]-a[i]);
	sort(b+1,b+tp+1);
	for(int i=1;i<=tp;++i){
		int x=b[i].x,y=b[i].y;
		if(rk[x]>rk[y])swap(x,y);
		chk(1,rk[x]-1,a[rk[x]],a[rk[y]],0);
		chk(rk[y]+1,n,a[rk[x]],a[rk[y]],1);
		swap(a[rk[x]],a[rk[y]]);
		swap(rk[x],rk[y]);
	}
	puts("No");
}