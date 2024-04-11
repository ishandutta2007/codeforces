#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,S=1<<21;
struct atom{
	int x,y;
	inline void ins(int z){
		if(z>x)y=x,x=z;else y=max(y,z);
	}
	inline void ins(const atom&z){
		if(z.x>x)y=max(x,z.y),x=z.x;else{
			if(z.x<x)y=max(y,z.x);else y=max(y,z.y);
		}
	}
}f[S|5];
int n,a[N],i,j,k,m,tmm[S|5],ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),f[a[i]].ins(i);
	for(i=2;i<=S;i<<=1)for(j=0,m=i>>1;j<S;j+=i)
		for(k=0;k<m;++k)f[j+k].ins(f[j+k+m]);
	for(i=0;i<S;++i)tmm[i]=f[i].y;
	for(i=1;i<n-1;++i){
		int v=0;
		for(j=20;j>=0;--j)if(!(a[i]>>j&1) && tmm[v|(1<<j)]>i)v|=1<<j;
		ans=max(ans,v|a[i]);
	}
	printf("%d\n",ans);
	return 0;
}