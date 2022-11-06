#include<stdio.h>
int a[100002],n,cnt,cntt,maxx=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>=0)a[i]=-1-a[i];
		if(-a[i]>maxx)maxx=-a[i];
	}
	if(n&1){
		for(int i=1;i<=n;i++){
			if(maxx==-a[i]){
				a[i]=-a[i]-1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
}