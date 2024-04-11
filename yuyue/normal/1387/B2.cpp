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
const int M=1e5+10;
int n,sz[M],rt,mx[M];
vector<int> v[M];
void gr(int x,int fa){
	sz[x]=1; mx[x]=0;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue;
		gr(y,x);
		sz[x]+=sz[y];
		mx[x]=max(mx[x],sz[y]); 
	}
	mx[x]=max(mx[x],n-sz[x]);
	if (mx[rt]>mx[x]) rt=x;
}
int wn[M],tot;
int dep[M],p[M];
LL ans=0;
void dfs(int x,int fa){
	wn[tot++]=x;
	ans+=2*dep[x];
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue;
		dep[y]=dep[x]+1;
		dfs(y,x);
	}
}
int main(){
	n=read();
	F(i,1,n-1){
		int x=read(),y=read();
		 v[x].pb(y); v[y].pb(x);
	}
	mx[0]=1e9;
	gr(1,0);
	dfs(rt,0); 
	cout<<ans<<"\n";
	F(i,0,n-1){
		p[wn[i]]=wn[(i+n/2)%n];
	}
	F(i,1,n){
		cout<<p[i]<<" ";
	}
	cout<<"\n";
	return 0; 
}