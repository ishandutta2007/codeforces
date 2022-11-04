#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int N=100005;
struct edge{int to,next;}e[N*2];
int head[N],color[N],ppp[N*2];
int n,x,y,flag,tot;
void add(int x,int y){
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
}
int dfs(int fa,int x,int id){
	//printf("%d %d %d %d\n",id,ppp[id],fa,x);
	if (ppp[id]!=-1) return ppp[id];
	ppp[id]=color[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			int tmp=dfs(x,e[i].to,i);
			if (tmp==0||tmp!=ppp[id]) return ppp[id]=0;
		}
	return ppp[id];
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
    	scanf("%d%d",&x,&y);
    	add(x,y);
    	add(y,x);
	}
	for (int i=1;i<=n;i++) scanf("%d",&color[i]);
	memset(ppp,-1,sizeof(ppp));
	for (int i=1;i<=n;i++){
		flag=1;
		for (int j=head[i];j;j=e[j].next)
			if (dfs(i,e[j].to,j)==0) flag=0;
		if (flag){
			printf("YES\n%d",i);
			return 0;
		}
	}
	/*for (int i=1;i<=n;i++)
		for (int j=head[i];j;j=e[j].next)
			printf("?%d %d %d %d\n",j,ppp[j],i,e[j].to);*/
	printf("NO");
}