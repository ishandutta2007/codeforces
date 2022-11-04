#include<bits/stdc++.h>
using namespace std;
struct P{
	int x,y;
	void init(){
		scanf("%d%d",&x,&y);
	}
	P operator +(const P &a)const{
		return (P){x+a.x,y+a.y};
	}
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	int operator *(const P &a){
		return x*a.y-a.x*y;
	}
	int dis(){
		return x*x+y*y;
	}
}p,q,a[1005],b[1005];
double sqr(double x){
	return x*x;
}
double R;
void work(P o,P l,P r){
	double mn=(l-o).dis();
	double mx=(r-o).dis();
	if (mn>mx) swap(mn,mx);
	if ((l-r).dis()+(o-l).dis()>=(o-r).dis()&&
		(l-r).dis()+(o-r).dis()>=(o-l).dis())
			mn=min(mn,sqr((l-o)*(r-o)/sqrt((l-r).dis())));
	if (mn<=R&&R<=mx){
		puts("YES");
		exit(0);
	}
}
int n,m;
int main(){
	p.init(); 
	scanf("%d",&n);
	for (int i=1;i<=n;i++) a[i].init();
	q.init(); 
	scanf("%d",&m);
	for (int i=1;i<=m;i++) b[i].init();
	P d=q-p; R=d.dis();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			work(d+a[i],b[j],b[j%m+1]);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			work(b[i]-d,a[j],a[j%n+1]);
	puts("NO");
}
/*
1 0
4
0 0
1 0
1 5
0 5
9 0
4
9 0
9 -5
10 -5
10 0

0 0
3
1 0
2 -1
2 1
0 0
3
-1 0
-2 1
-2 -1
*/