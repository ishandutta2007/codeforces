/*
	Author: zxy_hhhh
	date: 2019/12/15
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#define ll long long
inline ll rd() {
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 3005
#define inf 10000000000000000
int n,m,T;
int w[maxn],b[maxn],a[maxn];
std::vector<int> G[maxn];
int sz[maxn];
std::pair<int,ll> dp[maxn][maxn],tmp[maxn];
std::pair<int,ll> operator + (std::pair<int,ll> A,std::pair<int,ll> B) {
	return std::make_pair(A.first+B.first,A.second+B.second);
}
void dfs(int u,int fa) {
	sz[u]=0;
	dp[u][0]=std::make_pair(0,0);
	for(auto i:G[u]) if (i!=fa) {
		dfs(i,u);
		for(int j=0;j<=sz[u]+sz[i];j++) 
			tmp[j]=std::make_pair(0,-inf);
		for(int j=0;j<=sz[u];j++) {
			for(int k=0;k<=sz[i];k++) {
				tmp[j+k]=std::max(tmp[j+k],dp[u][j]+dp[i][k]);
			}
		}
		sz[u]+=sz[i];
		for(int j=0;j<=sz[u];j++) dp[u][j]=tmp[j];
	}
	if (sz[u]==0) {
		sz[u]=1;
		dp[u][0]=std::make_pair(0,a[u]);
		dp[u][1]=std::make_pair(a[u]>0,0);
		return ;
	}
	for(int i=0;i<=sz[u];i++) {
		dp[u][i].second+=a[u];
	}
	sz[u]++;dp[u][sz[u]]=std::make_pair(0,-inf);
	if (u==1) {
		for(int i=sz[u]-1;i>=0;i--) {
			if (dp[u][i].second>0) {
				dp[u][i+1]=std::make_pair(dp[u][i].first+1,0ll);
			}
			else {
				dp[u][i+1]=std::make_pair(dp[u][i].first,0ll);
			}
		}
		return ;
	}
	for(int i=sz[u]-1;i>=0;i--) {
		if (dp[u][i].second>0) {
			dp[u][i+1]=std::max(dp[u][i+1],std::make_pair(dp[u][i].first+1,0ll));
		}
		else {
			dp[u][i+1]=std::max(dp[u][i+1],std::make_pair(dp[u][i].first,0ll));
		}
	}
}
int main() {
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	T=rd();
	while(T--) {
		n=rd(),m=rd();
		for(int i=1;i<=n;i++) w[i]=rd();
		for(int i=1;i<=n;i++) b[i]=rd();
		for(int i=1;i<=n;i++) a[i]=b[i]-w[i];
		for(int i=2;i<=n;i++) {
			int x=rd(),y=rd();
			G[x].push_back(y),G[y].push_back(x);
		}
		dfs(1,1);
		wrt(dp[1][m].first,'\n');
		for(int i=1;i<=n;i++) G[i].clear();
	}

}