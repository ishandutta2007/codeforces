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
const int M=1010;
int n,a[M],p[M],rk[M],b[M][M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n) a[i]=read(),p[i]=i;
	sort(p+1,p+n+1,[&](int x,int y){
		return a[x]>a[y];
	});
	F(i,1,n) rk[p[i]]=i;
 	F(i,1,n+1) F(j,1,n){
		b[i][j]=(j!=i-1);
	}
	F(i,1,n){
		int ps=i;
		F(j,1,n-a[p[i]]) b[ps][i]=0,ps=(ps==1 ? n+1 : ps-1);
	}
	cout<<n+1<<"\n";
	F(i,1,n+1){
		F(j,1,n){
			cout<<b[i][rk[j]];
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
11111
01111
10111
11011
11101
11110

ai,k=aj,k

ai,j=(bi)
*/