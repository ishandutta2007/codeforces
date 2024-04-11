#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<24],*ih=ibuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
inline void readstr(char*s){
	for(;isspace(*ih);++ih);
	for(;!isspace(*ih);*s++=*ih++);*s=0;
}
const int N=100005;
int f[22][N],dep[N];
inline int lca(int x,int y){
	int i,d;
	if(dep[x]>dep[y])swap(x,y);d=dep[y]-dep[x];
	for(i=19;i>=0;--i)if(d>>i&1)y=f[i][y];
	if(x==y)return x;
	for(i=19;i>=0;--i)if(f[i][x]!=f[i][y])x=f[i][x],y=f[i][y];
	return f[0][x];
}
inline int ka(int x,int k){
	for(int i=19;i>=0;--i)if(k>>i&1)x=f[i][x];
	return x;
}
vector<pair<int,char> >e[N];
int n,Q,i,u,v;
char s[N][105],fc[N];
void dfs(int u,int fa){
	for(int i=0;i<e[u].size();++i){
		int y=e[u][i].first;if(y==fa)continue;
		dep[y]=dep[u]+1;fc[y]=e[u][i].second;f[0][y]=u;dfs(y,u);
	}
}
char*gg[N];
struct solver{	
	char s[N][105];
	struct kt{
		int x;
		bool operator<(const kt&rhs)const{
			int i=1,y=rhs.x;
			for(;gg[x][i] && gg[y][i] && gg[x][i]==gg[y][i];++i);
			return gg[x][i]<gg[y][i];
		}
	}kt[N];
	int rk[N],xb;
	inline void addstr(char*c){
		++xb;kt[xb].x=xb;;char*p=s[xb]+1;
		for(++c;*c;*p++=*c++);
	}
	bool cmp(char*a,char*b){
		int i=1;
		for(;a[i] && b[i] && a[i]==b[i];++i);
		return	a[i]<b[i];
	}
	inline void ini(){
		int i;//cmp(1,2);
		for(i=1;i<=xb;++i)gg[i]=s[i];
		sort(kt+1,kt+xb+1);
		for(i=1;i<=xb;++i)rk[kt[i].x]=i;
	}
	inline pair<int,int>askbd(char*c){
		pair<int,int>ans;
		int l=1,r=xb,m,i;
		for(;l<r;){
			m=(l+r)>>1;
			if(cmp(s[kt[m].x],c))l=m+1;else r=m;
		}
		for(i=1;c[i] && c[i]==s[kt[l].x][i];++i);
		if(c[i])return make_pair(0,0);ans.first=l;
		for(r=xb;l<r;){
			m=(l+r+1)>>1;
			for(i=1;c[i] && c[i]==s[kt[m].x][i];++i);
			if(!c[i])l=m;else r=m-1;
		}
		ans.second=r;
		return ans;
	}
	int bi[N];
	inline void add(int x,int v){for(x=rk[x];x<=xb;x+=x&-x)bi[x]+=v;}
	inline int query(int x){int ans=0;for(;x;x-=x&-x)ans+=bi[x];return ans;}
	inline int sum(int l,int r){return query(r)-query(l-1);}
}S;//S[0]->up,S[1]->down
struct atom{
	int v,l,r,id;
};
vector<atom>ve[N];
int ans[N];atom g;
void geta(int x,int fa){
	S.add(x,1);
	for(int i=0;i<ve[x].size();++i)
		g=ve[x][i],ans[g.id]+=g.v*S.sum(g.l,g.r);
	for(int i=0;i<e[x].size();++i)if(e[x][i].first!=fa)geta(e[x][i].first,x);
	S.add(x,-1);
}
int main(){
	fread(ibuf,1,1<<24,stdin);
	read(n);
	for(i=1;i<n;++i){
		static char c[5];read(u);read(v);
		readstr(c);
		e[u].push_back(make_pair(v,*c));
		e[v].push_back(make_pair(u,*c));
	}
	dfs(1,0);
	for(i=1;i<20;++i)for(int j=1;j<=n;++j)f[i][j]=f[i-1][f[i-1][j]];
	for(i=1;i<=n;++i){
		static char c[105];
		int j,k=0;
		for(j=i;f[0][j] && k<100;j=f[0][j])c[++k]=fc[j];c[k+1]=0;
		S.addstr(c);
	}
	S.ini();
	read(Q);
	for(i=1;i<=Q;++i){
		read(u);read(v);
		readstr(s[i]+1);
		int w=lca(u,v),l=strlen(s[i]+1),uu,vv;pair<int,int>z;
		if(dep[u]-dep[w]>l){
			uu=ka(u,dep[u]-dep[w]-l);
			z=S.askbd(s[i]);
			if(z.first){
				ve[u].push_back((atom){1,z.first,z.second,i});
				ve[uu].push_back((atom){-1,z.first,z.second,i});
			}
		}else uu=u;
		if(dep[v]-dep[w]>l){
			vv=ka(v,dep[v]-dep[w]-l);
			std::reverse(s[i]+1,s[i]+l+1);
			z=S.askbd(s[i]);
			if(z.first){
				ve[v].push_back((atom){1,z.first,z.second,i});
				ve[vv].push_back((atom){-1,z.first,z.second,i});
			}
			std::reverse(s[i]+1,s[i]+l+1);
		}else vv=v;
		static char c[500];
		int j,k,cl;
		cl=dep[uu]+dep[vv]-dep[w]*2;if(cl<l)continue;
		memcpy(c+1,S.s[uu]+1,dep[uu]-dep[w]);
		memcpy(c+dep[uu]-dep[w]+1,S.s[vv]+1,dep[vv]-dep[w]);
		std::reverse(c+dep[uu]-dep[w]+1,c+cl+1);
		static int nxt[500];
		for(j=2;j<=l;++j){
			for(nxt[j]=nxt[j-1];nxt[j] && s[i][nxt[j]+1]!=s[i][j];nxt[j]=nxt[nxt[j]]);
			nxt[j]+=s[i][nxt[j]+1]==s[i][j];
		}
		for(j=1,k=0;j<=cl;++j){
			for(;k && s[i][k+1]!=c[j];k=nxt[k]);
			k+=s[i][k+1]==c[j];ans[i]+=k==l;
		}
	}
	geta(1,0);
	for(i=1;i<=Q;++i)printf("%d\n",ans[i]);
	return 0;
}