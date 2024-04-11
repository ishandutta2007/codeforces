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
const int M=3e5+10;
#define pii pair<int,int>
#define mp make_pair
int dfn[M],low[M],sta[M],tp,tim,scc,bl[M];
LL dep[M],h[M];
bool in[M];
vector<pii> v[M];
LL d;
LL gcd(LL x,LL y){
	return (!y ? x : gcd(y,x%y));
}
inline void dfs(int x,LL depth){
	dep[x]=depth;
	for (auto O:v[x]){
		int y=O.first,len=O.second;
		if (bl[y]!=bl[x]) continue;
		if (!dep[y]) dfs(y,depth+len);
		else {
//			cerr<<x<<" "<<y<<" "<<abs(dep[y]-dep[x])<<" "<<len<<"   dfs\n";
			d=gcd(d,abs(dep[y]-dep[x]-len));	
		}
	}
}                                                   	
int sz[M];
void tarjan(int x){
	dfn[x]=low[x]=++tim;
	in[x]=1; sta[++tp]=x;
	for (auto O:v[x]){
		int y=O.first;
		if (!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (in[y]) low[x]=min(low[x],dfn[y]);
	}	
	if (dfn[x]==low[x]){
		scc++; int now=0;
		while (now!=x){
			now=sta[tp--];
			bl[now]=scc;
			in[now]=0;
			sz[scc]++;
		}
		d=0;
		dfs(x,1);
		h[scc]=d;
	}	
//	cerr<<x<<" "<<dfn[x]<<" "<<low[x]<<" "<<scc<<"\n";

}
int n,m;
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read(),z=read();
		v[x].pb(mp(y,z));
	}
	F(i,1,n){
		if (!dfn[i]) tarjan(i);
	}
	int Q=read();
	while (Q--){
		int x=read(),y=read(),z=read();
		int res=(z-y)%z;
		LL dd=gcd((LL)z,h[bl[x]]);
		if (res%dd==0) puts("YES");
		else puts("NO");
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