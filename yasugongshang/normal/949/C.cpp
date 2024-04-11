#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
using namespace std;
const int N=200005,M=200005,oo=1000000005;
struct data{
    int son[N],nextt[M],ed[M],nedge;
    inline void aedge(int a,int b){
    	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
	}
}e1,e2;
int rd[N],anss,tong[N],n,ans,zh[N],sum[N],vis[N],low[N],dfn[N],zhan[N],tot,h,m,b[N],cd[N],anan;
inline void dfs(int p){
    dfn[p]=low[p]=++h;
    vis[p]=zh[p]=true;
    zhan[++tot]=p;
    for(int i=e1.son[p];i;i=e1.nextt[i]){
        if(vis[e1.ed[i]]==false){
            dfs(e1.ed[i]);
            low[p]=min(low[e1.ed[i]],low[p]);
        }else if(zh[e1.ed[i]]) low[p]=min(low[p],dfn[e1.ed[i]]);
    }
    if(dfn[p]==low[p]){
        ans++;
        while(zhan[tot+1]!=p){
            tong[zhan[tot]]=ans; sum[ans]++;
            zh[zhan[tot--]]=false;
        }
    }
}
int main(){
	n=read(); m=read(); h=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		if((b[u]+1)%h==b[v]){
			e1.aedge(u,v);
		}
		if((b[v]+1)%h==b[u]){
			e1.aedge(v,u);
		}
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	for(int i=1;i<=n;i++){
		for(int j=e1.son[i];j;j=e1.nextt[j])if(tong[e1.ed[j]]!=tong[i]){
			cd[tong[i]]++;
		}
	}
	int an=1e9;
	for(int i=1;i<=ans;i++)if(!cd[i]){
		if(sum[i]<an){
			an=sum[i]; anan=i;
		}
	}
	writeln(an);
	for(int i=1;i<=n;i++)if(tong[i]==anan){
		write(i); putchar(' ');
	}
}