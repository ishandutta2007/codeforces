#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,x,y,vx,vy;
int refx,refy;
LL exgcd(LL a,LL b,LL &x,LL &y){
	if (!b){
		x=1,y=0;
		return a;
	}
	LL res=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return res;
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&vx,&vy);
	if (vx==0){
		if (x==0||x==n){
			if (vy==1)
				printf("%d %d\n",x,m);
			else
				printf("%d %d\n",x,0);
		}
		else
			puts("-1");
		return 0;
	}
	if (vy==0){
		if (y==0||y==m){
			if (vx==1)
				printf("%d %d\n",n,y);
			else
				printf("%d %d\n",0,y);
		}
		else
			puts("-1");
		return 0;
	}
	if (vx==-1)
		refx=1,x=n-x;
	if (vy==-1)
		refy=1,y=m-y;
	//s'=(0,y-x)
	//an+(y-x)=bm => an+bm=(x-y)
	LL a,b,g;
	g=exgcd(n,m,a,b);
	if ((x-y)%g!=0){
		puts("-1");
		return 0;
	}
	LL t=(x-y)/g;
	a*=t,b*=t;
	int _m=m/g,_n=n/g;
	LL _a=(a%_m+_m+_m-1)%_m+1,_b=-((x-y)-_a*n)/m;
/*	if (_b<0){
		puts("-1");
		return 0;
	}*/
	LL ansx=n,ansy=m;
	if (_a%2==0)
		ansx=n-ansx;
	if (_b%2==0)
		ansy=m-ansy;
	if (refx)
		ansx=n-ansx;
	if (refy)
		ansy=m-ansy;
	printf("%I64d %I64d",ansx,ansy);
	return 0;
}