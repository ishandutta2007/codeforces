#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=103;
int pa[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
int n,bel[N][N],d[N];
bool flg[N][N][N],vis[N];
char str[N];
vector<vector<int> >vec[N];
vector<int>G[N];
int cnt;
inline void add_e(int x,int y){
	G[x].push_back(y),G[y].push_back(x);
}
bool ok;
void dfs(int x,int fa){
	cnt++,vis[x]=1;
	int i=bel[x][fa];
	for(int y:vec[x][i])
		if(y^fa){
			if(vis[y]){ok=0;return;}
			add_e(x,y),dfs(y,x);
			if(!ok)break;
		}
}
void dfs1(int x,int fa){
	d[x]=d[fa]+1;
	for(int y:G[x])if(y^fa)dfs1(y,x);	
}
inline void work(){
	n=read();
	ok=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			scanf("%s",str+1);
			for(int k=1;k<=n;k++){
				flg[i][j][k]=str[k]&1;
				if(i==k || j==k)ok&=!flg[i][j][k];
			}
		}
	if(!ok){puts("No");return;}
		//cerr<<"qwq"<<endl;
	for(int i=1;i<=n;i++){
		vec[i].clear();
		iota(pa+1,pa+n+1,1);
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(flg[j][k][i])pa[find(k)]=find(j);
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(flg[j][k][i]!=(find(j)==find(k))){puts("No");return;}
				//cout<<flg[1][2][1]<<endl;
		int tot=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			//cerr<<i<<" "<<j<<" "<<find(j)<<endl;
			if(find(j)==j)vec[i].push_back({j}),bel[i][j]=tot++;
			else vec[i][bel[i][j]=bel[i][find(j)]].push_back(j);
		}
	}
	//cerr<<1<<endl;
	for(int i=0;i<(int)vec[1].size();i++){
		for(int x=1;x<=n;x++)G[x].clear(),vis[x]=0;
		cnt=1,ok=1,vis[1]=1;
		//cerr<<i<<" "<<vec[1].size()<<endl;
		for(int x:vec[1][i])
			add_e(1,x),dfs(x,1);
		//cerr<<cnt<<" "<<ok<<endl;
		if(cnt<n || !ok)continue;
		for(int x=1;x<=n && ok;x++){
			dfs1(x,0);
			for(int j=0;ok && j<(int)vec[x].size();j++)
				for(int k=1;k<(int)vec[x][j].size();k++)
					if(d[vec[x][j][k-1]]!=d[vec[x][j][k]]){ok=0;break;}
		}
		if(ok){
			puts("Yes");
			for(int x=1;x<=n;x++)
				for(int y:G[x])
					if(x<y)printf("%d %d\n",x,y);
				//cerr<<endl;
			return;
		}
	}
	puts("No");
					//cerr<<endl;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}