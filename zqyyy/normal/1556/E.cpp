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
int n,Q,a[N],lg[N];
ll s[N],f[2][N][17];
inline ll query(int o,int l,int r){
	int k=lg[r-l+1];
	if(o)return max(f[o][l][k],f[o][r-(1<<k)+1][k]);
	else return min(f[o][l][k],f[o][r-(1<<k)+1][k]);
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;i++)a[i]=-read();
	for(int i=1;i<=n;i++)a[i]+=read(),s[i]=s[i-1]+a[i];
	lg[0]=-1;
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1,f[0][i][0]=f[1][i][0]=s[i];
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[0][i][j]=min(f[0][i][j-1],f[0][i+(1<<j-1)][j-1]);
			f[1][i][j]=max(f[1][i][j-1],f[1][i+(1<<j-1)][j-1]);
		}
	while(Q--){
		int l=read(),r=read();
		if(s[r]!=s[l-1] || query(0,l,r)<s[r])puts("-1");
		else printf("%lld\n",query(1,l,r)-s[r]);
	}
	return 0;
}