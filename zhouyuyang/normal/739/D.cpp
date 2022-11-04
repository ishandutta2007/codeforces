#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(j);i<=(k);i++)
using namespace std;
const int N=330,M=100233;
int head[N*2],dis[N*2],q[N*2];
int id[N][N],mx[N],cur[N];
int num[N],ANS[N];
struct lzh{int x,y;}a[N],B[N*2];
struct LZH{int x,y,q;}Ans[N];
struct edge{int to,next,f;}e[M];
int S,T,n,m,maxx,tot,at;
#define gc() getchar()
int read(){
	int x=0;
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc())
		if (ch=='?') return -1;
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
bool cmp(LZH a,LZH b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=cur[x];i&&flow;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			cur[x]=i;
			k=dfs(e[i].to,min(e[i].f,rest));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
bool work(){
	S=n; tot=1;
	int ans=0,sum=0;
	memset(head,0,sizeof(head));
	memset(id,0,sizeof(id));
	memset(mx,-1,sizeof(mx));
	memset(num,0,sizeof(num));
	For(i,1,n)
		if (a[i].y!=-1){
			if (a[i].x==0) num[a[i].y]++;
			if (a[i].y) mx[a[i].y]=max(mx[a[i].y],0);
			mx[a[i].y]=max(mx[a[i].y],a[i].x);
		}
	For(i,1,n) For(j,0,mx[i]){
		id[i][j]=++S;
		B[S].x=j; B[S].y=i;
	}
	S++; T=S+1;
	For(i,1,n)
		if (a[i].x==0&&a[i].y!=-1)
			add(S,i,0);
		else add(S,i,1);
	For(i,1,n)
		if (mx[i]>-1){
			int k=i;
			for (;k<num[i];k+=i);
			add(id[i][0],T,k-num[i]);
			sum+=k-num[i]+mx[i];
			For(j,1,mx[i])
				add(id[i][j],T,1);
		}
	if (sum>n) return 0;
	For(i,1,n)
		if (a[i].x!=-1&&a[i].y!=-1){
			if (!a[i].x) add(i,id[a[i].y][a[i].x],0);
			else add(i,id[a[i].y][a[i].x],1);
		}
		else if (a[i].x==-1&&a[i].y==-1){
			For(j,n+1,S-1) add(i,j,1);
		}
		else if (a[i].x!=-1){
			For(j,1,n)
				if (id[j][a[i].x])
					add(i,id[j][a[i].x],1);	
		}
		else{
			For(j,0,n)
				if (id[a[i].y][j])
					add(i,id[a[i].y][j],1);
		}
	while (bfs()){
		For(i,1,T) cur[i]=head[i];
		ans+=dfs(S,1e9);
	}
	if (ans!=sum) return 0;
	For(i,1,n){
		int k;
		Ans[i].q=i;
		if (!e[i*2].f){
			for (k=head[i];k;k=e[k].next)
				if (e[k].to!=S&&!e[k].f){
					Ans[i].x=B[e[k].to].x;
					Ans[i].y=B[e[k].to].y;
					break;
				}
		}
		else{
			for (k=head[i];k;k=e[k].next)
				if (e[k].to!=S&&B[e[k].to].x){
					Ans[i].x=B[e[k].to].x;
					Ans[i].y=B[e[k].to].y;
					break;
				}
			if (!k){
				if (a[i].x<=0&&a[i].y==-1){
					Ans[i].x=0;
					Ans[i].y=1;
					continue;
				}
				if (a[i].x==-1&&a[i].y!=-1){
					Ans[i].x=1;
					Ans[i].y=a[i].y;
					continue;
				}
				return 0;
			}
		}
	}
	sort(Ans+1,Ans+n+1,cmp);
	For(i,1,n)
		if (Ans[i].x==0){
			For(j,1,Ans[i].y-1)
				ANS[Ans[i+j].q]=Ans[i+j-1].q;
			ANS[Ans[i].q]=Ans[i+Ans[i].y-1].q;
			i+=Ans[i].y-1;
		}
		else{
			int j=i;
			while (Ans[j].x==Ans[j+1].x&&Ans[j].y==Ans[j+1].y) j++;
			For(k,i,j) ANS[Ans[k].q]=Ans[i-1].q;
			i=j;
		}
	For(i,1,n)
		printf("%d ",ANS[i]);
	return 1;
}
int main(){
	n=read(); maxx=0;
	For(i,1,n){
		a[i].x=read(); a[i].y=read();
		if (a[i].x>maxx&&a[i].y==-1)
			maxx=a[i].x,at=i;
	}
	if (work()) return 0;
	if (!at) return puts("-1"),0;
	For(i,1,n){
		a[at].y=i;
		if (work()) return 0;
		a[at].y=-1;
	}
	puts("-1");
}