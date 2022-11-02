#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const long long N=1000005,M=1000005;
struct data{
	long long son[N],nextt[M],ed[M],nedge,di[M];
}e1,e2;
long long s3[M],f[N],l,r,a[N],s,b[N],que[N],ans,zs1,zs2,rd[N],cd[N],zz,T,s1[M],s2[M],anss,tong[N],zs,k,n,m,i,zh[N],vis[N],low[N],dfn[N],zhan[N],tot,h;
inline void aedge1(long long a,long long b){
	e1.nextt[++e1.nedge]=e1.son[a];
	e1.son[a]=e1.nedge;
	e1.ed[e1.nedge]=b;
}
inline void aedge2(long long a,long long b,long long c){
	rd[b]++; //cout<<a<<" fasihgofias "<<b<<endl;
	e2.nextt[++e2.nedge]=e2.son[a];
	e2.son[a]=e2.nedge;
	e2.ed[e2.nedge]=b;
	e2.di[e2.nedge]=c;
}
inline void dfs(long long p){
	dfn[p]=low[p]=++h;
	vis[p]=zh[p]=true;
	zhan[++tot]=p;
	for(long long i=e1.son[p];i;i=e1.nextt[i]){
		if(vis[e1.ed[i]]==false){
			dfs(e1.ed[i]);
			low[p]=min(low[e1.ed[i]],low[p]);
		}else if(zh[e1.ed[i]]) low[p]=min(low[p],dfn[e1.ed[i]]);
    }
	if(dfn[p]==low[p]){
		ans++;
		while(zhan[tot+1]!=p){
			tong[zhan[tot]]=ans;
			zh[zhan[tot--]]=false;
		}
	}
}
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
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
#include<cmath>
long long ycl[50005];
inline long long solve(long long x){
	if(x==0)return 0;
	long long t=sqrt(x*2); if(t*(t+1)/2>x)t--;
	return (long long)(t+1)*x-ycl[t];
}
int main(){
    for(long long i=1;i<=50000;i++)ycl[i]=ycl[i-1]+i*(i+1)/2;
    n=read(); m=read();
	for(i=1;i<=m;i++){s1[i]=read(); s2[i]=read(); s3[i]=read(); aedge1(s1[i],s2[i]);}
	for(i=1;i<=n;i++)if(vis[i]==false)dfs(i);
	for(i=1;i<=m;i++){
		if(tong[s1[i]]!=tong[s2[i]]){
			aedge2(tong[s1[i]],tong[s2[i]],s3[i]);
		}else a[tong[s1[i]]]+=solve(s3[i]);
    }
    s=tong[read()];
    for(long long i=1;i<=ans;i++)f[i]=-4e18;
	anss=0; f[s]=a[s];
    for(long long i=1;i<=ans;i++)if(!rd[i])que[++r]=i;
    while(l<r){
    	long long k=que[++l]; anss=max(anss,f[k]);
    	for(long long i=e2.son[k];i;i=e2.nextt[i]){
    		f[e2.ed[i]]=max(f[e2.ed[i]],f[k]+a[e2.ed[i]]+e2.di[i]);
    		if(--rd[e2.ed[i]]==0)que[++r]=e2.ed[i];
		}
	}
	writeln(anss);
}