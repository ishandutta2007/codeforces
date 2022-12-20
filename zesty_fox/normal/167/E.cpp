#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N=610;
typedef long long ll;
int n,m,MOD,in[N],out[N],head[N],tot;
ll a[N][N],f[N][N],ans=1;
struct Edge{
	int to,nxt;
}e[N*N*2];
void addedge(int x,int y){
	e[++tot]=(Edge){y,head[x]};
	head[x]=tot;
	out[x]++,in[y]++;
}

ll qpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%MOD;
		x=x*x%MOD;y>>=1;
	}
	return res;
}

void calc(int n){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!a[i][i]&&a[j][i]){
				ans=-ans;
				for(int k=1;k<=n;k++) swap(a[i][k],a[j][k]);
				break;
			}
		}
		ll inv=qpow(a[i][i],MOD-2);
		for(int j=i+1;j<=n;j++){
			ll tmp=a[j][i]*inv%MOD;
			for(int k=i;k<=n;k++) a[j][k]=((a[j][k]-tmp*a[i][k]%MOD)%MOD+MOD)%MOD;
		}
	}
}

vector<int> st,ed;
int vis[N];
void dfs(int x){
	vis[x]=1;
	if(!out[x]) f[x][x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(!vis[y]) dfs(y);
		for(auto j:ed) (f[x][j]+=f[y][j])%=MOD;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&MOD);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!out[i]) ed.push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!in[i]) st.push_back(i),dfs(i);
	}
	for(int i=0;i<st.size();i++){
		for(int j=0;j<ed.size();j++) a[i+1][j+1]=f[st[i]][ed[j]];
	}
	calc(st.size());
	for(int i=1;i<=st.size();i++) (ans*=a[i][i])%=MOD;
	cout<<(ans+MOD)%MOD<<endl;
	return 0;
}