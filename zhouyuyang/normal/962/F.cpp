#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct edge{
	int from,to,next;
}e[N*2];
int head[N],tot;
int dfn[N],low[N],T;
int sta[N],top;
int be[N],h[N],cnt;
vector<int> s[N]; 
int ans[N];
int n,m;
void add(int x,int y){
	e[++tot]=(edge){x,y,head[x]};
	head[x]=tot; 
}
void tarjan(int x){
	low[x]=dfn[x]=++T;
	sta[++top]=x;
	for (int i=head[x];i;i=e[i].next)
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
			if (low[e[i].to]>=dfn[x]){
				cnt++;
				int id=437281913;
				do{
					id=sta[top--];
					h[cnt]++;
					be[id]=cnt;
				}while(id!=e[i].to);
				h[cnt]++;
			}
		}
		else low[x]=min(low[x],dfn[e[i].to]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]){
			tarjan(i);
			cnt++;
			for (;top>0;)
				h[cnt]++,top--;
		}
	for (int i=1;i<=m;i++){
		int id=i*2,x;
		if (dfn[e[id].from]>dfn[e[id].to])
			x=e[id].from;
		else x=e[id].to;
		s[be[x]].push_back(i);
	}
	for (int i=1;i<=cnt;i++)
		if (s[i].size()==h[i])
			for (int j=0;j<s[i].size();j++)
				ans[++ans[0]]=s[i][j];
	sort(ans+1,ans+ans[0]+1);
	printf("%d\n",ans[0]);
	for (int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
}