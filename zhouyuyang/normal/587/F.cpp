#include<bits/stdc++.h>
const int N=100005;
using namespace std;
vector<int> vec[N],Q[N],adj[N],G[N];
int L[N],R[N],id[N],st[N],ed[N];
int be[N],dfn[N],tg[N],l[N];
int ch[N][26],fail[N],q[N];
int sz=1,T,n,m,cntBlk,Blk=316;
long long ans[N],sum[N];
char s[N];
void insert(char *s,int id){
	int x=1;
	for (int i=0;i<l[id];i++){
		if (!ch[x][s[i]-'a'])
			ch[x][s[i]-'a']=++sz;
		x=ch[x][s[i]-'a'];
	}
	vec[x].push_back(id);
}
void build(){
	int h=0,t=0;
	for (int i=0;i<26;i++)
		if (!ch[1][i])
			ch[1][i]=1;
		else{
			q[++t]=ch[1][i];
			fail[ch[1][i]]=1;
		}
	while (h!=t){
		int x=q[++h];
		for (int i=0;i<26;i++)
			if (!ch[x][i])
				ch[x][i]=ch[fail[x]][i];
			else{
				q[++t]=ch[x][i];
				fail[ch[x][i]]=ch[fail[x]][i];
			}
	}
	for (int i=2;i<=sz;i++)
		adj[fail[i]].push_back(i);
}
int dfs(int x){
	int sz=(dfn[x]==T);
	for (int i=0;i<adj[x].size();i++)
		sz+=dfs(adj[x][i]);
	for (int i=0;i<vec[x].size();i++)
		sum[vec[x][i]]+=sz;
	return sz;
}

void add(int x,int v){
	for (int i=x;i<=ed[be[x]];i++) sum[i]+=v;
	for (int i=be[x]+1;i<=cntBlk;i++) tg[i]+=v;
}
long long ask(int x){
	return tg[be[x]]+sum[x];
}
void calc(int x){
	for (int i=0;i<vec[x].size();i++)
		add(vec[x][i],1);
	for (int i=0;i<G[x].size();i++){
		int id=G[x][i];
		ans[id]+=ask(R[id])-ask(L[id]-1);
	}
	for (int i=0;i<adj[x].size();i++)
		calc(adj[x][i]);
	for (int i=0;i<vec[x].size();i++)
		add(vec[x][i],-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		st[i]=ed[i-1];
		scanf("%s",s+st[i]);
		l[i]=strlen(s+st[i]);
		ed[i]=ed[i-1]+l[i];
		insert(s+st[i],i);
	}
	build();
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&L[i],&R[i],&id[i]);
		if (l[id[i]]>Blk)
			Q[id[i]].push_back(i);
		else{
			int x=1;
			for (int k=st[id[i]];k<ed[id[i]];k++){
				x=ch[x][s[k]-'a'];
				G[x].push_back(i);
			}
		}
	}
	//1
	for (int i=1;i<=n;i++)
		if (Q[i].size()){
			++T; int x=1;
			memset(sum,0,sizeof(sum));
			for (int k=st[i];k<ed[i];k++){
				x=ch[x][s[k]-'a'];
				dfn[x]=T;
			}
			dfs(1);
			for (int k=1;k<=n;k++)
				sum[k]+=sum[k-1];
			for (int k=0;k<Q[i].size();k++){
				int id=Q[i][k];
				ans[id]=sum[R[id]]-sum[L[id]-1];
			} 
		}
	cntBlk=(n-1)/Blk+1;
	memset(sum,0,sizeof(sum));
	for (int i=1;i<=cntBlk;i++){
		st[i]=(i-1)*Blk+1;
		ed[i]=min(n,i*Blk);
		for (int k=st[i];k<=ed[i];k++)
			be[k]=i;
	}
	calc(1);
	for (int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
}