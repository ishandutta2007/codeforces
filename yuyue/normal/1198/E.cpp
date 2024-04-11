#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define int LL
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=500000;
int tx[M],ty[M],cx,cy,X0[M],X1[M],Y0[M],Y1[M];
int n,m,S,T;
int head[M],w[M],to[M],nxt[M],cnt;
void add(int x,int y,int v){
	nxt[++cnt]=head[x]; head[x]=cnt; to[cnt]=y; w[cnt]=v;
}
void addedge(int x,int y,int v){
//	cout<<x<<" "<<y<<" "<<v<<"  FUCK\n";
	add(x,y,v); add(y,x,0);
}
int q[M],dep[M];
bool bfs(){
	int l=1,r=1; q[1]=S;
	ms(dep,0); dep[S]=1;
	while (l<=r){
		int x=q[l++];
//		cout<<x<<"\n";system("pause");
		for (int i=head[x];~i;i=nxt[i]){
			int y=to[i];
//			cout<<i<<" "<<to[i]<<" "<<w[i]<<"\n";	

			if (!dep[y] && w[i]){
				dep[y]=dep[x]+1;
				q[++r]=y;
			}
		}
	}
	return dep[T];
}
int dfs(int x,int flow){
	if (x==T || !flow) return flow;
	int use=0;
	for (int i=head[x];~i;i=nxt[i]){
		int y=to[i];
		if (dep[y]==dep[x]+1 && w[i]){
			int ff=dfs(y,min(w[i],flow));
			flow-=ff;
			use+=ff;
			w[i]-=ff; 
			w[i^1]+=ff;
		}
	}
	return use;
}
signed main(){
	n=read(); m=read(); cnt=1; S=0; ms(head,-1);
	F(i,1,m){
		X0[i]=tx[++cx]=read(); Y0[i]=ty[++cy]=read();
		X1[i]=tx[++cx]=read()+1; Y1[i]=ty[++cy]=read()+1;
	}
	sort(tx+1,tx+cx+1); sort(ty+1,ty+cy+1);
	int nx=unique(tx+1,tx+cx+1)-tx-1;
	int ny=unique(ty+1,ty+cy+1)-ty-1;
	T=nx+ny+1;
	F(i,2,nx){
		addedge(S,i,tx[i]-tx[i-1]);
	}
	F(i,2,ny){
		addedge(nx+i,T,ty[i]-ty[i-1]);
	}
	F(i,1,m){
		X0[i]=lower_bound(tx+1,tx+nx+1,X0[i])-tx;
		X1[i]=lower_bound(tx+1,tx+nx+1,X1[i])-tx;
		Y0[i]=lower_bound(ty+1,ty+ny+1,Y0[i])-ty;
		Y1[i]=lower_bound(ty+1,ty+ny+1,Y1[i])-ty;
		F(j,X0[i]+1,X1[i]){
			F(k,Y0[i]+1,Y1[i]){
				addedge(j,k+nx,2e9);
			}
		}
	}
//	cout<<to[head[0]]<<"\n";
//	cout<<1;
	int ans=0;
	while (bfs()) ans+=dfs(S,2e9);
	cout<<ans<<"\n";
	return 0;
}