#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n;
vector<int> v[M];
int dfn[M],wn[M],f[M],tot,dp[M];
void dfs(int x,int fa){
	f[x]=fa;
	dfn[x]=++tot; wn[tot]=x;
	for (int y:v[x]){
		if (y^fa){
			dfs(y,x);
		}
	}
}
int suan(int k){
	int ret=0;
	DF(i,n,1){
		int x=wn[i];
		dp[x]=0;
		for (int y:v[x]){
			if (y!=f[x]){
				if (dp[y]+1+dp[x]>=k){
					dp[x]=-1;
					ret++;
					break;
				}
				dp[x]=max(dp[x],dp[y]+1);
			}
		}
	}
	return ret;
}
int ans[M];
void solve(int l,int r,int ll,int rr){
	if (l>r) return ;
	if (ll==rr){
		F(i,l,r){
			ans[i]=ll;
		}
		return ;
	}
	int mid=(l+r>>1);
	int res=suan(mid);
	ans[mid]=res;
	solve(l,mid-1,res,rr);
	solve(mid+1,r,ll,res);
}
int main(){
	n=read();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	solve(1,n-1,0,n);
	ans[0]=n;
	F(i,0,n-1){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/