#include <bits/stdc++.h>
using namespace std;
#define GG puts("0"),exit(0)
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,a[N],pre[N],suf[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)pre[i]=a[i]>a[i-1]?pre[i-1]+1:1;
	for(int i=n;i;i--)suf[i]=a[i]>a[i+1]?suf[i+1]+1:1;
	int mx=0,tot=0,k1=0,k2=0;
	for(int i=1;i<=n;i++){
		if(pre[i]>mx)mx=pre[i],tot=1,k1=i,k2=0;
		else if(pre[i]==mx)tot++,k2=i;
		if(suf[i]>mx)mx=suf[i],tot=1,k1=i,k2=0;
		else if(suf[i]==mx)tot++,k2=i;
	}
	puts((tot==2 && k1==k2 && (mx&1))?"1":"0");
	return 0;
}