#include<bits/stdc++.h>
using namespace std;


int a[101];
double f[101][10001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,x,s=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=n;j>=1;j--)
			for(int k=a[i];k<=10000;k++)
				f[j][k]+=f[j-1][k-a[i]];
	double ans=0;
	double C=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10000;j++)
			ans+=f[i-1][j]/C*min((1+1.0*n/(n-i+1))*x/2,1.0*(s-j)/(n-i+1));
		C=C*(n-i+1)/i;
	}
	cout<<fixed<<setprecision(20)<<ans<<endl;

			
}