#include<bits/stdc++.h>
const int N=200005;
int n,m,i,j,x;
char s[N],t[N];
inline void O(){
	puts("NO");exit(0);
}
int main(){
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	for(x=1;x<=n;++x)if(s[x]=='*')break;
	if(x<=n){
		if(n>m+1)O();
		for(i=1;i<x;++i)if(s[i]!=t[i])O();
		for(i=x+1;i<=n;++i)if(s[i]!=t[m-(n-i+1)+1])O();
	}else{
		if(n!=m)O();
		for(i=1;i<=n;++i)if(s[i]!=t[i])O();
	}
	puts("YES");
	return 0;
}