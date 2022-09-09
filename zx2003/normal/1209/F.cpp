#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=13e5,mo=1e9+7;
typedef pair<int,int>pii;
int ff[M][20],dep[M],ch[M][10],fc[M],xb,h[M];
inline bool query(int x,int y){
	if(x==y)return 0;
	if(dep[x]>dep[y])return 0;if(dep[x]<dep[y])return 1;
	for(int i=19;i>=0;--i)if(ff[x][i]!=ff[y][i])x=ff[x][i],y=ff[y][i];
	return fc[x]<fc[y];
}
inline int ins(int x,int*p){
	for(int i=1;i<=*p;++i){
		if(!ch[x][p[i]]){
			int y=ch[x][p[i]]=++xb;
			fc[y]=p[i];dep[y]=dep[x]+1;ff[y][0]=x;
			for(int j=1;j<20;++j)ff[y][j]=ff[ff[y][j-1]][j-1];
		}
		x=ch[x][p[i]];
	}
	return x;
}
void dfs(int u){
	for(int i=0;i<10;++i)if(ch[u][i])h[ch[u][i]]=(10ll*h[u]+i)%mo,dfs(ch[u][i]);
}
int n,m,x,y,i,j,c[N][9],id[N];
vector<pii>e[N];
struct cmp{
	inline bool operator()(const pii&a,const pii&b)const{
		return query(b.second,a.second);
	}
};
priority_queue<pii,vector<pii>,cmp>q;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		e[x].push_back(pii(y,i));
		e[y].push_back(pii(x,i));
		for(j=i;j;j/=10)c[i][++*c[i]]=j%10;
		reverse(c[i]+1,c[i]+*c[i]+1);
	}
	memset(id+1,-1,n<<2);
	id[1]=0;q.push(pii(1,0));
	for(;!q.empty();){
		pii u=q.top();q.pop();if(u.second!=id[x=u.first])continue;
		for(pii z:e[x]){
			int p=ins(id[x],c[z.second]);y=z.first;
			if(id[y]==-1 || query(p,id[y]))q.push(pii(y,id[y]=p));
		}
	}
	dfs(0);
	for(i=2;i<=n;++i)printf("%d\n",h[id[i]]);
	return 0;
}