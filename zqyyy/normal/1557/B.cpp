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
int n,K,a[N],b[N];
inline void work(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	int res=1;
	for(int i=2;i<=n;i++)if(a[i]!=a[i-1]+1)res++;
	puts(res<=K?"Yes":"No");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}