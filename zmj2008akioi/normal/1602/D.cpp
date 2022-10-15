#include <cstdio>
#include <queue>
#include <stack>
int n,pos,a[300010],b[300010],f[300010],dis[300010],last[300010],lasta[300010];
bool vis[300010];
std::queue<int> queue;
std::stack<int> stack;
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
int next(int u){
	return u+b[u];
}
int ck(int u){
	if(u!=-1)return u;
	return n+1;
}
void update(int u){
	int nw=u,ups=u-a[u];
	while(nw>=ups&&nw!=n+1){
		if(vis[next(nw)]){f[nw]=ck(nw-1),nw=find(nw);continue;}
		f[nw]=ck(nw-1),dis[next(nw)]=dis[u]+1,last[next(nw)]=u,lasta[next(nw)]=nw,vis[next(nw)]=true,queue.push(next(nw)),nw=find(nw);
	}
}
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n+1;++i)f[i]=i;
	for(register int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(register int i=1;i<=n;++i)scanf("%d",&b[i]);
	dis[n]=0,vis[n]=true,queue.push(n);
	while(queue.size())update(queue.front()),queue.pop();
	if(!vis[0])printf("-1");
	else{
		printf("%d\n",dis[0]);
		while(pos!=n)stack.push(lasta[pos]),pos=last[pos];
		while(stack.size())printf("%d ",stack.top()),stack.pop();
	}
	return 0;
}
/*
5
1 2 1 3 2
1 1 0 0 0
*/