#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n,m,rt,f[M],s[M],a[M],in[M],tp,vis[M],tt[M];
vector<int> v[M];
void dfs(int x,int fa,int tg){
	in[x]=1; s[++tp]=x; vis[x]=1; f[x]=fa; tt[x]=tg;
//	cerr<<" "<<x<<" "<<f[x]<<"\n";
	for (int y:v[x]){
		if (!vis[y]) dfs(y,x,(x==rt ? y : tg));
		else{
			if (!in[y] && tt[x]^tt[y]){
				cout<<"Possible\n";
				cout<<tp+1<<"\n";
				F(i,1,tp) cout<<s[i]<<" "; cout<<y<<"\n";
				int num=0;
				while (y){
					a[++num]=y;
					y=f[y];
				}
				cout<<num<<"\n";
				DF(i,num,1) cout<<a[i]<<" "; cout<<"\n";
				exit(0);
			}
		}
	}
	in[x]=0;
	tp--;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read(); rt=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y);	
	}
	dfs(rt,0,0);
	cout<<"Impossible\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/