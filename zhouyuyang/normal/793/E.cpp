#include<bits/stdc++.h>
#define N 5005
using namespace std;
int n,tot,fa[N],sz[N];
int head[N],fl[N];
struct edge{int to,next;}e[N];
vector<int> cur;
bitset<N> f;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void select(int x){
	for (;x>1;x=fa[x]){
		fl[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (!fl[e[i].to]) cur.push_back(sz[e[i].to]);
	}
}
bool solve(int x,int y,int z){
	cur.clear();
	memset(fl,0,sizeof(fl));
	select(x);
	select(z);
	f.reset();
	for (;fa[y]>1;y=fa[y]);
	fl[y]=1;
	f[sz[y]]=1;
	for (int i=0;i<cur.size();i++)
		f|=f<<cur[i];
	for (int i=head[1];i;i=e[i].next)
		if (!fl[e[i].to])
			f|=f<<sz[e[i].to];
	return f[sz[1]/2-1];
}
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	for (int i=n;i>1;i--){
		sz[i]=max(sz[i],1);
		sz[fa[i]]+=sz[i];
	}
	if (sz[1]&1){
		puts("NO");
		return 0;
	}
	if (2*(*max_element(sz+2,sz+n+1))>=sz[1]){
		puts("NO");
		return 0;
	}
	if (solve(a,b,c)&&solve(b,c,d))
		puts("YES");
	else puts("NO");
}