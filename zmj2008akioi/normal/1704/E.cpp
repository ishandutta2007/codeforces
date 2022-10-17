#include <cstdio>
#include <cstring>
const int P=998244353,N=1e3+10;
int T,n,m,ans,dnt,a[N],b[N],deg[N],head[N],to[N],next[N];
void addedge(int u,int v){++deg[v],next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
bool chk(){for(int i=1;i<=n;++i)if(a[i])return false;return true;}
struct queue{
	int p,q,a[N];
	queue(){};
	void clear(){p=q=0;}
	int size(){return q-p;}
	void push(int x){a[++q]=x;}
	int front(){return a[++p];}
}q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m),memset(deg,0,sizeof(deg));
		dnt=0,memset(head,0,sizeof(head));
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int u,v,i=1;i<=m;++i)scanf("%d %d",&u,&v),addedge(u,v);
		q.clear();bool tag=false;
		for(int i=1;i<=n;++i){
			if(chk()){tag=true,printf("%d\n",i-1);break;}
			for(int j=1;j<=n;++j)b[j]=a[j];
			for(int j=1;j<=n;++j){
				if(!a[j])continue;--b[j];
				for(int k=head[j];k;k=next[k])++b[to[k]];
			}
			for(int j=1;j<=n;++j)a[j]=b[j];
		}
		if(tag)continue;
		for(int i=1;i<=n;++i)if(!deg[i])q.push(i);
		while(q.size()){
			int u=q.front();a[u]%=P;
			for(int i=head[u];i;i=next[i]){
				a[to[i]]=(a[to[i]]+a[u])%P;
				if(!(--deg[to[i]]))q.push(to[i]);
			}
			ans=a[u];
		}
		printf("%d\n",(ans+n)%P);
	}
	return 0;
}