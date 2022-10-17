#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=8080,mod=1e9+7;
char ch[M];
int n,cur[M],lst[M],dp[M],s[M];
int main(){
//	freopen("count1.in","r",stdin);
//	freopen("count1.out","w",stdout);
	n=read(); scanf("%s",ch+1);
	F(i,1,n){
		int o=ch[i]-'a';
    	lst[i]=cur[o];
		cur[o]=i;
		if (!lst[i]) dp[i]=1;
	}
	F(i,2,n){
		F(j,1,n) s[j]=(s[j-1]+dp[j])%mod;
		F(j,1,n){
			dp[j]=(s[j]+mod-s[lst[j]])%mod;	
		}
	}
	LL ans=0;
	F(i,1,n) ans=(ans+dp[i])%mod;
	cout<<ans<<"\n";
	return 0;
}