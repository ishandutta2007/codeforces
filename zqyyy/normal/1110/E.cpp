#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+5;
int n,a[N],b[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	if(a[1]^b[1])puts("No"),exit(0);
	for(int i=n;i>1;i--)a[i]=a[i]-a[i-1],b[i]=b[i]-b[i-1];
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)if(a[i]^b[i])puts("No"),exit(0);
	return puts("Yes"),0;
}