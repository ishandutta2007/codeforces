#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],my;
double f[100005],s[100005];
int main(){
	scanf("%d%d",&n,&m);
	f[0]=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		my+=a[i];
		s[0]=f[0];
		for (int j=1;j<=i*m;j++)
			s[j]=s[j-1]+f[j];
		for (int j=i*m;j>=0;j--){
			f[j]=(j?s[j-1]:0);
			f[j]-=(j>m?s[j-m-1]:0);
			f[j]-=(j>=a[i]?f[j-a[i]]:0);
			f[j]/=m-1;
		}
	}
	double ans=0;
	for (int i=n;i<my;i++)
		ans+=f[i];
	printf("%.10lf\n",ans*(m-1)+1);
}