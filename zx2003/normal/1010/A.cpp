#include<cstdio>
const int N=1005;
double l,r,mid,x;
int n,m,i,a[N],b[N],j;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]==1)return puts("-1");
	}
	for(i=1;i<=n;++i){
		scanf("%d",b+i);
		if(b[i]==1)return puts("-1");
	}
	a[n+1]=a[1];b[n+1]=b[1];
	r=1e10;
	for(;r-l>1e-9;){
		mid=(l+r)/2;
		x=m+mid;
		for(i=1;i<=n;++i){
			x*=(a[i]-1)*1.0/a[i];
			x*=(b[i+1]-1)*1.0/b[i+1];
		}
		if(x>=m)r=mid;
			else l=mid;
	}
	printf("%.7f\n",l);
	return 0;
}