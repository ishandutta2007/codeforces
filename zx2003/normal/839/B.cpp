#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10005;
int n,k,a[N],i,x,y,u,v,w,s1,s2,s3;
int main(){
	scanf("%d%d",&k,&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	x=k;
	y=k<<1;
	for(i=1;i<=n;++i){
		u=min(a[i]>>2,x);
		x-=u;
		a[i]-=u<<2;
	}
	if(x)for(i=1;i<=n && x;++i)if(a[i]&1)--a[i],--x,++y;
	for(i=1;i<=n;++i){
		u=min(a[i]>>1,y);
		y-=u;
		a[i]-=u<<1;
	}
	for(i=1;i<=n;++i)
		if(a[i]==2 && x){
			--x;
			++y;
			a[i]=0;
		}
	w=x*2+y;
	for(i=1;i<=n;++i){
		w-=a[i];
		if(w<0)break;
	}
	puts(i>n?"YES":"NO");
	return 0;
}