#include<bits/stdc++.h>
using namespace std;
int n,v,p[1000005];
double ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=1000000;i++)
		p[i]=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&v);
		if (p[v]==0) ans++;
		ans-=1.0*(i-p[v]-1)*(i-p[v]-1)/n/n;
		p[v]=i;
	}
	for (int i=1;i<=1000000;i++)
		if (p[i]&&p[i]!=n)
			ans-=1.0*(n-p[i])*(n-p[i])/n/n;
	printf("%.15lf\n",ans);
}