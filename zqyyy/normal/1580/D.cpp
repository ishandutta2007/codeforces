#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=4007;
int n,m,a[N];
int tp,sz[N],stk[N],ls[N],rs[N];
ll f[N][N];
void dfs(int x){
	if(!x)return;
	dfs(ls[x]),dfs(rs[x]),sz[x]=sz[ls[x]]+sz[rs[x]]+1;
	for(int i=0;i<=sz[ls[x]];i++)
		for(int j=0;j<=sz[rs[x]];j++){
			f[x][i+j]=max(f[x][i+j],f[ls[x]][i]+f[rs[x]][j]-2ll*i*j*a[x]);	
			f[x][i+j+1]=max(f[x][i+j+1],f[ls[x]][i]+f[rs[x]][j]+1ll*(m-2*(i+1)*j-2*i-1)*a[x]);	
		}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		while(tp && a[stk[tp]]>a[i])ls[i]=stk[tp--];
		if(tp)rs[stk[tp]]=i;stk[++tp]=i;
	}
	dfs(stk[1]);
	printf("%lld\n",f[stk[1]][m]);
	return 0;
}