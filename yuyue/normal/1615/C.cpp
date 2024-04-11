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
char s[M],t[M];

void work(){
	n=read(); 
	scanf("%s%s",s+1,t+1);
	int ans=n+1;
	int n10=0,n01=0;
	F(i,1,n){
		if (s[i]=='0' && t[i]=='1') n01++;
		if (s[i]=='1' && t[i]=='0') n10++;
	}
	if (n10==n01) ans=2*n10;
	n01=n10=0;
	F(i,1,n){
		
		if (s[i]=='0' && t[i]=='0') n01++;
		if (s[i]=='1' && t[i]=='1') n10++;
	}
	if (n10==n01+1) ans=min(ans,n10+n01);
	if (ans==n+1) cout<<"-1\n";
	else cout<<ans<<"\n";
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