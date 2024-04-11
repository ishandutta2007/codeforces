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
const int mod=1e9+7,M=1e6+10;
int n;
char s[M],t[M];
int curl[M],nxt[M][2];
int dp[M]; 
void red(int &x){
	x=(x>=mod ? x-mod : x); 
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1); n=strlen(s+1);
	LL l0=1;
	while (n && s[n]=='0') n--,l0++;
	if (!n){
		cout<<l0-1<<"\n";
		return 0;
	}
	int o=0;
	F(i,1,n) if (s[i]=='1'){
		l0=l0*i%mod;
		o=i;
		break;
	}
	F(i,1,n-o+1) t[i]=s[i+o-1];
	n=n-o+1;
	F(i,1,n) s[i]=t[i];//,cerr<<s[i];cerr<<"\n";
//	cerr<<l0<<" !!\n";
	int la=n+1;
	F(i,1,n+1) curl[i]=n+1;
	nxt[n+1][0]=nxt[n+1][1]=n+1;
	DF(i,n,1){
		if (s[i]=='1'){
			nxt[i][1]=la;
			F(j,i+1,la-1){
				curl[j-i]=j;
			}
			nxt[i][0]=curl[1];
		
			la=i;
		}
		else{
			nxt[i][1]=la;
			if (i<n && s[i+1]=='0') nxt[i][0]=i+1;
			else{
				int le=1;
				while (s[i-le]=='0') le++;
				nxt[i][0]=curl[le+1];
			}
		}
	}
	if (la==n+1){
		cout<<n<<"\n";
		return 0;
	}
	F(j,1,la-1){
		curl[j]=j;
	}
	nxt[0][1]=la; nxt[0][0]=n+1;
	dp[0]=1;
//	F(i,0,n){
//		cerr<<nxt[i][0]<<" "<<nxt[i][1]<<"  nxt \n";
//	}
	F(i,0,n-1){
		F(o,0,1)
		red(dp[nxt[i][o]]+=dp[i]);
	}
	LL ans=0;
	F(i,1,n){
		if (s[i]=='1')
		ans=(ans+dp[i])%mod;
	}
//	cerr<<ans<<"\n";
	cout<<ans*l0%mod<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
001011000111
*/