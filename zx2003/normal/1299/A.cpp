#include<bits/stdc++.h>
int c[35],n,a[100005],i,j,ans,id;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		for(j=0;j<30;++j)c[j]+=a[i]>>j&1;
	}
	for(i=1;i<=n;++i){
		int x=0;
		for(j=0;j<30;++j)if((a[i]>>j&1) && c[j]==1)x|=1<<j;
		if(x>=ans)ans=x,id=i;
	}
	printf("%d ",a[id]);for(i=1;i<=n;++i)if(i!=id)printf("%d ",a[i]);puts("");
	return 0;
}