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
const int M=1e6+5;
int n,m,t[M],ans[M];
char s[M];
void work(){
	n=read(); m=read();
	scanf("%s",s);
	set<int> g;
	F(i,0,n*m-1){
		int o=s[i]-'0';
		t[i]=(i ? t[i-1] :0);
		t[i]+=o;
		if (i>=m) ans[i]=ans[i-m]+(t[i]-t[i-m]>0);
		else ans[i]=(t[i]>0);
		if (o) g.insert(i%m);
		cout<<ans[i]+g.size()<<" ";
		
	}
	cout<<"\n";
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
*/