#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=2005;
const LL INF=1e18;
int n,m,S,T;
vector <pair <int,int> > e[N];
int a[N];
LL dS[N],dT[N];
vector <int> idS[N],idT[N];
int Sc,Tc;
void Dijkstra(int S,LL *dis,vector <int> *id,int &idc){
	typedef pair <LL,int> pLi;
	static int vis[N];
	priority_queue <pLi,vector <pLi>,greater <pLi> > Q;
	while (!Q.empty())
		Q.pop();
	For(i,1,n)
		dis[i]=INF;
	clr(vis);
	dis[S]=0;
	Q.push(mp(dis[S],S));
	idc=0;
	while (!Q.empty()){
		pLi p=Q.top();
		Q.pop();
		int x=p.se;
		if (vis[x])
			continue;
		vis[x]=1;
		if (!idc||dis[id[idc].back()]!=dis[x])
			idc++;
		id[idc].pb(x);
		for (auto E : e[x])
			if (!vis[E.fi]&&dis[x]+E.se<dis[E.fi]){
				dis[E.fi]=dis[x]+E.se;
				Q.push(mp(dis[x]+E.se,E.fi));
			}
	}
}
LL pre[N][N][2],dp[N][N][2];
int gameover[N][N];
int pS[N],pT[N];

int main(){
	n=read(),m=read();
	S=read(),T=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,m){
		int x=read(),y=read(),z=read();
		e[x].pb(mp(y,z));
		e[y].pb(mp(x,z));
	}
	Dijkstra(S,dS,idS,Sc);
	Dijkstra(T,dT,idT,Tc);
//	outarr(dS,1,n);
//	outarr(dT,1,n);
	For(i,1,Sc)
		for (auto x : idS[i])
			pS[x]=i;
	For(i,1,Tc)
		for (auto x : idT[i])
			pT[x]=i;
//	outarr(pS,1,n);
//	outarr(pT,1,n);
	For(i,0,Sc){
		int mi=0;
		For(j,1,n)
			if (pS[j]>i)
				mi=max(mi,pT[j]);
		For(j,mi,Tc)
			gameover[i][j]=1;
	}
//	For(i,0,Sc){
//		For(j,0,Tc)
//			putchar('0'+gameover[i][j]);
//		putchar('\n');
//	}
	For(i,0,N-1)
		For(j,0,N-1)
			For(k,0,1)
				pre[i][j][k]=dp[i][j][k]=-INF;
	Fod(i,Sc,0)
		Fod(j,Tc,0){
			if (gameover[i][j]){
				dp[i][j][0]=0;
				dp[i][j][1]=0;
				pre[i][j][0]=0;
				pre[i][j][1]=0;
			}
			else {
				int flag=0;
				LL s=0;
				for (auto t : idS[i+1])
					if (pT[t]>j)
						s+=a[t],flag=1;
				pre[i][j][0]=max(pre[i+1][j][0],dp[i+1][j][1])+s;
				dp[i][j][0]=dp[i+1][j][0]+s;
				if (flag)
					dp[i][j][0]=max(dp[i][j][0],pre[i][j][0]);
				flag=0;
				s=0;
				for (auto t : idT[j+1])
					if (pS[t]>i)
						s+=a[t],flag=1;
				pre[i][j][1]=min(pre[i][j+1][1],dp[i][j+1][0])-s;
				dp[i][j][1]=dp[i][j+1][1]-s;
				if (flag)
					dp[i][j][1]=min(dp[i][j][1],pre[i][j][1]);
			}
//			printf("dp[%d][%d] = (%lld,%lld)\n",i,j,dp[i][j][0],dp[i][j][1]);
		}
	LL v=dp[0][0][0];
//	outval(v);
	if (v<0)
		puts("Cry");
	else if (v==0)
		puts("Flowers");
	else
		puts("Break a heart");
	return 0;
}