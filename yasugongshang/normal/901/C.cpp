#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=600005,M=600005;
struct data{
    int son[N],nextt[M],ed[M],nedge;
}e1,e2;
int dp[N],tt[N],mmin[N],s3[N],T,s1[M],s2[M],anss,tong[N],zs,k,n,m,i,ans,zh[N],vis[N],low[N],dfn[N],zhan[N],tot,h;
inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void aedge1(int a,int b){
    e1.nextt[++e1.nedge]=e1.son[a];
    e1.son[a]=e1.nedge;
    e1.ed[e1.nedge]=b;
}
inline void aedge2(int a,int b){
    e2.nextt[++e2.nedge]=e2.son[a];
    e2.son[a]=e2.nedge;
    e2.ed[e2.nedge]=b;
}
inline void dfs(int p,int last){
    dfn[p]=low[p]=++h;
    vis[p]=zh[p]=true;
    zhan[++tot]=p;
    for(int i=e1.son[p];i;i=e1.nextt[i])if(e1.ed[i]!=last){
        if(vis[e1.ed[i]]==false){
            dfs(e1.ed[i],p);
            low[p]=min(low[e1.ed[i]],low[p]);
        }else if(zh[e1.ed[i]]) low[p]=min(low[p],dfn[e1.ed[i]]);
    }
    if(dfn[p]==low[p]){
        ans++;
        while(zhan[tot+1]!=p){
            tong[zhan[tot]]=ans; tt[ans]++;
            zh[zhan[tot--]]=false;
        }
    }
}
#include<cstring>
long long sum[N];
int bj[N],mmax[N];
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int main(){
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        aedge1(s1[i]=read(),s2[i]=read()); aedge1(s2[i],s1[i]);
    }
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,0);
	for(int i=1;i<=ans;i++)mmin[i]=n+1;
	for(int i=1;i<=n;i++)mmax[tong[i]]=max(mmax[tong[i]],i);
    for(int i=1;i<=n;i++)mmin[tong[i]]=min(mmin[tong[i]],i); 
    for(int i=1;i<=ans;i++)if(tt[i]>=3){
		bj[mmax[i]]=max(bj[mmax[i]],mmin[i]);
	}
	for(int i=1;i<=n;i++)bj[i]=max(bj[i-1],bj[i]);
	//for(int i=1;i<=n;i++)cout<<bj[i]<<" "<<i<<endl;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+bj[i];
	m=read();
	while(m--){
		int l=read(),r=read();
		int t=lower_bound(&bj[l],&bj[r+1],l)-bj;
		writeln((long long)(l+r)*(r-l+1)/2-(long long)(t-l)*(l-1)-sum[r]+sum[t-1]);
	}

}