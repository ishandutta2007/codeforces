#include<stdio.h>
#define N 2005
using namespace std;
double ans,d[N],sum[N];
int n,m,i,j,x;
inline double work(int x,int y) {
	double s=1;
	for (int i=y;i<=x;i++) s*=i;
	return s;
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++)
	for (j=i+1;j<=n;j++) {
		scanf("%d",&x);
		if (x>=0) d[i]++,sum[i]+=x,d[j]++,sum[j]+=x;
	}
	if (m<=5) {
		for (i=1;i<=n;i++) if (d[i]>=m) ans=ans+m*work(d[i]-1,d[i]-m+1)*sum[i];
		ans/=(work(n,n-m+1)); printf("%I64d\n",(long long) ans);
	}
	else {
		for (i=1;i<=n;i++) if (d[i]>=m) ans=ans+work(d[i]-1,m)/work(d[i]-m,1)*sum[i];
		ans/=(work(n,m+1)/work(n-m,1));
		printf("%I64d\n",(long long) ans);
	}
}