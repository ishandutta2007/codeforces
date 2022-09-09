#include<bits/stdc++.h>
const int N=1e5+5;
int d[N],n,x,y,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),++d[x],++d[y];
	for(i=1;i<=n;++i)if(d[i]==2)break;
	puts(i<=n?"NO":"YES");
	return 0;
}