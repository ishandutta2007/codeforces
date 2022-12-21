#include <bits/stdc++.h>
#define ll long long 
#define il inline 
#define re register int 
using namespace std;
int T,n,m,a,b;
il int read(){
	char c=getchar();int z=0,f=1;
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') z=z*10+c-'0',c=getchar();
	return z*f;
}
const int N=2e5+5;
int ans,s[N],runtim,pushtim; 
il void work(){
	n=read();m=read();a=read();b=read();
	for(re i=1;i<=m;i++) s[i]=read();
	sort(s+1,s+1+m);
	if(a<b) runtim=a-1;
	else runtim=n-a;
	pushtim=max(b-a,a-b);
	ans=0;
	for(re i=1,nowtim=0;i<pushtim&&i<=m&&nowtim<=runtim+pushtim-1;)
		if(nowtim>=s[i]) nowtim++,i++,ans++;
		else nowtim=s[i];
	cout<<ans<<'\n';
}
int main (){
	T=read();
	while(T--) work();
	return 0;
}
/*
3
7 3 3 6
1 4 4 
7 2 3 6
5 1
7 2 3 6
4 4

*/