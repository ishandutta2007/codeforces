#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9,M=N*6,f1[4]={1,0,-1,0},f2[4]={0,1,0,-1};
const char fc[9]="DRUL";
struct graph{
	struct edge{int to,next,f;}e[M<<1];
	int h[N],cur[N],xb;
	inline void addedge(int x,int y,int z){
		e[++xb]=(edge){y,h[x],z};h[x]=xb;
		e[++xb]=(edge){x,h[y],0};h[y]=xb;
	}
	int S,T,d[N],n;
	inline bool bfs(){
		static int q[N];int t=0,w=1;q[1]=S;
		memset(d+1,0,n<<2);d[S]=1;
		for(;t<w;){
			int u=q[++t];
			for(int i=h[u];i;i=e[i].next)if(e[i].f && !d[e[i].to])
				d[e[i].to]=d[u]+1,q[++w]=e[i].to;
		}
		return d[T];
	}
	int dfs(int x,int f){
		if(x==T)return f;
		int ans=0,&i=cur[x],t;
		for(;i;i=e[i].next)if(e[i].f && d[e[i].to]==d[x]+1){
			if(t=dfs(e[i].to,min(f,e[i].f))){
				ans+=t,e[i].f-=t;e[i^1].f+=t;f-=t;
				if(!f)break;
			}
		}
		return ans;
	}
	inline int dinic(int s,int t){
		int ans=0;S=s;T=t;
		for(;bfs();ans+=dfs(s,1<<30))
			memcpy(cur+1,h+1,n<<2);
		return ans;
	}
}g;
int T,n,m,i,j,k,x,y;
vector<int>s[N],bo[N],A[N],ee[N];
string B[N];
int main(){
//	freopen("1","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>n>>m;
		for(i=0;i<n;++i){s[i].resize(m);for(int&x:s[i])cin>>x;}
		for(i=0;i<n;++i)for(bo[i].resize(m),memset(&bo[i][0],0,m<<2),j=0;j<m;++j){
			bo[i][j]=1;
			for(k=0;k<4;++k){
				x=i+f1[k];y=j+f2[k];
				if(0<=x && x<n && 0<=y && y<m)bo[i][j]&=s[x][y]>=s[i][j];
			}
		}
		int gs,gt;
		g.n=n*m+3;g.xb=1;gs=g.n-2;gt=g.n-1;memset(g.h+1,0,g.n<<2);
		auto idx=[&](int i,int j){return i*m+j+1;};
		for(i=0;i<n;++i)ee[i].resize(m);
		for(i=0;i<n;++i)for(j=0;j<m;++j)if((i+j)%2==1)for(g.addedge(gs,idx(i,j),1),ee[i][j]=g.xb-1,k=0;k<4;++k){
			x=i+f1[k];y=j+f2[k];
if(idx(i,j)==7)
++i,--i;
			if(0<=x && x<n && 0<=y && y<m && s[x][y]==s[i][j] && (bo[i][j] || bo[x][y]))
				g.addedge(idx(i,j),idx(x,y),1);
		}else g.addedge(idx(i,j),gt,1),ee[i][j]=g.xb-1;
		g.dinic(gs,gt);
		int ss=g.n;
		for(i=0;i<n;++i)for(j=0;j<m;++j)if((i+j)%2==1){
			if(!bo[i][j] && !g.e[ee[i][j]].f)g.addedge(idx(i,j),ss,1);
			if(!bo[i][j])g.e[ee[i][j]].f=0;
		}else{
			if(!bo[i][j] && !g.e[ee[i][j]].f)g.addedge(ss,idx(i,j),1);
			if(!bo[i][j])g.e[ee[i][j]].f=0;
if(i==2 && j==4)
++i,--i;
		}
		g.dinic(gs,ss);
		g.dinic(ss,gt);
		for(i=0;i<n;++i)A[i].resize(m),B[i].resize(m),memset(&A[i][0],0,m<<2);
		for(i=0;i<n;++i)for(j=0;j<m;++j)if((i+j)%2==1){
			for(k=g.h[idx(i,j)];k;k=g.e[k].next)if(!g.e[k].f && g.e[k].to<=n*m)break;if(!k)continue;
			x=(g.e[k].to-1)/m;y=(g.e[k].to-1)%m;
//cout<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
			for(k=0;k<4;++k)if(i+f1[k]==x && j+f2[k]==y)B[i][j]=fc[k],B[x][y]=fc[k^2];
			A[i][j]=1;A[x][y]=s[i][j]-1;
		}
//		for(i=0;i<n;++i)for(j=0;j<m;++j)if(!A[i][j] && bo[i][j])cout<<i<<' '<<j<<endl;
		for(i=0;i<n;++i){
			for(j=0;j<m;++j)if(!A[i][j]){
				for(k=0;k<4;++k){
					x=i+f1[k];y=j+f2[k];
					if(0<=x && x<n && 0<=y && y<m && s[x][y]<s[i][j]){A[i][j]=s[i][j]-s[x][y];B[i][j]=fc[k];break;}
				}
				if(k==4)break;
			}
			if(j<m)break;
		}
		if(j<m)cout<<"NO\n";else{
			cout<<"YES\n";
			for(i=0;i<n;++i)for(j=0;j<m;++j)cout<<A[i][j]<<(j==m-1?'\n':' ');
			for(i=0;i<n;++i)for(j=0;j<m;++j)cout<<B[i][j]<<(j==m-1?'\n':' ');
		}
	}
	return 0;
}