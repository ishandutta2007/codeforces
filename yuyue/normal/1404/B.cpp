#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read() {
	char ch=getchar();
	int w=1,c=0;
	for(; !isdigit(ch); ch=getchar()) if (ch=='-') w=-1;
	for(; isdigit(ch); ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
vector<int> v[M];
int d,dp[M],dep[M];
void dfs(int x,int fa) {
	dp[x]=0;
	dep[x]=dep[fa]+1;
	F(i,0,SZ(v[x])) {
		int y=v[x][i];
		if (y==fa) continue;
		dfs(y,x);
		d=max(dp[x]+dp[y]+1,d);
		dp[x]=max(dp[x],dp[y]+1);
	}
}
int n,da,db,a,b;
void work() {
	n=read();a=read();b=read();da=read();db=read();
	F(i,1,n) v[i].clear();
	F(i,1,n-1) {
		int x=read(),y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	d=0;
	dfs(a,0);
//	cout<<d<<"\n"; 
	if (dep[b]-1<=da) {
		cout<<"Alice\n";
		return ;
	}
	if (da>=(d+1)/2) {
		cout<<"Alice\n";
		return;
	}
	if (db>2*da) {
		cout<<"Bob\n";
	} else cout<<"Alice\n";
}
int main() {
	int T=read();
	while (T--) work();
	return 0;
}