#include<bits/stdc++.h>
const int N=1e5+5;
int n,a[N],i,l,r,m;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);std::sort(a+1,a+n+1);
	l=0;r=n;
	for(;l<r;){
		m=l+r+1>>1;
		for(i=1;i<=m;++i)if(a[i]>=a[i+n-m])break;
		if(i<=m)r=m-1;else l=m;
	}
	printf("%d\n",l);
	return 0;
}