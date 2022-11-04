#include<bits/stdc++.h>
#define ll long long
#define N 150005
using namespace std;
int n;
ll T,suml,sumr;
struct LBC{
	int p,t;
	ll l,r;
}a[N];
bool cmp1(LBC a,LBC b){
	return 1ll*a.p*b.t>1ll*a.t*b.p;
}
bool cmp2(LBC a,LBC b){
	return a.p<b.p;
}
bool check(double x){
	double mx1=0,mx2=0;
	for (int i=1;i<=n;i++){
		int j=i;
		double t=a[i].p*(1.0-1.0*x*a[i].r/T);
		if (mx1>t+1e-12) return 0;
		t=a[i].p*(1.0-1.0*x*a[i].l/T);
		if (mx2<t) mx2=t;
		while (a[j].p==a[j+1].p){
			j++;
			t=a[j].p*(1.0-1.0*x*a[j].r/T);
			if (mx1>t+1e-12) return 0;
			t=a[j].p*(1.0-1.0*x*a[j].l/T);
			if (mx2<t) mx2=t;
		}
		mx1=mx2; i=j;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].p);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].t),T+=a[i].t;
	sort(a+1,a+n+1,cmp1);
	suml=sumr=0;
	for (int i=1;i<=n;i++){
		int j=i; sumr+=a[i].t;
		for (;j<n&&1ll*a[j].t*a[j+1].p==1ll*a[j+1].t*a[j].p;j++) sumr+=a[j+1].t;
		for (int k=i;k<=j;k++)
			a[k].l=suml+a[k].t,a[k].r=sumr;
		suml=sumr; i=j;
	} 
	sort(a+1,a+n+1,cmp2);
	double l=0,r=1;
	for (int i=1;i<=60;i++){
		double mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
 	}
 	printf("%.15lf\n",l);
}