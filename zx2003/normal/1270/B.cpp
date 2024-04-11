#include<bits/stdc++.h>
const int N=2e5+5;
int T,n,a[N],i,l,r;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		int mx1=-(1<<30),mx2=mx1,id1,id2;
		l=r=0;
		for(i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]-i+mx1>=0)l=id1,r=i;
			if(-a[i]-i+mx2>=0)l=id2,r=i;
			if(-a[i]+i-1>mx1)mx1=-a[i]+i-1,id1=i;
			if(a[i]+i-1>mx2)mx2=a[i]+i-1,id2=i;
		}
		if(!l)puts("NO");else printf("YES\n%d %d\n",l,r);
	}
	return 0;
}