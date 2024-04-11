#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m;
struct Rec{
	int u,v,d;
}rec[100010];
bool operator<(Rec x,Rec y){return x.d<y.d;}
struct Edge{
	int to,nxt,v;
}edge[240010];
int cnt,last[20010],S,T,_last[20010];
inline void addedge(int x,int y,int v){
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],0},last[y]=cnt;
}
int que[20010],hd,tl;
int dep[20010];
bool bfs(){
	for (int i=1;i<=T;i++) dep[i]=-1;
	hd=tl=0;
	que[++tl]=S; dep[S]=1;
	while (hd<tl){
		int u=que[++hd],v;
		for (int i=last[u];i;i=edge[i].nxt)
			if (edge[i].v&&!~dep[v=edge[i].to]){
				dep[v]=dep[u]+1;
				if (v==T) return 1;
				que[++tl]=v;
			}
	}
	return 0;
}
int dfs(int x,int flw){
	if (x==T) return flw;
	int t,used=0;
	for (int &i=_last[x],v;i;i=edge[i].nxt)
		if (edge[i].v&&dep[x]+1==dep[v=edge[i].to]){
			t=dfs(v,min(edge[i].v,flw-used));
			edge[i].v-=t; edge[i^1].v+=t;
			used+=t; if (used==flw) return used;
		}
	if (!used) dep[x]=-1;
	return used;
}
int dinic(){
	int res=0;
	while (bfs()){
		for (int i=1;i<=T;i++) _last[i]=last[i];
		res+=dfs(S,1e9);
	}
	return res;
}
bool check(int x){
	S=n<<1|1,T=S+1;
	cnt=1; for (int i=1;i<=T;i++) last[i]=0;
	for (int i=1;i<=n;i++) addedge(S,i,1),addedge(i+n,T,1);
	for (int i=1;i<=x;i++) addedge(rec[i].u,n+rec[i].v,1);
	return dinic()==n;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		rec[i].u=read(),rec[i].v=read(),rec[i].d=read();
	}
	sort(rec+1,rec+m+1);
	int l=1,r=m,mid;
	if (!check(r)) return puts("-1"),0;
	while (l<r){
		mid=l+r>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",rec[l].d);
	return 0;
}