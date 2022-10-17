#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=2e5+5;
int n,m,pre[N],suf[N];
char s[N],t[N];
int main(){
	n=read(),m=read();
	scanf("%s%s",s+1,t+1);
	int pos=1;
	for(int i=1;i<=n && pos<=m;i++)
		if(s[i]==t[pos])pre[pos++]=i;
	pos=m;
	for(int i=n;i && pos;i--)
		if(s[i]==t[pos])suf[pos--]=i;
	int ans=1;
	for(int i=1;i<m;i++)ans=max(ans,suf[i+1]-pre[i]);
	return cout<<ans,0;
}