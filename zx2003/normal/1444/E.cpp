#include<bits/stdc++.h>
using namespace std;
const int N=105;
typedef __int128 lll;
int n,i,j,x,y,dad[N],rk[N],X;
vector<int>e[N];
inline void del(int x,int y){
	e[x].erase(find(e[x].begin(),e[x].end(),y));
	e[y].erase(find(e[y].begin(),e[y].end(),x));
}
lll dfs(int x,int fa){
	dad[x]=fa;
	vector<lll>ve;
	for(int y:e[x])if(y!=fa)ve.push_back(dfs(y,x));if(ve.empty())return 0;
	vector<int>en(ve.size());
	auto ck=[&](lll x){
		auto val=ve;int i,j,mxid;lll mx;
		for(i=N-1;i>=0;--i)if(x>>i&1){
			mx=-(lll(1)<<N);for(j=0;j<ve.size();++j)if(val[j]>mx)mx=val[j],mxid=j;
			en[mxid]=i,val[mxid]-=lll(1)<<i;
		}
		for(j=0;j<ve.size();++j)if(val[j]>=0)return 0;return 1;
	};
	int i;lll z=(lll(1)<<N)-1;
	for(i=N-1;i>=0;--i)if(ck(z-(lll(1)<<i)))
		z-=lll(1)<<i;
	assert(ck(z));
	i=0;for(int y:e[x])if(y!=fa)rk[y]=en[i++];
	lll ret=0;for(i=0;i<ve.size();++i)ret|=ve[i]&(~((lll(1)<<en[i])-1))|lll(1)<<en[i];
	return ret;
}
inline void upd(int x,int y){if(dad[x]==y)swap(x,y);if(!X || rk[y]>rk[X])X=y;}
void gete(int x,int fa){for(int y:e[x])if(y!=fa)gete(y,x),upd(x,y);}
int main(){
	scanf("%d",&n);for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);dfs(1,0);
	for(x=1;!e[x].empty();){
		X=0;gete(x,0);del(X,dad[X]);
		printf("? %d %d\n",X,dad[X]);fflush(stdout);
		scanf("%d",&x);
	}
	printf("! %d\n",x);fflush(stdout);
}