#include<bits/stdc++.h>
using namespace std;
inline void upa(int&a,const int&b){a<b?a=b:0;}
const int N=5e5+5;
typedef vector<int>V;
int n,u,v,i,ans[N],len[N],ud[N],mll;
V e[N],ee[N];
int a1[N],a2[N];
bool cmp(int x,int y){return len[x]>len[y];}
void dfs1(int x,int fa){
	if(fa)e[x].erase(find(e[x].begin(),e[x].end(),fa));
	for(int y:e[x])dfs1(y,x),upa(len[x],len[y]+1);
	sort(e[x].begin(),e[x].end(),cmp);
	for(int i=0;i+1<e[x].size();++i)upa(mll,len[e[x][i]]+len[e[x][i+1]]+2);
	upa(mll,len[x]);
}
void dfs2(int x){
	if(e[x].empty())return;
	if(e[x].size()>1)ud[e[x][0]]=max(ud[x]+1,len[e[x][1]]+2);
		else ud[e[x][0]]=ud[x]+1;
	dfs2(e[x][0]);
	for(int i=1;i<e[x].size();++i)ud[e[x][i]]=max(ud[x]+1,len[e[x][0]]+2),dfs2(e[x][i]);
	ee[x]=e[x];for(int&z:ee[x])z=len[z]+1;if(x>1)ee[x].push_back(ud[x]);
}
void work1(V&v){
	sort(v.begin(),v.end(),greater<int>());
	int i,j;
	for(i=2;i<v.size();++i)upa(a1[v[i]*2],i+1);
	for(i=0;i<v.size() && v[i]==v[0];++i);
	for(j=0;i<v.size();++i){
		for(;j<v.size() && v[j]>v[i];++j);
		upa(a1[v[i]*2+1],j+1);
	}
}
int cnt[N];
void work2(int x){
	int i,j,mx=0;
	vector<pair<int,int>>ve;
	for(i=0;i<e[x].size();++i)for(int z:e[e[x][i]])ve.push_back({len[z]+1,i});
	memset(cnt,0,i<<2);
	sort(ve.begin(),ve.end(),greater<pair<int,int>>());
	for(i=j=0;i<ee[x].size();++i){
		for(;j<ve.size() && ve[j].first>=ee[x][i];++j){
			int t=++cnt[ve[j].second];
//			upa(a2[ve[j].first*2+1],i+t-1);
			upa(mx,t);
		}
		upa(a2[ee[x][i]*2],i+mx);
	}
	memset(cnt,0,e[x].size()<<2);
	for(i=j=0;i<ve.size();++i){
		for(;j<ee[x].size() && ee[x][j]>=ve[i].first;++j);
		int t=++cnt[ve[i].second];
		upa(a2[ve[i].first*2],j+t-1);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	for(i=1;i<=n;++i)upa(ans[1],e[i].size()+1);
	dfs1(1,0);
	dfs2(1);
	for(i=1;i<=n;++i){
		work1(ee[i]);
		work2(i);
	}
	upa(a1[n],1);
	for(i=n;i;--i)upa(a1[i],a1[i+1]);
	for(i=n&1?n-1:n;i>0;i-=2)upa(a2[i],a2[i+2]);
	for(i=1;i<=n;++i)upa(ans[i],max(a1[i],a2[i]));
	for(i=1;i<=mll;++i)upa(ans[i],2);
	for(i=1;i<=n;++i)printf("%d ",ans[i]);puts("");
	return 0;
}