#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=1e5+7;
int n,f[N],go[N],g[N],pre[N],suf[N],pa[N];
vector<int>G[N],vec[N],ans;
void dfs1(int x,int fa){
	go[x]=0,f[x]=1,pa[x]=fa,vec[x].clear();
	for(int y:G[x])if(y^fa)dfs1(y,x),vec[x].push_back(y);
	sort(vec[x].begin(),vec[x].end(),[&](int x,int y){return f[x]>f[y];});
	go[x]=vec[x].empty()?x:go[vec[x][0]];
	for(int i=0;i<(int)vec[x].size();i++)f[x]=max(f[x],f[vec[x][i]]+i);
	f[x]=max(f[x],(int)vec[x].size());
}
void dfs2(int x,int fa){
	vec[x]=G[x],sort(vec[x].begin(),vec[x].end(),[&](int x,int y){return f[x]>f[y];});
	for(int i=1;i<(int)vec[x].size();i++)ans[x-1]=max(ans[x-1],f[vec[x][i]]+i-1);
	ans[x-1]+=f[vec[x][0]],pre[0]=suf[vec[x].size()+1]=0;
	for(int i=0;i<(int)vec[x].size();i++)pre[i+1]=max(pre[i],f[vec[x][i]]+i);
	for(int i=vec[x].size()-1;~i;i--)suf[i+1]=max(suf[i+2],f[vec[x][i]]+i-1);
	for(int i=0;i<(int)vec[x].size();i++)g[vec[x][i]]=max(pre[i],suf[i+2]);
	for(int y:G[x])if(y^fa)f[x]=max({1,g[y],(int)vec[x].size()-1}),dfs2(y,x);
}
int query(int x){cout<<"? "<<x<<endl;return read();}
int dfs3(int x){
	bool fl=0;
	for(int y:vec[x])
		if(y^pa[x]){
			if(!fl){fl=1;continue;}
			int u=query(go[y]);
			if(u^x)return dfs3(u);
		}
	return x;
}
inline void solve(int x){
	dfs1(x,0);int a=0,b=0;
	for(int y:vec[x]){
		int u=query(go[y]);
		if(u^x)(a?b:a)=dfs3(u);
		if(b)break;
	}
	printf("! %d %d\n",a?a:x,b?b:x);
}
int main(){
	n=read(),ans.resize(n);
	if(n==1)cout<<0<<endl,printf("! 1 1\n"),exit(0);
	for(int i=1,x,y;i<n;i++)x=read(),y=read(),G[x].push_back(y),G[y].push_back(x);
	dfs1(1,0),dfs2(1,0),cout<<*max_element(ans.begin(),ans.end())<<endl,solve(read());
	return 0;
}