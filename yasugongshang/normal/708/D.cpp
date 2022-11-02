#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){write(a); puts("");}
inline void wri(int a){write(a); putchar(' ');}
const int inf=1e9;
const int N=105,M=805;
int nedge=1,son[N],nextt[M],ed[M];
int cost[M],dist[N],di[M];
bool vis[N];
int last[N],que[N],laedge[N];
bool spfa(int s,int t,int n){
    for (int i=1;i<=n;i++) {dist[i]=inf;last[i]=laedge[i]=vis[i]=que[i-1]=0;}
    int tot=1,l=0,r=0; que[0]=s; vis[s]=true; dist[s]=0;
    while (tot) {
        int k=que[l];
        vis[k]=false;
        if (++l==n) l=0;
        tot--; 
        for(int i=son[k];i;i=nextt[i]){
            if(di[i]>0&&dist[ed[i]]>dist[k]+cost[i]){
                dist[ed[i]]=dist[k]+cost[i]; laedge[ed[i]]=i; last[ed[i]]=k;
                if(vis[ed[i]]==0) {
                    if(++r==n)r=0;
                    que[r]=ed[i]; tot++; vis[ed[i]]=true;
                }
            }
        }
    }
    return last[t]>0;
}
int costflow(int s,int t,int n){
	int sum=0; int cost=0;
    while(spfa(s,t,n)){
        int mmin=inf; 
        for(int i=t;last[i];i=last[i]){mmin=min(mmin,di[laedge[i]]);} 
        sum+=mmin;
        cost+=dist[t]*mmin; 
        for(int i=t;last[i];i=last[i]){
            di[laedge[i]]-=mmin;
            di[laedge[i]^1]+=mmin;
        }
    }
    return cost;
}
inline void aedge(int a,int b,int c,int d){
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c; cost[nedge]=d;
}
inline void ins(int a,int b,int c,int d){
    aedge(a,b,c,d); aedge(b,a,0,-d);
}
int d[N];
int main(){
	int n=read(),m=read(),s=n+1,t=s+1,ans=0;
	For(i,1,m){
		int u=read(),v=read(),lim=read(),c=read(); 
		if(c>lim)ans+=c-lim;
		d[u]+=c; d[v]-=c;
		if(lim>=c){
			ins(u,v,lim-c,1);
			ins(u,v,inf,2);
			ins(v,u,c,1);
		}else{
			ins(u,v,inf,2);
			ins(v,u,c-lim,0);
			ins(v,u,lim,1);
		}
	}
	ins(n,1,inf,0);
	For(i,1,n)if(d[i]>0)ins(i,t,d[i],0); else ins(s,i,-d[i],0);
	cout<<costflow(s,t,t)+ans<<endl;
}