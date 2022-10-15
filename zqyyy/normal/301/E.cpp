#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=107,mod=1e9+7;
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int n,m,K,C[N][N],f[2][N][N][N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),K=read();
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			if(C[i][j]>K)C[i][j]=K+1;
		}
	}
	for(int i=1;i<=n/2;i++)f[1][i][i][1]=1;
	int ans=0;
	for(int j=1,o=1;j<m;j++,o^=1){
		for(int i=1;i<=n;i++)
			for(int k=1;k<=K;k++)add(ans,1ll*f[o][i][0][k]*(m-j+1)%mod);
		memset(f[!o],0,sizeof(f[!o]));
		for(int i=1;i<n;i++)
			for(int k=1;k<=n;k++)
				for(int O=1;O<=K;O++)
					if(f[o][i][k][O])
						for(int l=k;l+i<=n;l++)
							add(f[!o][i+l][l-k][min(K+1,O*C[l-1][k-1])],f[o][i][k][O]);
	}
	for(int j=1;j<=n;j++)
		for(int k=1;k<=K;k++)add(ans,f[m&1][j][0][k]);
	return cout<<ans,0;
}