#include<bits/stdc++.h>
#define maxn 201000
using namespace std;
typedef long long ll;
struct Point{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	Point operator+(const Point& p)const{return Point(x+p.x,y+p.y);}
	Point operator-(const Point& p)const{return Point(x-p.x,y-p.y);}
	ll operator*(const Point& p)const{return 1ll*x*p.y-1ll*y*p.x;}
	bool operator<(const Point & p)const{return x==p.x?y<p.y:x<p.x;}
}a[maxn];
typedef pair<Point,int> pii;
int tp,n,ans=0,ban[maxn];
pii sta[maxn];
vector<int> sol2(){
	sort(a+1,a+n+1);
	int tp=0;
	for(int i=1;i<=n;++i)if(!ban[i]){
		while(tp>1&&(sta[tp].first-sta[tp-1].first)*(a[i]-sta[tp-1].first)>=0)tp--;
		sta[++tp]=pii(a[i],i);
	}
	int m=tp;
	for(int i=n-1;i>=1;--i)if(!ban[i]){
		while(tp>m&&(sta[tp].first-sta[tp-1].first)*(a[i]-sta[tp-1].first)>=0)tp--;
		sta[++tp]=pii(a[i],i);
	}
//	for(int i=1;i<tp;++i)printf("[%d,%d]",sta[i].first.x,sta[i].first.y);puts("");
	vector<int> ret;
	for(int i=1;i<tp;++i)ret.push_back(sta[i].second);
	for(int i=1;i<tp;++i)if(sta[i].first.x%2||sta[i].first.y%2){
		puts("Ani");
		exit(0);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	int M=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(!a[i].x&&!a[i].y)M=1;
	}
	if(!M)a[++n]=Point(0,0);
	auto a=sol2();
	for(int i=0;i<a.size();++i)ban[a[i]]=i&1;
	sol2();
	memset(ban,0,sizeof(ban));
	for(int i=2;i<a.size();++i)ban[a[i]]=~i&1;
	sol2();
	puts("Borna");
}