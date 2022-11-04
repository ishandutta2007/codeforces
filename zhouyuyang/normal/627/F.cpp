#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int WZP=6666666;
char LZH[WZP],*SSS=LZH,*TTT=LZH;
inline char gc(){
	if (SSS==TTT){
		TTT=(SSS=LZH)+fread(LZH,1,WZP,stdin);
		if (SSS==TTT) return EOF;
	}
	return *SSS++;
}
inline int read01(){
	char s=gc();
	for (;s<'0'||s>'1';s=gc());
	return s-'0';
}
inline int read(){
	char s=gc(); int x=0;
	for (;s<'0'||s>'9';s=gc());
	for (;s>='0'&&s<='9';s=gc())
		x=x*10-48+s;
	return x;
}
const int N=200005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
int dep[N],dfn[N],ed[N];
int fa[N][19],a[N],b[N];
int n,spe1,spe2,A[N],B[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	dfn[x]=++*dfn;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dfs(e[i].to);
		}
	ed[x]=*dfn;
}
bool insub(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,18) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,18,0) if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
pii merge(const pii &a,int x){
	if (a.fi==-1) return pii(-1,-1);
	if (a.fi==0) return pii(x,x);
	static int c[5],L;
	c[0]=a.fi; c[1]=a.se; c[2]=x;
	L=LCA(c[0],c[1]);
	if (insub(L,c[2])&&(insub(c[2],c[0])||insub(c[2],c[1]))) return pii(c[0],c[1]);
	L=LCA(c[0],c[2]);
	if (insub(L,c[1])&&(insub(c[1],c[0])||insub(c[1],c[2]))) return pii(c[0],c[2]);
	L=LCA(c[1],c[2]);
	if (insub(L,c[0])&&(insub(c[0],c[1])||insub(c[0],c[2]))) return pii(c[1],c[2]);
	return pii(-1,-1);
}
ll solve(int x,int y,int L,int *a){
	int l=1,r=dep[x]+dep[y]-2*dep[L],len=r,at=1;
	for (;x!=L;x=fa[x][0],l++) A[l]=a[x],B[l]=b[x];
	for (;y!=L;y=fa[y][0],r--) A[r]=a[y],B[r]=b[y];
	For(i,1,len) if (A[i])
	for (;A[1]!=B[at];at++);
	for (int i=1;i<=len;i++)
		if (A[i]!=B[(i+at-2)%len+1])
			return 1ll<<60;
	return 1ll*min(at-1,len+1-at)*(len+1);
}
int cnt,aa[N];
bool dfs(int x,int fa,int spe){
	if (x==spe) return 1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			if (dfs(e[i].to,x,spe)){
				cnt++;
				swap(aa[x],aa[e[i].to]);
				return 1;
			}
	return 0;
}
void flip(int p1,int p2){
	dfs(p2,0,p1);
}
bool checkSAME(int *a,int *b){
	For(i,1,n) if (a[i]!=b[i]) return 0;
	return 1;
}
int tp;
int main(){
	n=read();
	For(i,1,n) a[i]=read(),spe1=(a[i]==0?i:spe1);
	For(i,1,n) b[i]=read(),spe2=(b[i]==0?i:spe2);
	For(i,1,n-1){
		int x=read(),y=read();
		add(x,y); add(y,x);
	}
	
	memcpy(aa,a,sizeof(aa));
	dfs(spe2);
	flip(spe1,spe2);
	if (checkSAME(aa,b))
		return printf("0 %d\n",cnt),0;
	For(i,1,18)	For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	pii tmp(0,0);
	For(i,1,n) if (aa[i]!=b[i])
		tmp=merge(tmp,i);
	
	if (tmp.fi==-1) return puts("-1"),0;
	if (dep[tmp.fi]>dep[tmp.se]) swap(tmp.fi,tmp.se);
	if (insub(tmp.fi,tmp.se)) tmp.fi=fa[tmp.fi][0];
	
	ll ans=1ll<<60;
	int L1=LCA(tmp.fi,tmp.se);
	
	cnt=0;
	memcpy(aa,a,sizeof(aa));
	flip(spe1,tmp.fi);
	swap(aa[tmp.fi],aa[tmp.se]); cnt++;
	flip(tmp.se,spe2);
	ans=min(ans,cnt+solve(tmp.fi,tmp.se,L1,aa));
	
	cnt=0;
	memcpy(aa,a,sizeof(aa));
	flip(spe1,tmp.se);
	swap(aa[tmp.se],aa[tmp.fi]); cnt++;
	flip(tmp.fi,spe2);
	ans=min(ans,cnt+solve(tmp.fi,tmp.se,L1,aa));
	
	if (ans>=1ll<<50)
		return puts("-1"),0;
	if (tmp.fi>tmp.se) swap(tmp.fi,tmp.se);
	printf("%d %d ",tmp.fi,tmp.se);
	printf("%lld\n",ans);
}