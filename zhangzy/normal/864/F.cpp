#include<bits/stdc++.h>
using namespace std;

int n,m,q,d[3010],fa[3010][20],used[3010],pre[3010];
vector<int>r[3010];
int ans[2333333];
struct Q{
	int who,dis,id;
}tmp;
vector<Q>vec[3010];

int dfs(int x,int dep,int died){
	d[x]=dep;
	for (int i=1;i<=18;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	if (died) used[x]=-2;
	int t,pre=0;
	for (auto y:r[x]){
		if (!d[y]){
			fa[y][0]=x;
			t=dfs(y,dep+1,died);
			if (t!=y&&t){
				died=1;
				pre=(d[t]<d[pre]||pre==0)? t: pre;
			}
		}else{
			if (used[y]) continue;
			died=1;
			pre=(d[y]<d[pre]||pre==0)? y: pre;
		}
	}
	used[x]++;
	return pre;
}

int gofa(int x,int y){
	for (int t=0;y;y>>=1,t++) if (y&1) x=fa[x][t];
	return x;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	int x,y,z;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		r[x].push_back(y);
	}
	for (int i=1;i<=n;i++) sort(r[i].begin(),r[i].end());
	for (int i=1;i<=q;i++){
		scanf("%d%d%d",&x,&y,&z);
		vec[x].push_back((Q){y,z,i});
	}
	for (int i=1;i<=n;i++){
		memset(d,0,sizeof d);
		memset(used,0,sizeof used);
		memset(fa,0,sizeof fa);
		dfs(i,1,0);
		for (int j=0;j<(int)vec[i].size();j++){
			tmp=vec[i][j];
			if (used[tmp.who]<1||d[tmp.who]<tmp.dis) ans[tmp.id]=-1;
			else ans[tmp.id]=gofa(tmp.who,d[tmp.who]-tmp.dis);
		}
	}
	for (int i=1;i<=q;printf("%d\n",ans[i++]));
}