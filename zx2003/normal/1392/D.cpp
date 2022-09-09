#include<bits/stdc++.h>
using namespace std;
const int N=2e5+99;
int T,n,i,f[N];
char c[N];
inline int calc(int l,int r){
	for(i=l;i<=r;++i)f[i]=1<<30;f[l-1]=0;
	for(i=l-1;i<=r;++i){
		if(i+2<=r)f[i+2]=min(f[i+2],f[i]+(c[i+1]!='R')+(c[i+2]!='L'));
		if(i+3<=r)f[i+3]=min(f[i+3],f[i]+(c[i+1]!='R')+(c[i+3]!='L'));
		if(i+4<=r)f[i+4]=min(f[i+4],f[i]+(c[i+1]!='R')+(c[i+2]!='R')+(c[i+3]!='L')+(c[i+4]!='L'));
	}
	return f[r];
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%s",&n,c+1);
		for(i=1;i<=3;++i)c[n+i]=c[i];
		printf("%d\n",min(min(calc(1,n),calc(2,n+1)),min(calc(3,n+2),calc(4,n+3))));
	}
}