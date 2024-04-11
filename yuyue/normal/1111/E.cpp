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
const int M=2e5+10,mod=1e9+7;
int head[M],to[M],nxt[M],cnt,son[M],sz[M],dep[M],f[M],baba[M];
void add(int x,int y){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt;
}
void dfs(int x,int fa){
	sz[x]=1; dep[x]=dep[fa]+1; baba[x]=fa;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa) continue;
		dfs(y,x); sz[x]+=sz[y];
		if (sz[son[x]]<sz[y]) son[x]=y; 
	}
}
int tot,dfn[M],tp[M];
void dfs1(int x,int fa,int fp){
	dfn[x]=++tot; tp[x]=fp; //cout<<x<<" "<<son[x]<<" "<<fp<<"    ggggg\n";
	if (son[x]) dfs1(son[x],x,fp);
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==son[x] || y==fa) continue;
		dfs1(y,x,y); 
	}
}
#define lowbit(x) (x&-x)
int d[M],n,q;
void Add(int x){
	for (;x<=n;x+=lowbit(x)) d[x]++;
}
void Del(int x){
	for (;x<=n;x+=lowbit(x)) d[x]--;
}
int s(int x){
	int ret=0;
	for (;x;x-=lowbit(x)) ret+=d[x]; 
	return ret;
}
int sum(int l,int r){
	return s(r)-s(l-1);
}
int qry(int x,int y){
	int ret=0;
	while (tp[x]!=tp[y]){
//		cout<<x<<" "<<y<<" "<<f[x]<<" "<<f[y]<<"    ghgh\n";
		if (dep[tp[x]]<dep[tp[y]]) swap(x,y);
		ret+=sum(dfn[tp[x]],dfn[x]);
		x=baba[tp[x]];
	}
	if (dep[x]>dep[y]) swap(x,y);
	ret+=sum(dfn[x],dfn[y]);
	return ret;
}
int dp[M][303],a[M];
bool cmp(int x,int y){
	return f[x]<f[y];
}
int main(){
	n=read(); q=read();
	F(i,1,n-1){
		int x=read(),y=read();
		add(x,y); add(y,x); 
	}
	dfs(1,0); dfs1(1,0,1);
//	F(i,1,n) cout<<tp[i]<<"   fuck\n";
	while (q--){
		int k=read(),m=read(),r=read();
		F(i,1,k) a[i]=read(),Add(dfn[a[i]]);
		F(i,1,k) f[a[i]]=qry(a[i],r)-1;//,cout<<a[i]<<" "<<r<<" "<<f[a[i]]<<"    gg\n";
		sort(a+1,a+k+1,cmp);
		dp[0][0]=1; 
		F(i,1,k){
			F(j,1,m){
				dp[i][j]=(1ll*max(j-f[a[i]],0)*dp[i-1][j]+dp[i-1][j-1])%mod;
			}
		}
		int ans=0; 
		F(i,1,m) ans=(ans+dp[k][i])%mod;
		F(i,1,k) Del(dfn[a[i]]);
		cout<<ans<<"\n";
	}
    return 0;
}