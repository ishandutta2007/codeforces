#include <cstdio>
const int S1=10001,T1=10002,S2=10003,T2=10004,inf=1e9,N=3e5+10;
int n,m,dnt,sum,a[N],u[N],v[N],s[N],h[N],sup[N],deg[N],cur[N],head[N],to[N],val[N],next[N];
template<typename T>T rv(T x){return x>T()?x:(-x);}
template<typename T>T min(T x,T y){return x<y?x:y;}
struct queue{
	int p,q,a[N];queue(){};
	void clr(){p=q=0;}
	int size(){return q-p;}
	void push(int x){a[++q]=x;}
	int front(){return a[++p];}
}q;
void ad(int u,int v,int w){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v,val[dnt]=w;}
void af(int u,int v,int w){ad(u,v,w),ad(v,u,0);}
void upd(int u){for(int i=head[u];i;i=next[i])if(val[i]&&h[to[i]]==-1)h[to[i]]=h[u]+1,q.push(to[i]);}
bool bfs(){
	for(int i=1;i<=T2;++i)cur[i]=head[i],h[i]=-1;
	q.clr(),q.push(S1),h[S1]=0;while(q.size())upd(q.front());
	return ~h[T1];
}
int dinic(int u,int flow){
	if(u==T1)return flow;
	int nflow=0;
	for(int &i=cur[u];i;i=next[i]){
		if(val[i]&&h[to[i]]==h[u]+1){
			int tflow=dinic(to[i],min(flow,val[i]));
			flow-=tflow,nflow+=tflow,val[i]-=tflow,val[i^1]+=tflow;
		}
		if(!flow)break;
	}
	return nflow;
}
int work(){
	int res=0;
	while(bfs())res+=dinic(S1,inf);
	return res;
}
int main(){
	dnt=1,scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&s[i]);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i){
		scanf("%d %d",&u[i],&v[i]);
		--deg[u[i]],++deg[v[i]],af(v[i],u[i],2),sup[i]=dnt;
	}
	for(int i=1;i<=n;++i){
		if(!s[i]){af(S2,i,inf),af(i,T2,inf);continue;}
		if((a[i]-deg[i])&1){puts("No");return 0;}
		if(a[i]>deg[i])af(i,T1,a[i]-deg[i]),af(S1,T2,a[i]-deg[i]);
		if(a[i]<deg[i])af(S1,i,deg[i]-a[i]),af(S2,T1,deg[i]-a[i]);
		sum+=rv(a[i]-deg[i]);
	}
	af(S2,T2,inf),af(T2,S2,inf);
	if(sum!=work()){puts("No");return 0;}
	puts("Yes");
	for(int i=1;i<=m;++i){
		if(val[sup[i]])printf("%d %d\n",v[i],u[i]);
		else printf("%d %d\n",u[i],v[i]);
	}
	return 0;
}