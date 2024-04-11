#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=3005,M=305;
int n,m,cnt[N];
double f[M][N],g[N],d[N],sv[N],siv[N],val[N];
double ans,p[N][M];
inline void upd(int x){
	memcpy(g,f[x],sizeof(g));
	f[x][0]=0;
	for(int i=1;i<=n;i++)
		f[x][i]=f[x][i-1]*(1-p[i][x])+g[i-1]*p[i][x];
	cnt[x]++,sv[x]+=f[x][n];
	siv[x]+=f[x][n]*cnt[x];
	double E=siv[x]+cnt[x]*(1-sv[x]);
	d[x]=E-val[x],val[x]=E;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			p[i][j]=read()/1000.;
	for(int i=1;i<=m;i++){
		f[i][0]=1;
		for(int j=1;j<=n;j++)
			f[i][j]=f[i][j-1]*(1-p[j][i]);
		sv[i]=f[i][n],upd(i); 
	}
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=m;j++)
			if(d[k]<d[j])k=j;
		if(!k)break;
		ans+=d[k],upd(k);
	} 
	return printf("%.12lf\n",ans),0;
}