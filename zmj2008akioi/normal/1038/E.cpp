#include <cstdio>
#include <cstring>
const int D=4,N=210;
int n,nw,ans,cnt,u[N],v[N],w[N],f[N],dig[N];
bool vis[N];
namespace basic{
	int lt,nw,res,dig[30];
	char cdc;
	inline void cmax(int &x,int y){if(x<y)x=y;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(int x){
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
	}
}using basic::cmax;using basic::read;using basic::write;
int find(int u){
	if(f[u]!=u)f[u]=find(f[u]);
	return f[u];
}
int main(){
	n=read();
	for(int i=1;i<=D;++i)f[i]=i;
	for(int fu,fv,i=1;i<=n;++i){
		u[i]=read(),w[i]=read(),v[i]=read();
		++dig[u[i]],++dig[v[i]],fu=find(u[i]),fv=find(v[i]);
		if(fu!=fv)f[fu]=fv,++cnt;
	}
	if(cnt==3){
		if((dig[1]&1)&&(dig[2]&1)&&(dig[3]&1)&&(dig[4]&1)){
			for(int i=1;i<=n;++i){
				if(u[i]==v[i])continue;
				for(int j=1;j<=D;++j)f[j]=j;
				for(int j=1;j<=n;++j)if(i!=j)f[find(u[j])]=find(v[j]);
				for(int j=1;j<=D;++j){
					nw=0;
					for(int k=1;k<=D;++k)vis[k]=find(j)==find(k);
					for(int k=1;k<=n;++k)if(vis[u[k]]&&vis[v[k]]&&k!=i)nw+=w[k];
					cmax(ans,nw);
				}
			}
		}
		else for(int i=1;i<=n;++i)ans+=w[i];
	}
	else{
		for(int i=1;i<=D;++i){
			nw=0;
			for(int j=1;j<=D;++j)vis[j]=find(i)==find(j);
			for(int j=1;j<=n;++j)if(vis[u[j]]&&vis[v[j]])nw+=w[j];
			cmax(ans,nw);
		}
	}
	write(ans);
	return 0;
}