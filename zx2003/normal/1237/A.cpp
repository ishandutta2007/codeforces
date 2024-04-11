#include<bits/stdc++.h>
const int N=15005;
int n,a[N],i,c0,c1;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]&1){
			if(a[i]>0){
				if(++c0&1)a[i]=(a[i]+1)/2;else a[i]=a[i]/2;
			}else{
				if(++c1&1)a[i]=(a[i]-1)/2;else a[i]=a[i]/2;
			}
		}else a[i]/=2;
		printf("%d\n",a[i]);
	}
	return 0;
}