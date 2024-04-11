#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
int n,m,ot[M];
vector<int> v[M],g[M]; 
LL dis[M];
bool vis[M];
#define pii pair<LL,int> 
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[y].pb(x);
		g[x].pb(y);
		ot[x]++;
	}
	ms(dis,60);
	dis[n]=0; q.push(mp(0,n));
	while (q.size()){
		int x=q.top().second;  q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int y:v[x]){
			ot[y]--;
			if (ot[y]+dis[x]+1<dis[y]){
				dis[y]=dis[x]+1+ot[y];
				q.push(mp(dis[y],y));
			}
		}
	}
	cout<<dis[1]<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/