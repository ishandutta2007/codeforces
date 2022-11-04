#include<bits/stdc++.h>
using namespace std;
const int N=100005;
double ans,pos[N];
int n,x[N],y[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	pos[0]=1;
	for (int i=1;i<N;i++)
		pos[i]=pos[i-1]*0.5;
	for (int i=1;i<=n;i++){
		int j=i%n+1,t=100,k=2;
		for (;j!=i&&t;t--,j=j%n+1,k++)
			ans+=(pos[k]-pos[n])*(1.0*x[i]*y[j]-1.0*x[j]*y[i]-gcd(abs(x[i]-x[j]),abs(y[i]-y[j])));
	}
	ans=ans*0.5/(1-pos[n]*(1+n+1.0*n*(n-1)/2));
	printf("%.10lf\n",ans+1);
}