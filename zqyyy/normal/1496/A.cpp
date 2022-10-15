#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
int n,K;
char s[111];
inline void work(){
	n=read(),K=read();
	scanf("%s",s+1);
	if(!K)return puts("YES"),void();
	for(int i=1;i<=K;i++)if(s[i]!=s[n-i+1])return puts("NO"),void();
	if(K*2==n)return puts("NO"),void();
	puts("YES");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}