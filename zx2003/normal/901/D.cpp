#include<bits/stdc++.h>
typedef long long ll;
inline int getint(){
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;return x*f;
}
inline void putl(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x){
		static int buf[30],xb;
		for(xb=0;x;x/=10)buf[++xb]=x%10;
		for(;xb;)putchar(buf[xb--]|48);
	}else putchar('0');
}
const int N=100005;
struct edge{
	int to,next;
}e[N<<1];
ll ans[N],c[N],cc[N],v;
int n,m,x,y,h[N],xb,i,dep[N],be,en,dad[N],ef[N],id;
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=fa){
			if(!dep[e[i].to]){
				dfs(e[i].to,x);
				c[x]-=ans[i>>1]=c[e[i].to];
			}else if(!((dep[e[i].to]^dep[x])&1))be=x;
		}
}
void dfs2(int x,int fa){
	dep[x]=dep[dad[x]=fa]+1;for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=fa){
			if(!dep[e[i].to]){
				dfs2(e[i].to,x);
				c[x]-=ans[ef[e[i].to]=i>>1]=c[e[i].to];
			}else if(!((dep[e[i].to]^dep[x])&1) && e[i].to==be)en=x,id=i>>1;
		}
}
int main(){
	n=getint(),m=getint();xb=1;
	for(i=1;i<=n;++i)cc[i]=c[i]=getint();
	for(i=1;i<=m;++i){
		x=getint(),y=getint();
		e[++xb]=(edge){y,h[x]};h[x]=xb;
		e[++xb]=(edge){x,h[y]};h[y]=xb;
	}
	dfs(1,0);
	if(!c[1]){
		puts("YES");
		for(i=1;i<=m;++i)putl(ans[i]),putchar('\n');
		return 0;
	}
	if(be){
		puts("YES");
		memset(dep+1,0,n<<2);
		memset(ans+1,0,m<<3);
		memcpy(c+1,cc+1,n<<3);
		dfs2(be,0);
		for(ans[id]+=v=c[be]>>1,i=en,y=-1;i!=be;i=dad[i],v=-v)
			ans[ef[i]]-=v;
		for(i=1;i<=m;++i)putl(ans[i]),putchar('\n');
	}else puts("NO");
	return 0;
}