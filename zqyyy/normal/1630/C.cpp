#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
struct seg{
	int l,r;	
}b[N];
int n,m,R[N],a[N],f[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),R[a[i]]=i,f[i]=i;
	for(int i=1,j=0;i<=n;i++){
		f[i]=min(f[i],f[i-1]+1);
		j=max(j,R[a[i]]);
		f[j]=min(f[j],f[i]+1);
	}
	printf("%d\n",n-f[n]);
	return 0;
}