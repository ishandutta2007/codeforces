#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int mod=51123987,M=2e6+10;
char to[M];
int nxt[M],head[M],cnt=1;
void add(int x,char o){
	to[++cnt]=o; nxt[cnt]=head[x]; head[x]=cnt;
}
int chk(int x,char o){
	for (int i=head[x];i;i=nxt[i]) if (to[i]==o) return i;
	return 0;
}
int tot,lst,dep[M],fa[M],len[M],ed[M];
void init(){
	fa[0]=fa[1]=1; len[1]=-1;
	lst=tot=cnt=1;
}
char s[M];
int getfa(int x,int i){
	while (s[i]^s[i-1-len[x]]) x=fa[x];
	return x;
}
void ins(int i){
	int p=getfa(lst,i);
	int xx=chk(p,s[i]);
	if (!xx){
		int np=++tot; xx=tot;
		len[np]=len[p]+2;
		fa[np]=chk(getfa(fa[p],i),s[i]);
		add(p,s[i]);
		dep[np]=dep[fa[np]]+1;
	}
	lst=xx;
}
int n;
int main(){
	n=read();
	scanf("%s",s+1);
	int all=0; init();
	F(i,1,n){
		ins(i);
		ed[i]=dep[lst];
		all+=ed[i]; 
		all%=mod;
	}
	F(i,0,tot) len[i]=fa[i]=dep[i]=head[i]=0;
	init();
	reverse(s+1,s+n+1);
	int now=0;
	LL ans=1ll*all*(all-1)/2; ans%=mod;
	F(i,1,n){
		ins(i);
		now=(now+dep[lst])%mod;
		ans=(ans+mod-1ll*now*ed[n-i]%mod)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/