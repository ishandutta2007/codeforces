#include<cstdio>
#include<cstring>
const int N=155;
int g[N][N],i,j,k,a[N],n,f[N][N][N],l,ans[N];
char s[N];
inline void up(int&a,int b){
	if(a<b)a=b;
}
inline int max(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&n);
	memset(f,-0x3f,sizeof(f));
  	memset(g,-0x3f,sizeof(g));
  	for(i=1;i<=n+1;i++)g[i][i-1]=0;
	for(i=1;i<=n;++i)scanf("%d",a+i),a[i]=(a[i]==-1?(-1<<30):a[i]),up(g[i][i],a[1]),f[i][i][1]=0;
	scanf("%s",s+1);
	for(i=1;i<n;++i)
		for(j=1;j<=n-i;++j){
			f[j][j+i][1]=max(g[j+1][j+i],g[j][j+i-1]);
			if(s[j]==s[j+i])f[j][j+i][2]=g[j+1][j+i-1];
			for(k=1;k<=i+1;++k){				
				if(s[j]==s[j+i] && k>2)up(f[j][j+i][k],f[j+1][j+i-1][k-2]);
				for(l=j;l<j+i;++l){
					up(f[j][j+i][k],g[j][l]+f[l+1][j+i][k]);
					up(f[j][j+i][k],f[j][l][k]+g[l+1][j+i]);
				}
				up(g[j][j+i],f[j][j+i][k]+a[k]);
			}
		}
	for(i=1;i<=n;++i){
		ans[i]=ans[i-1];
		for(j=0;j<i;++j)up(ans[i],ans[j]+g[j+1][i]);
	}
	printf("%d\n",ans[n]);
}