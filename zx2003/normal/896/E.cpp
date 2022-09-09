#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<24],*ih=ibuf,obuf[1<<23],*oh=obuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
inline void out(int x){
	if(!x){*oh++='0';return;}
	static int buf[30];int xb=0;
	for(;x;x/=10)buf[++xb]=x%10;
	for(;xb;)*oh++=buf[xb--]|48;
}
const int N=5e5+5;
int n,m,bl,op[N],lb[N],rb[N],xx[N],ans[N],i,j,a[N],l,r;
int g[N],tg,mx,sz[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
inline void uni(int x,int y){g[y]=x;sz[x]+=sz[y];}
int main(){
	fread(ibuf,1,1<<24,stdin);
	read(n);read(m);
	for(i=1;i<=n;++i)read(a[i]);
	for(i=1;i<=m;++i)read(op[i]),read(lb[i]),read(rb[i]),read(xx[i]);
	bl=sqrt(n)*1.5;bl=min(bl,n);
	for(l=1;l<=n;l+=bl){
		r=min(l+bl-1,n);
		mx=0;tg=0;
		for(i=l;i<=r;++i)mx=max(mx,a[i]);
		for(i=1;i<=mx;++i)g[i]=i;memset(sz+1,0,mx<<2);
		for(i=l;i<=r;++i)++sz[a[i]];
		for(i=1;i<=m;++i)if(lb[i]<=l && r<=rb[i]){
			if(xx[i]>mx)continue;
			if(op[i]==1){
				if(xx[i]*2<=mx){
					for(j=1;j<=xx[i];++j)uni(j+xx[i]+tg,j+tg);
					tg+=xx[i];mx-=xx[i];
				}else{
					for(j=mx;j-xx[i]>=1;--j)uni(j-xx[i]+tg,j+tg);
					mx=xx[i];
				}
			}else ans[i]+=sz[xx[i]+tg];
		}else if(lb[i]<=r && rb[i]>=l){
			int be=max(l,lb[i]),en=min(r,rb[i]);
			if(op[i]==1){
				for(j=be;j<=en;++j){
					a[j]=gfa(a[j]);
					a[j]>xx[i]+tg?--sz[a[j]],++sz[a[j]-=xx[i]]:0;
				}
			}else for(j=be;j<=en;++j)ans[i]+=gfa(a[j])==xx[i]+tg;
		}
	}
	for(i=1;i<=m;++i)if(op[i]==2)out(ans[i]),*oh++='\n';
	fwrite(obuf,1,oh-obuf,stdout);
	return 0;
}