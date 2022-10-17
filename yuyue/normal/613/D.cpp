#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
int head[M],to[M],nxt[M],cnt;
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
}
int lg[M],stk[M],tp,dep[M],f[M][20],tt,dfn[M];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1; f[x][0]=fa; dfn[x]=++tt;
	F(i,1,lg[dep[x]]) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa) continue; 
		dfs(y,x);
	}
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	F(i,0,lg[del]) if (del>>i&1) x=f[x][i];
	if (x==y) return x;
	DF(i,lg[dep[x]],0) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
bool ip[M];
int sz[M];
vector<int> v[M];
int dp(int x){
	int ret=0; sz[x]=0;
	F(i,0,SZ(v[x])){
		int y=v[x][i];	
//		cout<<x<<" "<<y<<"   fuck\n";
		int jj=dp(y);
		ret+=jj; sz[x]+=sz[y];
	}
	if (ip[x]) ret+=sz[x],sz[x]=1;
	else if (sz[x]>1) sz[x]=0,ret++;
	v[x].clear();
	return ret;
}
int n,a[M];
int main(){
	n=read(); 
	F(i,2,n) lg[i]=lg[i>>1]+1;
	F(i,1,n-1){
		int x=read(),y=read();
		add(x,y); add(y,x);
	}
	dfs(1,0);
	int Q=read();
	while (Q--){
		int k=read();
		tp=1; stk[1]=1;
		F(i,1,k){
			a[i]=read(); ip[a[i]]=1;
		}
		bool flag=0;
		F(i,1,k) 
		if (ip[f[a[i]][0]]) {
//			cout<<a[i]<<" "<<f[a[i]][0]<<"\n";
			cout<<"-1\n";
			flag=1; break;
		}
		if (flag) {
			F(i,1,k) ip[a[i]]=0;
			continue;
		}
		sort(a+1,a+k+1,cmp);
		F(i,1,k){
			int x=a[i],p=lca(stk[tp],x);
			while (dep[p]<dep[stk[tp]]){
				if (dep[p]>=dep[stk[tp-1]]){
					v[p].pb(stk[tp--]);
					if (stk[tp]^p) stk[++tp]=p;
					break;
				}
				v[stk[tp-1]].pb(stk[tp]); tp--;
			}
			if (x^stk[tp]) stk[++tp]=x;
		}
		while (tp>1) v[stk[tp-1]].pb(stk[tp]),tp--;
		cout<<dp(1)<<"\n";
		F(i,1,k) ip[a[i]]=0;
	}
    return 0;
}