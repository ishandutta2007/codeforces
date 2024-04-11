#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005,M=1000005;
bool vis[N];
int sum1,sum2,ti[N],d[N],p[N],n,m,nedge,oo=1000000005,last[N],son[N],ed[M],nextt[M],di[M],que[N],laedge[N],dist[N],cost[M];
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline bool spfa(int s,int t){
	for (int i=1;i<=n;i++) {dist[i]=oo;last[i]=laedge[i]=vis[i]=que[i-1]=0;}
	int tot=1,l=0,r=0; que[0]=s; vis[s]=true; dist[s]=0;
	while (tot) {
		int k=que[l]; 
		vis[k]=false;
		if (++l==n) l=0;
		tot--; 
		for(int i=son[k];i;i=nextt[i]){
			if (di[i]>0&&dist[ed[i]]>dist[k]+cost[i]) 
			{
				dist[ed[i]]=dist[k]+cost[i]; laedge[ed[i]]=i; last[ed[i]]=k;
				if (vis[ed[i]]==0) {
					if(++r==n)r=0;
					que[r]=ed[i]; tot++; vis[ed[i]]=true;
				}
			}
		}
	}
	return last[t]>0;
}
inline int costflow(int s,int t){
    int sum=0,cost=0;
	while(spfa(s,t)){
		int mmin=oo; 
		for(int i=t;last[i];i=last[i]){mmin=min(mmin,di[laedge[i]]);}
		sum+=mmin;
		cost+=dist[t]*mmin; 
		for(int i=t;last[i];i=last[i]){
			di[laedge[i]]-=mmin;
			di[(1^(laedge[i]-1))+1]+=mmin;
		}
	}
	return cost;
}
inline void aedge(int a,int b,int c,int d){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c; cost[nedge]=d;
}
inline void insert(int a,int b,int c,int d){
	aedge(a,b,c,-d); aedge(b,a,0,d);
}
char ch[105];
int tong[26],b[105];
int main(){
	n=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		ch[i]=ch[i]-'a'+1;
		tong[ch[i]]++;
		b[i]=read();
	}
	int s=26+26*n/2+26*n+n+1,t=s+1;
	for(int i=1;i<=26;i++){
		insert(s,i,tong[i],0);
		for(int j=1;j<=n/2;j++){
			int zs=26+(i-1)*(n/2)+j;
			insert(i,zs,1,0);
			insert(zs,26+26*n/2+(i-1)*n+j*2-1,1,ch[j]==i?b[j]:0);
			insert(zs,26+26*n/2+(i-1)*n+j*2,1,ch[n-j+1]==i?b[n-j+1]:0);
			insert(26+26*n/2+(i-1)*n+j*2-1,26+26*n/2+26*n+j,1,0);
			insert(26+26*n/2+(i-1)*n+j*2,26+26*n/2+26*n+n-j+1,1,0);
		}
	}
	for(int i=1;i<=n;i++)insert(26+26*n/2+26*n+i,t,1,0);
	n=t;
	writeln(-costflow(s,t));
}