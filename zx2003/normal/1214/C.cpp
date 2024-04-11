#include<bits/stdc++.h>
const int N=2e5+5;
char c[N];
int n,i,s[N],mn;
int main(){
	scanf("%d%s",&n,c+1);
	for(i=1;i<=n;++i)s[i]=s[i-1]+(c[i]=='('?1:-1),mn=std::min(mn,s[i]);
	puts(mn>=-1 && s[n]==0?"Yes":"No");
	return 0;
}