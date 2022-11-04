#include <cstdio>
#include <algorithm>
using namespace std;

#define n	200005
#define I64	long long
#define max(a,b)	((a)>(b)?(a):(b))

I64		L,A[n],B[n];
int		N,D,Q,Ans,S[n],F[n],fa[n],st[n],bel[n];
struct	Lin{int v,c,next;}E[n*2];

void	Link(int u,int v,int c){
		E[++D]=(Lin){v,c,st[u]};	st[u]=D;
		E[++D]=(Lin){u,c,st[v]};	st[v]=D;
}

void	DFS(int u,int f){
		for	(int i=st[u],v;i;i=E[i].next)
		if	((v=E[i].v)^f)	{
			DFS(v,u);	I64 t=A[v]+E[i].c;
			if	(t>A[u])B[u]=A[u],A[u]=t;
				else	if	(t>B[u])	B[u]=t;
		}
}
void	DFS(int u,int f,I64 x){
		A[u]=max(A[u],x);
		for	(int i=st[u],v;i;i=E[i].next)
		if	((v=E[i].v)^f)	{
			I64 t=A[v]+E[i].c;
			if	(t==A[u])	DFS(v,u,max(x,B[u])+E[i].c);
				else	DFS(v,u,max(x,A[u])+E[i].c);
		}
}
void	Pre(int u,int f){
		bel[u]=f;
		for	(int i=st[u],v;i;i=E[i].next)
			if	((v=E[i].v)^f)	Pre(v,u);
}
int		Get(int u)	{return	u==fa[u]?u:fa[u]=Get(fa[u]);}
bool	Cmp(int a,int b)	{return	A[a]>A[b];}

int		main(){
		scanf("%d",&N);
		for	(int i=1,u,v,c;i<N;i++)
			scanf("%d%d%d",&u,&v,&c),Link(u,v,c);
		DFS(1,0);	DFS(1,0,0);
		for	(int i=1;i<=N;i++)	S[i]=i;
		sort(S+1,S+N+1,Cmp);	Pre(S[N],0);

		for	(scanf("%d",&Q);Q--;Ans=0){
			scanf("%I64d",&L);
			for	(int i=1;i<=N;i++)	F[i]=1,fa[i]=i;
			for	(int i=1,ed=1;i<=N;i++){
				int u=S[i];
				for	(int j=st[u],v;j;j=E[j].next)
					if	((v=E[j].v)^bel[u])	F[u]+=F[v],fa[v]=u;
				for	(;ed<=N&&A[S[ed]]-A[u]>L;ed++)	F[Get(S[ed])]--;
				Ans=max(Ans,F[u]);
			}	printf("%d\n",Ans);
		}
}