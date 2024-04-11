#include<bits/stdc++.h>
using namespace std;
const int N=14e4;
int n,i,a,b,sz[N],z;
vector<int>e[N],A,B,ans;
bool FL;
void dfs(int u,int fa){
	sz[u]=1;
	for(int v:e[u])if(v!=fa){
		dfs(v,u);sz[u]+=sz[v];
		if(!FL && sz[v]*2+2==1<<n)B=vector<int>{u,v};
	}
}
bool vi[N];
bool ckk(int x,int d){
	int ch=0;vi[x]=1;
	for(int y:e[x])if(!vi[y]){if(!ckk(y,d-1))return 0;++ch;}
	return d>1?ch==2:ch==0;
}
bool cmp(int x,int y){return sz[x]>sz[y];}
inline void ck(int x,int d){
	auto E=e[x];
	FL=1;dfs(x,0);sort(e[x].begin(),e[x].end(),cmp);
	e[z]={x};
	for(;d--;)e[z].push_back(e[x].back()),e[x].pop_back();e[x].push_back(z);
	if((memset(vi+1,0,1<<n),ckk(B[0],n)) || (memset(vi+1,0,1<<n),ckk(B[1],n)))ans.push_back(x);
	e[x]=E;
}
inline void O(){
	printf("%d\n",ans.size());
	sort(ans.begin(),ans.end());for(int x:ans)printf("%d ",x);puts("");
}
int main(){
	scanf("%d",&n);
	for(i=0;i+3<1<<n;++i)scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a);
	for(i=1;i<1<<n;++i)if(e[i].empty())z=i;
	if(n==2){if(a>b)swap(a,b);return printf("2\n%d %d\n",a,b),0;}
	FL=0;dfs(e[1].empty()?2:1,0);if(B.empty()){puts("0");return 0;}
	for(i=1;i<1<<n;++i){if(e[i].size()==4){ck(i,2);O();return 0;}if(e[i].size()==2)A.push_back(i);}
	if(A.size()==2)for(int x:A)if(x!=B[0] && x!=B[1]){ck(x,0);O();return 0;}
	ck(B[0],2);ck(B[1],2);O();
	return 0;
}