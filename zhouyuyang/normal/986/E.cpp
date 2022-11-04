#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int dep[N],fa[N][20];
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=18;i>=0;i--)
		if (tmp&(1<<i)) x=fa[x][i];
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return (x==y?x:fa[x][0]);
}

const int M=10000005;
bool fl[M];
int mn[M],pri[666666],cnt;
#define pa pair<int,int>
void divide(vector<pa> &a,int v){
	a.resize(0);
	for (;v!=1;){
		int cnt=0,id=mn[v],lav=pri[id];
		for (;v%lav==0;v/=lav,cnt++);
		a.push_back(pa(id,cnt));
	}
}
vector<pa> vec[N],tmp;

struct que{
	int type,id,first,second;
};
vector<que> q[N];
int tong[666666][30];
const int mo=1000000007;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int ans[N];
void work(int x){
	for (int i=0;i<vec[x].size();i++)
		tong[vec[x][i].first][vec[x][i].second]++;
	for (int i=0;i<q[x].size();i++){
		int sum=0;
		for (int j=0;j<=28;j++)
			if (tong[q[x][i].first][j])
				sum+=tong[q[x][i].first][j]*min(q[x][i].second,j);
		int tmp=power(pri[q[x][i].first],sum)%mo;
		if (q[x][i].type==-1) tmp=power(tmp,mo-2);
		ans[q[x][i].id]=1ll*ans[q[x][i].id]*tmp%mo;
	}
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]) work(e[i].to);
	for (int i=0;i<vec[x].size();i++)
		tong[vec[x][i].first][vec[x][i].second]--;
}
int n,Q;
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=2;i<M;i++)
		if (!fl[i]){
			pri[++cnt]=i; mn[i]=cnt;
			for (int j=i+i;j<M;j+=i){
				fl[j]=1;
				if (!mn[j]) mn[j]=cnt;
			}
		}
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		divide(vec[i],x);
	}
	dfs(1);
	for (int i=1;i<=18;i++)
		for (int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		int x,y,v,L;
		scanf("%d%d%d",&x,&y,&v);
		divide(tmp,v); L=lca(x,y);
		for (int j=0;j<tmp.size();j++){
			q[x].push_back((que){1,i,tmp[j].first,tmp[j].second});
			q[y].push_back((que){1,i,tmp[j].first,tmp[j].second});
			q[L].push_back((que){-1,i,tmp[j].first,tmp[j].second});
			q[fa[L][0]].push_back((que){-1,i,tmp[j].first,tmp[j].second});
		}
		ans[i]=1;
	}
	work(1);
	for (int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
}