#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10,mod=1e9+7;
char s[M],hry[M];
int n,fa[M],len[M],tot,lst,del[M],slink[M],t[M][26];
void init(){
	fa[1]=fa[0]=1; len[1]=-1; tot=1; lst=1;
}
int gt(int x,int id){
	for (;hry[id]^hry[id-len[x]-1];x=fa[x]);
	return x;
}
void extend(int id){
	int p=gt(lst,id),o=hry[id]-'a';
//	cout<<p<<"   gang \n";
	if (!t[p][o]){
		int np=++tot;
		fa[np]=t[gt(fa[p],id)][o];
		t[p][o]=np;
		len[np]=len[p]+2;
		del[np]=len[np]-len[fa[np]];
//		cout<<del[np]<<"\n";
		if (del[np]!=del[fa[np]]) slink[np]=fa[np];
		else slink[np]=slink[fa[np]];
	}
	lst=t[p][o];
}
LL ans[M],f[M];
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	if (n&1){
		cout<<0<<"\n";
		return 0;
	}
	int o=0;
	F(i,1,n/2){
		hry[++o]=s[i];
		hry[++o]=s[n-i+1];
	}
	init();
	ans[0]=1;
	F(i,1,n){
		extend(i);
		for (int x=lst;x;x=slink[x]){
			f[x]=ans[i-len[slink[x]]-del[x]]; 
			if (del[x]==del[fa[x]]) f[x]=(f[x]+f[fa[x]])%mod;
			if (i%2==0) ans[i]=(ans[i]+f[x])%mod;
		}
	}
	cout<<ans[n]<<"\n";
	return 0;
}