#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
struct Edge{
    int x,y,cap,nxt;
    Edge(){}
    Edge(int a,int b,int c,int d){
        x=a,y=b,cap=c,nxt=d;
    }
};
struct gragh{
    static const int N=605*4,M=1000000,INF=0x7FFFFFFF;
    int n,S,T,fst[N],cnt;
    int dist[N],num[N],cur[N],p[N];
    LL MaxFlow;
    Edge e[M];
    void clear(int _n){
        cnt=1,n=_n;
        memset(fst,0,sizeof fst);
    }
    void add(int a,int b,int c){
        e[++cnt]=Edge(a,b,c,fst[a]),fst[a]=cnt;
        e[++cnt]=Edge(b,a,0,fst[b]),fst[b]=cnt;
    }
    void init(){
        memset(dist,0,sizeof dist);
        memset(num,0,sizeof num);
        for (int i=1;i<=n;i++)
            num[dist[i]]++,cur[i]=fst[i];
    }
    void init(int _S,int _T){
        S=_S,T=_T;
        MaxFlow=0;
        init();
    }
    int Augment(int &x){
        int Flow=INF;
        for (int i=T;i!=S;i=e[p[i]].x)
            if (e[p[i]].cap<=Flow)
                Flow=e[p[i]].cap,x=e[p[i]].x;
        for (int i=T;i!=S;i=e[p[i]].x)
            e[p[i]].cap-=Flow,e[p[i]^1].cap+=Flow;
        return Flow;
    }
    LL ISAP(){
        int x=S,y;
        while (dist[S]<n){
            if (x==T){
                MaxFlow+=Augment(x);
                continue;
            }
            bool found=0;
            for (int i=cur[x];i;i=e[i].nxt)
                if (dist[y=e[i].y]+1==dist[x]&&e[i].cap){
                    cur[x]=p[y]=i,x=y,found=1;
                    break;
                }
            if (!found){
                int d=n+1;
                for (int i=fst[x];i;i=e[i].nxt)
                    if (e[i].cap)
                        d=min(d,dist[e[i].y]+1);
                if (!--num[dist[x]])
                    return MaxFlow;
                num[dist[x]=d]++,cur[x]=fst[x],x=x==S?x:e[p[x]].x;
            }
        }
        return MaxFlow;
    }
    LL Auto(int _S,int _T){
        init(_S,_T);
        return ISAP();
    }
}g;
const int N=605;
int T,n,m,k;
int in[N],a[N],b[N];
int k1[N],k2[N],k3[N],ans[N];
vector <int> e[N];
void Out0(){
	for (int i=1;i<=m;i++)
		printf("0 ");
	puts("");
}
void Main(){
	n=read(),m=read(),k=read();
	memset(in,0,sizeof in);
	for (int i=1;i<=n;i++)
		e[i].clear();
	for (int i=1;i<=m;i++){
		a[i]=read(),b[i]=read();
		in[a[i]]++,in[b[i]]++;
	}
	int S=n*2+m*2+1,T=S+1;
	g.clear(T);
	for (int i=1;i<=n;i++){
		if (k*2<in[i])
			return Out0();
		int lim=min(in[i],k*2-in[i]);
		g.add(i,T,lim);
	}
	for (int i=1;i<=m;i++){
		g.add(S,i+n,1),k1[i]=g.cnt;
		g.add(i+n,a[i],1),k2[i]=g.cnt;
		g.add(i+n,b[i],1),k3[i]=g.cnt;
	}
	g.Auto(S,T);
	int totcnt=0;
	for (int i=1;i<=m;i++)
		totcnt+=g.e[k1[i]].cap;
	if (totcnt<m)
		return Out0();
	for (int i=1;i<=m;i++)
		if (g.e[k2[i]].cap){
			e[b[i]].push_back(i);
//			printf("%d pb %d\n",b[i],i);
		}
		else {
			e[a[i]].push_back(i);
//			printf("%d pb %d\n",a[i],i);
		}
	int cnt=0;
	memset(ans,0,sizeof ans);
	for (int i=1;i<=n;i++)
		for (int j=0;j<e[i].size();j++){
			if (j%2==0)
				cnt++;
//			printf(":: %d %d %d %d\n",i,j,e[i][j],cnt);
			ans[e[i][j]]=cnt;
		}
	for (int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main(){
	T=read();
	while (T--)
		Main();
	return 0;
}