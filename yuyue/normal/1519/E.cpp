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
#define pii pair<LL,LL>
#define mp(x,y) make_pair(x/__gcd(x,y),y/__gcd(x,y))
map<pii,int> hs;
const int M=5e5+10;
int to[M],head[M],w[M],nxt[M],cnt;
void add(int x,int y,int z){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=z;
}
vector<int> ax,ay;
bool vis[M],in[M];
int dfs(int x){
	int now=-1; vis[x]=1; in[x]=1;
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i],z=w[i];
		if (!vis[y]){
			int tmp=dfs(y);
			if (tmp!=-1) ax.pb(z),ay.pb(tmp);
			else{
				if (now!=-1) ax.pb(now),ay.pb(z),now=-1;
				else now=z;
			}
		}
		else{
			if (!in[y]){
				if (now!=-1) ax.pb(now),ay.pb(z),now=-1;
				else now=z;
			}
		}
	}
	in[x]=0;
	return now;
}
int n,tot;
int main(){
	n=read();
	F(i,1,n){
		LL x=read(),y=read(),p=read(),q=read();
		pii A=mp(p*y,q*(x+y)),B=mp((p+q)*y,x*q);
		if (!hs.count(A)) hs[A]=++tot;
		if (!hs.count(B)) hs[B]=++tot;
		int u=hs[A],v=hs[B];
		add(u,v,i);
		add(v,u,i);
	}
	F(i,1,tot){
		if (!vis[i]) dfs(i);
	}
	cout<<ax.size()<<"\n";
	F(i,0,SZ(ax)){
		cout<<ax[i]<<" "<<ay[i]<<"\n";
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