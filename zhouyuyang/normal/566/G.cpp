#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct P{	
	int x,y;
	bool operator <(const P &a)const{
		if (x==a.x) return y<a.y;
		return x<a.x;
	}
}a[N],b[N];
long long cha(P a,P b,P c){
	int x1=b.x-a.x,x2=c.x-b.x;
	int y1=b.y-a.y,y2=c.y-b.y;
	return 1ll*x1*y2-1ll*y1*x2;
}
int n,m,rx,ry;
int main(){
	scanf("%d%d%*d%*d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		rx=max(rx,b[i].x); ry=max(ry,b[i].y);
	}
	for (int i=1;i<=n;i++)
		if (a[i].x>=rx||a[i].y>=ry) return puts("Max"),0;
	b[++m]=(P){0,ry};
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int j=0;
	for (int i=1;i<=m;i++){
		for (;j&&cha(b[j-1],b[j],b[i])>=0;j--);
		b[++j]=b[i];
	}
	m=j; j=1;
	for (int i=1;i<=n;i++){
		for (;b[j+1].x<=a[i].x;j++);
		if (cha(b[j],a[i],b[j+1])<=0)
			return puts("Max"),0;
	}
	puts("Min");
}