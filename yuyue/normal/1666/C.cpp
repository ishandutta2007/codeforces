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
const int M=555;
int X[M],Y[M],tx[M],ty[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	F(i,1,3){
		X[i]=read();
		Y[i]=read();
		tx[i]=X[i];
		ty[i]=Y[i];
	}
	sort(tx+1,tx+4);
	sort(ty+1,ty+4);
	cout<<3<<"\n";
	cout<<tx[1]<<" "<<ty[2]<<" "<<tx[3]<<" "<<ty[2]<<"\n";
	bool fl=0;
	F(i,1,3){
		if (Y[i]==ty[2] && !fl){
			fl=1;
			continue;
		}
		cout<<X[i]<<" "<<Y[i]<<" "<<X[i]<<" "<<ty[2]<<"\n";
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