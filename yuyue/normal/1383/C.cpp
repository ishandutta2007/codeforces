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
const int M=5e5+10;
int f[M],sz[M];
int Fd(int x){
	return f[x]==x ? x : f[x]=Fd(f[x]);
}
char s[M],t[M]; 
int n,e[55],in[55],dp[(1<<20)+5];
void work(){
	n=read();
	scanf("%s%s",s+1,t+1);
	F(i,0,25) sz[i]=0,f[i]=i,e[i]=in[i]=0;
	F(i,1,n){
//		if (s[i]>t[i]){
//			puts("-1");
//			return ;
//		}
		int x=s[i]-'a',y=t[i]-'a';
		if (x!=y){
			e[x]|=(1<<y);
			in[y]|=(1<<x);
		}
		f[Fd(x)]=Fd(y);
	}
	int ans=0,msk=0;
	F(i,0,19){
		if (e[i]) ans++,msk|=(1<<i);
		if (!e[i] && in[i]) ans++;
	}
//	cerr<<msk<<" !!!!\n";
	int lim=(1<<20)-1;
	ms(dp,1);dp[0]=0; 
	F(i,0,lim){ 
		if (!((i&msk)==i))continue;
		F(j,0,19) if (msk>>j&1 && !(i>>j&1)){
			int o=(in[j]&i)!=in[j];
//			cerr<<"trans "<<i<<" "<<j<<" "<<dp[i]<<" \n";
			dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+o);
		}
	}
	ans+=dp[msk];
	F(i,0,19) if ((e[i]||in[i]) && Fd(i)==i) ans--;
	cout<<ans<<"\n";
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