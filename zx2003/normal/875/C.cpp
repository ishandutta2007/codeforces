#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
const int N=100005;
vector<int> a[N],e[N],e2[N];
int n,m,v[N],i,j,l[N],x,y;
bool vi[N];
inline void EXIT(){puts("No");exit(0);}
void dfs(int x){
	vi[x]=1;
	for(unsigned int i=0;i<e[x].size();++i)if(!vi[e[x][i]]){
		if(v[e[x][i]]==-1)EXIT();
		v[e[x][i]]=1;dfs(e[x][i]);
	}
}
void dfs2(int x){
	vi[x]=1;
	for(unsigned int i=0;i<e2[x].size();++i)if(!vi[e2[x][i]]){
		if(v[e2[x][i]]==1)EXIT();
		v[e2[x][i]]=-1;dfs2(e2[x][i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",l+i);
		for(j=0;j<l[i];++j){
			scanf("%d",&x);
			a[i].push_back(x);
		}
		if(i>1){
			for(j=0;j<l[i] && j<l[i-1] && a[i-1][j]==a[i][j];++j);
			if(j==l[i-1])continue;
			if(j==l[i])EXIT();
			x=a[i-1][j],y=a[i][j];
			if(x<y){
				if(v[x]==1 && v[y]==-1)EXIT();
				e[x].push_back(y);
				e2[y].push_back(x);
			}else{
				if(v[x]==1 || v[y]==-1)EXIT();
				v[x]=-1,v[y]=1;
			}
		}
	}
	for(i=1;i<=m;++i)if(!vi[i] && v[i]==1)dfs(i);
	for(i=1;i<=m;++i)if(!vi[i] && v[i]==-1)dfs2(i);
	for(i=1,j=0;i<=m;++i)j+=v[i]==-1;
	printf("Yes\n%d\n",j);
	for(i=1;i<=m;++i)if(v[i]==-1)printf("%d ",i);
	return 0;
}