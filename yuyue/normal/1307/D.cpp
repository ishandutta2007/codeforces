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
int dis[2][M],q[M],inf;
vector<int> v[M];
void bfs(int S,int op){
	ms(dis[op],1); inf=dis[op][0];
	dis[op][S]=0;
	int l=1,r=0; q[++r]=S;
	while (l<=r){
		int x=q[l++];
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			if (dis[op][y]==inf && y!=S) dis[op][y]=dis[op][x]+1,q[++r]=y;
		}
	}
}
bool cmp(int A,int B){
	return dis[0][A]-dis[1][A]<dis[0][B]-dis[1][B];
}
int n,m,k;
int t[M];
int main(){
//	freopen("in.txt","r",stdin);
	n=read(); m=read(); k=read();
	F(i,1,k) t[i]=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	bfs(1,0); bfs(n,1);
	int old=dis[0][n];
	sort(t+1,t+k+1,cmp);
	int mx=dis[0][t[1]],ans=0;
	F(i,2,k){
		ans=max(ans,dis[1][t[i]]+1+mx);
		mx=max(mx,dis[0][t[i]]);
	}
	cout<<min(ans,old)<<"\n";
	return 0;
}