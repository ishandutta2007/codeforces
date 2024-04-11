#include<stdio.h>
int d[1000002],h[1000002][2],n,v=0,s;
int main(){
	scanf("%d",&n);s=n-1;
	for(int i=1;i<n;i++){
		scanf("%d%d",&h[i][0],&h[i][1]);
		d[h[i][0]]++;d[h[i][1]]++;
	}for(int i=1;i<n;i++){
		if(d[h[i][0]]==1||d[h[i][1]]==1)printf("%d\n",v++);
		else printf("%d\n",--s);
	}
}