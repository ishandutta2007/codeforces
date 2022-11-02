#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
const int N=2000005;
int sum,flag,nedge,n,m,nextt[N],son[N],ed[N],d[N],dist[N],vis[N],v[N],ans;
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
inline void dfs(int p,int fa,int li){ vis[p]=1; 
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]){
		dfs(ed[i],p,i);
	}//cout<<p<<" "<<fa<<" "<<li<<" "<<d[p]<<endl;
	if(d[p])v[(li+1)>>1]=1;
	d[fa]^=d[p]; d[p]=0;
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++)d[i]=read();
	for(int i=1;i<=n;i++)if(d[i]>=0)sum+=d[i]; else flag=1; //writeln(sum);
	if(sum&1){
		if(!flag){
			puts("-1"); return 0;
		}else{
			for(int i=1;i<=n;i++)if(d[i]<0){
				d[i]=1; break;
			}
		}
	}
	for(int i=1;i<=n;i++)if(d[i]<0)d[i]=0;
	for(int i=1;i<=m;i++){
		int s1=read(),s2=read(); aedge(s1,s2); aedge(s2,s1);
	}
	dfs(1,0,0);
	for(int i=1;i<=m;i++)if(v[i])ans++;
	writeln(ans);
	for(int i=1;i<=m;i++)if(v[i])writeln(i);
}