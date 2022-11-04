#include<bits/stdc++.h>
using namespace std;
double a[1005][55];
double b[1005][55];
double f[1005][55];
double p;
int n;
double solve(int n){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++){
		a[i][1]=p; a[i][2]=1-p; b[i][2]=1;
		for (int j=1;j<=51;j++){
			a[i][j]+=a[i][j-1]*a[i-1][j-1];
			b[i][j]+=b[i][j-1]*a[i-1][j-1];
		}
	}
	f[1][1]=p*(1-p);
	for (int i=2;i<=50;i++)
		f[1][i]=a[n][i]-a[n][i+1];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=50;j++)
			if (j==1){
				for (int k=2;k<=50;k++)
					f[i][k]+=f[i-1][j]*(b[n-i+1][k]-b[n-i+1][k+1]);
			}
			else if (j==2)
				f[i][1]+=f[i-1][2];
			else if (i==n){
				for (int k=1;k<j;k++)
					f[i][k]+=f[i-1][j]*a[1][k];
			}
			else
				for (int k=1;k<j;k++){
					double k1=a[n-i+1][k]-a[n-i+1][k+1];
					if (k==1) k1=p*(1-p);
					f[i][k]+=f[i-1][j]*k1/(1-a[n-i+1][j]);
				}
	double ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=50;j++)
			ans+=f[i][j]*j;
	return ans;
}
int main(){
	scanf("%d%lf",&n,&p);
	p/=1e9;
	if (n==1){
		printf("%.15lf\n",p+2*(1-p));
		return 0;
	}
	if (n<=1000){
		printf("%.15lf\n",solve(n));
		return 0;
	}
	double k1=solve(1000);
	double k2=solve(999);
	printf("%.15lf\n",k1+(k1-k2)*(n-1000));
}