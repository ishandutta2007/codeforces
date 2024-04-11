#include<bits/stdc++.h>
int T,n,i;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		if(n==1){puts("-1");continue;}
		for(i=1;i<=n;++i)putchar(i==1?'5':'7');puts("");
	}
}