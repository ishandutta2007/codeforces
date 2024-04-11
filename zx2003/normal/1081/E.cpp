#include<bits/stdc++.h>
const int N=1e5+5;
int n,a[N],i,j,x[N],y[N],xb,z,lst;
long long b[N];
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;i+=2){
		scanf("%d",a+i);
		xb=0;z=a[i];for(j=1;j*j<z;++j)if(z%j==0 && (z/j-j)%2==0)++xb,x[xb]=(z/j-j)/2,y[xb]=(z/j+j)/2;
		if(j*j==z)x[++xb]=0,y[xb]=j;
		if(!xb)break;
		int mn=1<<30,mnid=0;
		for(j=1;j<=xb;++j)if(lst<x[j] && y[j]<mn)mn=y[j],mnid=j;
		if(!mnid)break;
		b[i-1]=1ll*x[mnid]*x[mnid]-1ll*lst*lst;b[i]=a[i];lst=y[mnid];
	}
	if(i<=n){puts("No");return 0;}
	puts("Yes");
	for(i=1;i<=n;++i)printf("%lld%c",b[i],i==n?'\n':' ');
	return 0;
}