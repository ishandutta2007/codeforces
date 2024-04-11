#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back
template<int SZ> struct MCMF{//SZ = N+1
	typedef int F; typedef int C;typedef pair<C,int> pci;
	priority_queue<pci,vector<pci>,greater<pci> > q;
	const C INF = numeric_limits<C>::max();
	struct EDGE{int to,rev;F cap;C cost;};int n,s,t;F mf;C mc;
	bool in[SZ];C d[SZ],D[SZ];vector<EDGE> E;vector<int> G[SZ];
	void init(int N=SZ-1){for(int i=0;i<=N;i++) G[i].clear();E.clear();}
	void addedge(int u,int v,F cap,C cost){int id=E.size();
		E.eb((EDGE){v,id+1,cap,cost});G[u].eb(id);
		E.eb((EDGE){u,id,0,-cost});G[v].eb(id+1);}
	bool mod(){//if flow is short, use slack to modify d
		while(!q.empty())	q.pop();
		for(int i=0;i<=n;i++) if(in[i]) D[i]=0,q.emplace(0,i);else D[i]=INF;
		while(!q.empty()){
			C y,z;int x;tie(y,x)=q.top(),q.pop();
			if(x==t)	break;if(D[x]!=y)	continue;
			for(int i:G[x]){auto &e=E[i];
				if(e.cap&&(z=y+(e.cost-d[e.to]+d[x]))<D[e.to])
					D[e.to]=z,q.emplace(z,e.to);}
		}
		if(D[t]==INF)	return false;
		for(int i=0;i<=n;i++)	if(D[i]!=INF)	d[i]+=D[i];return true;}
	F aug(int x,F cf){
		if(x==t)	return mf+=cf,mc+=cf*d[t],cf;
		in[x]=1;F df,gf=cf;
		for(int i:G[x]){auto &e=E[i];
			if(e.cap&&!in[e.to]&&d[e.to]==e.cost+d[x]){
				df=aug(e.to,min(e.cap,gf));
				gf-=df,e.cap-=df,E[e.rev].cap+=df;
				if(!gf)	return in[x]=0,cf;}}return cf-gf;}
	pair<F,C> mcmf(int n_,int s_,int t_){
		n=n_,s=s_,t=t_,mc=0,mf=0;//for non-neg, init d=0 and then augment
		for(int i=0;i<=n;i++)	d[i]=(i==s?0:INF);
		while(!q.empty())	q.pop();q.emplace(0,s);
		while(!q.empty()){
			C y;int x;tie(y,x)=q.top();q.pop();if(d[x]!=y)	continue;
			for(int i:G[x]){auto &e=E[i];
				if(e.cap&&y+e.cost<d[e.to])
					d[e.to]=e.cost+y,q.emplace(d[e.to],e.to);}
		}
		do{do{for(int i=0;i<=n;i++)in[i]=0;}while(aug(s,INF));}while(mod());
		return{mf,mc};}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<string> ans(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			ans[i]+="2";
		ans[i][i]='0';
	}
	MCMF<1305> MC;
	MC.init();
	int pt=n;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		x--;y--;
		ans[x][y]='1';
		ans[y][x]='0';
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(ans[i][j]=='2'){
				++pt;
				MC.addedge(0,pt,1,0);
				MC.addedge(pt,i+1,1,0);
				MC.addedge(pt,j+1,1,0);
			}
	for(int i=0;i<n;i++){
		int c1=0,c2=0;
		for(char c:ans[i])
			c2+=c=='2',c1+=c=='0';
		for(int j=c1-1;j<=c1+c2-1;j++)
			MC.addedge(i+1,1300,1,j);
	}
	MC.mcmf(1300,0,1300);
	pt=n;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(ans[i][j]=='2'){
				++pt;
				int in;
				for(int i:MC.G[pt])
					if(MC.E[i].cap==0&&!(i&1))
						in=MC.E[i].to-1;
				ans[i+j-in][in]='1';
				ans[in][i+j-in]='0';
			}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;
}