#include<map>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n;
double ans=1e12,a[1005],b[1005];
double dis(int x,int y){
	return sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i],&b[i]);
	a[n+1]=a[1]; b[n+1]=b[1];
	a[n+2]=a[2]; b[n+2]=b[2];
	for (int i=1;i<=n;i++){
		double v,w,x,y,S;
		v=a[i]-a[i+1]; w=b[i]-b[i+1];
		x=a[i]-a[i+2]; y=b[i]-b[i+2];
		S=fabs(v*y-x*w);
		ans=min(ans,S/dis(i,i+2)); 
	}
	printf("%.10lf",ans/2);
}