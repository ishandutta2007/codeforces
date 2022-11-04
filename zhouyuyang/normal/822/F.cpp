#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=110;
int n,m,cnt=2;
int to[maxn<<1],nxt[maxn<<1],head[maxn],d[maxn],fa[maxn];
void dfs(int x,double tim){
	for(int i=head[x];i;i=nxt[i])	if(to[i]!=fa[x]){
		tim=tim+2.0/d[x];
		if(tim>=1.0)	tim-=2.0;
		fa[to[i]]=x;
		printf("%d %d ",1,i>>1);
		if(tim<0)	printf("%d %d %.10lf\n",to[i],x,1+tim);
		else	printf("%d %d %.10lf\n",x,to[i],tim);
		dfs(to[i],1+tim);
	}
}
inline void add(int a,int b){
	to[cnt]=b,nxt[cnt]=head[a],head[a]=cnt++;
}
int main(){
	scanf("%d",&n);
	printf("%d\n",n-1);
	int i,a,b;
	for(i=1;i<n;i++)	scanf("%d%d",&a,&b),add(a,b),add(b,a),d[a]++,d[b]++;
	dfs(1,0);
	return 0;
}