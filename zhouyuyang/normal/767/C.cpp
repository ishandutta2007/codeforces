#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring> 
#define N 1000005
using namespace std; 
struct edge{int to,next;}e[N*2];
int head[N],son[N],ok[N],ppp[N];
int n,x,sum,flag,tot,root;
void add(int x,int y){
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
void dfs(int x,int fa){
	for (int i=head[x];i;i=e[i].next){
		if (e[i].to==fa) continue;
		dfs(e[i].to,x);
		son[x]+=son[e[i].to];
		if (ok[e[i].to]){
			if (ok[x]){
				printf("%d %d",ok[x],ok[e[i].to]);
				exit(0);
			}
			ok[x]=ok[e[i].to];
		}
	}
	if (son[x]==2*sum&&ok[x]&&x!=root){
		printf("%d %d",ok[x],x);
		exit(0);
	}
	if (son[x]==sum&&!ok[x]) ok[x]=x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&son[i]);
		if (x) add(x,i),add(i,x); else root=i;
		sum+=son[i];
	}
	if (sum%3){
		printf("-1");
		return 0;
	}
	sum/=3;
	dfs(root,0);
	printf("-1");
}