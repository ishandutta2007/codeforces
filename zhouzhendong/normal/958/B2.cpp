#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct Gragh{
	int cnt,y[N*2],nxt[N*2],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,rt,depth[N],son[N],fa[N];
int q[N],vis[N],head,tail;
int findfar(int s){
	head=tail=0;
	q[++tail]=s;
	vis[s]=1;
	while (head<tail){
		int x=q[++head];
		for (int i=g.fst[x];i;i=g.nxt[i])
			if (!vis[g.y[i]]){
				vis[g.y[i]]=1;
				q[++tail]=g.y[i];
			}
	}
	return q[n];
}
void dfs(int x,int pre){
	fa[x]=pre;
	depth[x]=1;
	son[x]=x;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			dfs(g.y[i],x);
			if (depth[g.y[i]]+1>depth[x]){
				depth[x]=depth[g.y[i]]+1;
				son[x]=son[g.y[i]];
			}
		}
}
struct Node{
	int x;
	Node(){}
	Node(int v){x=v;}
	friend bool operator < (Node a,Node b){
		return depth[a.x]>depth[b.x];
	}
};
multiset <Node> st;
int ans[N];
int main(){
	scanf("%d",&n);
	g.clear();
	for (int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		g.add(x,y);
		g.add(y,x);
	}
	rt=findfar(1);
	dfs(rt,0);
	st.clear();
	ans[1]=1;
	for (int i=g.fst[rt];i;i=g.nxt[i])
		st.insert(Node(g.y[i]));
	for (int i=2;i<=n;i++){
		if (ans[i-1]==n){
			ans[i]=n;
			continue;
		}
		int x=(*(st.begin())).x;
		st.erase(st.begin());
		ans[i]=ans[i-1]+depth[x];
		for (int i=son[x],j;i!=x;i=j){
			j=fa[i];
			for (int k=g.fst[j];k;k=g.nxt[k])
				if (g.y[k]!=i&&g.y[k]!=fa[j])
					st.insert(Node(g.y[k]));
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}