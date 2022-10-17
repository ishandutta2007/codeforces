#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
int n;
int c[M][20];
void init(){
	F(i,1,200000){
		F(j,0,19){
			c[i][j]=c[i-1][j];
			if (i>>j&1) c[i][j]++;
		}
	}
}
void work(){
	int l=read(),r=read();
	int tt=r-l+1,ans=tt-1;
	F(i,0,19){
		ans=min(ans,tt-(c[r][i]-c[l-1][i]));
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	init();
	int T=read();
	while (T--) work();

	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/