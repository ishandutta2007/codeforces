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
int n,a[M],t[M],b[M],d[M],ans[M],used[M],q[M];
vector<int> va[M],v[M]; 
char s[M];
void work(){
	n=read();
	F(i,1,n) va[i].clear(),v[i].clear(),d[i]=0;
	F(i,1,n) a[i]=read(),va[a[i]].pb(i);
	F(i,1,n) b[i]=read();
//	int ct=0;
	int mx=0;
	F(i,1,n){
		if (va[i].size()>va[mx].size()) mx=i;
	}
	F(i,1,n){
		if (a[i]==mx || b[i]==mx) continue;
		d[a[i]]++;
		v[b[i]].pb(a[i]);
	}
	int l=1,r=0;
	F(i,1,n) if (!d[i]) q[++r]=i;

	while (l<=r){
		int x=q[l++];
		for (int y:v[x]){
			d[y]--;
			if (!d[y]) q[++r]=y;
		}
		v[x].clear();
	}
	F(i,1,n){
		if (v[i].size()){
			cout<<"WA\n";
			return ;
		}
	}
	cout<<"AC\n";
//	F(i,1,n){
//		F(j,1,ct){	
////			cerr<<ct<<" "<<t[j]<<" "<<i-1<<"\n";
//
//			int x=va[t[j]][i-1];
//			ans[x]=t[j%ct+1];
//		}
//		int tt=0;
//		F(j,1,ct){
//			if (va[t[j]].size()>i){
//				t[++tt]=t[j];
//			}
//		}
//		ct=tt;
//		if (!ct) break;
//	}
//	F(i,1,n) cout<<ans[i]<<" ";
//	cout<<"\n";
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
1 2 2 2 
1
5
1 2 3 2 1 2
3 2 1 1 2 2
*/