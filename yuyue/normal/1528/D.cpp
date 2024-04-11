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
const int M=666;
const LL inf=1e16;
int n,m;
LL c[M][M];
LL ans[M][M],dis[M],t[M];
bool vis[M];
void dij(int st){
	ms(dis,60); dis[st]=0; ms(vis,0);
	F(T,1,n){
		LL cm=inf;
		int x=-1;
		F(i,0,n-1){
			if (!vis[i] && cm>dis[i]) cm=dis[i],x=i;
		}
		if (x==-1) break;
		vis[x]=1;
		int dir=dis[x]%n;
		
//		cerr<<x<<" "<<dis[x]<<"    hhh\n";
		F(i,0,n-1) t[i]=inf;
		F(i,0,n-1){
			t[(i+dir)%n]=min(t[(i+dir)%n],dis[x]+c[x][i]);
		}
		if (!dis[x]){
			vis[x]=0;
			dis[x]=inf;
		}
		F(i,0,n-1) dis[i]=min(dis[i],t[i]);
		if (dis[x]){
			dis[(x+1)%n]=min(dis[(x+1)%n],dis[x]+1);
		}
	}
	F(i,0,n-1) ans[st][i]=dis[i];
	ans[st][st]=0;
}
int main(){
	n=read(); m=read();
	ms(c,60);
	F(i,1,m){
		int x=read(),y=read();
		LL z=read();
		c[x][y]=min(c[x][y],z);
	}
	F(i,0,n-1){
		dij(i);
	}
	F(i,0,n-1){
		F(j,0,n-1){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
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