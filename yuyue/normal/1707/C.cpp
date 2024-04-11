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
int n,m,ff[M];
int Fd(int x){
	return ff[x]==x ? x : ff[x]=Fd(ff[x]);
}
vector<int> v[M];
int head[M],depth[M],f[M][23],cnt,lg[M],dm,fa[M];
void dfs(int x,int dep)
{
    dm=max(dep,dm);
    depth[x]=dep; 
    for (register int i=1;(1<<i)<=dep;i++)
    {
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for (int y:v[x])
    {
    	
        if (!depth[y]) 
        {
        	fa[y]=x;
            f[y][0]=x;
            dfs(y,dep+1);
        }
    }
}
int Lca(int x,int y)
{
    if (depth[x]<depth[y]) swap(x,y);
    while(depth[x]>depth[y])
    x=f[x][lg[depth[x]-depth[y]]-1];
    if (x==y) return x;
    //cout<<x<<" "<<y<<endl;
    //cout<<"!  ";
    for (register int i=lg[depth[x]];i>=0;i--)
    {
        if (f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int jp(int x,int y){
	DF(i,20,0 ) if (y>>i&1) x=f[x][i];
	return x;
}
int d[M];
void dfs1(int x,int fa){
	for (int y:v[x]){
		if (y^fa){
			d[y]+=d[x];
			dfs1(y,x);
		}
	}
}
int X[M],Y[M];
bool used[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read();
	F(i,1,n) ff[i]=i;
	F(i,1,m){
		int x=read(),y=read();	
		if (Fd(x)^Fd(y)){
			used[i]=1;
			ff[Fd(x)]=Fd(y);
			v[x].pb(y);
			v[y].pb(x);
		}
		X[i]=x; Y[i]=y;
	}
	for (register int i=1;i<=n;i++)
    lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(1,1);
	F(i,1,m){
		if (!used[i]){
			int la=Lca(X[i],Y[i]);
			if (la==X[i] || la==Y[i]){
				if (la==Y[i]) swap(X[i],Y[i]);
				d[Y[i]]--; d[jp(Y[i],depth[Y[i]]-depth[X[i]]-1)]++;
			}
			else{
				d[1]++; d[X[i]]--; d[Y[i]]--;
			}
////			d[X[i]]++; d[Y[i]]++;
//			d[la]--; d[fa[la]]--;
//			d[fa[X[i]]]++; d[fa[Y[i]]]++;
		}
	}
	dfs1(1,0);
	F(i,1,n) cout<<(d[i]==0);
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/