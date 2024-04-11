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
const int M=1e6+10;
int n,a[M];
map<int,int> h,g;
void work(){
	n=read();  h.clear();
	F(i,1,n) a[i]=read(),h[a[i]]++;
	F(i,1,n-1){
		g.clear();
		int la=-1;
		for (auto O:h){
			if (la!=-1){
				g[O.first-la]++;
				
			}if (O.second>1) g[0]+=O.second-1;
				la=O.first;
//			cerr<<O.first<<" "<<O.second<<" !!!\n";
		}
//		cerr<<g.size()<<"\n";
		h=g;
	}
	cout<<h.begin()->first<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
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
1
6
2 4 8 16 32 64
*/