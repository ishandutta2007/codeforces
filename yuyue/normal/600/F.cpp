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
const int M=2020;
int col[M][M];
int A,B,m,X[100100],Y[100100];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	A=read();  B=read(); m=read();
	F(i,1,m){
		int x=read(),y=read()+A;
		X[i]=x; Y[i]=y;
	}
	int ans=0;
	F(i,1,m){
		int x=X[i],y=Y[i];
		int c1=1,c2=1;
		while (col[x][c1]) c1++;
		while (col[y][c2]) c2++;
		col[x][c1]=y;
		col[y][c2]=x;
		ans=max(ans,max(c1,c2));
		if (c1==c2) continue;
		for (int nw=y,co=c2;nw;nw=col[nw][co],co^=c1^c2){
//			cerr<<nw<<"\n"; 
			swap(col[nw][c1],col[nw][c2]);
		}
	}
	cout<<ans<<"\n";
	F(i,1,m){
		int x=X[i],y=Y[i];
		F(j,1,ans) if (col[x][j]==y){
			cout<<j<<" ";
			break;
		}
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