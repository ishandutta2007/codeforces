#include<bits/stdc++.h>
using namespace std;
const int U=1e9+5,N=14e4;
struct rect{int x1,y1,x2,y2;}a[N],pr[N],sf[N];
rect uni(rect a,rect b){
	return (rect){max(a.x1,b.x1),max(a.y1,b.y1),min(a.x2,b.x2),min(a.y2,b.y2)};
}
bool nE(rect a){return a.x1<=a.x2 && a.y1<=a.y2;}
void in(rect&a){scanf("%d%d%d%d",&a.x1,&a.y1,&a.x2,&a.y2);}
int n,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)in(a[i]);
	pr[0]=sf[n+1]=(rect){-U,-U,U,U};
	for(i=1;i<=n;++i)pr[i]=uni(pr[i-1],a[i]);for(i=n;i;--i)sf[i]=uni(sf[i+1],a[i]);
	for(i=1;i<=n;++i){
		rect z=uni(pr[i-1],sf[i+1]);
		if(nE(z)){printf("%d %d\n",z.x1,z.y1);return 0;}
	}
	return 0;
}