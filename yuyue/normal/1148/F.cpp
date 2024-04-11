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
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10; 
LL a[M],b[M];
int n;
vector<int> v[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	LL sm=0;
	F(i,1,n){
		b[i]=read(); a[i]=read();
		F(j,0,62){
			if (a[i]>>j&1){
				v[j].pb(i);
				break;
			}
		}
		sm+=b[i];
	}
	LL msk=0;
	DF(i,61,0){
		LL tmp=0;
		for (int x:v[i]){
			if (__builtin_popcountll(a[x]&msk)&1){
				tmp-=b[x];
			}
			else tmp+=b[x];
		}
		if (tmp==0) continue;
		if ((tmp<0)^(sm>0)){
			msk|=(1ll<<i);
		}
	}
//	F(i,1,n){
//		cout<<(__builtin_popcountll(a[i]&msk)&1)<<"\n";
//	}
	cout<<msk<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/