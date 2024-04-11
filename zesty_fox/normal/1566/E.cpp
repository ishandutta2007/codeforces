#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=400010;
struct Edge{int to,nxt;}e[N<<1];
int n,head[N],tot;

void addedge(int x,int y){
	e[++tot]=(Edge){y,head[x]};
	head[x]=tot;
}

int dep[N],isleaf[N],son[N],f[N],cnt[N],ans,siz[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1,f[x]=fa,siz[x]=1,cnt[x]=isleaf[x]=son[x]=0;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		dfs(y,x);
		cnt[x]+=isleaf[y];
		siz[x]+=siz[y];
		son[x]++;
	}
	if(siz[x]==1) isleaf[x]=1,ans++;
}

priority_queue<pii> q;
int vis[N],val[N],minx;

void clear(){
	tot=ans=0,minx=1e9;
	for(int i=1;i<=n;i++) head[i]=vis[i]=dep[i]=f[i]=siz[i]=cnt[i]=isleaf[i]=son[i]=val[i]=0;
}

void dfs2(int x,int sum){
	if(isleaf[x]){
		minx=min(minx,sum);
		return;
	}
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==f[x]) continue;
		dfs2(y,sum+val[x]);
	}
}

void solve(){
	n=rdi();clear();
	for(int i=1;i<n;i++){
		int x=rdi(),y=rdi();
		addedge(x,y);addedge(y,x);
	}
	dfs(1,0);
	for(int x=2;x<=n;x++){
		bool flg=1;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(y==f[x]) continue;
			if(!isleaf[y]) {flg=0;break;}
		}
		if(!son[x]) flg=0;
		if(flg) q.push(mp(dep[x],x)),vis[x]=1;
	}
	while(!q.empty()){
		int x=q.top().se;q.pop();
		if(son[f[x]]>1) ans--,val[x]=1;
		son[f[x]]--;
		if(f[x]!=1&&!vis[f[x]]&&son[f[x]]&&son[f[x]]==cnt[f[x]]){
			vis[f[x]]=1;
			q.push(mp(dep[f[x]],f[x]));
		}
		if(f[f[x]]){
			int gf=f[f[x]];
			if(!son[f[x]]) cnt[gf]++;
			if(gf!=1&&!vis[gf]&&son[gf]&&son[gf]==cnt[gf]){
				vis[gf]=1;
				q.push(mp(dep[gf],gf));
			}
		}
	}
	dfs2(1,0);ans+=minx;
	printf("%d\n",ans);
}

int T;
int main(){
	T=rdi();
	while(T--) solve();
    return 0;
}