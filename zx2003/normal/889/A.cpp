#include<cstdio>
#include<cctype>
#include<cstring>
const int N=400005,inf=1<<30,M=1000000;
inline int min(int a,int b){return a<b?a:b;}
int n,i,t;
struct graph{
    struct edge{
        int to,next,flow;
    }e[M<<1];
    int h[N],d[N],q[N],xb,n,cur[N],T;
    inline void init(int n){
    	this->n=n;
    	memset(h+1,0,n<<2);xb=1;
    }
    void addedge(int x,int y,int z){
        e[++xb]=(edge){y,h[x],z};h[x]=xb;
        e[++xb]=(edge){x,h[y],0};h[y]=xb;
    }
    bool bfs(int x,int y){
    	memset(d+1,0,n<<2);d[x]=1;
        register int t=0,w=1,u,i;q[1]=x;
        while(t<w)
            for(i=h[u=q[++t]];i;i=e[i].next)
                if(e[i].flow && !d[e[i].to]){
                    d[e[i].to]=d[u]+1;q[++w]=e[i].to;
                    if(e[i].to==T)return 1;
                }
        return 0;
    }
    int dfs(int x,int f){
        if(x==T)return f;
        int flow=0,a;
        for(int&i=cur[x];i && f;i=e[i].next)if(e[i].flow && d[e[i].to]==d[x]+1 && 
            (a=dfs(e[i].to,min(f,e[i].flow)),a))e[i].flow-=a,e[i^1].flow+=a,flow+=a,f-=a;
        return flow;
    }
    int maxflow(int x,int y){
        T=y;
        register int ans=0;
        while(bfs(x,y)){
        	memcpy(cur+1,h+1,n<<2);
            ans+=dfs(x,inf);
        }
        return ans;
    }
}g;
inline void read(int&x){
	static char c;
	for(c=getchar();!isdigit(c);c=getchar());
	for(x=0;isdigit(c);c=getchar())x=x*10+c-48;
}
int main(){
	//freopen("1.txt","r",stdin);
	scanf("%d",&n);g.init(n*2+4);
	for(i=1;i<=n;++i)read(t),g.addedge(t+1,i+n+2,1);
	for(i=1;i<=n+1;++i)g.addedge(2*n+3,i,1),g.addedge(i+n+1,2*n+4,1);
	printf("%d\n",n+1-g.maxflow(2*n+3,2*n+4));
	return 0;
}