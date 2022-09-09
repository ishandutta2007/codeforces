#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int T,n,k,i,j;
char a[N],b[N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%s",&n,&k,a+1);
		for(i=1;i<k;++i)b[i*2-1]='(',b[i*2]=')';
		for(i=1;i<=n/2-k+1;++i)b[2*(k-1)+i]='(',b[n-i+1]=')';
		printf("%d\n",n);
		for(i=n;i;--i){
			for(j=i;a[j]!=b[i];--j);
			printf("%d %d\n",j,i);reverse(a+j,a+i+1);
		}
	}
	return 0;
}