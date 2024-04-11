#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
int n,x,a[N],b[N];
inline void work(){
	n=read(),x=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	sort(b+1,b+n+1);int res=1e9;
	for(int i=1;i<=n;i++)if(a[i]!=b[i])res=min(res,max(i-1,n-i));
	puts(res>=x?"YES":"NO");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}