#include<bits/stdc++.h>
#define pa pair<int,int>
#define LZH 100005
using namespace std;
set<int> go[LZH];
map<pa,int> M;
vector<int> way[LZH];
struct edge{int to,next;}e[LZH*2];
int n,m,N,wh,now,tot,x,y;
int a[LZH],p[LZH],head[LZH];
int ans[LZH],pd[LZH],sz[LZH];
bool jdabi(int x,int y){
	return x>y;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
	e[++tot]=(edge){x,head[y]};
	head[y]=tot;
}
void dfs(int k1,int k2,int s){
	if (k1==s) return;
	way[N].push_back(k1);
	set<int>::iterator k=go[k1].lower_bound(k2);
	if (k==go[k1].begin()) k=go[k1].end();
	int ne=*(--k); go[k1].erase(k);
	M[pa(ne,k1)]=N; dfs(ne,k1,s);
}
bool cmp(int k1,int k2){
	return way[k1]<way[k2];
}
int dfs1(int x,int fa){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!pd[e[i].to])
			sz[x]+=dfs1(e[i].to,x);
	return sz[x];
}
int dfs2(int x,int fa){
	int num=n-sz[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!pd[e[i].to])
			dfs2(e[i].to,x),num=max(num,sz[e[i].to]);
	if (num<now)
		wh=x,now=num;
}
void getans(int x,int y){
	now=n=dfs1(x,0); wh=x;
	dfs2(x,0);
	int k=wh; pd[k]=1; ans[k]=y;
	for (int i=head[k];i;i=e[i].next)
		if (!pd[e[i].to]) getans(e[i].to,y+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int nxt=(i%n+1);
		go[nxt].insert(i);
		go[i].insert(nxt);
	}
	for (;m;m--){
		scanf("%d%d",&x,&y);
		go[x].insert(y);
		go[y].insert(x);
	}
	for (int now=1;now<=n;){
		if (go[now].size()==0){
			now++; continue;
		}
		set<int>::iterator k=go[now].begin();
		int k1=(*k); go[now].erase(k);
		way[++N].push_back(now);
		M[pa(k1,now)]=N;
		dfs(k1,now,now);
		sort(way[N].begin(),way[N].end(),jdabi);
	}
	for (int i=1;i<=N;i++) a[i]=i;
	sort(a+1,a+N+1,cmp);
	for (map<pa,int>::iterator k=M.begin();k!=M.end();k++){
		int k1=(*k).first.first,k2=(*k).first.second;
		if (k2==k1%n+1||k1==k2%n+1) continue;
		if (k1<k2) add(M[pa(k1,k2)],M[pa(k2,k1)]);
	}
	int flag=0;
	for (int i=1;i<=N;i++)
		if (pd[i]==0){
			int k=dfs1(i,0);
			if (k==1&&!flag){
				flag=i;
				continue;
			}
			getans(i,1);
		}
	for (int i=1;i<=N;i++){
		if (a[i]==flag) continue;
		printf("%d ",ans[a[i]]);
	}
}