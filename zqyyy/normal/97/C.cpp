#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=107;
int n,a[N];
double p[N];
int main(){
	n=read();
	for(int i=0;i<=n;i++)scanf("%lf",p+i),a[i]=abs(2*i-n);
	double ans=0;
	for(int i=0;i<=n>>1;i++)
		for(int j=n+1>>1;j<=n;j++)
			if(a[i]||a[j])ans=max(ans,(p[i]*a[j]+p[j]*a[i])/(a[i]+a[j]));
	return printf("%.10lf\n",ans),0;
}