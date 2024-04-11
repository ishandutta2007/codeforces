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
int n,a[M],b[M],used[M];
vector<int> va[M]; 
char s[M];
void work(){
	n=read();
	F(i,1,n) va[i].clear(),used[i]=0; 
	F(i,1,n) a[i]=read(),va[a[i]].pb(i);
	F(i,1,n) b[i]=read();
	int j=n; b[n+1]=-1;
	DF(i,n,1){
		if (b[i]!=b[i+1]){
			while (used[j]==1) j--;
			while (used[j]==2 && a[j]!=b[i]) j--;
			if (a[j]!=b[i]){
				cout<<"NO\n";
				return ;
			}
			used[va[b[i]].back()]=2;
			used[j]=1;
			va[b[i]].pop_back();
		}
		else{
			used[va[b[i]].back()]=2;
			va[b[i]].pop_back();
		}
	}
	cout<<"YES\n";
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
5
1 2 3 2 1 2
3 2 1 1 2 2
*/