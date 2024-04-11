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
const int M=1e5+10,C=110,N=M*C;
int qx[N],qy[N],dis[M][C];
int n,m,k,s;
vector<int> v[M];
int main(){
	n=read(); m=read(); k=read(); s=read();
	ms(dis,1);
	int l=1,r=0;
	F(i,1,n){
		int x=read();
		dis[i][x]=0;
		qx[++r]=i; qy[r]=x;
	}
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	while (l<=r){
		int x=qx[l],z=qy[l++];
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			if (dis[y][z]>dis[x][z]+1){
				dis[y][z]=dis[x][z]+1;
				qx[++r]=y; qy[r]=z;
			}
		}
	}
	F(i,1,n){
		sort(dis[i]+1,dis[i]+k+1);
		LL ans=0;
		F(j,1,s){
			ans+=dis[i][j];
		}
		cout<<ans<<' ';
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