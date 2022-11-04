#include<bits/stdc++.h>
#define ll long long
#define ldb long double
using namespace std;

ll n,xl,xm,xr,yl,ym,yr,X,Y;
int chk(ll x,ll y){
	printf("%lld %lld\n",x,y);
	fflush(stdout); int k; 
	scanf("%d",&k);
	return k;
}
int main(){
	scanf("%lld",&n);
	xl=yl=0; xm=xr=ym=yr=n+1;
	for (;;){
		ldb sa=(ldb)(xm-xl)*(ym-yl);
		ldb sb=(ldb)(xm-xl)*(yr-ym);
		ldb sc=(ldb)(xr-xm)*(ym-yl);
		if (sb<=sa+sc&&sc<=sa+sb)
			X=(xl+xm)/2,Y=(yl+ym)/2;
		else if (sb>sa+sc) X=(xl+xm)/2,Y=ym;
		else X=xm,Y=(yl+ym)/2;
		int g=chk(X,Y);
		if (!g) exit(0);
		if (g==1) xl=max(xl,X+1);
		else if (g==2) yl=max(yl,Y+1);
		else xm=min(xm,X),ym=min(ym,Y);
		if (xm<=xl) xm=xr,yr=ym;
		if (ym<=yl) ym=yr,xr=xm;
	} 
}