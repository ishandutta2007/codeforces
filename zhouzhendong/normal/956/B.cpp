#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,U,a[N];
int main(){
	scanf("%d%d",&n,&U);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	double ans=0;
	for (int i=1;i<=n-1;i++){
		int j=i+1,k=j;
		for (int t=18;t>=0;t--)
			if (k+(1<<t)<=n&&a[k+(1<<t)]-a[i]<=U)
				k+=1<<t;
		ans=max(ans,1.0*(a[k]-a[j])/(a[k]-a[i]));
	}
	if (fabs(ans)<1e-9)
		puts("-1");
	else
		printf("%.10lf\n",ans);
	return 0;
}