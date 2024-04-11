#include<bits/stdc++.h>
char c[1000];
int n,i,j,ans;
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j){
			int k=i;
			for(;k<=j;++k)if(c[k]!=c[j-(k-i)])break;
			if(k<=j && j-i+1>ans)ans=j-i+1;
		}
	printf("%d\n",ans);
	return 0;
}