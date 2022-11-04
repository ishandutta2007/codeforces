#include<bits/stdc++.h>
using namespace std;
double a[105],f[105];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lf",&a[i]),a[i]*=0.01;
	double ans=1.0,Ans;
	for (int i=1;i<=n;i++)
		ans=ans*a[i],f[i]=a[i];
	Ans=ans*n;
	for (int T=n+1;T<=300000;T++){
		double t=-1.0; int id;
		for (int i=1;i<=n;i++){
			double tt=(f[i]+(1.0-f[i])*a[i])/f[i];
			if (tt>t) t=tt,id=i;
		}
		f[id]+=(1-f[id])*a[id];
		Ans+=(t*ans-ans)*T;
		ans*=t;
	}
	printf("%.20lf\n",Ans);
}