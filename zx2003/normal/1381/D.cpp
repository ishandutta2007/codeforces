#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,A,B,i,x,y,L;
vector<int>e[N],P;
bool b0[N],b1[N],b[2][N];
int dad[N],len[N];
void dfs1(int x,int fa){
	dad[x]=fa;
	for(int y:e[x])if(y!=fa)dfs1(y,x);
}
int md[N];
void dfs2(int x,int fa){
	md[x]=0;
	int cnt=0;
	for(int y:e[x])if(y!=fa){
		dfs2(y,x);
		md[x]=max(md[x],md[y]+1);
		cnt+=md[y]+1>=L-1;
	}
	b0[i]|=cnt>0;b1[i]|=cnt>1;
}
void solve(int o){
	auto setv=[&](int oo,int i){
		if(b0[i])b[o^oo][o?L-1-i:i]=1;
	};
	static int p1[N],p2[N];
	int lb=0,rb=L-1;
	for(i=0;i<L;++i){
		p1[i]=max(i+1,i-len[i]+L-1);
		p2[i]=min(i-1,i+len[i]-L+1);
	}
	for(i=1;i<L;++i)p1[i]=min(p1[i],p1[i-1]);
	for(i=L-2;i>=0;--i)p2[i]=max(p2[i],p2[i+1]);
	for(;;){
		int olb=lb,orb=rb;
		lb=max(lb,p2[orb]);rb=min(rb,p1[olb]);
		if(lb==olb && rb==orb)break;
	}
	for(i=0;i<=lb;++i)setv(0,i);
	for(i=rb;i<=L-1;++i)setv(1,i);
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&A,&B);
		for(i=1;i<=n;++i)e[i].clear();
		for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
		dfs1(A,0);P.clear();for(i=B;i;i=dad[i])P.push_back(i);
		for(i=0;i+1<P.size();++i){
			e[P[i]].erase(find(e[P[i]].begin(),e[P[i]].end(),P[i+1]));
			e[P[i+1]].erase(find(e[P[i+1]].begin(),e[P[i+1]].end(),P[i]));
		}
		L=P.size();
		memset(b0,0,L);
		memset(b1,0,L);
		memset(b[0],0,L);
		memset(b[1],0,L);
		for(i=0;i<L;++i)dfs2(P[i],0),len[i]=md[P[i]];
		solve(0);
		reverse(b0,b0+L);
		reverse(b1,b1+L);
		reverse(len,len+L);
		solve(1);
		reverse(b0,b0+L);
		reverse(b1,b1+L);
		reverse(len,len+L);
		for(i=0;i<L;++i)if(b1[i]?b[0][i] || b[1][i]:0<i && i<L-1 && b[0][i] && b[1][i])break;
		puts(i<L?"YES":"NO");
	}
}