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
const int M=1505,mod=998244353; 
#define pii pair<int,int>
#define mp make_pair
vector<pii> v[M*M/2];
int n,a[M][M],f[M*2],dp[M*2][M],son[M*2][2],tt[M*2],sz[M*2];
void dfs(int x){
	if (tt[x]==(sz[x]-1)*sz[x]/2) {
//		cout<<x<<" "<<sz[x]<<"  dp ++ \n";
		dp[x][1]=1;
	}
	if (x<=n){
		return;
	}
	int ls=son[x][0],rs=son[x][1];
	dfs(ls); dfs(rs);
	F(i,1,sz[ls]){
		F(j,1,sz[rs]){
			dp[x][i+j]=(dp[x][i+j]+1ll*dp[ls][i]*dp[rs][j])%mod;
		}
	}
}
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
int main(){
	n=read(); 
	F(i,1,n){
		F(j,1,n){
			a[i][j]=read();
			if (i<j) v[a[i][j]].pb(mp(i,j));
		}
	}
	int num=n;
	F(i,1,n*2){
		f[i]=i;
		sz[i]=1;
	}
	int lim=(n-1)*n/2,rt=0;
	F(i,1,lim){
		F(j,0,SZ(v[i])){
			int x=v[i][j].first,y=v[i][j].second;
			x=Fd(x); y=Fd(y);
			if (x^y){
				++num; 
				f[x]=f[y]=num;
				sz[num]=sz[x]+sz[y]; 
				tt[num]=tt[x]+tt[y]+1;
				son[num][0]=x;
				son[num][1]=y;
				rt=num; 
			}
			else{
				tt[x]++;
			}
		}
	}
//	cout<<rt<<"\n";
	dfs(rt); 
	F(i,1,n) cout<<dp[rt][i]<<' ';
	cout<<"\n";
	return 0;
}